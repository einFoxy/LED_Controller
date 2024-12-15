/*
To do:
-Start UI selection
-Animations - Collor
*/


#include <Arduino.h>
#include "LED_Controller.hpp"

#define height  160
#define with    128

//LEDS
#define RED_LED   0
#define GREEN_LED 1
#define BLUE_LED  2

#define RED_PIN   6
#define GREEN_PIN 5
#define BLUE_PIN  3

LED_Controller ledcontroller;

void setup(){
  Serial.begin(11520);
  ledcontroller.SetupLCD(RED_PIN, GREEN_PIN, BLUE_PIN);
  ledcontroller.customColorGUI();

}



void loop(){
  static unsigned char tnow;
  static unsigned char tnext;
  tnow = millis();
  if ((unsigned char)(tnow - tnext) >= 10)
  {
    tnext += 10;

    ledcontroller.checkButton();
    ledcontroller.UpdateLEDs();
  }
  
  
  
 
}
