#include <msp430.h>
#include "Tanner's MSP Lib/setup/setup.h"
#include "Tanner's MSP Lib/led/led.h"
#include "Tanner's MSP Lib/button/button.h"

const int pull_up = 1;

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

    unsigned int i = 0;                 // Create index for loop

    while(1)
    {
        toggle_led1();                  // Toggle Led1
        for(i = 0; i < 10000; i++);     // Delay
        toggle_led2();                  // Toggle Led2
        for(i = 0; i < 10000; i++);     // Delay
    }
}
