
#include <stdio.h>
#include <stdint.h>
#include <libusb.h>
#include <stdbool.h>

// TODO clean up platform specific functions into port directory
#ifndef _MSC_VER
#include <endian.h>
#include <unistd.h>
#endif

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

static void send_data_pattern(uint8_t len)
{
    aup_out_msg_t *out_msg;
    int status;
    int txLen = 0;

    // TODO: add some defines to calculate message size
    out_msg = malloc(AUP_OUT_MSG_HDR_LEN + len);
    
    if (out_msg == NULL)
    {
        printf("could not malloc message\n");
        return;
    }

    out_msg->msg_type = AUP_MSG_DATA_WRITE;
    for (int i = 0; i < len; i++)
    {
        out_msg->msg_data.data_write.payload[i] = 0x10 + i;
    }

    status = libusb_bulk_transfer(dev, AUP_EP1OUT, (unsigned char *)out_msg, AUP_OUT_MSG_HDR_LEN + len, &txLen, 0);

    free(out_msg);
}

static void test_device()
{
	if (!version_check())
	{
		printf("Error reading version, or version mismatch.\n");
	}

	for (int repeat = 0; repeat < 4; repeat++)
	{
		printf("Loop %d\n", repeat);

		for (int i = 0; i < 3; i++)
		{
			printf("Send LED %d on\n", i);
			send_led(LED_REQ_MASK_ALL, 1 << i);
            send_data_pattern(16);
            sleep_ms(400);
		}
	}

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
