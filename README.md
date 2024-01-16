# Arduino Binary Calculator

The project implements an interactive binary calculator using Arduino.

This Arduino project implements a binary calculator where users can input an 8-bit number (ranging from 0 to 255) using switches that represent the individual bits. LEDs corresponding to the activated bits light up, and upon pressing a button, the system calculates the decimal equivalent. The result is then sent to another Arduino board, which displays it on a 4-digit display.

![Arduino schema](/doc/arduino-binary-calculator-featured.png)

See the [**Online simulation**](https://www.tinkercad.com/things/9uvCxPcXsQm-binary-digital-calculator?sharecode=IfuyTUP8s-cm-Dwd7OBbYEhUrjI_3NDLFUsgPBXSlCc) on Tinkercad

## Functionality

### 1st Script: Controller

The controller script handles the input from the switches, activates LEDs based on the selected bits, and calculates the decimal value when the button is pressed. The calculated result is sent to the display Arduino board.

#### Pin Configuration
- Switches: 19, 18, 17, 16, 2, 3, 4, 5
- LEDs: 6, 7, 8, 9, 10, 11, 12, 13
- Button: 14
- TX Pin: 1

#### Usage
1. Connect the switches and LEDs as per the specified pin configuration.
2. Input an 8-bit number by turning on the corresponding switches.
3. Press the button to calculate and send the decimal value to the display Arduino.

#### Code Explanation
The script reads the state of the switches, toggles LEDs based on switch states, and calculates the decimal value using the binary representation.

### 2nd Script: Display

The display script receives the calculated decimal value from the controller and showcases it on a 4-digit display.

#### Pin Configuration
- RX Pin: 0 (Connect to the TX pin of the sender Arduino)

#### Usage
1. Connect the RX pin to the TX pin of the sender Arduino.
2. The display Arduino will receive and showcase the calculated decimal value.

#### Code Explanation
The script listens for incoming data on the serial port, reads the integer value, and displays it on the 4-digit display.

## Future Enhancements

The project is planned to evolve, allowing users to input two numbers and perform calculations such as addition, subtraction, etc.

## Getting Started

1. Set up the hardware according to the provided pin configuration.
2. Upload the controller script to one Arduino board and the display script to another.
3. Power on the system and use the switches to input an 8-bit number.
4. Press the button to calculate and display the decimal value on the 4-digit display.

## Dependencies

- [Adafruit LEDBackpack Library](https://github.com/adafruit/Adafruit-LED-Backpack)

Ensure the Adafruit LEDBackpack library is installed for the display script.
