/* 
 *  Ex_03 - CH552_USB_Dongle-03-CapTouch
 *  Sample touch input on P1.1 as B1 (Button1)
 *  
 *  Challenge: Pin P1.4 is Touch Capable and is reg. as B2 (Button2) 
 */

#include "TomatoCubeWorker_v6.h"

void setup() {
  initTomatoCube(); // Convenient Function to initiate Pins on the CH552
  digitalWrite(LED_BUILTIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  scanTouchButton();
  
  if (getTouchB1State()) {
      digitalWrite(LED_BUILTIN, HIGH);
  } else {
      digitalWrite(LED_BUILTIN, LOW);
  }
  
}
