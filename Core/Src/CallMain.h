/*
 * CallMain.h
 *
 *  Created on: Oct 3, 2020
 *      Author: DELL
 */

#ifndef CALLMAIN_H_
#define CALLMAIN_H_
#include "Define.h"
#include "StepMotor.h"

void SetM1Pin(StepMotor* M1, uint8_t ahead);
void SetM2Pin(StepMotor* M2, uint8_t ahead);

#endif /* CALLMAIN_H_ */
