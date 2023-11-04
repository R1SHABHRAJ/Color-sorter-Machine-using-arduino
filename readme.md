# Color Sorting Machine (CSM) Arduino Project

Author: Rishabh Raj

Welcome to the GitHub repository for the Color Sorting Machine (CSM) Arduino project. This project demonstrates how to build a simple color sorting machine using Arduino. The machine can detect and sort objects based on their color, specifically red, blue, and green.

## Table of Contents

1. [Introduction](#introduction)
2. [Hardware Requirements](#hardware-requirements)
3. [Software Requirements](#software-requirements)
4. [Setup](#setup)
5. [How it Works](#how-it-works)
6. [Custom Function: readColor()](#custom-function-readcolor)


## Introduction

The Color Sorting Machine (CSM) project utilizes a combination of components, including TCS230 TCS3200 color sensors, servos, and an Arduino board, to detect and sort objects by their color. In this project, we can sort objects into three categories: red, blue, and green. The code provided here controls the servos, sensors, and LCD display to achieve this color sorting process.

## Hardware Requirements

To build the Color Sorting Machine, you will need the following hardware components:

- Arduino board
- Two Servo motors
- TCS3200 color sensor
- I2C LCD display
- Jumper wires
- Power supply

## Software Requirements

This project uses the Arduino IDE for programming the Arduino board. You can download the Arduino IDE [here](https://www.arduino.cc/en/software).

## Setup

1. **Wire Connections**: Connect the hardware components according to the schematic for the Color Sorting Machine.

2. **Upload the Code**: Open the Arduino IDE, connect your Arduino board, and upload the provided code to the board.

3. **Calibration**: To sort objects by color, you need to calibrate the sensor for the specific colors you want to detect. Adjust the frequency ranges in the `readColor()` function for each color you want to sort.

4. **Run the Machine**: Power up the machine and place objects in front of the color sensor. The machine will detect and sort the objects based on their colors.

Color Sensor Connections

SO----------------------->D2

S1----------------------->D3

S2----------------------->D4

S3----------------------->D5

OUT---------------------->D6

VCC---------------------->5V

GND--------------------->GND

Servo Coonections

Connect TOP servo signal wire at D7 pin of arduino

Connect Bottom servo signal wire at D8 pin of arduino

VCC---------------------->5V

GND--------------------->GND

LCD Connections

SCL---------------------->A5

SDA---------------------->A4

VCC---------------------->5V

GND--------------------->GND

## How it Works

The Color Sorting Machine works by using the TCS3200 color sensor to measure the frequency of reflected light from the object placed in front of it. The frequency corresponds to the color of the object, and the machine then sorts the object into the appropriate category based on the detected color.

The project also includes a simple user interface with an LCD display that provides information about the sorting process.

## Custom Function: readColor()

The `readColor()` function is a custom function that reads the color of an object based on the frequency of reflected light. This function is called in the `loop()` to detect the color of the object in front of the sensor. You can calibrate this function for different colors by adjusting the frequency ranges.

```arduino
// This is color section, you first have to calibrate for each color you have in your collection to be sorted out
// You have to take range for each color by first looking at its frequency you get from the color detector (serial monitor)
if (R > 55 && R < 90 && G > 150 && G < 210) {
    color = 1; // Red
}
if (G < 180 && G > 140 && B < 100 && B > 70) {
    color = 2; // Blue
}
if (R > 55 && R < 75 && G < 60 && G > 40) {
    color = 3; // Green
}
```

You can add more case statements for additional colors that you want to sort.

## Thank You