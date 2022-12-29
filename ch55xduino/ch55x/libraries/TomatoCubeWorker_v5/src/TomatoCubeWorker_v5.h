#include <TouchKey.h>
#include <WS2812.h>



#define NOTE_B0  1
#define NOTE_C1  2
#define NOTE_CS1 3
#define NOTE_D1  4
#define NOTE_DS1 5
#define NOTE_E1  6
#define NOTE_F1  7
#define NOTE_FS1 8
#define NOTE_G1  9
#define NOTE_GS1 10
#define NOTE_A1  11
#define NOTE_AS1 12
#define NOTE_B1  13
#define NOTE_C2  14
#define NOTE_CS2 15
#define NOTE_D2  16
#define NOTE_DS2 17
#define NOTE_E2  18
#define NOTE_F2  19
#define NOTE_FS2 20
#define NOTE_G2  21
#define NOTE_GS2 22
#define NOTE_A2  23
#define NOTE_AS2 24
#define NOTE_B2  25
#define NOTE_C3  26
#define NOTE_CS3 27
#define NOTE_D3  28
#define NOTE_DS3 29
#define NOTE_E3  30
#define NOTE_F3  31
#define NOTE_FS3 32
#define NOTE_G3  33
#define NOTE_GS3 34
#define NOTE_A3  35
#define NOTE_AS3 36
#define NOTE_B3  37
#define NOTE_C4  38
#define NOTE_CS4 39
#define NOTE_D4  40
#define NOTE_DS4 41
#define NOTE_E4  42
#define NOTE_F4  43
#define NOTE_FS4 44
#define NOTE_G4  45
#define NOTE_GS4 46
#define NOTE_A4  47
#define NOTE_AS4 48
#define NOTE_B4  49
#define NOTE_C5  50
#define NOTE_CS5 51
#define NOTE_D5  52
#define NOTE_DS5 53
#define NOTE_E5  54
#define NOTE_F5  55
#define NOTE_FS5 56
#define NOTE_G5  57
#define NOTE_GS5 58
#define NOTE_A5  59
#define NOTE_AS5 60
#define NOTE_B5  61
#define NOTE_C6  62
#define NOTE_CS6 63
#define NOTE_D6  64
#define NOTE_DS6 65
#define NOTE_E6  66
#define NOTE_F6  67
#define NOTE_FS6 68
#define NOTE_G6  69
#define NOTE_GS6 70
#define NOTE_A6  71
#define NOTE_AS6 72
#define NOTE_B6  73
#define NOTE_C7  74
#define NOTE_CS7 75
#define NOTE_D7  76
#define NOTE_DS7 77
#define NOTE_E7  78
#define NOTE_F7  79
#define NOTE_FS7 80
#define NOTE_G7  81
#define NOTE_GS7 82
#define NOTE_A7  83
#define NOTE_AS7 84
#define NOTE_B7  85
#define NOTE_C8  86
#define NOTE_CS8 87
#define NOTE_D8  88
#define NOTE_DS8 89
#define REST     90

#define LED_BUILTIN 17
#define TONE_PINOUT 34
#define RGB_PINOUT 16

#define LDR_PINOUT    15
#define SWITCH_PINOUT 33
#define IR_PINOUT     32



#define NUM_LEDS 5
#define COLOR_PER_LEDS 3
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)


void initTomatoCube();

//void runTomatoCubeFSM();
void sendMusicNotes(char *musicNotes, int musicSize);
int playMusic();
void stopMusic();

int freqLookup(unsigned char note);
void setHWSync(uint8_t enableHw);
void playTone(int pinToneOut, unsigned char note, int duration);
void adjustTempo(unsigned int _songTempo);
int getWholeNote();

void scanTouchButton();
uint8_t getTouchB1State();
uint8_t getTouchB2State();
int8_t getTouchB1Transition();
int8_t getTouchB2Transition();

void int0IRCallback();
int isIR_Received();
unsigned int getIRCommand();
unsigned int getIRAddress();

void setStarRGB(uint8_t _led, uint8_t _red, uint8_t _green, uint8_t _blue, uint8_t pushSeqNow);
