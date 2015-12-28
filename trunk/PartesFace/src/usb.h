#ifndef	_USB_H
#define	_USB_H	1

#include <iostream>
#include <libusb.h>

using namespace std;

void abrirPorta()
{
	libusb_device_handle *device;
	libusb_context *session = NULL;
	int r;
	
	r = libusb_init(&session);
	
	if(r < 0) {
		cout<<"Init Error "<<r<<endl;
		return;
	}
	
	libusb_set_debug(session, 3);

	device = libusb_open_device_with_vid_pid(session, 0x0403, 0x6001);

	if(device == NULL){
		cout<<"Cannot open device"<<endl;
		return;
	}

	unsigned char *data = new unsigned char[1];
	data[0]='a';

	if(libusb_kernel_driver_active(device, 0) == 1) {
		libusb_detach_kernel_driver(device, 0);
	}

	r = libusb_claim_interface(device, 0);

	if(r < 0) {
		cout<<"Cannot Claim Interface"<<endl;
		return;
	}

	int actual;
	libusb_bulk_transfer(device, (2 | LIBUSB_ENDPOINT_OUT), data, 4, &actual, 0);

	r = libusb_release_interface(device, 0);

	if(r!=0) {
		cout<<"Cannot Release Interface"<<endl;
		return;
	}

	libusb_close(device);
	libusb_exit(session);

	delete[] data;
}

#endif
