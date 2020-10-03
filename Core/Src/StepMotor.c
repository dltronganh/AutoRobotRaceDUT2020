#ifndef StepMotorCPP
#define StepMotorCPP
#include "StepMotor.h"

int8_t NumOfNextMotor = 0;
int32_t StepPendingOfMotors[NUM_OF_MOTOR] = { }; //maximum 10 motor can turn now
uint8_t RunningMotor[NUM_OF_MOTOR]={};

StepMotor *MotorArray[NUM_OF_MOTOR] = { };

uint8_t *Running; //if 1: running, 0: stop

void InitAutoCar(uint8_t *running) {
	Running = running;
	*Running = 0;
	for (int i = 0; i < NUM_OF_MOTOR; i++) {
		StepPendingOfMotors[i] = 0;
		RunningMotor[i] = 0;
	}
}

void SetSpeedMPin(StepMotor *M, uint8_t MS1, uint8_t MS2, uint8_t MS3) {
	HAL_GPIO_WritePin(M->Pin.MS1Port, M->Pin.MS1Pin, MS1);
	HAL_GPIO_WritePin(M->Pin.MS2Port, M->Pin.MS2Pin, MS2);
	HAL_GPIO_WritePin(M->Pin.MS3Port, M->Pin.MS3Pin, MS3);
}

void SetSpeedM(StepMotor *M, uint16_t speed) { //1 is slowest, 5 is fastest
	switch (speed) {
	case 1:
		SetSpeedMPin(M, 1, 1, 1);	//1/16 step
	case 2:
		SetSpeedMPin(M, 1, 1, 0);	//1/8 step
	case 3:
		SetSpeedMPin(M, 0, 1, 0);	//1/4 step
	case 4:
		SetSpeedMPin(M, 1, 0, 0);	//1/2 step
	case 5:
		SetSpeedMPin(M, 0, 0, 0);	//1 step
	}
}

void SetSpeed(uint16_t speed) {	//set speed for all Motor
	for (int i = 0; i < NUM_OF_MOTOR; i++) {
		SetSpeedM(MotorArray[i], speed);
	}
}

void InitMotor(StepMotor *M, uint8_t ahead) {
	HAL_GPIO_WritePin(M->Pin.EnPort, M->Pin.EnPin, 0); //enable
	SetSpeedM(M, 5); //set full speed of Motor

	M->Steps = 0;
	M->Ahead = ahead;

	MotorArray[NumOfNextMotor] = M;
	M->Num = NumOfNextMotor;
	NumOfNextMotor++;
}

void SetStepMotor(StepMotor *M, int32_t steps) { //if step < 0, then motor comback
	StepPendingOfMotors[M->Num] = steps;
}

void SetStepMotorContinue(StepMotor *M, int32_t steps) { //When you want to plus more step for motor to run continue or for a long routine
	StepPendingOfMotors[M->Num] += steps;
}

void RunCar() {
	for (int i = 0; i < NUM_OF_MOTOR; i++){
		MotorArray[i]->Steps = StepPendingOfMotors[i];
		if (StepPendingOfMotors[i] != 0) RunningMotor[i] = 1;
		if (StepPendingOfMotors[i] < 0) //back
			HAL_GPIO_WritePin(MotorArray[i]->Pin.DirPort, MotorArray[i]->Pin.DirPin, (1 - MotorArray[i]->Ahead));
		else if (StepPendingOfMotors[i] > 0) //ahead
			HAL_GPIO_WritePin(MotorArray[i]->Pin.DirPort, MotorArray[i]->Pin.DirPin, (MotorArray[i]->Ahead));
	}
	*Running = 1; //For Running Status
}

void RunningCar(){ //this void use to check if Step variable in Motor is zero or not? if not, take action
	for(int i = 0; i < NUM_OF_MOTOR; i++){
//		if (){

//		}
	}
}

#endif
