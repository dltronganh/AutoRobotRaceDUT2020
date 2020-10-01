#ifndef StepMotorCPP
#define StepMotorCPP

#include "StepMotor.h"

typedef struct {
	GPIO_TypeDef* DirPort;
	GPIO_TypeDef* StepPort;
	GPIO_TypeDef* EnPort;

	uint16_t DirPin;
	uint16_t StepPin;
	uint16_t EnPin;

	uint8_t Ahead; //which of Dir Pin will make the motor go ahead
}StepMotor;

void InitMotor(StepMotor M){
	HAL_GPIO_WritePin(M.EnPort, M.EnPin, 0);
}

void Start(StepMotor M, GPIO_TypeDef* DIRPORT, uint16_t DIRPIN, GPIO_TypeDef* STEPPORT, uint16_t STEPPIN, GPIO_TypeDef* ENPORT, uint16_t ENPIN){
	M.DirPort = DIRPORT;
	M.DirPin =  DIRPIN;

	M.StepPort = STEPPORT;
	M.StepPin = STEPPIN;

	M.EnPort = ENPORT;
	M.EnPin = ENPIN;

	InitMotor(M);
}

void TurnSingleMotor(StepMotor M, uint8_t direction, float angle){ //1 is ahead, 0 is back
	if (direction == AHEAD) direction = M.Ahead;
	else if (direction == BACK) direction = 1 - M.Ahead;

	HAL_GPIO_WritePin(M.DirPort, M.DirPin, direction);
}

#endif
