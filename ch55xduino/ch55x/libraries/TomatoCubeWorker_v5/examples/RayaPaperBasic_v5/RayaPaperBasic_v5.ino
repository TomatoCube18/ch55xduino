#include "TomatoCubeWorker_v5.h"

//Raya Song 1 - Selamat Hari Raya
const PROGMEM char rayaSong1[] = {
  NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 2, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 2, NOTE_C5, 8, 
  NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_D6, 8, 
  NOTE_C6, 8, NOTE_AS5, 8, NOTE_A5, 2, REST, 2, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 2, NOTE_F5, 8, 
  NOTE_G5, 8, NOTE_A5, 8, NOTE_C6, 4, NOTE_AS5, 4 , NOTE_G5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, 
  NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 2, REST, 2, 
  NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_AS5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_C6, 8, 
  NOTE_D6, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_C6, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 4 , NOTE_E5, 8, 
  NOTE_D5, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_AS5, 8, 
  NOTE_A5, 8, NOTE_C6, 2, REST, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_AS5, 4, NOTE_G5, 8, NOTE_A5, 8, 
  NOTE_AS5, 8, NOTE_C6, 8, NOTE_D6, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_C6, 8, NOTE_A5, 8, NOTE_G5, 8, 
  NOTE_F5, 4, NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 8, 
  NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 2, REST, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 2, NOTE_F5, 8, 
  NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 2, NOTE_C5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_G5, 8, 
  NOTE_A5, 8, NOTE_AS5, 8, NOTE_D6, 8, NOTE_C6, 8, NOTE_AS5, 8, NOTE_A5, 2, REST, 2, NOTE_F5, 8, NOTE_G5, 8, 
  NOTE_A5, 2, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_C6, 4, NOTE_AS5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_AS5, 8, 
  NOTE_A5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 2
};

//Raya Song 2 - Suasana Hari Raya
const PROGMEM char rayaSong2[] = {
  NOTE_C6, 8, REST, 8, NOTE_G6, 8, NOTE_G6, 8, REST, 8, NOTE_G6, 8, REST, 8, NOTE_G6, 8, REST, 8, NOTE_A6, 8, 
  NOTE_F6, 8, NOTE_G6, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_D6, 8, NOTE_E6, 8, NOTE_C6, 8, REST, 8, NOTE_G6, 8, 
  NOTE_G6, 8, REST, 8, NOTE_G6, 8, REST, 8, NOTE_G6, 8, REST, 8, NOTE_A6, 8, NOTE_F6, 8, NOTE_G6, 8, NOTE_E6, 8, 
  NOTE_F6, 8, NOTE_D6, 8, NOTE_C6, 8, NOTE_D6, 8, REST, 8, NOTE_A6, 8, NOTE_A6, 8, REST, 8, NOTE_A6, 8, REST, 8, 
  NOTE_A6, 8, REST, 8, NOTE_B6, 8, NOTE_G6, 8, NOTE_A6, 8, NOTE_F6, 8, NOTE_G6, 8, NOTE_E6, 8, NOTE_D6, 8, 
  NOTE_C6, 4, REST, 8, NOTE_C6, 8, NOTE_C6, 8, REST, 8, NOTE_E6, 4 , NOTE_E6, 4, NOTE_F6, 8, NOTE_G6, 8, NOTE_E6, 8, 
  NOTE_F6, 8, NOTE_A6, 4, REST, 4, NOTE_A6, 64, NOTE_B6, 64, NOTE_A6, 4 , NOTE_G6, 4, NOTE_B6, 4, NOTE_C7, 4, 
  NOTE_D7, 8, REST, 16, NOTE_D7, 16, NOTE_B6, 4, NOTE_C7, 16, NOTE_D7, 16, NOTE_C7, 132, REST, 16,  NOTE_G6, 4, 
  NOTE_G6, 4, NOTE_A6, 4, NOTE_G6, 4, NOTE_F6, 8, NOTE_G6, 8, NOTE_F6, 8, NOTE_E6, 8, NOTE_D6, 2, 
  NOTE_B5, 4, NOTE_C6, 4, NOTE_D6, 4, NOTE_E6, 8, NOTE_F6, 16, NOTE_E6, 16, NOTE_F6, 4, NOTE_D6, 4, NOTE_E6, 4, 
  REST, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_F6, 8, REST, 8, NOTE_F6, 8, NOTE_G6, 2, NOTE_C6, 4, NOTE_C6, 4, NOTE_C6, 64, 
  NOTE_E6, 4, NOTE_E6, 4, NOTE_F6, 8, NOTE_G6, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_A6, 4, REST, 4, 
  NOTE_A6, 64, NOTE_B6, 64, NOTE_A6, 8, NOTE_A6, 8, NOTE_G6, 4 , NOTE_B6, 4, NOTE_C7, 4, NOTE_D7, 8, NOTE_D7, 8, 
  NOTE_B6, 4, NOTE_C7, 16, NOTE_D7, 16, NOTE_C7, 132, REST, 8, NOTE_G6, 8, NOTE_G6, 4, NOTE_A6, 4, NOTE_G6, 4, 
  NOTE_F6, 8, NOTE_G6, 8, NOTE_F6, 8, NOTE_E6, 8, NOTE_D6, 2, 
  NOTE_B5, 4, NOTE_C6, 4, NOTE_D6, 4, NOTE_E6, 8, NOTE_F6, 16, NOTE_E6, 16, NOTE_F6, 4, NOTE_D6, 4, NOTE_C6, 4, 
  REST, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_F6, 4, NOTE_F6, 8, NOTE_G6, 4, REST, 8, NOTE_G6, 8, REST, 8, NOTE_G6, 8, 
  NOTE_G6, 8, REST, 8, NOTE_A6, 4, NOTE_A6, 4, NOTE_B6, 8, NOTE_C7, 8, NOTE_A6, 8, NOTE_B6, 8, NOTE_C7, 4, 
  REST, 8, NOTE_C7, 8 , NOTE_C7, 4, NOTE_G6, 4, NOTE_A6, 4, NOTE_G6, 4, NOTE_F6, 8, NOTE_G6, 8, NOTE_F6, 8, NOTE_E6, 8, 
  NOTE_D6, 4, REST, 8, NOTE_G6, 8, REST, 8, NOTE_G6, 8, NOTE_G6, 8, REST, 8, NOTE_A6, 4, NOTE_A6, 4, NOTE_B6, 8, NOTE_C7, 8, 
  NOTE_A6, 8, NOTE_B6, 8, NOTE_C7, 4, REST, 8, NOTE_C7, 8, NOTE_C7, 4, NOTE_G6, 4, NOTE_B6, 4, NOTE_C7, 4, NOTE_D7, 4, 
  NOTE_E7, 16, NOTE_F7, 16, NOTE_E7, 8, NOTE_D7, 4, REST, 8, NOTE_D6, 8, NOTE_D7, 8, REST, 4, 
  NOTE_E7, 8, NOTE_F7, 4, NOTE_E7, 4, NOTE_D7, 8, NOTE_F7, 4, NOTE_E7, 4, REST, 4, NOTE_C7, 8, NOTE_C7, 4, NOTE_E7, 4, 
  NOTE_D7, 4, NOTE_C7, 4, NOTE_B6, 4, NOTE_D7, 4, NOTE_C7, 4 , REST, 4, NOTE_D7, 4, 
  NOTE_E7, 8, NOTE_F7, 4, NOTE_E7, 4, NOTE_D7, 8, NOTE_F7, 4, NOTE_E7, 4, REST, 4, NOTE_C7, 8, NOTE_C7, 4, NOTE_E7, 4, 
  NOTE_D7, 4, NOTE_C7, 4, NOTE_B6, 4, NOTE_D7, 4, NOTE_E7, 16, NOTE_D7, 16, NOTE_C7, 2
};

// Uncomment session if you are using Software delay Sync, Delay Sync work with wider range of frequency but the inaccuracy of this method become
// Significant the higher frequency you go. Thus higher frequency, I would recommend going with HW PWM sync.
/*  
//Raya Song 1 - Selamat Hari Raya
const PROGMEM char rayaSong1[] = {
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2, NOTE_C4, 8, 
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_D5, 8, 
  NOTE_C5, 8, NOTE_AS4, 8, NOTE_A4, 2, REST, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, 
  NOTE_G4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_AS4, 4 , NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_A4, 8, 
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 2, REST, 2, 
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 4, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_C5, 8, 
  NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4 , NOTE_E4, 8, 
  NOTE_D4, 8, NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, 
  NOTE_A4, 8, NOTE_C5, 2, REST, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 4, NOTE_G4, 8, NOTE_A4, 8, 
  NOTE_AS4, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_G4, 8, 
  NOTE_F4, 4, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, 
  NOTE_AS4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 2, REST, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, 
  NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2, NOTE_C4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_G4, 8, 
  NOTE_A4, 8, NOTE_AS4, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_AS4, 8, NOTE_A4, 2, REST, 2, NOTE_F4, 8, NOTE_G4, 8, 
  NOTE_A4, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_AS4, 4, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, 
  NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 2
};

//Raya Song 2 - Suasana Hari Raya
const PROGMEM char rayaSong2[] = {
  NOTE_C5, 8, REST, 8, NOTE_G5, 8, NOTE_G5, 8, REST, 8, NOTE_G5, 8, REST, 8, NOTE_G5, 8, REST, 8, NOTE_A5, 8, 
  NOTE_F5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_C5, 8, REST, 8, NOTE_G5, 8, 
  NOTE_G5, 8, REST, 8, NOTE_G5, 8, REST, 8, NOTE_G5, 8, REST, 8, NOTE_A5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_E5, 8, 
  NOTE_F5, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_D5, 8, REST, 8, NOTE_A5, 8, NOTE_A5, 8, REST, 8, NOTE_A5, 8, REST, 8, 
  NOTE_A5, 8, REST, 8, NOTE_B5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_D5, 8, 
  NOTE_C5, 4, REST, 8, NOTE_C5, 8, NOTE_C5, 8, REST, 8, NOTE_E5, 4 , NOTE_E5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_E5, 8, 
  NOTE_F5, 8, NOTE_A5, 4, REST, 4, NOTE_A5, 64, NOTE_B5, 64, NOTE_A5, 4 , NOTE_G5, 4, NOTE_B5, 4, NOTE_C6, 4, 
  NOTE_D6, 8, REST, 16, NOTE_D6, 16, NOTE_B5, 4, NOTE_C6, 16, NOTE_D6, 16, NOTE_C6, 132, REST, 16,  NOTE_G5, 4, 
  NOTE_G5, 4, NOTE_A5, 4, NOTE_G5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8, NOTE_D5, 2, 
  NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4, NOTE_E5, 8, NOTE_F5, 16, NOTE_E5, 16, NOTE_F5, 4, NOTE_D5, 4, NOTE_E5, 4, 
  REST, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_F5, 8, REST, 8, NOTE_F5, 8, NOTE_G5, 2, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 64, 
  NOTE_E5, 4, NOTE_E5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_A5, 4, REST, 4, 
  NOTE_A5, 64, NOTE_B5, 64, NOTE_A5, 8, NOTE_A5, 8, NOTE_G5, 4 , NOTE_B5, 4, NOTE_C6, 4, NOTE_D6, 8, NOTE_D6, 8, 
  NOTE_B5, 4, NOTE_C6, 16, NOTE_D6, 16, NOTE_C6, 132, REST, 8, NOTE_G5, 8, NOTE_G5, 4, NOTE_A5, 4, NOTE_G5, 4, 
  NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8, NOTE_D5, 2, 
  NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4, NOTE_E5, 8, NOTE_F5, 16, NOTE_E5, 16, NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 4, 
  REST, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 4, REST, 8, NOTE_G5, 8, REST, 8, NOTE_G5, 8, 
  NOTE_G5, 8, REST, 8, NOTE_A5, 4, NOTE_A5, 4, NOTE_B5, 8, NOTE_C6, 8, NOTE_A5, 8, NOTE_B5, 8, NOTE_C6, 4, 
  REST, 8, NOTE_C6, 8 , NOTE_C6, 4, NOTE_G5, 4, NOTE_A5, 4, NOTE_G5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8, 
  NOTE_D5, 4, REST, 8, NOTE_G5, 8, REST, 8, NOTE_G5, 8, NOTE_G5, 8, REST, 8, NOTE_A5, 4, NOTE_A5, 4, NOTE_B5, 8, NOTE_C6, 8, 
  NOTE_A5, 8, NOTE_B5, 8, NOTE_C6, 4, REST, 8, NOTE_C6, 8, NOTE_C6, 4, NOTE_G5, 4, NOTE_B5, 4, NOTE_C6, 4, NOTE_D6, 4, 
  NOTE_E6, 16, NOTE_F6, 16, NOTE_E6, 8, NOTE_D6, 4, REST, 8, NOTE_D5, 8, NOTE_D6, 8, REST, 4, 
  NOTE_E6, 8, NOTE_F6, 4, NOTE_E6, 4, NOTE_D6, 8, NOTE_F6, 4, NOTE_E6, 4, REST, 4, NOTE_C6, 8, NOTE_C6, 4, NOTE_E6, 4, 
  NOTE_D6, 4, NOTE_C6, 4, NOTE_B5, 4, NOTE_D6, 4, NOTE_C6, 4 , REST, 4, NOTE_D6, 4, 
  NOTE_E6, 8, NOTE_F6, 4, NOTE_E6, 4, NOTE_D6, 8, NOTE_F6, 4, NOTE_E6, 4, REST, 4, NOTE_C6, 8, NOTE_C6, 4, NOTE_E6, 4, 
  NOTE_D6, 4, NOTE_C6, 4, NOTE_B5, 4, NOTE_D6, 4, NOTE_E6, 16, NOTE_D6, 16, NOTE_C6, 2
};

*/


unsigned long lastFingerPressed = 0;

uint8_t sensorLDRValue = 0;  // variable to store the value coming from the sensor
uint8_t buttonBuffer = 0x3F;


void setup() {
    initTomatoCube();

    setHWSync(true);  //Note: Enable Hardware PWM Sync for greater Sound accuracy
                      //      Limit to NOTE_FS4 -> NOTE_D8 (355 Hz to 90 Khz)


    // Run through each Neopixels (5) with a random color Light.
    // Note: setStarRGB(LED_Pixel#, Red, Green, Blue, Push/Update Neopixel Now);
    for (int ledNumber = 0; ledNumber<=4; ledNumber++) {
      setStarRGB(ledNumber, rand() % 0x3F, rand() % 0x3F, rand() % 0x3F, true);
      delay(250);
    }

    // Clear Neopixel
    setStarRGB(0, 0, 0, 0, false);
    setStarRGB(1, 0, 0, 0, false);
    setStarRGB(2, 0, 0, 0, false);
    setStarRGB(3, 0, 0, 0, false);
    setStarRGB(4, 0, 0, 0, true);

    // Play Ready Tone
    playTone(TONE_PINOUT, NOTE_E5, 50) ;
    playTone(TONE_PINOUT, REST, 20) ;
    playTone(TONE_PINOUT, NOTE_D5, 50) ;
    playTone(TONE_PINOUT, REST, 10) ;
    delay(5);          
    
}

uint8_t neopixelCrescent = false;
uint8_t neopixelLDRMosque = false;
uint8_t LastlLDRState = false;
uint8_t neopixelLevel = 0;
int neopixelintensity = 0;
uint8_t neopixelLevelChanged = false;



// the loop function runs over and over again forever
void loop() {

// Code for ButtonPress & LDR (Light)

      sensorLDRValue = analogRead(LDR_PINOUT);  // If ambient light is not detected, day time -> roughly 180. (255 max)
      
      buttonBuffer = (buttonBuffer << 1) | (digitalRead(SWITCH_PINOUT) & 0x01);

      if ((buttonBuffer & 0x3F) == 0) {   // If ButtonPressed is detected

          // Play Music When Button is pressed
          adjustTempo(210); 
          if ((millis()/500) % 2)
              sendMusicNotes(rayaSong1, sizeof(rayaSong1));
          else 
              sendMusicNotes(rayaSong2, sizeof(rayaSong2));
      }

      

// Code for IR (NEC infrared remote)
      
//      TomatoCube 3 Button IR { Addr: 255 }
//      1. < Power >  Cmd: 2
//      2. < UP >     Cmd: 152
//      3. < Down >   Cmd: 24


      if(isIR_Received()) {          // If a good NEC message is received
        if (getIRAddress() == 255) {   // Switch Case for TomatoCube 3 Button IR
          switch (getIRCommand()) {
              case 2:   // < Power >
                  playTone(TONE_PINOUT, NOTE_A5, 50) ;
                  playTone(TONE_PINOUT, REST, 10) ;
                  delay(5);
                  
                  // Code for TopCrescent
                  if (!neopixelCrescent) {
                      setStarRGB(4, rand() % 0x3F, rand() % 0x3F, rand() % 0x3F, true);
                      neopixelCrescent = true;
                  }
                  else {
                      setStarRGB(4, 0, 0, 0, true);
                      neopixelCrescent = false;
                  }
                  
              break;
              case 152:   // < Up >
                  playTone(TONE_PINOUT, NOTE_E5, 50) ;
                  playTone(TONE_PINOUT, REST, 10) ;
                  delay(5);
                  
                  // Code for increment of Mosque building brightness
                  neopixelLevel = (neopixelLevel <= 4)? neopixelLevel + 1: neopixelLevel;
                  neopixelLevelChanged = true;
                  
              break;
              case 24:  // < Down >
                  playTone(TONE_PINOUT, NOTE_D5, 50) ;
                  playTone(TONE_PINOUT, REST, 10) ;
                  delay(5);
                  
                  // Code for decrementing of Mosque building brightness
                  neopixelLevel = (neopixelLevel > 0)? neopixelLevel - 1: 0;
                  neopixelLevelChanged = true;
                  
              break;
              default:   
              break;
          }
        }     
    }   


// Code for CapTouch Switch.

      // Code to Enable & disable Night Light
      scanTouchButton();  // Update Capacitive Touch status
      if (getTouchB1Transition() == 1) {
          playTone(TONE_PINOUT, NOTE_E5, 50) ;
          playTone(TONE_PINOUT, REST, 10) ;
          delay(5); 
                 
          neopixelLDRMosque = true;
          LastlLDRState = false;
      }
      else if (getTouchB2Transition() == 1) {
          playTone(TONE_PINOUT, NOTE_D5, 50) ;
          playTone(TONE_PINOUT, REST, 10) ;
          delay(5); 
                  
          neopixelLDRMosque = false;
          neopixelLevelChanged = true;
      }
      // Night Light State Indicator => Blinking means NightLight mode activated
      digitalWrite(LED_BUILTIN, neopixelLDRMosque && ((millis()/500) % 2)? HIGH: LOW);
    

// Code for Mosque Light
      if (neopixelLDRMosque)  { // Mosque operated in Night Light fashion
      // Code for Night Light
          if ((sensorLDRValue < 160) && (!LastlLDRState)) {
                LastlLDRState = true;
                setStarRGB(0, 0x3F, 0x3F, 0x3F, false);
                setStarRGB(1, 0x3F, 0x3F, 0x3F, false);
                setStarRGB(2, 0x3F, 0x3F, 0x3F, false);
                setStarRGB(3, 0x3F, 0x3F, 0x3F, true);        
          }
          else if ((sensorLDRValue > 200) && (LastlLDRState)) {
                LastlLDRState = false;
                setStarRGB(0, 0, 0, 0, false);
                setStarRGB(1, 0, 0, 0, false);
                setStarRGB(2, 0, 0, 0, false);
                setStarRGB(3, 0, 0, 0, true);
          }
      } 
      else if (neopixelLevelChanged){    // Mosque Operating in normal mode 
          neopixelLevelChanged = false;
          neopixelintensity = 0xef * neopixelLevel / 5;
          setStarRGB(0, neopixelintensity, neopixelintensity, neopixelintensity, false);
          setStarRGB(1, neopixelintensity, neopixelintensity, neopixelintensity, false);
          setStarRGB(2, neopixelintensity, neopixelintensity, neopixelintensity, false);
          setStarRGB(3, neopixelintensity, neopixelintensity, neopixelintensity, true);  
      }
      

// Code for Music Playback, Call repeatedly.
     
    if (playMusic()) {     // If music is playing
        // Do something while music is playing
    }
    else {
        // Do something if music stop playing     
    }
     
}