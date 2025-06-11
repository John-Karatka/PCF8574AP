#ifndef PCF_H_
#define PCF_H_

class PCF {
	unsigned char address;
public:
	PCF(unsigned char PCF_Address);
	int sendData(unsigned char data);
	int sendData(unsigned char *dataArray, int arrayLength);
	unsigned char readData();
	void readData(unsigned char *dataArray, int arrayLength);
};

#endif