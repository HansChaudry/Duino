/***************************************************
//Web: http://www.buydisplay.com
EastRising Technology Co.,LTD
Examples for ER-OLEDM013-1
Display is Hardward SPI 4-Wire SPI Interface 
Tested and worked with:
Works with Arduino 1.6.0 IDE  
Test OK : Arduino DUE,Arduino mega2560,Arduino UNO Board 
****************************************************/

/*
  == Hardware connection ==
    OLED   =>    Arduino
  *1. GND    ->    GND
  *2. VCC    ->    3.3V
  *3. CLK    ->    SCK
  *4. MOSI    ->    MOSI
  *5. RES    ->    8 
  *6. DC     ->    9
  *7. CS     ->    10
*/

#include <Arduino.h>
#include <SPI.h>
#include "er_oled.h"

uint8_t oled_buf[WIDTH * HEIGHT / 8];
const int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  er_oled_begin();
  er_oled_clear(oled_buf);
}

void loop() {
   buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    er_oled_clear(oled_buf);
    er_oled_string(20, HEIGHT/2, "Button Pressed!!!", 12, 1, oled_buf);
    er_oled_display(oled_buf);
  } else {
    er_oled_clear(oled_buf);
    er_oled_string(20, HEIGHT/2, "Press Button!!!", 12, 1, oled_buf);
    er_oled_display(oled_buf);
  }
}
