/*
 * led.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Gabriela
 */


#include "led.h"
#include "main.h"

static GPIO_TypeDef* LED_GPIOx;
static uint16_t LED_GPIO_Pin;
static uint8_t LED_State = LED_OFF;
static uint32_t LED_LastToggle = 0;
static const uint32_t LED_Blink= 125; // 4Hz (1000ms / 8 = 125ms for on/off cycle)

/**
 * @brief  Initializes the LED GPIO pin.
 * @params  GPIOx: Pointer to GPIO Port to which LED is connected
 *         GPIO_Pin: Pin number of the LED
 */
void LED_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    LED_GPIOx = GPIOx;
    LED_GPIO_Pin = GPIO_Pin;
    HAL_GPIO_WritePin(LED_GPIOx, LED_GPIO_Pin, GPIO_PIN_RESET);
}

/**
 * @brief  Sets the state of the LED.
 * @params State: Desired state of the LED (LED_OFF, LED_ON, or LED_BLINK)
 * @note   For LED_BLINK state, the actual blinking is handled in LED_Update function
 */
void LED_SetState(uint8_t state) {
    LED_State = state;
    if (state == LED_OFF) {
        HAL_GPIO_WritePin(LED_GPIOx, LED_GPIO_Pin, GPIO_PIN_RESET);
    } else if (state == LED_ON) {
        HAL_GPIO_WritePin(LED_GPIOx, LED_GPIO_Pin, GPIO_PIN_SET);
    }
    // For LED_BLINK, we'll handle it in the LED_Update function
}

/**
 * @brief  Updates the LED state, handling blinking if necessary.
 * @note   This function should be called regularly in the main loop to handle LED blinking
 */
void LED_Update(void) {
    if (LED_State == LED_BLINK) {
        uint32_t currentTime = HAL_GetTick();
        if (currentTime - LED_LastToggle >= LED_Blink) {
            HAL_GPIO_TogglePin(LED_GPIOx, LED_GPIO_Pin);
            LED_LastToggle = currentTime;
        }
    }
}
