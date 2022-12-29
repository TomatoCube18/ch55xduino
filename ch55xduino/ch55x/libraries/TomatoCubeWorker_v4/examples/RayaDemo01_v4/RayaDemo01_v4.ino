#include "TomatoCubeWorker_v4.h"

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

//Raya Song 4 - Balik Kampung
const PROGMEM char rayaSong2[] = {
  NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, 
  NOTE_C5, 2, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_B4, 4, NOTE_A4, 8, 
  NOTE_G4, 8, NOTE_B4, 2, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_A4, 4, 
  NOTE_G4, 8, NOTE_F4, 8, NOTE_A4, 2, NOTE_B4, 4, NOTE_A4, 8, NOTE_GS4, 8, NOTE_B4, 4, NOTE_A4, 8, NOTE_GS4, 8, 
  NOTE_B4, 4, NOTE_A4, 8, NOTE_GS4, 8, NOTE_B4, 2,NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_B4, 8, 
  NOTE_A4, 8, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 2, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_B4, 4, 
  NOTE_A4, 8, NOTE_G4, 8, NOTE_B4, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_B4, 2, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 8, 
  NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_A4, 2, NOTE_B4, 4, NOTE_A4, 8, 
  NOTE_GS4, 8, NOTE_B4, 4, NOTE_A4, 8, NOTE_GS4, 8 , NOTE_B4, 4, NOTE_A4, 8, NOTE_GS4, 8, NOTE_A4, 1, REST, 4, 
  NOTE_CS5, 4, NOTE_D5, 4, NOTE_E5, 4, NOTE_F5, 4, NOTE_E5, 8, NOTE_D5, 8, NOTE_F5, 2, REST, 4, NOTE_F5, 4, 
  NOTE_G5, 4, NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 8, NOTE_C5, 8, NOTE_E5, 2, REST, 4, NOTE_E5, 4, NOTE_F5, 4, 
  NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_B4, 8, NOTE_D5, 2, REST, 4, NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4, 
  NOTE_E5, 1, REST, 4, NOTE_CS5, 4, NOTE_D5, 4, NOTE_E5, 4, NOTE_F5, 4, NOTE_E5, 8, NOTE_D5, 8, NOTE_F5, 2, 
  REST, 4, NOTE_F5, 4, NOTE_G5, 4, NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 8, NOTE_C5, 8, NOTE_E5, 2, REST, 4, 
  NOTE_E5, 4, NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_B4, 8, NOTE_D5, 2 , REST, 4, NOTE_B4, 4, 
  NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 1
};

//Raya Song 3 - Suasana Hari Raya
const PROGMEM char rayaSong3[] = {
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


//Raya Song 2 - Chan mali Chan (Malaysia Folk)
const PROGMEM char chanMaliChan[] = {
  NOTE_C5, 8, NOTE_C5, 8, NOTE_C5, 8, NOTE_C5, 8, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_B4, 8, 
  NOTE_A4, 8, NOTE_G4, 4, NOTE_G4, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 4, NOTE_C5, 8, 
  NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 2 , REST, 4, NOTE_C5, 8, NOTE_C5, 8, 
  NOTE_C5, 8, NOTE_C5, 8, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 4, 
  NOTE_G4, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, 
  NOTE_F5, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 4, NOTE_F5, 8, 
  NOTE_F5, 8, NOTE_F5, 2, NOTE_E5, 4, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 2, NOTE_D5, 4, NOTE_D5, 8, NOTE_D5, 8, 
  NOTE_D5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_C5, 8, 
  NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 4, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 2, NOTE_E5, 4, NOTE_E5, 8, NOTE_E5, 8, 
  NOTE_E5, 2, NOTE_D5, 4, NOTE_D5, 8, NOTE_D5, 8, NOTE_D5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, 
  NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 2, REST, 4
};

//Raya Song 5 - Kakak Tua (Malaysia Folk)

const PROGMEM char kakakTua[] = {
  NOTE_G4, 8, NOTE_G4, 4, NOTE_E4, 8, NOTE_C5, 4, NOTE_E4, 8, NOTE_D4, 2, NOTE_E4, 8, NOTE_F4, 4, NOTE_A4, 8, 
  NOTE_G4, 4, NOTE_F4, 8, NOTE_E4, 2, REST, 4, NOTE_G4, 8, NOTE_G4, 4, NOTE_E4, 8, NOTE_C5, 4, NOTE_E4, 8, 
  NOTE_D4, 2, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 4, NOTE_F4, 8, NOTE_E4, 4, NOTE_D4, 8, NOTE_C4, 2, REST, 8, 
  NOTE_G4, 8, NOTE_E4, 4, NOTE_G4, 8, NOTE_E4, 4, NOTE_G4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_A4, 4, 
  NOTE_F4, 8, NOTE_D4, 4, NOTE_F4, 8, NOTE_D4, 4, NOTE_F4, 8, NOTE_G4, 8, NOTE_G4, 8, NOTE_G4, 8, NOTE_G4, 4, 
  NOTE_G4, 8, NOTE_E4, 4, NOTE_G4, 8, NOTE_E4, 4, NOTE_G4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_D5, 4, 
  NOTE_C5, 8, NOTE_B4, 4, NOTE_G4, 8, NOTE_A4, 4, NOTE_B4, 8, NOTE_C5, 2, REST, 8
};

//Raya Song 6 - Rasa Sayang (Malaysia Folk)

const PROGMEM char rasaSayang[] = {
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_G4, 8, 
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_B4, 4, NOTE_A4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, 
  NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_B3, 8, NOTE_D4, 8, NOTE_C4, 4, NOTE_E4, 8, 
  NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_G4, 8, NOTE_E4, 8, 
  NOTE_F4, 8, NOTE_G4, 4, NOTE_B4, 4, NOTE_A4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, 
  NOTE_C4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_B3, 8, NOTE_D4, 8, NOTE_C4, 4, NOTE_E4, 8, NOTE_F4, 8, 
  NOTE_G4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_G4, 4, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_E4, 8, 
  NOTE_F4, 8, NOTE_E4, 4, NOTE_E4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_E4, 4, 
  NOTE_C4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8, NOTE_B3, 8, NOTE_D4, 8, NOTE_C4, 4, NOTE_E4, 8, NOTE_F4, 8, 
  NOTE_G4, 4, NOTE_G4, 4, NOTE_C5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, 
  NOTE_G4, 4, NOTE_B4, 4, NOTE_A4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_C4, 8, 
  NOTE_E4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_B3, 8, NOTE_D4, 8, NOTE_C4, 4
};

//Bonus Song 7 - Doraemon OP (well...)

const PROGMEM char doraemon[] = {
  NOTE_D5, 144, NOTE_CS5, 144, NOTE_B4, 144, NOTE_A4, 144, NOTE_B4, 144, NOTE_CS5, 144, NOTE_D5, 144, NOTE_CS5, 144, 
  NOTE_B4, 144, NOTE_A4, 144, NOTE_B4, 144, NOTE_CS5, 144, NOTE_D5, 144, NOTE_CS5, 144, NOTE_B4, 144, NOTE_A4, 144, 
  NOTE_B4, 144, NOTE_CS5, 144, NOTE_D5, 144, NOTE_CS5, 144, NOTE_B4, 144, NOTE_A4, 4 , NOTE_E5, 144, NOTE_D5, 144, 
  NOTE_CS5, 144, NOTE_B4, 144, NOTE_CS5, 144, NOTE_D5, 144, NOTE_E5, 144, NOTE_D5, 144, NOTE_CS5, 144, NOTE_B4, 144, 
  NOTE_CS5, 144, NOTE_D5, 144, NOTE_E5, 144, NOTE_D5, 144, NOTE_CS5, 144, NOTE_B4, 144, NOTE_CS5, 144, NOTE_D5, 144, 
  NOTE_CS5, 144, NOTE_D5, 144, NOTE_DS5, 144, NOTE_E5, 4, NOTE_B5, 144, NOTE_CS6, 144, NOTE_D6, 144, NOTE_G5, 144, 
  NOTE_A5, 144, NOTE_B5, 144, NOTE_A5, 144, NOTE_B5, 144, NOTE_CS6, 144, NOTE_FS5, 144, NOTE_G5, 144, NOTE_A5, 144, 
  NOTE_G5, 144, NOTE_A5, 144, NOTE_B5, 144, NOTE_E5, 144, NOTE_FS5, 144, NOTE_G5, 144, NOTE_FS5, 144, NOTE_G5, 144, 
  NOTE_A5, 144, NOTE_D5, 144, NOTE_E5, 144, NOTE_FS5, 144, NOTE_E5, 144, NOTE_DS5, 144, NOTE_D5, 144, NOTE_CS5, 144, 
  NOTE_C5, 144, NOTE_B4, 144, NOTE_AS4, 144, NOTE_A4, 144, NOTE_GS4, 144, NOTE_G4, 144, NOTE_FS4, 144, NOTE_F4, 144, 
  NOTE_E4, 132, REST, 4, REST, 2, NOTE_A3, 8, NOTE_D4, 8, NOTE_D4, 8, NOTE_FS4, 8, NOTE_B4, 8, NOTE_FS4, 8, NOTE_A4, 4, 
  NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_FS4, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_E4, 4, NOTE_B3, 8, NOTE_E4, 8, 
  NOTE_E4, 8, NOTE_G4, 8, NOTE_CS5, 8, NOTE_CS5, 8, NOTE_B4, 8, NOTE_A4, 8 , NOTE_G4, 4, NOTE_G4, 8, NOTE_FS4, 8, 
  NOTE_B3, 8, NOTE_CS4, 4, NOTE_D4, 8, NOTE_E4, 130, REST, 4, NOTE_A3, 8, NOTE_D4, 8, NOTE_D4, 8, NOTE_FS4, 8, 
  NOTE_B4, 8, NOTE_FS4, 8, NOTE_A4, 4, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_FS4, 8, NOTE_G4, 8, NOTE_FS4, 8, 
  NOTE_E4, 4, NOTE_B3, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_CS5, 4, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8, 
  NOTE_G4, 8, NOTE_FS4, 8, NOTE_E4, 8, NOTE_CS4, 4, NOTE_E4, 4, NOTE_D4, 130, REST, 4, NOTE_B4, 4, NOTE_B4, 8, 
  NOTE_A4, 8, NOTE_G4, 144, NOTE_A4, 144, NOTE_B4, 144, NOTE_A4, 4, NOTE_E4, 8, NOTE_FS4, 8, NOTE_GS4, 8, NOTE_E4, 8, 
  NOTE_A4, 4, REST, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_E4, 8, NOTE_FS4, 8, NOTE_GS4, 8, NOTE_E4, 8, NOTE_A4, 130, REST, 4, 
  NOTE_B4, 4, NOTE_A4, 4, NOTE_G4, 4, REST, 4, NOTE_E4, 4, NOTE_CS5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, 
  NOTE_G4, 8, REST, 4, NOTE_A4, 8, NOTE_B4, 8, NOTE_FS4, 132, NOTE_E4, 8, NOTE_D4, 130, REST, 4
};

unsigned char leftTotal = 0;
unsigned char rightTotal = 0;
bool inGameMode = true;
bool firstRunMusic = true;
unsigned char firstRunTune = 0;

unsigned long lastLEDMillis = 0;
unsigned char LEDStatus = LOW;

unsigned char randomLEDSeq[23] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0xFF, 0x00, 0xFF, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x04, 0x10, 0x40, 0x01, 0x00};
unsigned char currentLEDPattern = 0;

unsigned char lastSongPressed = 0;
unsigned long lastFingerPressed = 0;

void generateLEDSequence() {
    srand(millis());
    for (int i = 0; i < 20; i ++) {
        randomLEDSeq[i] = rand() % 0xFF;
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
  

  lastLEDMillis = millis();
}

// the loop function runs over and over again forever
void loop() {


    if (inGameMode) {
        scanTouchButton();
           if (getTouchB1Transition() == 1) {
              
                leftTotal += 1;
                if (leftTotal > 3) {
                    if (rightTotal == 4) {
                        inGameMode = false;
                        firstRunTune = 0;
                        srand(millis());
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
                if (rightTotal > 4) {
                    if (leftTotal == 3) {
                        inGameMode = false;
                        firstRunTune = 1;
                        srand(millis());
                        playTone(TONE_PINOUT, NOTE_E5, 50) ;
                        playTone(TONE_PINOUT, REST, 20) ;
                        playTone(TONE_PINOUT, NOTE_D5, 50) ;
                        playTone(TONE_PINOUT, REST, 500) ;
                        
                    }
                    else
                        rightTotal = 0;
                }
           }

          pixelLED(((leftTotal == 1)? 0x01: (leftTotal == 2)? 0x03: (leftTotal == 3)? 0x7: 0x00) | ((rightTotal == 1)? 0x08: (rightTotal == 2)? 0x28: (rightTotal == 3)? 0x38: (rightTotal == 4)? 0x78: 0x00) );    
    }
    else {
          scanTouchButton();
          if (firstRunMusic) {
              adjustTempo(210);
              sendMusicNotes(firstRunTune? rayaSong1: rayaSong2, firstRunTune? sizeof(rayaSong1) : sizeof(rayaSong2));
              lastSongPressed = firstRunTune;
              generateLEDSequence();
              firstRunMusic = false;
          }
          else if (getTouchB1Transition() == 1) {
              lastFingerPressed = millis();
              adjustTempo(210);
              if (getTouchB2State())
                sendMusicNotes(rasaSayang, sizeof(rasaSayang));
              else {
                sendMusicNotes((lastSongPressed != 0)? rayaSong2: chanMaliChan, (lastSongPressed != 0)? sizeof(rayaSong2) : sizeof(chanMaliChan));
                lastSongPressed = (lastSongPressed != 0)? 0: 2;
//                sendMusicNotes(rayaSong2, sizeof(rayaSong2));
              }
              generateLEDSequence();
              
          }
          else if (getTouchB2Transition() == 1) {
              lastFingerPressed = millis();
              adjustTempo(210);
              if (getTouchB1State())
                sendMusicNotes(kakakTua, sizeof(kakakTua));
              else {
                sendMusicNotes((lastSongPressed != 1)? rayaSong1: rayaSong3, (lastSongPressed != 1)? sizeof(rayaSong1) : sizeof(rayaSong3));
                lastSongPressed = (lastSongPressed != 1)? 1: 3;
//                sendMusicNotes(rayaSong1, sizeof(rayaSong1));
              }
              generateLEDSequence();
              //stopMusic();             
          }
          else if ((getTouchB1Transition() == -1) || (getTouchB2Transition() == -1)) {
              lastFingerPressed = 0;
          }
          else if ((lastFingerPressed != 0) && (millis() - lastFingerPressed >= 5000)) {
              lastFingerPressed = 0;
              sendMusicNotes(doraemon, 0);   
              playTone(TONE_PINOUT, NOTE_E5, 50) ;
              playTone(TONE_PINOUT, REST, 20) ;
              playTone(TONE_PINOUT, NOTE_D5, 50) ;
              playTone(TONE_PINOUT, REST, 500) ;
              sendMusicNotes(doraemon, sizeof(doraemon));   
          }
       
          if (!playMusic()) {     // If music is not playing
            if (millis() - lastLEDMillis >= 500) {
                    pixelLED(getRandomLED());
                    lastLEDMillis = millis(); 
              }
//                if (millis() - lastLEDMillis >= 1000) {
//                    pixelLED(0x00);
//                    lastLEDMillis = millis();
//                    LEDStatus = (LEDStatus == LOW)? HIGH: LOW;
//                    pixelLED(LEDStatus? 0x01: 0x00);     
//                }
          }
          else {
              if (millis() - lastLEDMillis >= 250) {
                    pixelLED(getRandomLED());
                    lastLEDMillis = millis(); 
              }
                    
          }
    
    }  
}
