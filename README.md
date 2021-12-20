# Lights Out

This project was created for ECE 198 in 1A Electrical/Computer Engineering at the University of Waterloo. 

## ***Description:*** 
This project uses an STM32 Nucleo microcontroller, 5 LEDs, 5 pushbuttons, a 7-segment LCD, jumper wires, and a breadboard. The puzzle has both user input and output display through the LEDs. This project corresponds with the theme of 'escape rooms'.

## ***How to Play:***
The final goal - Turn off all the LEDs
  1. Initially all the 5 LEDs will be switched on. 
  2. Start by pushing a button to turn an LED off, however you will notice that the two adjacent LEDs will also switch states (first on, now off, or vice versa).
  3. Keep toggling with the LEDs until all are switched off. 
  4. You will know you have won, once all the LEDs are switched off and a celebratory pattern begins to show up. 
  5. The attached 7-segment LCD will display the passcode in order to move further through the escape room.

## ***Acknowledgements:***
The team would like to thank instructors Bernie Roehl and Rodolfo Pellizzoni for their insights and provision of the microcontroller source files (ece198.h/ece198.c).
