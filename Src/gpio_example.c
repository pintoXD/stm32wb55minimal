/*
 * gpio_example.c
 *
 *  Created on: 29 de ago de 2022
 *      Author: firmware
 */

#include "gpio_example.h"


/* This function initializes the gpio peripheral according to the necessary configuration defined on the MCU's datasheet.
 *
 *
 * */
int gpio_init(){

	// Enabling the clock for the GPIO Port B peripheral. 
	// Without it, the IOs will not be able to work. 
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

	/*
	  It is necessary to configure some GPIO registers before use this
	  peripheral. For an output example there must be configurated the
	  GPIOB_MODER
	  GPIOB_
	
	*/
	// This statement do a reset in some bits from this register, 
	// without clearing another bits.
	// So, if the register has something like 110011000, with an statement like the below,
	// the new value will be 000011000. Only the two bits of the word are zeroed. 
	GPIOB->MODER &= ~(0x3 << (LED_PIN*2));


	//This line sets the bits to turn the current GPIOB pin to outuput mode.
	/*
		According to the Reference Manual the bits 10 and 11 of this register
		are reserved to configure the pin 5. As we need this pin set as output
		so the bit 10 must be set to 1. 
	*/

	GPIOB->MODER |= (0x1 << (LED_PIN*2));

	//According to the manual, if OUTPUT the ouput type register must be set too. 
	//The bit left shift is used to the set the corresponding pin bit.
	//Output push-pull output type chosen.
	GPIOB->OTYPER &= ~(0x1 << (LED_PIN));

	


}







int gpio_write(uint8_t GPIO_PIN, uint8_t PIN_STATE){

	GPIOB->ODR ^= (PIN_STATE << GPIO_PIN);
}



int main_led(){

	gpio_init();


	while(1){
		
		for (uint32_t i = 0; i < 100000; i++);
		gpio_write(LED_PIN, OUTPUT_HIGH);
		for (uint32_t i = 0; i < 100000; i++);
		gpio_write(LED_PIN, OUTPUT_HIGH);
	}


}



