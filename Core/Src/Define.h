/*
 * Define.h
 *
 *  Created on: Oct 1, 2020
 *      Author: DELL
 */

#ifndef SRC_DEFINE_H_
#define SRC_DEFINE_H_
#include "main.h"

//----------General Define---------
#define BACK 0
#define AHEAD 1
#define NUM_OF_MOTOR 2

//----------Define for motor 1---------
#define M1DirPort	GPIOD
#define M1DirPin	GPIO_PIN_11
#define M1StepPort 	GPIOD
#define M1StepPin	GPIO_PIN_12
#define M1EnPort	GPIOD
#define M1EnPin		GPIO_PIN_9

#define M1MS1Port	GPIOB
#define M1MS1Pin	GPIO_PIN_15
#define M1MS2Port	GPIOB
#define M1MS2Pin	GPIO_PIN_13
#define M1MS3Port	GPIOD
#define M1MS3Pin	GPIO_PIN_15

//----------Define for motor 2---------
#define M2DirPort	GPIOD
#define M2DirPin	GPIO_PIN_10
#define M2StepPort	GPIOD
#define M2StepPin	GPIO_PIN_12
#define M2EnPort	GPIOD
#define M2EnPin		GPIO_PIN_14

#define M2MS1Port	GPIOB
#define M2MS1Pin	GPIO_PIN_12
#define M2MS2Port	GPIOB
#define M2MS2Pin	GPIO_PIN_14
#define M2MS3Port	GPIOD
#define M2MS3Pin	GPIO_PIN_8

//---------Typedef for motor---------
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
	uint32_t Steps;//remain Step, positive to go ahead, negative to go back
	uint8_t Num;
} StepMotor;


#endif /* SRC_DEFINE_H_ */
