#include <msp430.h>
#include "Tanner's MSP Lib/setup/setup.h"
#include "Tanner's MSP Lib/led/led.h"

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    Setup_Init();                       // Turn off any high impedance GPIOs
    Led1_Init();                        // Set Led1 direction
    Led2_Init();                        // Set Led2 direction

                                        // Stagger Leds initially
    Led1_On();                          // Turn on LED1
    Led2_Off();                         // Turn off LED2

    unsigned int counter = 0;           // Initialize counter variable for different blinking rates
    int delay1 = 1000;                  // Rate at which LED1 will toggle
    int delay2 = 2500;                  // Rate at which LED2 will toggle

    while(1){
        counter++;                      // Increment counter at the beginning of every while loop
        if((counter % delay1) == 0){
            Led1_Toggle();              // Toggle led1 in increments of delay1
        }
        if((counter % delay2) == 0){    // Toggle in increments of delay2
            Led2_Toggle();
        }
    }
}
