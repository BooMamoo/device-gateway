#include <string.h>
#include <stdio.h>

#include <motelib/system.h>
#include <motelib/timer.h>
#include <motelib/radio.h>
#include <motelib/sensor.h>
#include <motelib/uart.h>
#include <motelib/led.h>

struct Device {
	char name[25];
	char type[25];
	uint16_t value;
};

uint8_t chartoint(char c) 
{
	return c - '0';
}

char inttochar(int i) 
{
	return i + '0';
}

void receive(Address source,MessageType type,void *message,uint8_t len)
{
	struct Device *dev = message;
	char name[sizeof(dev->name)];
	char type_device[sizeof(dev->type)];
	uint16_t value;

	memcpy(name, dev->name, sizeof(dev->name));
	memcpy(type_device, dev->type, sizeof(dev->type));
	memcpy(&value, &dev->value, sizeof(dev->value));

	printf("%s,%s,%d\n", name, type_device, value);
	ledToggle(0);
}

void boot()
{
	uartEnable(true, true); // Enable uart
	radioSetRxHandler(receive);
}
