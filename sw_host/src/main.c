
#include <stdio.h>
#include <stdint.h>
#include <libusb.h>
#include <stdbool.h>

// TODO clean up platform specific functions into port directory
#ifndef _MSC_VER
#include <endian.h>
#include <unistd.h>
#endif

#include <stdio.h>

#include "atusbprog_proto.h"
#include "device.h"

/* Build with a warning as long as we are still using a reserved PID. */
#if ATUSBPROG_USB_PID <= 0x0010
#pragma message("atusbprog is being built with a TEST PID! This is for development use ONLY")
#endif

static libusb_device_handle *dev;

// TODO cleanup into port directory
static void sleep_ms(unsigned int ms)
{
#ifdef _MSC_VER
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif
}

static bool version_check()
{
	aup_in_msg_t  in_msg;
	aup_out_msg_t out_msg;
	int status;
	int rxLen = 0;
	int txLen = 0;

	aup_in_msg_version_rsp_t *vers = NULL;

	// No payload for this command, and the msg type must be zero for compatibility.

	printf("Sending version request...\n");

	out_msg.msg_type = AUP_MSG_VERSION_REQ_RSP;
	status = libusb_bulk_transfer(dev, AUP_EP1OUT, (unsigned char *)&out_msg, AUP_OUT_MSG_HDR_LEN, &txLen, 0);
	if (status != LIBUSB_SUCCESS) {
		return false;
	}

	printf("Reading version response...\n");

	status = libusb_bulk_transfer(dev, AUP_EP1IN, (unsigned char *)&in_msg, sizeof(in_msg), &rxLen, 0);
	if (status != LIBUSB_SUCCESS) {
		return false;
	}

	printf("Received %d bytes\n", rxLen);
	if (rxLen != (sizeof(aup_in_msg_version_rsp_t) + AUP_IN_MSG_HDR_LEN))
	{
		printf("Invalid payload size.\n");
		return false;
	}

	if (in_msg.msg_type != AUP_MSG_VERSION_REQ_RSP) {
		printf("Invalid response type %d\n", in_msg.msg_type);
		return false;
	}

	vers = &in_msg.msg_data.version_rsp;
	printf("Connected device version %d.%d.%d\n", vers->maj, vers->min, vers->rev);
	if (vers->maj != AUP_PROTO_VERSION_MAJ || vers->min != AUP_PROTO_VERSION_MIN || vers->rev != AUP_PROTO_VERSION_REV)
	{
		printf("Expected version %d.%d.%d\n", AUP_PROTO_VERSION_MAJ, AUP_PROTO_VERSION_MIN, AUP_PROTO_VERSION_REV);
		return false;
	}

	return true;
}

static void send_led(uint8_t mask, uint8_t val)
{
	aup_out_msg_t out_msg;
	int status;
	int txLen = 0;

	out_msg.msg_type = AUP_MSG_LED_REQ;
	out_msg.msg_data.led_req.led_mask = mask;
	out_msg.msg_data.led_req.led_val = val;

	status = libusb_bulk_transfer(dev, AUP_EP1OUT, (unsigned char *)&out_msg, sizeof(aup_out_msg_led_req_t) + AUP_OUT_MSG_HDR_LEN, &txLen, 0);
	if (status != LIBUSB_SUCCESS)
	{
		printf("err send %d\n", status);
	}
}

static void send_data_raw(const uint8_t *buf, uint8_t len, uint8_t *outbuf)
{
    union
    {
        aup_in_msg_t msg;
        uint8_t raw[AUP_MAX_PACKET_SIZE];
    } in;

    aup_out_msg_t *out_msg;
    int status;
    int txLen = 0;
    int rxLen = 0;

    // TODO: add some defines to calculate message size
    out_msg = malloc(AUP_OUT_MSG_HDR_LEN + len);

    if (out_msg == NULL)
    {
        printf("could not malloc message\n");
        return;
    }

    out_msg->msg_type = AUP_MSG_DATA_WRITE;

    if (buf != NULL)
    {
        memcpy(out_msg->msg_data.data_write.payload, buf, len);
    }
    else
    {
        memset(out_msg->msg_data.data_write.payload, 0x00, len);
    }

    //printf("sending %d byte message\n", AUP_OUT_MSG_HDR_LEN + len);
    status = libusb_bulk_transfer(dev, AUP_EP1OUT, (unsigned char *)out_msg, AUP_OUT_MSG_HDR_LEN + len, &txLen, 0);
    //printf("sent %d byte(s)\n", txLen);
    free(out_msg);

    if (status == LIBUSB_SUCCESS)
    {
        // receive the response
        status = libusb_bulk_transfer(dev, AUP_EP1IN, (unsigned char*)&in.msg, AUP_MAX_PACKET_SIZE, &rxLen, 0);

        if (status == LIBUSB_SUCCESS)
        {
            //printf("received %d byte message\n", rxLen);

            if (rxLen >= AUP_OUT_MSG_HDR_LEN)
            {
                printf("rcv data {");
                for (int i = 0; i < rxLen - 1; i++)
                {
                    printf(" %02x", in.msg.msg_data.data_write.payload[i]);
                }
                printf(" }\n");

                if (outbuf != NULL)
                {
                    memcpy(outbuf, in.msg.msg_data.data_write.payload, rxLen - 1);
                }
            }
        }
        else
        {
            printf("err rcv data %d\n", status);
        }
    }
    else
    {
        printf("err xfr data %d\n", status);
    }
}


static void read_page(uint8_t page, uint8_t *buf)
{
    uint8_t pgbuf[256];

    // Use the page buffer as temp storage
    pgbuf[0] = 0x30; // Read Page command
    pgbuf[1] = page; // page number (0-31)

    printf("Reading page %d\n", page);

    // Send the read page command.
    send_data_raw(pgbuf, 2, NULL);

    // Read out all the chunks of the page.
    for (int i = 0; i < 16; i++)
    {
        send_data_raw(NULL, 16, &pgbuf[16 * i]);
    }

    if (buf != NULL)
    {
        memcpy(buf, pgbuf, 256);
    }
}

static void erase_chip(void)
{
    uint8_t cmd_buf[4];

    cmd_buf[0] = 0xAC;
    cmd_buf[1] = 0x80;
    cmd_buf[2] = 0x00;
    cmd_buf[3] = 0x00;

    printf("erasing chip...\n");
    send_data_raw(cmd_buf, sizeof(cmd_buf), NULL);
    sleep_ms(500);
}

static void program_byte(uint16_t addr, uint8_t byte)
{
    uint8_t cmd_buf[4];

    cmd_buf[0] = 0x40;
    cmd_buf[1] = (addr >> 8) & 0xff;
    cmd_buf[2] = (addr >> 0) & 0xff;
    cmd_buf[3] = byte;

    send_data_raw(cmd_buf, sizeof(cmd_buf), NULL);
    sleep_ms(10);
}

static void send_rst_cmd(bool oe, bool rst)
{
    aup_out_msg_t out_msg;
    int status;
    int txLen = 0;

    uint8_t flags = 0;

    if (oe)
    {
        flags |= RST_REQ_FLAG_OE;
    }

    if (rst)
    {
        flags |= RST_REQ_FLAG_RST;
    }

    out_msg.msg_type = AUP_MSG_RST_REQ;
    out_msg.msg_data.rst_req.flags = flags;

    status = libusb_bulk_transfer(dev, AUP_EP1OUT, (unsigned char *)&out_msg, AUP_OUT_MSG_HDR_LEN + sizeof(aup_out_msg_rst_req_t), &txLen, 0);
}

const uint8_t pgm_mem[] = {
    0x74, 0xf8, 0xf5, 0x80, 0x23, 0x7b, 0x01, 0x7a, 0x00, 0x79, 0x00, 0xd9, 0xfe, 0xda, 0xfc, 0xdb,
    0xfa, 0x80, 0xef,
};

static void test_device()
{
    const uint8_t at89s52_init_msg[] = { 0xAC, 0x53, 0x00, 0x00 };

    if (!version_check())
    {
        printf("Error reading version, or version mismatch.\n");
    }

    // Initializing programming mode...
    send_led(LED_REQ_MASK_ALL, LED_REQ_MASK_RED);

    // Initialize the reset line...
    send_rst_cmd(true, true);
    sleep_ms(100);
    send_led(LED_REQ_MASK_ALL, LED_REQ_MASK_GRN);

    // Send the data init message.
    send_data_raw(at89s52_init_msg, 4, NULL);

    erase_chip();

    for (uint16_t addr = 0; addr < sizeof(pgm_mem); addr++)
    {
        program_byte(addr, pgm_mem[addr]);
    }

    // Clear the reset line...
    send_rst_cmd(false, false);
    sleep_ms(100);

    printf ("Send LED off\n");
    send_led(LED_REQ_MASK_ALL, 0x00);

}

int main(int argc, char **argv)
{
	int status;

	printf("Initializing libusb...\n");
	status = libusb_init(NULL);

	if (status != LIBUSB_SUCCESS)
	{
		printf("Could not initialize libusb.\n");
		return 1;
	}

	printf("Detecting atusbprog device...\n");
	dev = libusb_open_device_with_vid_pid(NULL, ATUSBPROG_USB_VID, ATUSBPROG_USB_PID);

	if (dev != NULL)
	{
		printf("Device found!\n");

		status = libusb_claim_interface(dev, 0);
		if (status == LIBUSB_SUCCESS)
		{
			test_device();
			libusb_release_interface(dev, 0);
		}
		else
		{
			printf("Could not claim interface.\n");
		}

		libusb_close(dev);
	}
	else
	{
		printf("No device connected.\n");
	}

	printf("Deinitializing libusb...\n");
	libusb_exit(NULL);

    return 0;
}
