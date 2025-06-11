#include "PCF.h"
#include <Wire.h>

//Constructor
PCF::PCF(unsigned char PCF_Address) {
	address = PCF_Address;
	Wire.begin();
}

//Sends a byte of data to the PCF chip, returns any errors
int PCF::sendData(unsigned char data) {
	int ack;
	Wire.beginTransmission(address);
	Wire.write(data);
	ack = Wire.endTransmission();
	return(ack);
}

//Sends an array of data bytes to the PCF chip, returns any errors
int PCF::sendData(unsigned char *dataArray, int arrayLength) {
	int ack;
	Wire.beginTransmission(address);
	for (int i = 0; i < arrayLength; i++) { 
		Wire.write(dataArray[i]);
	}
	ack = Wire.endTransmission();
	return(ack);
}

//Reads the state of the PCF chip, returns result
unsigned char PCF::readData() {
	unsigned char data;
	Wire.requestFrom(address, 1, true);
	while(Wire.available()) {
		data = Wire.read();
	}
	return(data);
}

//Reads the state of the PCF chip muliple times and puts it in an array
void PCF::readData(unsigned char *dataArray, int arrayLength) {
	Wire.requestFrom(address, arrayLength, true);
	while (Wire.available()) {
		for (int i = 0; i < arrayLength; i++) {
			dataArray[i] = Wire.read();
		}
	}
}