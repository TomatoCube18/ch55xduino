#include "TomatoCubeWorker.h"


const PROGMEM char Jingle_melody[] = {
  // Jingle Bells
  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5,  4,
  NOTE_E5, 8, NOTE_G5, 8,  NOTE_C5, 8,  NOTE_D5, 8, 
  NOTE_E5, 2,
  NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, 
  NOTE_F5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 16, NOTE_E5, 16,
  NOTE_E5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_E5, 8, 
  NOTE_D5, 4, NOTE_G5, 4
};

const PROGMEM char pacman_melody[] = {
  // Pacman
  // Score available at https://musescore.com/user/85429/scores/107109
  NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
  NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
  NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,

  NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  //2
  NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
  NOTE_F5, 32,  NOTE_FS5, 32,  NOTE_G5, 32,  NOTE_G5, 32, NOTE_GS5, 32,  NOTE_A5, 16, NOTE_B5, 8
};

const PROGMEM char tetris_melody[] = {
  // Tetris
  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192 
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
  

  NOTE_E5,2,  NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,2,   NOTE_A4,2,
  NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
  NOTE_E5,2,   NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2
};

const PROGMEM char christmas_melody[] = {
  // We Wish You a Merry Christmas
  // Score available at https://musescore.com/user/6208766/scores/1497501
  NOTE_C5,4, //1
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,

  NOTE_F5,2, NOTE_C5,4, //8 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,

  NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,//17
  NOTE_E5,2, NOTE_E5,4,
  NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
  NOTE_C5,2, NOTE_A5,4,
  NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
  NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, //27
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,
  NOTE_E5,2, NOTE_E5,4,
  NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
  
  NOTE_C5,2, NOTE_A5,4,//36
  NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
  NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, 
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,//45
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, //53
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, REST,4
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
              sendMusicNotes(firstRunTune? christmas_melody: Jingle_melody, firstRunTune? sizeof(christmas_melody) : sizeof(Jingle_melody));
              generateLEDSequence();
              setStarRGB(rand() % 0x0F, rand() % 0x0F, rand() % 0x0F);
              firstRunMusic = false;
          }
          else if (getTouchB1Transition() == 1) {
              adjustTempo(300);
              if (getTouchB2State())
                sendMusicNotes(pacman_melody, sizeof(pacman_melody));
              else
                sendMusicNotes(Jingle_melody, sizeof(Jingle_melody));
              generateLEDSequence();
              setStarRGB(rand() % 0x0F, rand() % 0x0F, rand() % 0x0F);
              
          }
          else if (getTouchB2Transition() == 1) {
              adjustTempo(400);
              if (getTouchB1State())
                sendMusicNotes(tetris_melody, sizeof(tetris_melody));
              else 
                sendMusicNotes(christmas_melody, sizeof(christmas_melody));
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
