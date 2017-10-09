# Simple Blink
The purpose of this excercise is to dive into the world of embedded systems by blinking an LED. It is a trivial task that will be used for future labs and excercises.

## How Does The Code Work
Using the MSP430 library I created, it was easy to implement all five required processors into one main.c file. The main method disables the watchdog timer, initializes the processors setup and both LEDs (This is all done through the Library). LED1 is turned on and LED2 is turned off to stagger their initial states and then an infinite while loop runs which toggles LED1, toggles LED2 and then delays. This creates a 50% duty cycle for both LED1 and LED2. The LEDs will blink one after the other until the program is stopped.

## Important Things to Note
* For a few of the processors, the register PM5CTL0 had to have the LOCKLPM5 bit turned off. This is because some processors are initialized to have this bit turned on which turns GPIOs to high-impedance. Clearing this bit allows GPIO pins to be used normally. Setup_Init() takes care of this for all processors.
* LEDs are enabled by setting the bit direction to 1. Toggling uses an XOR operator, turning on uses an OR operator and turning off uses an AND operator.
* Innacurate delay is used instead of timer.