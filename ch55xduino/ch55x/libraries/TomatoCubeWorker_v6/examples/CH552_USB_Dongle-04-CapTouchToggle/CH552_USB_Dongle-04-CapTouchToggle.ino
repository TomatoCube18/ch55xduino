/* 
 *  Ex_04 - CH552_USB_Dongle-04-CapTouchToggle
 *  Sample touch input on P1.1 as B1 (Button1)
 *  
 *  Challenge: Pin P1.4 is Touch Capable and is reg. as B2 (Button2) 
 */

#include "TomatoCubeWorker_v6.h"

// Variable to hold the current state of the LED.
int ledPixel = LOW;

void setup() {
  initTomatoCube(); // Convenient Function to initiate Pins on the CH552
  digitalWrite(LED_BUILTIN, ledPixel);
}

// the loop function runs over and over again forever
void loop() {
  scanTouchButton();
  // getTouchB1Transition() -> 0 = no change, 1 = onPress, -1 = onRelease
  if (getTouchB1Transition() == 1) {
      ledPixel = !ledPixel; // Toggle the LED State of the Variable
  }
  
  digitalWrite(LED_BUILTIN, ledPixel);  // Write the Variable to the LED
}
