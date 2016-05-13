#include <string.h>
#include <stdio.h>

#include <motelib/system.h>
#include <motelib/timer.h>
#include <motelib/sensor.h>
#include <motelib/radio.h>
#include <motelib/led.h>
#include <motelib/actor.h>
#include <motelib/uart.h>

#include "platform.h"

Timer t1;

struct Device {
	char name[25];
	char type[25];
	uint16_t value;
};

void sendDone(RadioStatus s)
{
    ledToggle(0);
}

void send(uint16_t value)
{

	struct Device device;
	strcpy(device.name, "MRF2");
	strcpy(device.type, "Brightness");
	device.value = value;

	radioRequestTx(BROADCAST_ADDR, 2, (char*)&device, sizeof(device), sendDone);
	actorSetState(0,0);
}

void sensor(Timer *t)
{
	actorSetState(0, 1);
	sensorRequestAnalog(SENSOR_1, send);
}

void boot()
{
	uartEnable(true, true);
	timerCreate(&t1);
	timerStart(&t1, TIMER_PERIODIC, 300000, sensor);
}
