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
    Button1_Init(pull_up);              // Initialize Button1

                                        // Stagger Leds initially
    Led1_On();                          // Turn on LED1
    Led2_Off();                         // Turn off LED2

    unsigned int i = 0;                 // Create index for loop

    int prev_on = 0;                    // Variable which remembers the previous state of button1

    while (1){

        int button_pressed = Button1_Read(); // Store the state of button 1

        if(button_pressed){                  // If button is pressed
            if(prev_on == 0){                // And button was previously off
                Led1_Toggle();               // Toggle Led1 and Led2
                Led2_Toggle();
                prev_on = 1;
            }
        }
        else{
            prev_on = 0;
        }

        for(i = 0; i < 1000; i ++);

    }
}
