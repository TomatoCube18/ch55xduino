/* 
 *  Ex_06 - CH552_USB_Dongle-06-ToneBabyShark
 *  Generating Sound through the onBoard Buzzer/Spaker with the playTone() Function
 *  
 */

#include "TomatoCubeWorker_v6.h"
void setup() {
  initTomatoCube();
}

// the loop function runs over and over again forever
void loop() {
     scanTouchButton();
     if (getTouchB1Transition() == 1) {
         //BabyShark Theme
         playTone(TONE_PINOUT, NOTE_D5, 400);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_E5, 400);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);     
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 125);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 125);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
    
         playTone(TONE_PINOUT, NOTE_D5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_E5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);     
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 125);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 125);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
    
    
         playTone(TONE_PINOUT, NOTE_D5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_E5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);     
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 125);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 125);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_G5, 250);
         playTone(TONE_PINOUT, REST, 10);
         playTone(TONE_PINOUT, NOTE_A5, 250);
         playTone(TONE_PINOUT, NOTE_G5, 255);
         playTone(TONE_PINOUT, NOTE_FS5, 1000);
         
         playTone(TONE_PINOUT, REST, 20);
     }

     if (getTouchB2Transition() == 1) {
         //StarWars Theme
         playTone(TONE_PINOUT, NOTE_A5, 500);
         playTone(TONE_PINOUT, NOTE_A5, 500);
         playTone(TONE_PINOUT, NOTE_A5, 500);
         playTone(TONE_PINOUT, NOTE_F5, 350);
         playTone(TONE_PINOUT, NOTE_C6, 150);
         playTone(TONE_PINOUT, NOTE_A5, 500);
         playTone(TONE_PINOUT, NOTE_F5, 350);
         playTone(TONE_PINOUT, NOTE_C6, 150);
         playTone(TONE_PINOUT, NOTE_A5, 650);
         playTone(TONE_PINOUT, REST, 500);

         playTone(TONE_PINOUT, NOTE_E6, 500);
         playTone(TONE_PINOUT, NOTE_E6, 500);
         playTone(TONE_PINOUT, NOTE_E6, 500);
         playTone(TONE_PINOUT, NOTE_F6, 350);
         playTone(TONE_PINOUT, NOTE_C6, 150);
         playTone(TONE_PINOUT, NOTE_GS5, 500);
         playTone(TONE_PINOUT, NOTE_F5, 350);
         playTone(TONE_PINOUT, NOTE_C6, 150);
         playTone(TONE_PINOUT, NOTE_A5, 650);
         playTone(TONE_PINOUT, REST, 500);

         playTone(TONE_PINOUT, NOTE_A6, 500);
         playTone(TONE_PINOUT, NOTE_A5, 300);
         playTone(TONE_PINOUT, NOTE_A5, 150);
         playTone(TONE_PINOUT, NOTE_A6, 500);
         playTone(TONE_PINOUT, NOTE_GS6, 325);
         playTone(TONE_PINOUT, NOTE_G5, 175);
         playTone(TONE_PINOUT, NOTE_FS6, 125);
         playTone(TONE_PINOUT, NOTE_F6, 125);
         playTone(TONE_PINOUT, NOTE_FS6, 250);
         playTone(TONE_PINOUT, REST, 325);

         playTone(TONE_PINOUT, NOTE_AS5, 250);
         playTone(TONE_PINOUT, NOTE_DS6, 500);
         playTone(TONE_PINOUT, NOTE_D6, 325);
         playTone(TONE_PINOUT, NOTE_CS6, 175);
         playTone(TONE_PINOUT, NOTE_C6, 125);
         playTone(TONE_PINOUT, NOTE_B5, 125);
         playTone(TONE_PINOUT, NOTE_C6, 250);
         playTone(TONE_PINOUT, REST, 350);

         playTone(TONE_PINOUT, NOTE_F5, 250);
         playTone(TONE_PINOUT, NOTE_GS5, 500);
         playTone(TONE_PINOUT, NOTE_F5, 350);
         playTone(TONE_PINOUT, NOTE_A5, 125);
         playTone(TONE_PINOUT, NOTE_C6, 500);
         playTone(TONE_PINOUT, NOTE_A5, 375);
         playTone(TONE_PINOUT, NOTE_C6, 125);
         playTone(TONE_PINOUT, NOTE_E6, 650);
         playTone(TONE_PINOUT, REST, 350);
     
     }
  
}
