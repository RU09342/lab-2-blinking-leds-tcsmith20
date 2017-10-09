# Multiple Blink
The purpose of this excercise is to dive into the world of embedded systems by blinking an LED. It is a trivial task that will be used for future labs and excercises. This excerise will create two blinking LEDs at different rates.

## Code

## How Does The Code Work
Using the MSP430 library I created, it was easy to implement all five required processors into one main.c file. The main method disables the watchdog timer, initializes the processors setup and both LEDs (This is all done through the Library). LED1 is turned on and LED2 is turned off to stagger their initial states and then an infinite while loop runs which toggles LED1 and LED2 at different rates. Different rates are achieved by using the modulus operator. Whenever the counter is a multiple of a delay, the respective LED will toggle. Each LED is still blinking at 50% duty cycle but at different frequencies. The LEDs will blink until the program is stopped.

## Important Things to Note
* An unsigned integer is incremented an infinite number of times with a finite number of bits. This creates an overflow once counter reaches 65356 which does not save any bit after 16. Once the counter overflows, it starts again at 0 and continues until it overflows again.
* Innacurate delay is used instead of timer.