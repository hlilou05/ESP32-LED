 // Libraries
#include <Adafruit_PWMServoDriver.h>

// Pin Definitions
#define RED_PIN 26
#define GREEN_PIN 25
#define BLUE_PIN 33

// Objects
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Function to set the color
void setColor(uint16_t r, uint16_t g, uint16_t b) {
  pwm.setPWM(RED_PIN, 0, r);
  pwm.setPWM(GREEN_PIN, 0, g);
  pwm.setPWM(BLUE_PIN, 0, b);
}

// Setup
void setup() {
  // Initialize PWM driver
  pwm.begin();
  pwm.setPWMFreq(1000); // Set PWM frequency to 1000 Hz
}

// Main loop
void loop() {
  int r, g, b;

  // Get input for each color channel (0-255)
  Serial.println("Enter Red (0-255): ");
  while (Serial.available() == 0) {}
  r = Serial.parseInt();

  Serial.println("Enter Green (0-255): ");
  while (Serial.available() == 0) {}
  g = Serial.parseInt();

  Serial.println("Enter Blue (0-255): ");
  while (Serial.available() == 0) {}
  b = Serial.parseInt();

  // Set the color
  setColor(r, g, b);
}
