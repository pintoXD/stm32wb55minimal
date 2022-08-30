/*
 * gpio_example.h
 *
 *  Created on: 29 de ago de 2022
 *      Author: firmware
 */

#ifndef GPIO_EXAMPLE_H_
#define GPIO_EXAMPLE_H_ //--> This ifdef prevents this header to be included more than once. It's a common C programming pattern.

#include <stdint.h>
#include "stm32wb55xx.h"

/* The board LED is attached to the GPIO B Pin 5 of the microcontroller, thus we first define here the pin.
 * The GPIO will be set up later.
*/
#define LED_PIN 0
#define OUTPUT_HIGH 1
#define OUTPUT_LOW  0





int gpio_init();

int main_led();





#endif /* GPIO_EXAMPLE_H_ */
