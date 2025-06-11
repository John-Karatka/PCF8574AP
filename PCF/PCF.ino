#include <Wire.h>
#include "PCF.h"

//Addresses
/*
A2, A1, A0

000 - 56
001 - 57
010 - 58
011 - 59
100 - 60
101 - 61
110 - 62
111 - 63
*/
const int DEVICE_ADDRESS = 0; //Set addres of device here. See page 
uint8_t data;
PCF pcf_chip(DEVICE_ADDRESS);

void setup() {
	Wire.begin();
	Serial.begin(115200);
}

void loop() {
	uint8_t data = 0;
	
	//Send data to chip:
	pcf_chip.sendData(data);
	
	//Read data from chip:
	data = pcf_chip.readData();
	Serial.println(data);
	delay(1000);
}