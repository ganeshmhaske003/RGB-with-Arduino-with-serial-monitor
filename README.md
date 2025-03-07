# RGB-with-Arduino-with-serial-monitor
basic RBG led with arduino with serial monitoring colour changing 

# Componets Required 
-Arduino Uno 
-Breadboard
-RGB LED
-jumper wire
-resistor

## Code
'''CPP

// Define pin numbers for the RGB LED
const int redPin = 9;      // Pin connected to the red LED leg
const int greenPin = 10;   // Pin connected to the green LED leg
const int bluePin = 11;    // Pin connected to the blue LED leg

void setup() {
  // Set RGB pins as output so the Arduino can control them
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Check if there are at least 3 values available in the Serial buffer
  if (Serial.available() >= 3) {
    // Read 3 integer values (R, G, B) from Serial input
    int r = Serial.parseInt();  // Read red value
    int g = Serial.parseInt();  // Read green value
    int b = Serial.parseInt();  // Read blue value

    // Call setColor() to apply the color to the RGB LED
    setColor(r, g, b);
  }
}

// Function to set the color of the RGB LED using PWM
// Accepts 3 values: red, green, blue (each from 0 to 255)
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);      // Set red LED brightness
  analogWrite(greenPin, green);  // Set green LED brightness
  analogWrite(bluePin, blue);    // Set blue LED brightness
}
