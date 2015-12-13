# RotaryPulseGenerator
The objective of this lab is to connect a rotary pulse generator to the microcontroller and to correctly determine the number of turns and direction of the turns that the Rotary pulse generator is being spun. We then will use this information to control the LCD and ensure that we took the input in correctly.

First, as always we had to initialize our ports. We needed to create interrupts so we initialized the lowest bit of the port P and the upper four bits of port J. The program works by waiting for one of the interrupts to be changed by the rotary pulse generator spinning. When the generator spins we use the following logic to determine the direction of the spin.

https://i.imgur.com/Zbj4xZw.png

The main function in this code is a loop that runs infinitely waiting for one of the interrupts to be called. One thing that does happen in the main function is the LCD function that prints the current value is called. The integer count is a global variable so that the interrupt functions can change its value, but it can also be used in the call in main. When the rotary is spun it will create a change in either its input A or B, depending on its current position and the direction of the spin. Both interrupts work the same way. If a change is detected in the register associated with that interrupt we check what the values of the input is and can then use that information to change the count variable appropriately. For example if the interrupt for A is called we check the value of A and B. If we see A=1 and B=0 then we know the previous value of both inputs was A=0 and B=0. Looking at the figure above we see that the only way for that to happen is if we changed from position number 1 to 2. After count is changed all that is left to do is reset the flag registers and wait for another interrupt call.
