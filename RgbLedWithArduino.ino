// Define the RGB pin connections to Arduino
const int redPin = 9;      // Pin connected to the red leg of the RGB LED
const int greenPin = 10;   // Pin connected to the green leg of the RGB LED
const int bluePin = 11;    // Pin connected to the blue leg of the RGB LED

void setup() {
  // Set all RGB pins as output so Arduino can control the LED
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start serial communication at 9600 baud
  Serial.begin(9600);

  // Optional: Display a startup message in Serial Monitor
  Serial.println("Enter RGB values (0-255) separated by spaces:");
}

void loop() {
  // Check if there are at least 3 numbers available to read (R, G, B)
  if (Serial.available() >= 3) {
    // Read the red, green, and blue values (each should be between 0-255)
    int r = Serial.parseInt();  // Read red component
    int g = Serial.parseInt();  // Read green component
    int b = Serial.parseInt();  // Read blue component

    // Set the RGB LED color
    setColor(r, g, b);

    // Optional: Print the received values for confirmation
    Serial.print("Set Color - R: ");
    Serial.print(r);
    Serial.print(" G: ");
    Serial.print(g);
    Serial.print(" B: ");
    Serial.println(b);
  }
}

// Function to apply the specified color to the RGB LED
// Inputs are red, green, and blue brightness values (0 to 255)

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);      // Set brightness for red
  analogWrite(greenPin, green);  // Set brightness for green
  analogWrite(bluePin, blue);    // Set brightness for blue
}