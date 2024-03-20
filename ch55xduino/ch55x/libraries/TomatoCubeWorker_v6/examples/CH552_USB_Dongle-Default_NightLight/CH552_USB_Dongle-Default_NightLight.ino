/* 
 *  Ex_09 - CH552_USB_Dongle-Default_NightLight
 *  Fully functional NightLight with IR & Touch functions
 *  
 */

#include "TomatoCubeWorker_v6.h"

#define NUM_LEDS 4                // The number of Neopixel on the Neopixel strip
#define COLOR_PER_LEDS 3          // 3 Primary Color - Red, Green, Blue
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)

#define LDRThreshold 150          // The threshold preset for the LDR input
#define LDRBuffer 40              // The Buffer to prevent flickering of the Night Light

// Array Variable to hold NeoPixels Data
__xdata uint8_t ledData[NUM_BYTES] = {0,0,0,0,0,0,0,0,0,0,0,0};

uint8_t currentMode = 0;  // 0 - Manual Mode, 1 - Timer Mode, 2 - NightLight Mode

uint8_t sensorLDRValue = 0;  // variable to store the value coming from the sensor
uint8_t nightLightStatus = LOW;

unsigned long timerEndTime = 0; // Store Seconds
uint8_t timerLightStatus = LOW;

#define neopixelTotalLevel 2   // The total number of brightness level adjustment when using IR remote control
uint8_t neopixelLevel = 0;  // 0 - Off, 1..neopixelTotalLevel

uint8_t irCommand = 0; uint8_t lastIRCommand = 0;

uint8_t isRandomColor; uint8_t red; uint8_t green; uint8_t blue; 

// White light Preset
#define WHITE_Red    110
#define WHITE_Green 80
#define WHITE_Blue  90               
                
// Warm light Preset
#define WARM_Red    150
#define WARM_Green  80
#define WARM_Blue   10


void setStripColor(uint8_t randomColor, uint8_t red, uint8_t green, uint8_t blue) {
    // Loops for Clearing out all Pixel on the Neopixel Strip
    for (uint8_t i = 0; i < NUM_LEDS; i++) 
    {
        if (randomColor) {
            set_pixel_for_GRB_LED(ledData, i, rand() % 255, rand() % 255, rand() % 255);
        } else {
          set_pixel_for_GRB_LED(ledData, i, red, green, blue);
        }
    }
    neopixel_show_P1_6(ledData, NUM_BYTES);  
}

void setup() {
    initTomatoCube();
    digitalWrite(LED_BUILTIN, LOW);
    // Preset Color to Warm White
    red = WARM_Red; green = WARM_Green; blue  = WARM_Green;
    isRandomColor = false;
    setStripColor(isRandomColor, 0, 0, 0);

    setHWSync(false);  //Note: Enable Hardware PWM Sync for greater Sound accuracy
                       //      Limit to NOTE_FS4 -> NOTE_D8 (355 Hz to 90 Khz)                        
    // Play Ready Tone
    playTone(TONE_PINOUT, NOTE_D5, 50) ;
    playTone(TONE_PINOUT, REST, 20) ;
    playTone(TONE_PINOUT, NOTE_F5, 50) ;
    playTone(TONE_PINOUT, REST, 10) ;
    delay(5);     
    
}

// the loop function runs over and over again forever
void loop() {
    // Touch Detection Code
    scanTouchButton();
    // getTouchB1Transition() -> 0 - no change, 1, onPress, -1, onRelease
    if (getTouchB1Transition() == 1) {
        currentMode = 0;
        isRandomColor = false;
        
        if (neopixelLevel == 0) {
            neopixelLevel = 1;
            red = WHITE_Red; green = WHITE_Green; blue  = WHITE_Blue;
        } else if ((red == WHITE_Red) && (green == WHITE_Green) && (blue == WHITE_Blue)) {
            neopixelLevel = 1;
            red = WARM_Red; green = WARM_Green; blue  = WARM_Blue;
        } else if ((red == WARM_Red) && (green == WARM_Green) && (blue == WARM_Blue)) {
            neopixelLevel = 0;
        } else {
            neopixelLevel = 1;
            red = WHITE_Red; green = WHITE_Green; blue  = WHITE_Blue;
        }
    }
    // End of Touch Detection Code


    // Light Detection Code
    
    // If ambient light is not detected, day time -> roughly 100 - 245. (255 max)
    sensorLDRValue = analogRead(LDR_PINOUT);  
  
    if (nightLightStatus == HIGH) {
        if (sensorLDRValue >= LDRThreshold + LDRBuffer) {
            nightLightStatus = LOW;
        }
      
    } else {
        if (sensorLDRValue < LDRThreshold) {
            nightLightStatus = HIGH;
        }
    }
    // End of Light Detection Code
    

    // Timer Countdown Code
    
    if (timerLightStatus == HIGH) {
        if ((millis()/1000) >= timerEndTime) {
            timerLightStatus = LOW;
            currentMode = 0;      // Timer Elapse: Change to Manual Mode & Switch Off LED
            neopixelLevel = 0;
        }
    }

    // End of Timer Countdown Code
  
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
    // IR Detection Code
    
    if(isIR_Received()) {          // If a good NEC message is received
        if (getIRAddress() == 0x01FE) {   // Switch Case for TomatoCube 18 Buttons IR  
                  
            playTone(TONE_PINOUT, NOTE_A5, 50) ;
            playTone(TONE_PINOUT, REST, 20) ;                                   
                         
            irCommand = getIRCommand();
            switch (irCommand) {
                case 0x48: // < ON >     
                    currentMode = 0;   
                    neopixelLevel = 1;
                    break;
                    
                case 0x58: // < OFF >    
                    currentMode = 0;   
                    neopixelLevel = 0;      
                    break;   
                    
                case 0x78: // < Mode >   
                    if (currentMode == 2) {   // If Night Light Mode, Change to Manual Mode
                        currentMode = 0;
                    } else {                  // Else if Manual/Timer Mode, Change to Night Light Mode
                        currentMode = 2;
                    }
                    break; 
                     
                case 0x80: // < 4H >
                    currentMode = 1;  // Timer Mode
                    timerEndTime = (millis()/1000) + (4 * 60 * 60);   // setting timer to 4 hours
//                    timerEndTime = (millis()/1000) + (4 * 5);   // Test: setting timer to 20 Seconds
                    timerLightStatus = HIGH;
                    playTone(TONE_PINOUT, NOTE_C5, 50);
                    playTone(TONE_PINOUT, REST, 20); 
                    break;  
                      
                case 0x40: // < 8H > 
                    currentMode = 1;  // Timer Mode
                    timerEndTime = (millis()/1000) + (8 * 60 * 60);   // setting timer to 8 hours
                    timerLightStatus = HIGH;
                    playTone(TONE_PINOUT, NOTE_C5, 50);
                    playTone(TONE_PINOUT, REST, 20); 
                    break; 
                    
                case 0xC0: // < Multi Color >   
                    isRandomColor = true;
                    currentMode = 0;  
                    break; 

                case 0x20: // < Red > 
                    currentMode = 0;   // #define neopixelTotalLevel 2
                    neopixelLevel = (lastIRCommand == 0x20) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;  
                    isRandomColor = false;
                    red   = 255 * neopixelLevel / neopixelTotalLevel;
                    green = 0 * neopixelLevel / neopixelTotalLevel;
                    blue  = 0 * neopixelLevel / neopixelTotalLevel;    
                    break;

                case 0xA0: // < Green >                    
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0xA0) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 0 * neopixelLevel / neopixelTotalLevel;
                    green = 255 * neopixelLevel / neopixelTotalLevel;
                    blue  = 0 * neopixelLevel / neopixelTotalLevel;    
                    break;
                                    
                case 0x60: // < Indigo >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0x60) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 20 * neopixelLevel / neopixelTotalLevel;
                    green = 0 * neopixelLevel / neopixelTotalLevel;
                    blue  = 255 * neopixelLevel / neopixelTotalLevel;  
                    break;
                                    
                case 0xE0: // < White >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0xE0) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 110 * neopixelLevel / neopixelTotalLevel;
                    green = 80 * neopixelLevel / neopixelTotalLevel;
                    blue  = 90 * neopixelLevel / neopixelTotalLevel;    
                    break;
                                    
                case 0x10: // < Light Green >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0x10) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 100 * neopixelLevel / neopixelTotalLevel;
                    green = 255 * neopixelLevel / neopixelTotalLevel;
                    blue  = 20 * neopixelLevel / neopixelTotalLevel;    
                    break;
                                    
                case 0x90: // < Light Blue >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0x90) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 0 * neopixelLevel / neopixelTotalLevel;
                    green = 100 * neopixelLevel / neopixelTotalLevel;
                    blue  = 255 * neopixelLevel / neopixelTotalLevel;    
                    break;
                                    
                case 0x50: // < Yellow >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0x50) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 200 * neopixelLevel / neopixelTotalLevel;
                    green = 130 * neopixelLevel / neopixelTotalLevel;
                    blue  = 0 * neopixelLevel / neopixelTotalLevel;    
                    break;
                                    
                case 0xD8: // < Turqoise >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0xD8) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 0 * neopixelLevel / neopixelTotalLevel;
                    green = 230 * neopixelLevel / neopixelTotalLevel;
                    blue  = 200 * neopixelLevel / neopixelTotalLevel;    
                    break;
                                    
                case 0xF8: // < Pink >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0xF8) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 255 * neopixelLevel / neopixelTotalLevel;
                    green = 0 * neopixelLevel / neopixelTotalLevel;
                    blue  = 100 * neopixelLevel / neopixelTotalLevel;   
                    break;
                                    
                case 0x30: // < Baby Pink >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0x30) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 120 * neopixelLevel / neopixelTotalLevel;
                    green = 50 * neopixelLevel / neopixelTotalLevel;
                    blue  = 80 * neopixelLevel / neopixelTotalLevel;   
                    break;

                case 0xB0: // < Blue >                    
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0xB0) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 0 * neopixelLevel / neopixelTotalLevel;
                    green = 0 * neopixelLevel / neopixelTotalLevel;
                    blue  = 255 * neopixelLevel / neopixelTotalLevel;  
                    break;
                                    
                case 0x70: // < Purple >
                    currentMode = 0;   
                    neopixelLevel = (lastIRCommand == 0x70) ? (neopixelLevel < neopixelTotalLevel) ? neopixelLevel + 1 : 1  : 1;                    
                    isRandomColor = false;
                    red   = 80 * neopixelLevel / neopixelTotalLevel;
                    green = 0 * neopixelLevel / neopixelTotalLevel;
                    blue  = 255 * neopixelLevel / neopixelTotalLevel;  
                    break;
                
                default:
                    break;
            }
            lastIRCommand = irCommand;
        }
    }


    // OnBoard LED Control Code
    if (currentMode == 2) {             // Night Light Mode - Solid LED
        digitalWrite(LED_BUILTIN, HIGH);
    } else if (currentMode == 1) {      // Timer Mode - Flashing LED
        digitalWrite(LED_BUILTIN, (millis()/500)%2 ? HIGH: LOW);
    } else {
        digitalWrite(LED_BUILTIN, LOW); // Manual Mode - Switch Off LED
    }
    // End of OnBoard LED Control Code


    // Neopixel LED Control Code
    if (currentMode == 2) {             // Night Light Mode
        if (nightLightStatus == HIGH) {
            setStripColor(false,  red, green, blue);
        } else {
            setStripColor(false,  0, 0, 0);
        }
    } else if (currentMode == 1) {      // Timer Mode
        if (timerLightStatus == HIGH) {
            setStripColor(false,  red, green, blue);
        } else {
            setStripColor(false,  0, 0, 0);
        }
    } else {                            // Manual Mode
        if (neopixelLevel == 0) { // Off Button is Pressed
            setStripColor(false,  0, 0, 0);
        } else {
            setStripColor(isRandomColor,  red, green, blue);
        }
    }
    // End of Neopixel LED Control Code
    
    delay(50);
}
