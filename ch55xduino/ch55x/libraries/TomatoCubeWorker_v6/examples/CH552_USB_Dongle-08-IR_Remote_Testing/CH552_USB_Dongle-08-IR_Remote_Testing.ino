/* 
 *  Ex_08 - CH552_USB_Dongle-08-IR_Remote_Testing
 *  A remotely controlled Color LED Controller.
 *  
 */

#include "TomatoCubeWorker_v6.h"

#define NUM_LEDS 4                // The number of Neopixel on the Neopixel strip
#define COLOR_PER_LEDS 3          // 3 Primary Color - Red, Green, Blue
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)


// Array Variable to hold NeoPixels Data
__xdata uint8_t ledData[NUM_BYTES] = {0,0,0,0,0,0,0,0,0,0,0,0};

uint8_t irCommand = 0;
uint8_t red; uint8_t green; uint8_t blue;

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
    setStripColor(red, green, blue);
}

// the loop function runs over and over again forever
void loop() {
/*    Code for IR (NEC infrared remote) 
 *  
 *     TomatoCube Multi-color 18 Buttons IR { Addr: 0x01FE }
 *     < ON >              Cmd: 0x48
 *     < OFF >             Cmd: 0x58
 *     < Mode >            Cmd: 0x78
 *     < 4H >              Cmd: 0x80
 *     < 8H >              Cmd: 0x40
 *     < Multi Color >     Cmd: 0xC0
 *     < Red >             Cmd: 0x20
 *     < Green >           Cmd: 0xA0
 *     < Indigo >          Cmd: 0x60
 *     < White >           Cmd: 0xE0
 *     < Light Green >     Cmd: 0x10
 *     < Light Blue >      Cmd: 0x90
 *     < Yellow >          Cmd: 0x50
 *     < Turqoise >        Cmd: 0xD8
 *     < Pink >            Cmd: 0xF8
 *     < Baby Pink >       Cmd: 0x30
 *     < Blue >            Cmd: 0xB0
 *     < Purple >          Cmd: 0x70
 */     

    if(isIR_Received()) {          // If a good NEC message is received
        if (getIRAddress() == 0x01FE) {   // Switch Case for TomatoCube 18 Buttons IR  
                  
            playTone(TONE_PINOUT, NOTE_A5, 50) ;
            playTone(TONE_PINOUT, REST, 20) ;                                   
                         
            irCommand = getIRCommand();
            switch (irCommand) {
                case 0x20: // < Red > 
                    red = 128; green = 0; blue = 0;
                break;
                case 0xA0: // < Green >     
                    red = 0; green = 128; blue = 0;
                break;
                case 0x60: // < Indigo >     
                    red = 20; green = 0; blue = 128;
                break;
                case 0xE0: // < White >     
                    red = 128; green = 128; blue = 128;
                break;
                case 0x10: // < Light Green >     
                    red = 80; green = 128; blue = 20;
                break;
                case 0x90: // < Light Blue >     
                    red = 0; green = 80; blue = 128;
                break;
                case 0x50: // < Yellow >
                    red   = 200; green = 130; blue  = 0;
                break;
                case 0xD8: // < Turqoise >
                    red   = 0; green = 230; blue  = 200;
                break;
                case 0xF8: // < Pink >
                    red   = 255; green = 0; blue  = 100;
                break;
                case 0x30: // < Baby Pink >
                    red   = 120; green = 50; blue  = 80;
                break;
                case 0xB0: // < Blue >                    
                    red   = 0; green = 0; blue  = 128;
                break;
                case 0x70: // < Purple >
                    red   = 80; green = 0; blue  = 255;
                break;
                
                default:
                    break;
            }
        }
    }

    setStripColor(red, green, blue);
    delay(50);
}
