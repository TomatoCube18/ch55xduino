#include "TomatoCubeWorker_v2.h"

__xdata uint8_t ledData[NUM_BYTES];

__xdata uint8_t button1State = LOW;
__xdata uint8_t button2State = LOW;

__xdata uint8_t button1RFlag = LOW;
__xdata uint8_t button2RFlag = LOW;

__xdata uint8_t button1FFlag = LOW;
__xdata uint8_t button2FFlag = LOW;

__xdata uint8_t button1tmp = 0;
__xdata uint8_t button2tmp = 0;


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

  pinMode(RGB_PINOUT, OUTPUT);

  // Shift register to control LED
  pinMode(Data_PINOUT, OUTPUT);
  pinMode(Clock_PINOUT, OUTPUT);
  pinMode(Latch_PINOUT, OUTPUT);
  digitalWrite(Data_PINOUT, LOW); 
  digitalWrite(Clock_PINOUT, LOW); 
  digitalWrite(Latch_PINOUT, LOW); 
  
  // Pins to control sound Chip
  pinMode(BIT_0_PINOUT, OUTPUT);
  pinMode(BIT_1_PINOUT, OUTPUT);
  pinMode(BIT_2_PINOUT, OUTPUT);
  pinMode(TRIG_PINOUT, OUTPUT);
  delay(500);
  digitalWrite(BIT_0_PINOUT, LOW); 
  digitalWrite(BIT_1_PINOUT, LOW); 
  digitalWrite(BIT_2_PINOUT, LOW); 
  digitalWrite(TRIG_PINOUT, LOW);  
  delay(500);
  
  digitalWrite(TRIG_PINOUT, HIGH);  
  delay(5);
  digitalWrite(TRIG_PINOUT, LOW);  
  delay(5);
  
}

//void runTomatoCubeFSM() {
//    scanTouchButton();
//    
//}


void adjustTempo(unsigned int _songTempo) {
  songTempo = _songTempo;
  wholenote = (60000 * 4) / songTempo;
}

int getWholeNote() {
  return wholenote;
}

void playTone(int pinToneOut, unsigned char note, int duration) {
    playToneInf(note);
    delay(duration);
    playToneInf(REST);
}

int playToneInf(unsigned char note) {
  
    if (note == 90) {
        sendToneCmd(0, 0);
    }
    else if ((note >= 0) && (note < 20)) {
        sendToneCmd(2, note);
    }
    
    else if ((note >= 20) && (note < 40)) {
        sendToneCmd(3, note - 20);
    }
    
    else if ((note >= 40) && (note < 60)) {
        sendToneCmd(4, note - 40);
    }
    
    else if ((note >= 60) && (note < 80)) {
        sendToneCmd(5, note - 60);
    }
    
    else if ((note >= 80) && (note < 100)) {
        sendToneCmd(6, note - 80);
    }
}

void sendToneCmd(uint8_t octave, uint8_t note) {
    uint8_t actual_note = (note >= 7) ? note + 2: note + 1;
    uint8_t actual_octave = octave + 1;
    if ((octave == 0) && (note == 0)) { //Rest
        digitalWrite(BIT_2_PINOUT, LOW); 
        digitalWrite(BIT_1_PINOUT, LOW); 
        digitalWrite(BIT_0_PINOUT, LOW); 
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, HIGH);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
        digitalWrite(BIT_2_PINOUT, LOW); 
        digitalWrite(BIT_1_PINOUT, LOW); 
        digitalWrite(BIT_0_PINOUT, LOW); 
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, HIGH);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
    }
    else {
        digitalWrite(BIT_2_PINOUT, (actual_note & 0x04)?HIGH:LOW); 
        digitalWrite(BIT_1_PINOUT, (actual_note & 0x02)?HIGH:LOW); 
        digitalWrite(BIT_0_PINOUT, (actual_note & 0x01)?HIGH:LOW); 
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, HIGH);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
    
        digitalWrite(BIT_2_PINOUT, HIGH); 
        digitalWrite(BIT_1_PINOUT, (actual_note & 0x10)?HIGH:LOW); 
        digitalWrite(BIT_0_PINOUT, (actual_note & 0x08)?HIGH:LOW); 
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, HIGH);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
    
        digitalWrite(BIT_2_PINOUT, (actual_octave & 0x04)?HIGH:LOW); 
        digitalWrite(BIT_1_PINOUT, (actual_octave & 0x02)?HIGH:LOW); 
        digitalWrite(BIT_0_PINOUT, (actual_octave & 0x01)?HIGH:LOW); 
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, HIGH);  
        delayMicroseconds(10);
        digitalWrite(TRIG_PINOUT, LOW);  
        delayMicroseconds(10);
    }
}

__xdata unsigned long startToneMillis;
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
//        if (toneMsDelay > 0) {
//            digitalWrite(TONE_PINOUT, HIGH);   // turn the LED on (HIGH is the voltage level)
//            delayMicroseconds(toneMsDelay);                       // wait for a second
//            digitalWrite(TONE_PINOUT, LOW);    // turn the LED off by making the voltage LOW
//            delayMicroseconds(toneMsDelay);  
//        }
//        else
//            digitalWrite(TONE_PINOUT, LOW); 

        return 1;
   }
   else if ((millis() - startToneMillis) < (noteDuration + (noteDuration * 1.30)) ) {
   // to distinguish the notes, set a minimum time between them.
   // the note's duration + 30% seems to work well:
        playToneInf(REST);
        return 1;
   }
   else if (thisNote < sizeMusic) {
//        int noteDuration = 0;
        if (songNotes[(thisNote * 2) + 1] < 128) {
          // regular note, just proceed
          noteDuration = (getWholeNote()) / (songNotes[(thisNote * 2) + 1]);
        } else {// if (songNotes[(thisNote * 2) + 1] < 0) {
          noteDuration = (getWholeNote()) / ((songNotes[(thisNote * 2) + 1]) - 128);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }

        startToneMillis = millis();
        toneMsDelay = songNotes[(thisNote * 2)];
        if (toneMsDelay == REST)
            playToneInf(REST);
        else 
            playToneInf(toneMsDelay);
           
        thisNote += 1;
        return 1;
    }
    else {
      playToneInf(REST);
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
        
        button1FFlag = (button1tmp & 0x3F) == 0x38;  // On Press or Rising flag
        button2FFlag = (button2tmp & 0x3F) == 0x38;
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

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
     uint8_t i;
     for (i = 0; i < 8; i++)  {
           if (bitOrder == LSBFIRST)
                 digitalWrite(dataPin, !!(val & (1 << i)));
           else      
                 digitalWrite(dataPin, !!(val & (1 << (7 - i))));              
           digitalWrite(clockPin, HIGH);
           digitalWrite(clockPin, LOW);            
     }
}

void pixelLED(unsigned char ledPattern) {
   digitalWrite(Latch_PINOUT, LOW);
   shiftOut(Data_PINOUT, Clock_PINOUT, LSBFIRST, ~ledPattern);
   digitalWrite(Latch_PINOUT, HIGH);
}
