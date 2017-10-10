# Button Blink
The purpose of this excercise is to dive into the world of embedded systems by blinking an LED. It is a trivial task that will be used for future labs and excercises. This excerise will create a program where the LEDs toggle everytime a button is pressed.

![alt text](https://github.com/RU09342/lab-2-blinking-leds-tcsmith20/blob/master/Button%20Blink/Button%20Blink.gif)

## How Does The Code Work
Using the MSP430 library I created, it was easy to implement all five required processors into one main.c file. The main method disables the watchdog timer, initializes the processor's setup, button and LEDs (This is all done through the Library). LED1 is turned on and LED2 is turned off to stagger their initial states and then an infinite while loop runs which polls for when the button is pressed. Since the LEDs only need to toggle on the high-to-low edge, a local variable is used to remember the previous state of the button. If the button was previously not pressed and now it is pressed, the LEDs are toggled. Otherwise, do nothing. A for loop was added as a delay to counter debouncing.

## Important Things to Note
* My implementation uses a polling method to determine when the button is pressed. This has the processor always executing something which is inneficient for both time and power. An interrupt would be much better.
* My implementation uses a for loop to prevent button bouncing. This means the processor has to execute this for loop instead of executing other functions. A timer would be better to prevent debouncing. 