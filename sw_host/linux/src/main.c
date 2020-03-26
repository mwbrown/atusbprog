
#include <stdio.h>
#include <stdint.h>
#include <libusb.h>
#include <endian.h>
#include <stdbool.h>
#include <unistd.h>

#include "atusbprog_proto.h"

#include "device.h"

/* Build with a warning as long as we are still using a reserved PID. */
#if ATUSBPROG_USB_PID <= 0x0010
#warning "atusbprog is being built with a TEST PID! This is for development use ONLY"
#endif

static libusb_device_handle *dev;
static uint16_t last_sof_nr;

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
	if (status != 0) {
		return false;
	}

	printf("Reading version response...\n");

	status = libusb_bulk_transfer(dev, AUP_EP1IN, (unsigned char *)&in_msg, sizeof(in_msg), &rxLen, 0);
	if (status != 0) {
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
	if (status != 0)
	{
		printf("err send %d\n", status);
	}	
}

static void test_device()
{
	if (!version_check())
	{
		printf("Error reading version, or version mismatch.\n");
	}

	printf ("Send LED on\n");
	send_led(0x01, 0x01);
	usleep(1000000);

	printf ("Send LED off\n");
	send_led(0x01, 0x00);
}

int main(int argc, char **argv)
{
	printf("Initializing libusb...\n");
	libusb_init(NULL);

	printf("Detecting atusbprog device...\n");
	dev = libusb_open_device_with_vid_pid(NULL, ATUSBPROG_USB_VID, ATUSBPROG_USB_PID);

	if (dev != NULL)
	{
		printf("Device found!\n");
		
		test_device();
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
