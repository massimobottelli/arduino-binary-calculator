// Control switches and leds

const int switchPins[] = {19, 18, 17, 16, 2, 3, 4, 5};
const int ledPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
const int buttonPin = 14;
const int numSwitches = sizeof(switchPins) / sizeof(int); 
const int txPin = 1;  

int switchStates[numSwitches];
int buttonState = 0;
double result;

void setup() {
  
  for (int i = 0; i < numSwitches; i++) {
    pinMode(switchPins[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPin, INPUT);
    pinMode(txPin, OUTPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  // Read the state of the switches
  for (int i = 0; i < numSwitches; i++) {
    switchStates[i] = digitalRead(switchPins[i]);
        
    // Toggle the LED based on the switch state
    if (switchStates[i] == HIGH) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {

    // Calculate the result
    result = 0;
    for (int i = 0; i < numSwitches; i++) {
      result += switchStates[i] * pow(2, i);
    }
    
    int myByte = round(result);
    Serial.println(myByte);


    // Add a delay to avoid rapid serial prints
    delay(100);
  }
}
