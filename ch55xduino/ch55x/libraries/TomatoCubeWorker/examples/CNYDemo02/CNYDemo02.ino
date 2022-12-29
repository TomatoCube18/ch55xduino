#include "TomatoCubeWorker.h"

//CNY Song 1
const PROGMEM char cnySong1[] = {
  NOTE_D4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_AS4, 4, NOTE_A4,  4,
  NOTE_A4, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_A4, 8, NOTE_A4, 4, NOTE_G4,  4,
  NOTE_G4, 8, NOTE_AS4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_G4, 4, NOTE_F4,  4,
  NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_CS4, 8, NOTE_D4, 4, NOTE_D4,  4,
  NOTE_G4, 136, NOTE_A4, 16, NOTE_F4, 136, NOTE_A4, 16, NOTE_E4, 8, NOTE_A4,  8, NOTE_D4, 8, NOTE_A4,  8,
  NOTE_G4, 136, NOTE_A4, 16, NOTE_F4, 136, NOTE_A4, 16, NOTE_E4, 8, NOTE_A4,  8, NOTE_D4, 4,
  NOTE_G4, 136, NOTE_A4, 16, NOTE_F4, 136, NOTE_A4, 16, NOTE_E4, 8, NOTE_A4,  8, NOTE_D4, 8, NOTE_A4,  8,
  NOTE_G4, 136, NOTE_A4, 16, NOTE_F4, 136, NOTE_A4, 16, NOTE_E4, 8, NOTE_A4,  8, NOTE_D4, 4
};

//CNY Song 2

const PROGMEM char cnySong2[] = {

  NOTE_G5,8, NOTE_GS5,8, 
  NOTE_A5, 4, NOTE_G5, 8, NOTE_E5, 8, NOTE_C5, 4, NOTE_B4, 8, NOTE_C5,  8,
  NOTE_D5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 4, REST, 8, NOTE_B4,  8,
  NOTE_D5, 8, NOTE_G5, 4, NOTE_A5, 8, NOTE_G5, 136, NOTE_A5, 16, NOTE_F5,  8, NOTE_E5,  8,
  NOTE_G5, 2, NOTE_C5, 16, NOTE_D5, 16, NOTE_E5, 16, NOTE_F5, 16, NOTE_G5, 8, NOTE_GS5,  8,
  NOTE_A5, 4, NOTE_G5, 8, NOTE_E5, 8, NOTE_C5, 4, NOTE_B4, 8, NOTE_C5,  8,
  NOTE_D5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 4, REST, 8, NOTE_B4,  8,
  NOTE_D5, 8, NOTE_G5, 4, NOTE_A5, 8, NOTE_A5, 136, NOTE_G5, 16, NOTE_G5,  8, NOTE_B4,  8,
  NOTE_C5, 2
};

//CNY Song 3

const PROGMEM char tokyoBon[] = {
  NOTE_CS5, 8, NOTE_FS5, 8, NOTE_FS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_GS5,  8, NOTE_FS5, 8,
  NOTE_D5, 8, NOTE_FS5, 8, NOTE_FS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_GS5,  8, NOTE_FS5, 8,
  NOTE_GS5, 8, NOTE_GS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_B5, 8, NOTE_B5, 8, NOTE_A5,  8, NOTE_GS5, 8,
  NOTE_FS5, 8, NOTE_F5, 8, NOTE_FS5, 8, NOTE_GS5, 8, NOTE_A5, 4, REST, 4, 
  NOTE_CS5, 8, NOTE_FS5, 8, NOTE_FS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_GS5,  8, NOTE_FS5, 8,
  NOTE_D5, 8, NOTE_FS5, 8, NOTE_FS5, 8, NOTE_GS5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_GS5,  8, NOTE_FS5, 8,
  NOTE_GS5, 12, NOTE_FS5, 12, NOTE_GS5, 12, NOTE_B5, 8, NOTE_A5, 8, NOTE_GS5, 8, NOTE_A5,  8, NOTE_GS5, 8, NOTE_FS5, 8,
  NOTE_FS5, 4, NOTE_FS5, 4, NOTE_FS5, 8, NOTE_FS4, 8, NOTE_FS4, 8, NOTE_FS4, 8,
  
  NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_D5, 8, NOTE_CS5, 8, NOTE_FS4, 8, NOTE_FS4,  8, NOTE_FS4, 8,
  NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_D5, 8, NOTE_CS5, 8, NOTE_FS4, 8, NOTE_FS4,  8, NOTE_FS4, 8,
  NOTE_B4, 8, NOTE_B4, 8, NOTE_B4, 8, NOTE_CS5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_A4,  8, NOTE_GS4, 8,
  NOTE_A4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_GS4, 4, NOTE_FS4, 8, NOTE_FS4, 8,

  NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_D5, 8, NOTE_CS5, 8, NOTE_FS4, 8, NOTE_FS4,  8, NOTE_FS4, 8,
  NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_D5, 8, NOTE_CS5, 8, NOTE_FS4, 8, NOTE_FS4,  8, NOTE_FS4, 8,
  NOTE_B4, 8, NOTE_B4, 8, NOTE_B4, 8, NOTE_CS5, 8, NOTE_B4, 8, NOTE_A4, 4, NOTE_A4,  8, 
  NOTE_GS4, 8, NOTE_GS4, 8, NOTE_A4, 8, NOTE_GS4, 8, NOTE_FS4, 4, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, 

  NOTE_FS5, 132, NOTE_FS5, 4, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, 
  NOTE_E5, 8, NOTE_D5, 8, NOTE_CS5, 8, NOTE_D5, 4, NOTE_B4, 8, NOTE_B4, 8, NOTE_B4, 8, 

  NOTE_E5, 132, NOTE_E5, 4, NOTE_B4, 8, NOTE_B4, 8, NOTE_B4, 8, 
  NOTE_D5, 8, NOTE_CS5, 8, NOTE_B4, 8, NOTE_CS5, 4, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, 

  NOTE_FS5, 132, NOTE_FS5, 4, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, 
  NOTE_E5, 8, NOTE_D5, 8, NOTE_CS5, 8, NOTE_D5, 4, NOTE_B4, 8, NOTE_CS5, 8, NOTE_D5, 8, 

  NOTE_CS5, 3, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_CS5, 8, 
  NOTE_F5, 1
};

//CNY Song 4

const PROGMEM char cnySong3[] = {
  NOTE_C4, 132, NOTE_D4, 8, NOTE_E4, 4, NOTE_G4, 4, 
  NOTE_A4, 8, NOTE_G4, 2, NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, 
  NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_C5, 4, 
  NOTE_A4, 2, REST, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 8, 
  NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_C5, 4, 
  NOTE_G4, 2, REST, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_G4, 8, 
  NOTE_A4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_G4, 4, 
  NOTE_D4, 2, REST, 8,  NOTE_D4, 8, NOTE_E4, 8, NOTE_F4, 8,
  NOTE_A4, 4, NOTE_G4, 4, NOTE_B4, 4, NOTE_D5, 4, 
  NOTE_C5, 2, REST, 2, 
  NOTE_C5, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 132, REST, 4,
  NOTE_A4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 132, REST, 4,

  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 4, 
  NOTE_G4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 4, NOTE_G5, 4,

  NOTE_C4, 132, NOTE_D4, 8, NOTE_E4, 4, NOTE_G4, 4, 
  NOTE_A4, 8, NOTE_G4, 2, NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, 
  NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_C5, 4, 
  NOTE_A4, 2, REST, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 8, 

  NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_C5, 4, 
  NOTE_G4, 2, REST, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_G4, 8, 
  NOTE_A4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_G4, 4, 

  NOTE_D4, 2, REST, 8,  NOTE_D4, 8, NOTE_E4, 8, NOTE_F4, 8,
  NOTE_A4, 4, NOTE_G4, 4, NOTE_B4, 4, NOTE_D5, 4, 
  NOTE_C5, 2, REST, 2
};

unsigned char leftTotal = 0;
unsigned char rightTotal = 0;
bool inGameMode = true;
bool firstRunMusic = true;
unsigned char firstRunTune = 0;

unsigned long lastLEDMillis = 0;
unsigned char LEDStatus = LOW;

unsigned char randomLEDSeq[23] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x00, 0x3f, 0x00, 0x03, 0x0C, 0x30, 0x00, 0x10, 0x04, 0x01, 0x02, 0x08, 0x20, 0x00, 0x3f, 0x00};
unsigned char currentLEDPattern = 0;


void generateLEDSequence() {
    srand(millis());
    for (int i = 0; i < 20; i ++) {
        randomLEDSeq[i] = rand() % 0x3F;
    }
}

unsigned char getRandomLED() {
    currentLEDPattern += 1;
    if (currentLEDPattern >= 23)
        currentLEDPattern = 0;
    return randomLEDSeq[currentLEDPattern];
}

// the setup function runs once when you press reset or power the board
void setup() {

  initTomatoCube();
  
  for (int ledPatterni = 0; ledPatterni< 23; ledPatterni++) {
      pixelLED(randomLEDSeq[ledPatterni]);
      delay(150);
  }
  
  setStarRGB(0xFF, 0x00, 0x00);
  delay(250);
  setStarRGB(0x00, 0xEF, 0x00);
  delay(250);
  setStarRGB(0x00, 0x00, 0X0F);
  delay(250);
  setStarRGB(0x00, 0x00, 0x00);

  lastLEDMillis = millis();
}

// the loop function runs over and over again forever
void loop() {


    if (inGameMode) {
          scanTouchButton();
           if (getTouchB1Transition() == 1) {
              
                leftTotal += 1;
                if (leftTotal > 3) {
                    if (rightTotal == 3) {
                        inGameMode = false;
                        firstRunTune = 0;
                        srand(millis());
                        setStarRGB(rand() % 0x0F, rand() % 0x0F, rand() % 0x0F);
                        playTone(TONE_PINOUT, NOTE_E5, 50) ;
                        playTone(TONE_PINOUT, REST, 20) ;
                        playTone(TONE_PINOUT, NOTE_D5, 50) ;
                        playTone(TONE_PINOUT, REST, 500) ;
                        
                    }
                    else
                        leftTotal = 0;
                }
           }
           else  if (getTouchB2Transition() == 1) {
                rightTotal += 1;
                if (rightTotal > 3) {
                    if (leftTotal == 3) {
                        inGameMode = false;
                        firstRunTune = 1;
                        srand(millis());
                        setStarRGB(rand() % 0x0F, rand() % 0x0F, rand() % 0x0F);
                        playTone(TONE_PINOUT, NOTE_E5, 50) ;
                        playTone(TONE_PINOUT, REST, 20) ;
                        playTone(TONE_PINOUT, NOTE_D5, 50) ;
                        playTone(TONE_PINOUT, REST, 500) ;
                        
                    }
                    else
                        rightTotal = 0;
                }
           }

           pixelLED(((leftTotal == 1)? 0x01: (leftTotal == 2)? 0x05: (leftTotal == 3)? 0x15: 0x00) | ((rightTotal == 1)? 0x02: (rightTotal == 2)? 0x0A: (rightTotal == 3)? 0x2A: 0x00) );
    }
    else {
          scanTouchButton();
          if (firstRunMusic) {
              adjustTempo(400);
              sendMusicNotes(firstRunTune? cnySong3: cnySong2, firstRunTune? sizeof(cnySong3) : sizeof(cnySong2));
              generateLEDSequence();
              setStarRGB(rand() % 0x0F, rand() % 0x0F, rand() % 0x0F);
              firstRunMusic = false;
          }
          else if (getTouchB1Transition() == 1) {
              adjustTempo(300);
              if (getTouchB2State())
                sendMusicNotes(tokyoBon, sizeof(tokyoBon));
              else
                sendMusicNotes(cnySong2, sizeof(cnySong2));
              generateLEDSequence();
              setStarRGB(rand() % 0x0F, rand() % 0x0F, rand() % 0x0F);
              
          }
          else if (getTouchB2Transition() == 1) {
              adjustTempo(400);
              if (getTouchB1State())
                sendMusicNotes(cnySong1, sizeof(cnySong1));
              else 
                sendMusicNotes(cnySong3, sizeof(cnySong3));
              generateLEDSequence();
              setStarRGB(rand() % 0x0F, rand() % 0x0F, rand() % 0x0F);
              //stopMusic();
              
          }
       
          if (!playMusic()) {     // If music is not playing
                if (millis() - lastLEDMillis >= 1000) {
                    pixelLED(0x00);
                    lastLEDMillis = millis();
                    LEDStatus = (LEDStatus == LOW)? HIGH: LOW;
                    digitalWrite(LED_BUILTIN, LEDStatus);   // turn the LED on (HIGH is the voltage level)          
                }
          }
          else {
              if (millis() - lastLEDMillis >= 250) {
                    pixelLED(getRandomLED());
                    lastLEDMillis = millis();
              }
                    
          }
    
    }  
}
