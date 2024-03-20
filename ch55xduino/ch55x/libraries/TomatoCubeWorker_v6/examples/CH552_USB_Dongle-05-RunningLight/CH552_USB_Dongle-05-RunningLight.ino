/* 
 *  Ex_05 - CH552_USB_Dongle-05-RunningLight
 *  Running Touch Light combining Touch Sensing code with Neopixel Code
 *  
 *  Challenge: Pin P1.4 is Touch Capable and is reg. as B2 (Button2) 
 */

#include "TomatoCubeWorker_v6.h"
#include <math.h>

#define NUM_LEDS 4                // The number of Neopixel on the Neopixel strip
#define COLOR_PER_LEDS 3          // 3 Primary Color - Red, Green, Blue
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)

// Array Variable to hold NeoPixels Data
__xdata uint8_t ledData[NUM_BYTES] = {0,0,0,0,0,0,0,0,0,0,0,0};

// Variable to fold which LED to turn On
int ledOnPixel = 0;

// Helper function to manage the Neopixel
void turnOnPixel(int pixelNumber) {
  // Loops for Clearing out all Pixel on the Neopixel Strip
  for (uint8_t i = 0; i < NUM_LEDS; i++) 
  {
      set_pixel_for_GRB_LED(ledData, i, 0, 0, 0);
  }
  // Turning one Pixel on with a random Color
  set_pixel_for_GRB_LED(ledData, pixelNumber, rand() % 128, rand() % 128, rand() % 128);
  neopixel_show_P1_6(ledData, NUM_BYTES);  
}

void setup() {
  initTomatoCube(); // Convenient Function to initiate Pins on the CH552
  turnOnPixel(ledOnPixel);
}

// the loop function runs over and over again forever
void loop() {
  scanTouchButton();
  
  if (getTouchB1Transition() == 1) {
      ledOnPixel++;
      if (ledOnPixel >= NUM_LEDS) {   
          ledOnPixel = 0;
      }

      turnOnPixel(ledOnPixel);
  }
}
