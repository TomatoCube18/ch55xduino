/* 
 *  Ex_01 - CH552_USB_Dongle-01-DigitalOut
 *  Simple blinking of LED
 *  
 */

#include "TomatoCubeWorker_v6.h"
#define LED_BUILTIN 17 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait 250 milliseconds.
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait 500 milliseconds.
}
