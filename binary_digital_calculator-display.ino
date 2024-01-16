// Receive value and control display

#include "Adafruit_LEDBackpack.h"
Adafruit_7segment dis = Adafruit_7segment();

const int rxPin = 2; // Connect this pin to the TX pin of the sender
int receivedData;

void setup() {
  Serial.begin(9600);
  pinMode(rxPin, INPUT);

 dis.begin(0x70);
}

void loop() {
  // Check if data is available on Serial
  if (Serial.available() > 0) {
    // Read the integer value from Serial
    receivedData = Serial.parseInt();

    // Print the received data
    Serial.println(receivedData);

    // Show on 7-digit Display
    dis.println(receivedData);
    delay(10);
    dis.writeDisplay();
    }
}