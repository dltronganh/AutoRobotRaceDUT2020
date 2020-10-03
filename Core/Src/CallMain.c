/*
 * CallMain.c
 *
 *  Created on: Oct 3, 2020
 *      Author: DELL
 */

#include "CallMain.h"

void SetM1Pin(StepMotor *M1, uint8_t ahead) {
	M1->Pin.DirPin = M1DirPin;
	M1->Pin.DirPort = M1DirPort;
	M1->Pin.EnPin = M1EnPin;
	M1->Pin.EnPort = M1EnPort;
	M1->Pin.StepPin = M1StepPin;
	M1->Pin.StepPort = M1StepPort;

	M1->Pin.MS1Pin = M1MS1Pin;
	M1->Pin.MS1Port = M1MS1Port;
	M1->Pin.MS2Pin = M1MS2Pin;
	M1->Pin.MS2Port = M1MS2Port;
	M1->Pin.MS3Pin = M1MS3Pin;
	M1->Pin.MS3Port = M1MS3Port;

	InitMotor(M1, ahead);
}

void SetM2Pin(StepMotor *M2, uint8_t ahead) {
	M2->Pin.DirPin = M2DirPin;
	M2->Pin.DirPort = M2DirPort;
	M2->Pin.EnPin = M2EnPin;
	M2->Pin.EnPort = M2EnPort;
	M2->Pin.StepPin = M2StepPin;
	M2->Pin.StepPort = M2StepPort;

	M2->Pin.MS1Pin = M2MS1Pin;
	M2->Pin.MS1Port = M2MS1Port;
	M2->Pin.MS2Pin = M2MS2Pin;
	M2->Pin.MS2Port = M2MS2Port;
	M2->Pin.MS3Pin = M2MS3Pin;
	M2->Pin.MS3Port = M2MS3Port;

	InitMotor(M2, ahead);
}
