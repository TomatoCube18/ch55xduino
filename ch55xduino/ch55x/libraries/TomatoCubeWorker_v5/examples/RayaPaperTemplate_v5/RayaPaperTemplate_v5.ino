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

//Raya Song 4 - Balik Kampung
const PROGMEM char rayaSong2[] = {
  NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, 
  NOTE_C6, 2, NOTE_B5, 4, NOTE_A5, 8, NOTE_G5, 8, NOTE_B5, 4, NOTE_A5, 8, NOTE_G5, 8, NOTE_B5, 4, NOTE_A5, 8, 
  NOTE_G5, 8, NOTE_B5, 2, NOTE_A5, 4, NOTE_G5, 8, NOTE_F5, 8, NOTE_A5, 4, NOTE_G5, 8, NOTE_F5, 8, NOTE_A5, 4, 
  NOTE_G5, 8, NOTE_F5, 8, NOTE_A5, 2, NOTE_B5, 4, NOTE_A5, 8, NOTE_GS5, 8, NOTE_B5, 4, NOTE_A5, 8, NOTE_GS5, 8, 
  NOTE_B5, 4, NOTE_A5, 8, NOTE_GS5, 8, NOTE_B5, 2,NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_C6, 4, NOTE_B5, 8, 
  NOTE_A5, 8, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_C6, 2, NOTE_B5, 4, NOTE_A5, 8, NOTE_G5, 8, NOTE_B5, 4, 
  NOTE_A5, 8, NOTE_G5, 8, NOTE_B5, 4, NOTE_A5, 8, NOTE_G5, 8, NOTE_B5, 2, NOTE_A5, 4, NOTE_G5, 8, NOTE_F5, 8, 
  NOTE_A5, 4, NOTE_G5, 8, NOTE_F5, 8, NOTE_A5, 4, NOTE_G5, 8, NOTE_F5, 8, NOTE_A5, 2, NOTE_B5, 4, NOTE_A5, 8, 
  NOTE_GS5, 8, NOTE_B5, 4, NOTE_A5, 8, NOTE_GS5, 8 , NOTE_B5, 4, NOTE_A5, 8, NOTE_GS5, 8, NOTE_A5, 1, REST, 4, 
  NOTE_CS6, 4, NOTE_D6, 4, NOTE_E6, 4, NOTE_F6, 4, NOTE_E6, 8, NOTE_D6, 8, NOTE_F6, 2, REST, 4, NOTE_F6, 4, 
  NOTE_G6, 4, NOTE_F6, 4, NOTE_E6, 4, NOTE_D6, 8, NOTE_C6, 8, NOTE_E6, 2, REST, 4, NOTE_E6, 4, NOTE_F6, 4, 
  NOTE_E6, 4, NOTE_D6, 4, NOTE_C6, 8, NOTE_B5, 8, NOTE_D6, 2, REST, 4, NOTE_B5, 4, NOTE_C6, 4, NOTE_D6, 4, 
  NOTE_E6, 1, REST, 4, NOTE_CS6, 4, NOTE_D6, 4, NOTE_E6, 4, NOTE_F6, 4, NOTE_E6, 8, NOTE_D6, 8, NOTE_F6, 2, 
  REST, 4, NOTE_F6, 4, NOTE_G6, 4, NOTE_F6, 4, NOTE_E6, 4, NOTE_D6, 8, NOTE_C6, 8, NOTE_E6, 2, REST, 4, 
  NOTE_E6, 4, NOTE_F6, 4, NOTE_E6, 4, NOTE_D6, 4, NOTE_C6, 8, NOTE_B5, 8, NOTE_D6, 2 , REST, 4, NOTE_B5, 4, 
  NOTE_C6, 4, NOTE_B5, 4, NOTE_A5, 1
};

//Raya Song 3 - Suasana Hari Raya
const PROGMEM char rayaSong3[] = {
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

//Raya Song 2 - Chan mali Chan (Malaysia Folk)
const PROGMEM char chanMaliChan[] = {
  NOTE_C6, 8, NOTE_C6, 8, NOTE_C6, 8, NOTE_C6, 8, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_C6, 8, NOTE_B5, 8, 
  NOTE_A5, 8, NOTE_G5, 4, NOTE_G5, 8, NOTE_D6, 8, NOTE_D6, 8, NOTE_D6, 8, NOTE_D6, 8, NOTE_D6, 4, NOTE_C6, 8, 
  NOTE_D6, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_E6, 8, NOTE_D6, 8, NOTE_C6, 2 , REST, 4, NOTE_C6, 8, NOTE_C6, 8, 
  NOTE_C6, 8, NOTE_C6, 8, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_C6, 8, NOTE_B5, 8, NOTE_A5, 8, NOTE_G5, 4, 
  NOTE_G5, 8, NOTE_D6, 8, NOTE_D6, 8, NOTE_D6, 8, NOTE_D6, 8, NOTE_D6, 4, NOTE_C6, 8, NOTE_D6, 8, NOTE_E6, 8, 
  NOTE_F6, 8, NOTE_E6, 8, NOTE_D6, 8, NOTE_C6, 8, NOTE_C6, 8, NOTE_D6, 8, NOTE_E6, 8, NOTE_F6, 4, NOTE_F6, 8, 
  NOTE_F6, 8, NOTE_F6, 2, NOTE_E6, 4, NOTE_E6, 8, NOTE_E6, 8, NOTE_E6, 2, NOTE_D6, 4, NOTE_D6, 8, NOTE_D6, 8, 
  NOTE_D6, 4, NOTE_C6, 8, NOTE_D6, 8, NOTE_E6, 8, NOTE_F6, 8, NOTE_E6, 8, NOTE_D6, 8, NOTE_C6, 8, NOTE_C6, 8, 
  NOTE_D6, 8, NOTE_E6, 8, NOTE_F6, 4, NOTE_F6, 8, NOTE_F6, 8, NOTE_F6, 2, NOTE_E6, 4, NOTE_E6, 8, NOTE_E6, 8, 
  NOTE_E6, 2, NOTE_D6, 4, NOTE_D6, 8, NOTE_D6, 8, NOTE_D6, 4, NOTE_C6, 8, NOTE_D6, 8, NOTE_E6, 8, NOTE_F6, 8, 
  NOTE_E6, 8, NOTE_D6, 8, NOTE_C6, 2, REST, 4
};

//Raya Song 5 - Kakak Tua (Malaysia Folk)

const PROGMEM char kakakTua[] = {
  NOTE_G5, 8, NOTE_G5, 4, NOTE_E5, 8, NOTE_C6, 4, NOTE_E5, 8, NOTE_D5, 2, NOTE_E5, 8, NOTE_F5, 4, NOTE_A5, 8, 
  NOTE_G5, 4, NOTE_F5, 8, NOTE_E5, 2, REST, 4, NOTE_G5, 8, NOTE_G5, 4, NOTE_E5, 8, NOTE_C6, 4, NOTE_E5, 8, 
  NOTE_D5, 2, NOTE_B5, 8, NOTE_A5, 8, NOTE_G5, 4, NOTE_F5, 8, NOTE_E5, 4, NOTE_D5, 8, NOTE_C5, 2, REST, 8, 
  NOTE_G5, 8, NOTE_E5, 4, NOTE_G5, 8, NOTE_E5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_A5, 4, 
  NOTE_F5, 8, NOTE_D5, 4, NOTE_F5, 8, NOTE_D5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_G5, 8, NOTE_G5, 8, NOTE_G5, 4, 
  NOTE_G5, 8, NOTE_E5, 4, NOTE_G5, 8, NOTE_E5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_A5, 8, NOTE_D6, 4, 
  NOTE_C6, 8, NOTE_B5, 4, NOTE_G5, 8, NOTE_A5, 4, NOTE_B5, 8, NOTE_C6, 2, REST, 8
};

//Raya Song 6 - Rasa Sayang (Malaysia Folk)

const PROGMEM char rasaSayang[] = {
  NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 4, NOTE_G5, 4, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_G5, 8, 
  NOTE_E5, 8, NOTE_F5, 8, NOTE_G5, 4, NOTE_B5, 4, NOTE_A5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8, 
  NOTE_G5, 8, NOTE_C5, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_F5, 8, NOTE_B4, 8, NOTE_D5, 8, NOTE_C5, 4, NOTE_E5, 8, 
  NOTE_F5, 8, NOTE_G5, 4, NOTE_G5, 4, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_G5, 8, NOTE_E5, 8, 
  NOTE_F5, 8, NOTE_G5, 4, NOTE_B5, 4, NOTE_A5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8, NOTE_G5, 8, 
  NOTE_C5, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_F5, 8, NOTE_B4, 8, NOTE_D5, 8, NOTE_C5, 4, NOTE_E5, 8, NOTE_F5, 8, 
  NOTE_G5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 4, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 8, 
  NOTE_F5, 8, NOTE_E5, 4, NOTE_E5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_E5, 4, 
  NOTE_C5, 8, NOTE_E5, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_D5, 8, NOTE_C5, 4, NOTE_E5, 8, NOTE_F5, 8, 
  NOTE_G5, 4, NOTE_G5, 4, NOTE_C6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_F5, 8, 
  NOTE_G5, 4, NOTE_B5, 4, NOTE_A5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8, NOTE_G5, 8, NOTE_C5, 8, 
  NOTE_E5, 8, NOTE_D5, 8, NOTE_F5, 8, NOTE_B4, 8, NOTE_D5, 8, NOTE_C5, 4
};

//Bonus Song 7 - Doraemon OP (well...)

const PROGMEM char doraemon[] = {
  NOTE_D6, 144, NOTE_CS6, 144, NOTE_B5, 144, NOTE_A5, 144, NOTE_B5, 144, NOTE_CS6, 144, NOTE_D6, 144, NOTE_CS6, 144, 
  NOTE_B5, 144, NOTE_A5, 144, NOTE_B5, 144, NOTE_CS6, 144, NOTE_D6, 144, NOTE_CS6, 144, NOTE_B5, 144, NOTE_A5, 144, 
  NOTE_B5, 144, NOTE_CS6, 144, NOTE_D6, 144, NOTE_CS6, 144, NOTE_B5, 144, NOTE_A5, 4 , NOTE_E6, 144, NOTE_D6, 144, 
  NOTE_CS6, 144, NOTE_B5, 144, NOTE_CS6, 144, NOTE_D6, 144, NOTE_E6, 144, NOTE_D6, 144, NOTE_CS6, 144, NOTE_B5, 144, 
  NOTE_CS6, 144, NOTE_D6, 144, NOTE_E6, 144, NOTE_D6, 144, NOTE_CS6, 144, NOTE_B5, 144, NOTE_CS6, 144, NOTE_D6, 144, 
  NOTE_CS6, 144, NOTE_D6, 144, NOTE_DS6, 144, NOTE_E6, 4, NOTE_B6, 144, NOTE_CS7, 144, NOTE_D7, 144, NOTE_G6, 144, 
  NOTE_A6, 144, NOTE_B6, 144, NOTE_A6, 144, NOTE_B6, 144, NOTE_CS7, 144, NOTE_FS6, 144, NOTE_G6, 144, NOTE_A6, 144, 
  NOTE_G6, 144, NOTE_A6, 144, NOTE_B6, 144, NOTE_E6, 144, NOTE_FS6, 144, NOTE_G6, 144, NOTE_FS6, 144, NOTE_G6, 144, 
  NOTE_A6, 144, NOTE_D6, 144, NOTE_E6, 144, NOTE_FS6, 144, NOTE_E6, 144, NOTE_DS6, 144, NOTE_D6, 144, NOTE_CS6, 144, 
  NOTE_C6, 144, NOTE_B5, 144, NOTE_AS5, 144, NOTE_A5, 144, NOTE_GS5, 144, NOTE_G5, 144, NOTE_FS5, 144, NOTE_F5, 144, 
  NOTE_E5, 132, REST, 4, REST, 2, NOTE_A4, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_FS5, 8, NOTE_B5, 8, NOTE_FS5, 8, NOTE_A5, 4, 
  NOTE_A5, 8, NOTE_B5, 8, NOTE_A5, 8, NOTE_FS5, 8, NOTE_G5, 8, NOTE_FS5, 8, NOTE_E5, 4, NOTE_B4, 8, NOTE_E5, 8, 
  NOTE_E5, 8, NOTE_G5, 8, NOTE_CS6, 8, NOTE_CS6, 8, NOTE_B5, 8, NOTE_A5, 8 , NOTE_G5, 4, NOTE_G5, 8, NOTE_FS5, 8, 
  NOTE_B4, 8, NOTE_CS5, 4, NOTE_D5, 8, NOTE_E5, 130, REST, 4, NOTE_A4, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_FS5, 8, 
  NOTE_B5, 8, NOTE_FS5, 8, NOTE_A5, 4, NOTE_A5, 8, NOTE_B5, 8, NOTE_A5, 8, NOTE_FS5, 8, NOTE_G5, 8, NOTE_FS5, 8, 
  NOTE_E5, 4, NOTE_B4, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_G5, 8, NOTE_CS6, 4, NOTE_B5, 8, NOTE_A5, 8, NOTE_G5, 8, 
  NOTE_G5, 8, NOTE_FS5, 8, NOTE_E5, 8, NOTE_CS5, 4, NOTE_E5, 4, NOTE_D5, 130, REST, 4, NOTE_B5, 4, NOTE_B5, 8, 
  NOTE_A5, 8, NOTE_G5, 144, NOTE_A5, 144, NOTE_B5, 144, NOTE_A5, 4, NOTE_E5, 8, NOTE_FS5, 8, NOTE_GS5, 8, NOTE_E5, 8, 
  NOTE_A5, 4, REST, 4, NOTE_B5, 4, NOTE_A5, 4, NOTE_E5, 8, NOTE_FS5, 8, NOTE_GS5, 8, NOTE_E5, 8, NOTE_A5, 130, REST, 4, 
  NOTE_B5, 4, NOTE_A5, 4, NOTE_G5, 4, REST, 4, NOTE_E5, 4, NOTE_CS6, 8, NOTE_B5, 8, NOTE_A5, 8, NOTE_B5, 8, NOTE_A5, 8, 
  NOTE_G5, 8, REST, 4, NOTE_A5, 8, NOTE_B5, 8, NOTE_FS5, 132, NOTE_E5, 8, NOTE_D5, 130, REST, 4
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

// the loop function runs over and over again forever
void loop() {

// Code for ButtonPress & LDR (Light)

      sensorLDRValue = analogRead(LDR_PINOUT);
      buttonBuffer = (buttonBuffer << 1) | (digitalRead(SWITCH_PINOUT) & 0x01);

      if ((buttonBuffer & 0x3F) == 0) {   // If ButtonPressed is detected
          
          if ((millis()/100) % 2)   // Flash LED every 100ms
              digitalWrite(LED_BUILTIN, HIGH);
          else 
              digitalWrite(LED_BUILTIN, LOW);
              
      }
      
      else if (sensorLDRValue > 180) {    // If ambient light is detected, day time -> roughly 180. (255 max)
          
          if ((millis()/2000) % 2)  // Flash LED every 2000ms (2s)
              digitalWrite(LED_BUILTIN, HIGH);
          else 
              digitalWrite(LED_BUILTIN, LOW);
              
      }
      
      else {                              // If No Button Pressed & in a Dark Room/Night
        
          if ((millis()/500) % 2)   // Flash LED every 500ms (0.5s)
              digitalWrite(LED_BUILTIN, HIGH);
          else 
              digitalWrite(LED_BUILTIN, LOW);
              
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
              break;
              case 152:   // < Up >
                  playTone(TONE_PINOUT, NOTE_E5, 50) ;
                  playTone(TONE_PINOUT, REST, 10) ;
                  delay(5);
              break;
              case 24:  // < Down >
                  playTone(TONE_PINOUT, NOTE_D5, 50) ;
                  playTone(TONE_PINOUT, REST, 10) ;
                  delay(5);
              break;
              default:   
              break;
          }
        }     
    }   


// Code for CapTouch Switch.

      scanTouchButton();  // Update Capacitive Touch status
      if (getTouchB1Transition() == 1) {
          lastFingerPressed = millis(); // Optional: Capture finger press time for Press & Hold
          if (getTouchB2State()) {  // Button2 remained Touch when Button1 is released
              adjustTempo(210);
              sendMusicNotes(rasaSayang, sizeof(rasaSayang));
          }
          else {    // Button1 Touch & released
              adjustTempo(210); 
              sendMusicNotes(rayaSong1, sizeof(rayaSong1));
          }
      }
      else if (getTouchB2Transition() == 1) {
          lastFingerPressed = millis(); // Optional: Capture finger press time for Press & Hold
          adjustTempo(210);
          if (getTouchB1State()) {  // Button1 remained Touch when Button2 is released
              adjustTempo(210);
              sendMusicNotes(rayaSong3, sizeof(rayaSong3));
          }
          else {    // Button2 Touch & released
              adjustTempo(210);
              sendMusicNotes(rayaSong2, sizeof(rayaSong2));
          }
      }

      // Note: Optional, just for double press & hold
      else if ((getTouchB1Transition() == -1) || (getTouchB2Transition() == -1)) {  // Reset Touch Timer when any finger is released.
          lastFingerPressed = 0;
      }
      else if ((lastFingerPressed != 0) && (millis() - lastFingerPressed >= 5000)) {  // Press 2 buttons & hold for 5 seconds
          lastFingerPressed = 0;
          sendMusicNotes(doraemon, 0);   
          playTone(TONE_PINOUT, NOTE_E5, 50) ;
          playTone(TONE_PINOUT, REST, 20) ;
          playTone(TONE_PINOUT, NOTE_D5, 50) ;
          playTone(TONE_PINOUT, REST, 500) ;
          sendMusicNotes(doraemon, sizeof(doraemon));   
      }


// Code for Music Playback, Call repeatedly.
     
    if (playMusic()) {     // If music is playing
        // Do something while music is playing
    }
    else {
        // Do something if music stop playing     
    }
    
    
}
