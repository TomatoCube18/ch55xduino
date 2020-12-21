#include "TomatoCubeWorker.h"

__xdata uint8_t ledData[NUM_BYTES];

uint8_t button1State = LOW;
uint8_t button2State = LOW;

uint8_t button1RFlag = LOW;
uint8_t button2RFlag = LOW;

uint8_t button1FFlag = LOW;
uint8_t button2FFlag = LOW;

uint8_t button1tmp = 0;
uint8_t button2tmp = 0;


// change this to make the song slower or faster
int songTempo ;
// this calculates the duration of a whole note in ms
int wholenote;

char *songNotes;
int sizeMusic;
int thisNote = 0;

void initTomatoCube() {

  TouchKey_begin( (1 << 1) | (1 << 2)  ); //Enable all 2 channels:  TIN1(P1.1), TIN2(P1.4)
  
  songTempo = 200;
  wholenote = (60000 * 4) / songTempo;

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TONE_PINOUT, OUTPUT);

  pinMode(RGB_PINOUT, OUTPUT);
  pinMode(LED_1_PINOUT, OUTPUT);
  pinMode(LED_2_PINOUT, OUTPUT);
  pinMode(LED_3_PINOUT, OUTPUT);
  pinMode(LED_4_PINOUT, OUTPUT);
  pinMode(LED_5_PINOUT, OUTPUT);
  pinMode(LED_6_PINOUT, OUTPUT);

  
}

//void runTomatoCubeFSM() {
//    scanTouchButton();
//    
//}

int freqLookup(unsigned char note) {
  switch(note) {
    case NOTE_B0:
        return 31;
        break;
    case NOTE_C1 :
        return 33;
        break;
    case NOTE_CS1 :
        return 35;
        break;
    case NOTE_D1  :
        return 37;
        break;
    case NOTE_DS1 :
        return 39;
        break;
    case NOTE_E1  :
        return 41;
        break;
    case NOTE_F1  :
        return 44;
        break;
    case NOTE_FS1 :
        return 46;
        break;
    case NOTE_G1  :
        return 49;
        break;
    case NOTE_GS1 :
        return 52;
        break;
    case NOTE_A1  :
        return 55;
        break;
    case NOTE_AS1 :
        return 58;
        break;
    case NOTE_B1  :
        return 62;
        break;
    case NOTE_C2  :
        return 65;
        break;
    case NOTE_CS2 :
        return 69;
        break;
    case NOTE_D2  :
        return 73;
        break;
    case NOTE_DS2 :
        return 78;
        break;
    case NOTE_E2  :
        return 82;
        break;
    case NOTE_F2  :
        return 87;
        break;
    case NOTE_FS2 :
        return 93;
        break;
    case NOTE_G2  :
        return 98;
        break;
    case NOTE_GS2 :
        return 104;
        break;
    case NOTE_A2  :
        return 110;
        break;
    case NOTE_AS2 :
        return 117;
        break;
    case NOTE_B2  :
        return 123;
        break;
    case NOTE_C3  :
        return 131;
        break;
    case NOTE_CS3 :
        return 139;
        break;
    case NOTE_D3  :
        return 147;
        break;
    case NOTE_DS3 :
        return 156;
        break;
    case NOTE_E3  :
        return 165;
        break;
    case NOTE_F3  :
        return 175;
        break;
    case NOTE_FS3 :
        return 185;
        break;
    case NOTE_G3  :
        return 196;
        break;
    case NOTE_GS3 :
        return 208;
        break;
    case NOTE_A3  :
        return 220;
        break;
    case NOTE_AS3 :
        return 233;
        break;
    case NOTE_B3  :
        return 247;
        break;
    case NOTE_C4  :
        return 262;
        break;
    case NOTE_CS4 :
        return 277;
        break;
    case NOTE_D4  :
        return 294;
        break;
    case NOTE_DS4 :
        return 311;
        break;
    case NOTE_E4  :
        return 330;
        break;
    case NOTE_F4  :
        return 349;
        break;
    case NOTE_FS4 :
        return 370;
        break;
    case NOTE_G4  :
        return 392;
        break;
    case NOTE_GS4 :
        return 415;
        break;
    case NOTE_A4  :
        return 440;
        break;
    case NOTE_AS4 :
        return 466;
        break;
    case NOTE_B4  :
        return 494;
        break;
    case NOTE_C5  :
        return 523;
        break;
    case NOTE_CS5 :
        return 554;
        break;
    case NOTE_D5  :
        return 587;
        break;
    case NOTE_DS5 :
        return 622;
        break;
    case NOTE_E5  :
        return 659;
        break;
    case NOTE_F5  :
        return 698;
        break;
    case NOTE_FS5 :
        return 740;
        break;
    case NOTE_G5  :
        return 784;
        break;
    case NOTE_GS5 :
        return 831;
        break;
    case NOTE_A5  :
        return 880;
        break;
    case NOTE_AS5 :
        return 932;
        break;
    case NOTE_B5  :
        return 988;
        break;
    case NOTE_C6  :
        return 1047;
        break;
    case NOTE_CS6 :
        return 1109;
        break;
    case NOTE_D6  :
        return 1175;
        break;
    case NOTE_DS6 :
        return 1245;
        break;
    case NOTE_E6  :
        return 1319;
        break;
    case NOTE_F6  :
        return 1397;
        break;
    case NOTE_FS6 :
        return 1480;
        break;
    case NOTE_G6  :
        return 1568;
        break;
    case NOTE_GS6 :
        return 1661;
        break;
    case NOTE_A6  :
        return 1760;
        break;
    case NOTE_AS6 :
        return 1865;
        break;
    case NOTE_B6  :
        return 1976;
        break;
    case NOTE_C7  :
        return 2093;
        break;
    case NOTE_CS7 :
        return 2217;
        break;
    case NOTE_D7  :
        return 2349;
        break;
    case NOTE_DS7 :
        return 2489;
        break;
    case NOTE_E7  :
        return 2637;
        break;
    case NOTE_F7  :
        return 2794;
        break;
    case NOTE_FS7 :
        return 2960;
        break;
    case NOTE_G7  :
        return 3136;
        break;
    case NOTE_GS7 :
        return 3322;
        break;
    case NOTE_A7  :
        return 3520;
        break;
    case NOTE_AS7 :
        return 3729;
        break;
    case NOTE_B7  :
        return 3951;
        break;
    case NOTE_C8  :
        return 4186;
        break;
    case NOTE_CS8 :
        return 4435;
        break;
    case NOTE_D8  :
        return 4699;
        break;
    case REST :
        return 0;
        break;
    default:
        return 5000;
    
  }
}

void adjustTempo(unsigned int _songTempo) {
  songTempo = _songTempo;
  wholenote = (60000 * 4) / songTempo;
}

int getWholeNote() {
  return wholenote;
}

void playTone(int pinToneOut, unsigned char note, int duration) {
  unsigned long startMillis = millis();
  if (note == REST) {
      while ( (millis() - startMillis) < duration) {
            digitalWrite(pinToneOut, LOW); 
      }
  } 
  else {
      int msDelay = 500000/(freqLookup(note));
      while ( (millis() - startMillis) < duration) {
            digitalWrite(pinToneOut, HIGH);   // turn the LED on (HIGH is the voltage level)
            delayMicroseconds(msDelay);                       // wait for a second
            digitalWrite(pinToneOut, LOW);    // turn the LED off by making the voltage LOW
            delayMicroseconds(msDelay);  
      }
  }
}

unsigned long startToneMillis;
int toneMsDelay = 0;
int noteDuration = 0;


void sendMusicNotes(char *musicNotes, int musicSize) {
      songNotes = musicNotes;
      sizeMusic = musicSize;
      sizeMusic /= sizeof(unsigned char);
      sizeMusic /= 2;

      thisNote = 0;
      startToneMillis = 0;
}

void stopMusic() {
    sendMusicNotes(0, 0);
}

int playMusic() {
   if ( (millis() - startToneMillis) < noteDuration) {
        if (toneMsDelay > 0) {
            digitalWrite(TONE_PINOUT, HIGH);   // turn the LED on (HIGH is the voltage level)
            delayMicroseconds(toneMsDelay);                       // wait for a second
            digitalWrite(TONE_PINOUT, LOW);    // turn the LED off by making the voltage LOW
            delayMicroseconds(toneMsDelay);  
        }
        else
            digitalWrite(TONE_PINOUT, LOW); 

        return 1;
   }
   else if ((millis() - startToneMillis) < (noteDuration + (noteDuration * 1.30)) ) {
   // to distinguish the notes, set a minimum time between them.
   // the note's duration + 30% seems to work well:
        digitalWrite(TONE_PINOUT, LOW); 
        return 1;
   }
   else if (thisNote < sizeMusic) {
//        int noteDuration = 0;
        if (songNotes[(thisNote * 2) + 1] > 0) {
          // regular note, just proceed
          noteDuration = (getWholeNote()) / (songNotes[(thisNote * 2) + 1]);
        } else if (songNotes[(thisNote * 2) + 1] < 0) {
          // dotted notes are represented with negative durations!!
          noteDuration = (getWholeNote()) / abs(songNotes[(thisNote * 2) + 1]);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }

        startToneMillis = millis();
        toneMsDelay = songNotes[(thisNote * 2)];
        if (toneMsDelay == REST)
            toneMsDelay = 0;
        else 
            toneMsDelay = 500000/(freqLookup(toneMsDelay));
              
//        playTone(TONE_PINOUT, songNotes[(thisNote * 2)], noteDuration);
        
        thisNote += 1;
        return 1;
    }
    else {
      digitalWrite(TONE_PINOUT, LOW); 
      return 0;
    }
}


void scanTouchButton() {
        TouchKey_Process();
        uint8_t touchResult = TouchKey_Get();
      
        button1tmp = (button1tmp << 1) | ((touchResult & (1 << 1)) ? 1 : 0);
        button2tmp = (button2tmp << 1) | ((touchResult & (1 << 2)) ? 1 : 0);
      
        button1State = (button1tmp & 0x0F) == 0x0F;  // Current State
        button2State = (button2tmp & 0x0F) == 0x0F;   
        
        button1RFlag = (button1tmp & 0x3F) == 0x07;  // On Press or Rising flag
        button2RFlag = (button2tmp & 0x3F) == 0x07;
        
        button1FFlag = (button1tmp & 0x3F) == 0x18;  // On Press or Rising flag
        button2FFlag = (button2tmp & 0x3F) == 0x18;
}

uint8_t getTouchB1State() {
    return button1State;
}

uint8_t getTouchB2State() {
    return button2State;
}

int8_t getTouchB1Transition() { // 0 - no change, 1, onPress, -1, onRelease
    return button1RFlag? 1: button1FFlag? -1: 0;
}

int8_t getTouchB2Transition() { // 0 - no change, 1, onPress, -1, onRelease
    return button2RFlag? 1: button2FFlag? -1: 0;
}


void setStarRGB(uint8_t _red, uint8_t _green, uint8_t _blue) {
    set_pixel_for_GRB_LED(ledData, 0, _red, _green, _blue);
    neopixel_show_P1_5(ledData, NUM_BYTES);
}

void pixelLED(unsigned char ledPattern) {
      P1 = (P1 & 0x3F) | ((ledPattern & 0x03) << 6); 
      P3 = (P3 & 0xF0) | ((ledPattern & 0x0C)) | ((ledPattern & 0x30) >> 4);
}
