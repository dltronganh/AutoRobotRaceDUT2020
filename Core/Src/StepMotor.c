#ifndef StepMotorCPP
#define StepMotorCPP

#include "StepMotor.h"

typedef struct {
	GPIO_TypeDef *DirPort;
	GPIO_TypeDef *StepPort;
	GPIO_TypeDef *EnPort;

	uint16_t DirPin;
	uint16_t StepPin;
	uint16_t EnPin;

	GPIO_TypeDef *MS1Port;
	uint16_t MS1Pin;

	GPIO_TypeDef *MS2Port;
	uint16_t MS2Pin;

	GPIO_TypeDef *MS3Port;
	uint16_t MS3Pin;
} pin;

typedef struct {
	pin Pin;
	uint8_t Ahead; //which of Dir Pin will make the motor go ahead
	uint32_t Steps;
} StepMotor;

void InitMotor(StepMotor M) {
	HAL_GPIO_WritePin(M.Pin.EnPort, M.Pin.EnPin, 0); //enable

	HAL_GPIO_WritePin(M.Pin.MS1Port, M.Pin.MS1Pin, 0); //set to speed 1 step
	HAL_GPIO_WritePin(M.Pin.MS2Port, M.Pin.MS2Pin, 0);
	HAL_GPIO_WritePin(M.Pin.MS3Port, M.Pin.MS3Pin, 0);

	M.Steps = 0;
}

void Start(StepMotor M, pin Pin, uint8_t ahead) {
	M.Pin.DirPort = Pin.DirPort;
	M.Pin.DirPin = Pin.DirPin;

	M.Pin.StepPort = Pin.StepPort;
	M.Pin.StepPin = Pin.StepPin;

	M.Pin.EnPort = Pin.EnPort;
	M.Pin.EnPin = Pin.EnPin;

	M.Pin.MS1Port = Pin.MS1Port;
	M.Pin.MS1Pin = Pin.MS1Pin;

	M.Pin.MS2Port = Pin.MS2Port;
	M.Pin.MS2Pin = Pin.MS2Pin;

	M.Pin.MS3Port = Pin.MS3Port;
	M.Pin.MS3Pin = Pin.MS3Pin;

	M.Ahead = ahead;
	InitMotor(M);
}

//void TurnSingleMotor(StepMotor M, uint8_t direction, float angle) { //1 is ahead, 0 is back
//	if (direction == AHEAD)
//		direction = M.Ahead;
//	else if (direction == BACK)
//		direction = 1 - M.Ahead;
//
//	HAL_GPIO_WritePin(M.Pin.DirPort, M.Pin.DirPin, direction);
//}

void SetSpeed(uint16_t speeds){

}

void SetStepMotor(StepMotor M, int32_t steps) {//if step < 0, then motor comback

}

void RunMotor(){

}

#endif
