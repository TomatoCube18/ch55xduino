/* 
 *  Ex_07 - CH552_USB_Dongle-07-Fancy_NightLight
 *  Simple Night Light Code based on a software flow diagram.
 *  Threshold Point could be configured/set in the firmware
 *  
 */

#include "TomatoCubeWorker_v6.h"

#define NUM_LEDS 4                // The number of Neopixel on the Neopixel strip
#define COLOR_PER_LEDS 3          // 3 Primary Color - Red, Green, Blue
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)

#define LDRThreshold 200          // The threshold preset for the LDR input
#define LDRBuffer 20              // The Buffer to prevent flickering of the Night Light

// Array Variable to hold NeoPixels Data
__xdata uint8_t ledData[NUM_BYTES] = {0,0,0,0,0,0,0,0,0,0,0,0};

uint8_t sensorLDRValue = 0;  // variable to store the value coming from the sensor
uint8_t lightStatus = LOW;

void setStripColor(uint8_t red, uint8_t green, uint8_t blue) {
    // Loops for Clearing out all Pixel on the Neopixel Strip
    for (uint8_t i = 0; i < NUM_LEDS; i++) 
    {
        set_pixel_for_GRB_LED(ledData, i, red, green, blue);
    }
    neopixel_show_P1_6(ledData, NUM_BYTES);  
}

void setup() {
    initTomatoCube();
    setStripColor(0, 0, 0);
}

// the loop function runs over and over again forever
void loop() {
  
    // If ambient light is not detected, day time -> roughly 100 - 245. (255 max)
    sensorLDRValue = analogRead(LDR_PINOUT);  
  
    if (lightStatus == HIGH) {
        if (sensorLDRValue >= LDRThreshold + LDRBuffer) {
            lightStatus = LOW;
        }
      
    } else {
        if (sensorLDRValue < LDRThreshold) {
            lightStatus = HIGH;
        }
    }
  
    if (lightStatus == HIGH) {
        setStripColor(128, 128, 128);
    } else {
        setStripColor(0, 0, 0);
    }
    
    delay(500);
  
}
