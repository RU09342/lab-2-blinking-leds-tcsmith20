#include <msp430.h>
#include "Tanner's MSP Lib/setup/setup.h"
#include "Tanner's MSP Lib/led/led.h"

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	        // Stop watchdog timer
	Setup_Init();                       // Turn off any high impedance GPIOs
	Led1_Init();                        // Set Led1 direction
	Led2_Init();                        // Set Led2 direction

	                                    // Stagger Leds initially
	Led1_On();                          // Turn on LED1
	Led2_Off();                         // Turn off LED2
	
	unsigned int i = 0;                 // Create index for loop

	while(1){
        Led1_Toggle();                  // Toggle LED1
        Led2_Toggle();                  // Toggle LED2
        for(i = 0; i < 10000; i++);     // Delay
    }
}
