/*
 * led.h
 *
 *  Created on: Sep 10, 2024
 *      Author: Gabriela
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include <stdint.h>
#include <main.h>

// LED states
#define LED_OFF 0
#define LED_ON 1
#define LED_BLINK 2

// Function prototypes
void LED_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void LED_SetState(uint8_t state);
void LED_Update(void);

#endif /* INC_LED_H_ */
