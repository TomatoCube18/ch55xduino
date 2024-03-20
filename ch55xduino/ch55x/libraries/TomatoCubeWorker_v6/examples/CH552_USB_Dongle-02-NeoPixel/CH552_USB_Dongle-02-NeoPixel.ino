/* 
 *  Ex_02 - CH552_USB_Dongle-02-NeoPixel
 *  Light up the individual Neopixels on the Strip
 *  
 */

#include "TomatoCubeWorker_v6.h"
#define RGB_PINOUT 16

#define NUM_LEDS 4                // The number of Neopixel on the Neopixel strip
#define COLOR_PER_LEDS 3          // 3 Primary Color - Red, Green, Blue
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)

// Array Variable to hold NeoPixels Data
__xdata uint8_t ledData[NUM_BYTES] = {0,0,0,0,0,0,0,0,0,0,0,0};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin RGB_PINOUT as an output.
  pinMode(RGB_PINOUT, OUTPUT); 
}

// the loop function runs over and over again forever
void loop() {
  // Exp: Neopixel_Function (Array, LED Number, Red Intensity, Green, Blue);
  set_pixel_for_GRB_LED(ledData, 0, 128, 0, 0);  // LED 1: Red
  set_pixel_for_GRB_LED(ledData, 1, 0, 128, 0);  // LED 2: Green
  set_pixel_for_GRB_LED(ledData, 2, 0, 0, 128);  // LED 3: Blue
  set_pixel_for_GRB_LED(ledData, 3, 128, 0x00, 128);  // LED 4: Color??
  neopixel_show_P1_6(ledData, NUM_BYTES);

  delay(50);
}
