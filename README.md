# Traffic Light System
## Description
This project utilizes the STM32F103RB microcontroller to simulate a two-way traffic light system. The setup includes 8 seven-segment displays (2 for each direction), 4 buttons ( 1 to switching mode of system, 2 dedicated to adjusting the timer(1 increase, 1 descrease) and 1 for pedestrian), and 12 LEDs (4 red, 4 yellow, and 4 green) to represent the traffic signals. having some main features:
  - Automatic mode: The system operates as normal. The  light colors are red, yellow, and green.
  - Manual mode: A button is used to switch the light colors in this mode (red -> yellow -> green -> auto mode and repeat if the button1 is pressed)
  - Tuning mode: This mode is used to modify the light timing length (presse button 2 to increase time and button 3 to descrease time).
  - Pedestrian scramble: when the button 4, which is used for pedestrian, is pressed. Its light is turned on and operates reversely to the light of vehicles

## Block diagram:

![image](https://user-images.githubusercontent.com/96888431/237023066-bda3c064-791b-4fa6-9399-18f92e2e90e4.png)
