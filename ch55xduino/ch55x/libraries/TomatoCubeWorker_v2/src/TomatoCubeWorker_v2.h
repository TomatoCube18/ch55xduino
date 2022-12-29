#include <TouchKey.h>
#include <WS2812.h>


#define NOTE_C2  0
#define NOTE_CS2 1
#define NOTE_D2  2
#define NOTE_DS2 3
#define NOTE_E2  4
#define NOTE_F2  5
#define NOTE_FS2 6
#define NOTE_G2  7
#define NOTE_GS2 8
#define NOTE_A2  9
#define NOTE_AS2 10
#define NOTE_B2  11
#define NOTE_C3  20
#define NOTE_CS3 21
#define NOTE_D3  22
#define NOTE_DS3 23
#define NOTE_E3  24
#define NOTE_F3  25
#define NOTE_FS3 26
#define NOTE_G3  27
#define NOTE_GS3 28
#define NOTE_A3  29
#define NOTE_AS3 30
#define NOTE_B3  31
#define NOTE_C4  40
#define NOTE_CS4 41
#define NOTE_D4  42
#define NOTE_DS4 43
#define NOTE_E4  44
#define NOTE_F4  45
#define NOTE_FS4 46
#define NOTE_G4  47
#define NOTE_GS4 48
#define NOTE_A4  49
#define NOTE_AS4 50
#define NOTE_B4  51
#define NOTE_C5  60
#define NOTE_CS5 61
#define NOTE_D5  62
#define NOTE_DS5 63
#define NOTE_E5  64
#define NOTE_F5  65
#define NOTE_FS5 66
#define NOTE_G5  67
#define NOTE_GS5 68
#define NOTE_A5  69
#define NOTE_AS5 70
#define NOTE_B5  71
#define NOTE_C6  72
#define NOTE_CS6 73
#define NOTE_D6  74
#define NOTE_DS6 75
#define NOTE_E6  76
#define NOTE_F6  77
#define NOTE_FS6 78
#define NOTE_G6  79
#define NOTE_GS6 80
#define NOTE_A6  81
#define NOTE_AS6 82
#define NOTE_B6  83
#define REST     90

#define RGB_PINOUT 15

#define BIT_0_PINOUT  34
#define BIT_1_PINOUT  16
#define BIT_2_PINOUT  17
#define TRIG_PINOUT   33

#define Data_PINOUT   32
#define Clock_PINOUT  31
#define Latch_PINOUT  30

#define TONE_PINOUT 0   //Dummy

#define NUM_LEDS 1
#define COLOR_PER_LEDS 3
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)


void initTomatoCube();

//void runTomatoCubeFSM();
void sendMusicNotes(char *musicNotes, int musicSize);
int playMusic();
void stopMusic();

void playTone(int pinToneOut, unsigned char note, int duration);
int playToneInf(unsigned char note);
void sendToneCmd(uint8_t octave, uint8_t note);

void adjustTempo(unsigned int _songTempo);
int getWholeNote();

void scanTouchButton();
uint8_t getTouchB1State();
uint8_t getTouchB2State();
int8_t getTouchB1Transition();
int8_t getTouchB2Transition();

void setStarRGB(uint8_t _red, uint8_t _green, uint8_t _blue);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
void pixelLED(unsigned char ledPattern);
