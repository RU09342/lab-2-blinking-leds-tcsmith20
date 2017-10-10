# Off-Board Blink
The purpose of this excercise is to dive into the world of embedded systems by blinking an LED. It is a trivial task that will be used for future labs and excercises. This excerise will add an extra step to Simple Blink by taking the MSP430G2553 processor off the dev board and onto a bread board.

![alt text](https://github.com/RU09342/lab-2-blinking-leds-tcsmith20/blob/master/Off_Board%20Blink/Offboard%20Blink.gif)

## How Does The Code Work
The code is identical Simple Blink.

## Circuit
![alt text](https://github.com/RU09342/lab-2-blinking-leds-tcsmith20/blob/master/Off_Board%20Blink/Circuit.PNG)

## How Does The Circuit Work
The circuit consists of a bulk capacitor from power to ground which prevents sudden spikes or drops in voltage. A bypass capictor was also placed as close to the power pin as possible between power and ground. A reset circuit was used in order to reset the processor if necessary. The reset pin was connected to a resistor (connected to power) and a capacitor (connected to ground). This connects reset to power when the reset button is pressed. The resistor limits the drawn current and the capacitor creates a time constant so the processor has enough time to reset. Finally, the gate of a PMOS is connected to the processors GPIO pin to not draw too much current and an LED is placed in a high-side switch fashion. One PMOS was used for P1.0 and one for P1.6.

## Important Things to Note
* A lot of wasted time was spent figuring out why the circuit wasn't working. Eventually, the problem was solved by checking the datasheet of the PMOS. The PMOS found in the lab had a high voltage operating region where the 3.3V GPIO pins did not have any effect. A new PMOS was then found with a lower gate voltage.