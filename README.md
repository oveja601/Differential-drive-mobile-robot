# Differential-Drive Mobile-robot
Differential-drive robot with DC motor control and embedded navigation.

## Overview
Designed and implemented a differential-drive wheeled robot controlled by two DC motors. The project focused on motor driving, forward motion control, left/right turning, and basic robot navigation logic.

The robot was programmed to navigate around a predefined rectangular field while maintaining stable movement and directional control. Through this project, I learned embedded system programming, DC motor control, and fundamental mobile robot navigation concepts.

## Demo

Click the image above to watch the demo video!
<p align="center">
  <a href="https://drive.google.com/file/d/1E_J3dIohsi-GpMVY-oG9z74lT1Zbexfk/view?usp=drive_link">
    <img src="images/demo.png" width="700">
  </a>
</p>

## Key Features
- DC motor control
- Differential-drive robot design
- Forward / left / right motion control
- Basic navigation logic
- Embedded system integration
## Hardware Used
- AVR ATmega328P Microcontroller
- H-Bridge Motor Driver Board
- Two-Wheel Robot Chassis
- DC Motors

## Hardware Setup
<p align="center">
<img width="486" height="728" alt="Image" src="https://github.com/user-attachments/assets/0b923282-6850-417f-b7c3-6c208d904e2f" />
</p>


## Source Code

Use Timer0 and Timer2 to generate the PWM signals. Connect OC0A and OC0B (PD6 and
PD5) to IN1 and IN2. These two output signals control a DC motor. 
Connect OC2A and OC2B (PB3 and PD3) to IN3 and IN4.These two output signals
control the other DC motor.
<p align="center">
<img width="562" height="240" alt="image" src="https://github.com/user-attachments/assets/77904524-ee3a-474d-bcfe-812558550793" />
</p>


## Technologies Used
- C++ / Arduino
- Embedded Programming
- Robot Navigation Logic
