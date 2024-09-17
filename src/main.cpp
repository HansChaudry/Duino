#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   // QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define i2c_Address 0x3c // initialize with the I2C addr 0x3C Typically eBay OLED's

const int buttonPin = 2; 
int buttonState = 0;

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  display.begin(i2c_Address);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println("Hello Duino on Mac");
  display.display();
  
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Print button state to Serial Monitor for debugging
  Serial.print("Button state: ");
  Serial.println(buttonState);

  display.clearDisplay(); // Clear display
  display.setCursor(0, 0); // Set cursor to top-left corner

  if (buttonState == HIGH) { // Button pressed (assuming pull-up configuration)
    display.print("Button pressed");
  } else {
    display.print("Press btn");
  }
  
  display.display(); // Update the display
  delay(50); // Short delay to reduce flickering and CPU usage
}
