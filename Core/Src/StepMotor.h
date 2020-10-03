/*
 * StepMotor.h
 *
 *  Created on: Sep 30, 2020
 *      Author: DELL
 */

#ifndef SRC_STEPMOTOR_H_
#define SRC_STEPMOTOR_H_
#include "Define.h"

void InitAutoCar();
void SetSpeedMPin(StepMotor* M, uint8_t MS1, uint8_t MS2, uint8_t MS3);
void SetSpeedM(StepMotor* M, uint16_t speed);
void SetSpeed(uint16_t speed);
void InitMotor(StepMotor* M, uint8_t ahead);
void SetStepMotor(StepMotor* M, int32_t steps);
void SetStepMotorContinue(StepMotor* M, int32_t steps);
void RunCar();
void RunningCar();

#endif /* SRC_STEPMOTOR_H_ */
