#include "TomatoCubeWorker_v4.h"

//Raya Song 1
const PROGMEM char rayaSong1[] = {
  REST, 1,
  
  NOTE_F4, 2, NOTE_C5, 8, NOTE_B4, 8, NOTE_F4, 4, NOTE_GS4, 4,
  NOTE_D4, 4, NOTE_G4, 4, NOTE_C4, 8, NOTE_E4, 4,
  NOTE_F4, 2, NOTE_C5, 8, NOTE_B4, 8, NOTE_F4, 4, NOTE_GS4, 4,
  NOTE_D4, 4, NOTE_G4, 4, NOTE_C4, 8, NOTE_E4, 4, NOTE_F4, 3, REST, 8, NOTE_F4, 4, REST, 4,

  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_C4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_D5, 8,
  NOTE_C5, 8, NOTE_AS4, 8, NOTE_A4, 2, REST, 4,
  
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_AS4, 4,
  NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8,
  NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 2, REST, 4,

  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_C4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_D5, 8,
  NOTE_C5, 8, NOTE_AS4, 8, NOTE_A4, 2, REST, 4,
  
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_AS4, 4,
  NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8,
  NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 2, REST, 4,
  
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 4, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_C5, 8,
  NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4 , NOTE_E4, 8,
  NOTE_D4, 8, NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8,
  NOTE_A4, 8, NOTE_C5, 2, REST, 8,
  
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 4, NOTE_G4, 8, NOTE_A4, 8,
  NOTE_AS4, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_F5, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_F4, 4, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8, NOTE_D4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8,
  NOTE_AS4, 8, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 2, REST, 8,
  
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8,NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 2,
  NOTE_C4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_G4, 8,
  NOTE_A4, 8, NOTE_AS4, 8, NOTE_D5, 8, NOTE_C5, 8, NOTE_AS4, 8, NOTE_A4, 2, REST, 4,
  
  NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 2, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_C5, 4, NOTE_AS4, 4,
  NOTE_G4, 8, NOTE_A4, 8, NOTE_AS4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_F4, 2, REST, 4,

  NOTE_A4, 8, NOTE_AS4, 8, NOTE_C5, 2, NOTE_C5, 2, NOTE_D5, 2, NOTE_E5, 2, NOTE_F5, 1,
};

//Raya Song 2
const PROGMEM char rayaSong2[] = {
  REST, 1,
  
  NOTE_B4, 4, NOTE_B4, 8, NOTE_C5, 4, NOTE_D5, 4, NOTE_E5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_D5, 8,
  NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_B4, 8,
  NOTE_C5, 4, NOTE_C5, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 2,
  REST, 8,
  
  NOTE_B4, 4, NOTE_B4, 8, NOTE_C5, 4, NOTE_D5, 4, NOTE_E5, 8, NOTE_D5, 8, NOTE_E5, 8, NOTE_D5, 8,
  NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_FS4, 4, REST, 8, NOTE_G4, 8, NOTE_G4, 1, REST, 8, 

  NOTE_B4, 4, NOTE_B4, 8, NOTE_B4, 4, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 3, NOTE_B4, 8, NOTE_A4, 4, NOTE_A4, 2,
  NOTE_A4, 4, NOTE_A4, 8, NOTE_A4, 6, NOTE_B4, 6, NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 2,
  NOTE_B4, 4, NOTE_B4, 8, NOTE_B4, 4, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 3, NOTE_B4, 8, NOTE_A4, 4, NOTE_A4, 2,
  NOTE_A4, 4, NOTE_A4, 8, NOTE_A4, 6, NOTE_B4, 6, NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 2,

  NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4, NOTE_E5, 3, NOTE_D5, 8, NOTE_C5, 4, NOTE_C5, 2,
  NOTE_A4, 4, NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 3, NOTE_C5, 8, NOTE_B4, 4, NOTE_B4, 2,
  NOTE_G4, 4, NOTE_A4, 4, NOTE_B4, 4, NOTE_C5, 3, NOTE_B4, 8, NOTE_A4, 4, NOTE_A4, 4,
  NOTE_FS4, 6, NOTE_FS4, 6, NOTE_FS4, 8, NOTE_FS4, 4, NOTE_E4, 6, NOTE_FS4, 8, NOTE_G4, 1,

  NOTE_B4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 2,
  NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_D4, 8, NOTE_G4, 8, NOTE_B4, 8, NOTE_A4, 6, NOTE_A4, 6, NOTE_G4, 8, NOTE_FS4, 6, NOTE_G4, 6,
  NOTE_A4, 8, NOTE_B4, 2,

  NOTE_B4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 2,
  NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_D4, 8, NOTE_G4, 8, NOTE_B4, 8, NOTE_A4, 6, NOTE_A4, 6, NOTE_G4, 8, NOTE_FS4, 6, NOTE_E4, 6,
  NOTE_FS4, 8, NOTE_G4, 2,

  NOTE_B4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 2,
  NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_D4, 8, NOTE_G4, 8, NOTE_B4, 8, NOTE_A4, 6, NOTE_A4, 6, NOTE_G4, 8, NOTE_FS4, 6, NOTE_G4, 6,
  NOTE_A4, 8, NOTE_B4, 2,

  NOTE_B4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 2,
  NOTE_C5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, 8, NOTE_C5, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_G4, 8,
  NOTE_D4, 8, NOTE_G4, 8, NOTE_B4, 8, NOTE_A4, 6, NOTE_A4, 6, NOTE_G4, 8, NOTE_FS4, 6, NOTE_E4, 6,
  NOTE_A4, 8, NOTE_G4, 1,
};

//Raya Song 3
const PROGMEM char rayaSong3[] = {
  REST, 1,

  NOTE_FS4, 2, NOTE_B4, 1, NOTE_A4, 4, NOTE_FS4, 4, NOTE_A4, 4, NOTE_G4, 1, REST, 4,
  NOTE_E4, 2, NOTE_A4, 1, NOTE_G4, 4, NOTE_E4, 4, NOTE_G4, 4, NOTE_FS4, 1,
  NOTE_A4, 4, NOTE_G4, 4, NOTE_FS4, 4, NOTE_E4, 4, NOTE_D4, 8, NOTE_CS4, 8, NOTE_D4, 8,
  NOTE_E4, 8, NOTE_FS4, 8, NOTE_E4, 8, NOTE_FS4, 8, NOTE_A4, 8, NOTE_B4, 4, REST, 8,

  NOTE_FS4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_FS4, 4, NOTE_FS4, 4, NOTE_FS4, 8, NOTE_FS4, 4, NOTE_B4, 8, NOTE_B4, 3, REST, 16,
  NOTE_B4, 8, NOTE_B4, 4, NOTE_CS5, 8, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_FS4, 4, NOTE_G4, 3, REST, 16,
  NOTE_G4, 8, NOTE_G4, 4, NOTE_A4, 8, NOTE_B4, 4, NOTE_B4, 4, NOTE_B4, 8, NOTE_A4, 4, NOTE_E4, 4, NOTE_FS4, 3, REST, 16,
  NOTE_FS4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_A4, 4, NOTE_A4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_FS4, 4, NOTE_G4, 3, REST, 16,
  NOTE_E4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_FS4, 4, NOTE_FS4, 4, NOTE_FS4, 8, NOTE_FS4, 4, NOTE_AS3, 4, NOTE_B3, 2, REST, 4,

  NOTE_D4, 8, NOTE_CS4, 8, NOTE_D4, 8, NOTE_E4, 8, NOTE_FS4, 8, NOTE_E4, 8, NOTE_FS4, 8, NOTE_A4, 8, NOTE_B4, 4, REST, 8,

  NOTE_FS4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_FS4, 4, NOTE_FS4, 4, NOTE_FS4, 8, NOTE_FS4, 4, NOTE_B4, 8, NOTE_B4, 3, REST, 16,
  NOTE_B4, 8, NOTE_B4, 4, NOTE_CS5, 8, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_FS4, 4, NOTE_G4, 3, REST, 16,
  NOTE_G4, 8, NOTE_G4, 4, NOTE_A4, 8, NOTE_B4, 4, NOTE_B4, 4, NOTE_B4, 8, NOTE_A4, 4, NOTE_E4, 4, NOTE_FS4, 3, REST, 16,
  NOTE_FS4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_A4, 4, NOTE_A4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_FS4, 4, NOTE_G4, 3, REST, 16,
  NOTE_E4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_FS4, 4, NOTE_FS4, 4, NOTE_FS4, 8, NOTE_FS4, 4, NOTE_AS3, 4, NOTE_B3, 2, REST, 4,

  NOTE_FS4, 8, NOTE_E4, 8, NOTE_FS4, 8, NOTE_CS5, 8, NOTE_B4, 8, NOTE_AS4, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_B4, 4, REST, 8,

  NOTE_B4, 8, NOTE_B4, 4, NOTE_CS5, 8, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_B4, 4, NOTE_D5, 3, REST, 16,
  NOTE_D5, 8, NOTE_D5, 4, NOTE_E5, 8, NOTE_FS5, 4, NOTE_FS5, 4, NOTE_FS5, 8, NOTE_E5, 4, NOTE_D5, 4, NOTE_E5, 3, REST, 16,
  NOTE_CS5, 8, NOTE_CS5, 4, NOTE_D5, 8, NOTE_E5, 4, NOTE_E5, 4, NOTE_E5, 8, NOTE_D5, 4, NOTE_CS5, 4, NOTE_D5, 2, REST, 2,
  NOTE_B4, 4, NOTE_AS4, 4, NOTE_G4, 4, NOTE_AS4, 1,

  NOTE_FS4, 8, NOTE_E4, 8, NOTE_FS4, 8, NOTE_CS5, 8, NOTE_B4, 8, NOTE_AS4, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_B4, 4, REST, 8,

  NOTE_B4, 8, NOTE_B4, 4, NOTE_CS5, 8, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_B4, 4, NOTE_D5, 3, REST, 16,
  NOTE_D5, 8, NOTE_D5, 4, NOTE_E5, 8, NOTE_FS5, 4, NOTE_FS5, 4, NOTE_FS5, 8, NOTE_E5, 4, NOTE_D5, 4, NOTE_E5, 3, REST, 16,
  NOTE_CS5, 8, NOTE_CS5, 4, NOTE_D5, 8, NOTE_E5, 4, NOTE_E5, 4, NOTE_E5, 8, NOTE_D5, 4, NOTE_CS5, 4, NOTE_D5, 2, REST, 2,
  NOTE_B4, 4, NOTE_CS5, 4, NOTE_B4, 4, NOTE_FS5, 1, REST, 2,

  NOTE_CS5, 8, NOTE_CS5, 3, NOTE_D5, 8, NOTE_E5, 2, NOTE_D5, 3, NOTE_B4, 8, NOTE_G4, 2,
  NOTE_G4, 8, NOTE_B4, 3, NOTE_G4, 8, NOTE_FS4, 1,

  NOTE_D4, 8, NOTE_CS4, 8, NOTE_D4, 8, NOTE_E4, 8, NOTE_FS4, 8, NOTE_E4, 8, NOTE_FS4, 8, NOTE_A4, 8, NOTE_B4, 4, REST, 8,

  NOTE_FS4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_FS4, 4, NOTE_FS4, 4, NOTE_FS4, 8, NOTE_FS4, 4, NOTE_B4, 8, NOTE_B4, 3, REST, 16,
  NOTE_B4, 8, NOTE_B4, 4, NOTE_CS5, 8, NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_FS4, 4, NOTE_G4, 3, REST, 16,
  NOTE_G4, 8, NOTE_G4, 4, NOTE_A4, 8, NOTE_B4, 4, NOTE_B4, 4, NOTE_B4, 8, NOTE_A4, 4, NOTE_E4, 4, NOTE_FS4, 3, REST, 16,
  NOTE_FS4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_A4, 4, NOTE_A4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_FS4, 4, NOTE_G4, 3, REST, 16,
  NOTE_E4, 8, NOTE_FS4, 4, NOTE_G4, 8, NOTE_FS4, 4, NOTE_FS4, 4, NOTE_FS4, 8, NOTE_FS4, 4, NOTE_AS3, 4, NOTE_B3, 1,
  
  /*
  NOTE_E4, 4, NOTE_E4, 8, NOTE_FS4, 8, NOTE_G4, 2, REST, 4,
  NOTE_E4, 8, NOTE_FS4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_G4, 8, NOTE_A4, 4,
  NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 2,

  NOTE_E4, 4, NOTE_E4, 8, NOTE_FS4, 8, NOTE_G4, 2, REST, 4,
  NOTE_E4, 8, NOTE_FS4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_G4, 8, NOTE_B4, 2,
  NOTE_CS5, 8, NOTE_CS5, 4, NOTE_B4, 2, REST, 8,

  NOTE_E4, 4, NOTE_FS4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_FS4, 4, NOTE_G4, 4, NOTE_E4, 2,
  NOTE_DS4, 4, NOTE_E4, 4, NOTE_FS4, 4, NOTE_E4, 4, NOTE_DS4, 4, NOTE_E4, 4, NOTE_FS4, 2,
  NOTE_FS4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_FS4, 2,
  NOTE_G4, 4, NOTE_FS4, 4, NOTE_G4, 4, NOTE_FS4, 4, NOTE_G4, 4, NOTE_A4, 4, NOTE_B4, 2,
  NOTE_A4, 4, NOTE_B4, 4, NOTE_C5, 2, NOTE_B4, 4, NOTE_C5, 4, NOTE_A4, 2,
  NOTE_G4, 4, NOTE_A4, 4, NOTE_B4, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_B4, 4, NOTE_G4, 2,
  NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_FS4, 4, NOTE_E4, 4, NOTE_B3, 2,
  NOTE_FS4, 4, NOTE_A4, 4, NOTE_G4, 4, NOTE_E4, 4, NOTE_FS4, 4, NOTE_DS4, 4, NOTE_E4, 2,

  NOTE_E4, 4, NOTE_FS4, 4, NOTE_GS4, 4, NOTE_FS4, 4, NOTE_GS4, 4, NOTE_A4, 4, NOTE_B4, 2,
  NOTE_CS5, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_GS4, 4, NOTE_FS4, 4, NOTE_GS4, 4, NOTE_A4, 2,
  NOTE_FS4, 4, NOTE_E4, 4, NOTE_FS4, 4, NOTE_E4, 4, NOTE_FS4, 4, NOTE_GS4, 4, NOTE_A4, 2,
  NOTE_DS5, 4, NOTE_CS5, 4, NOTE_B4, 4, NOTE_AS4, 4, NOTE_GS4, 4, NOTE_AS4, 4, NOTE_B4, 2,
  NOTE_CS5, 4, NOTE_DS5, 4, NOTE_E5, 2, NOTE_CS5, 2, NOTE_A4, 2,
  NOTE_B4, 4, NOTE_CS5, 4, NOTE_DS5, 4, NOTE_DS5, 4, NOTE_CS5, 4, NOTE_DS5, 4, NOTE_B4, 2,
  NOTE_CS5, 4, NOTE_DS5, 4, NOTE_E5, 2, NOTE_E4, 4, NOTE_A4, 4, NOTE_GS4, 2,
  NOTE_E4, 4, NOTE_GS4, 4, NOTE_FS4, 4, NOTE_E4, 4, NOTE_DS4, 4, NOTE_FS4, 4, NOTE_E4, 2,
  NOTE_CS5, 4, NOTE_DS5, 4, NOTE_E5, 2, NOTE_E4, 4, NOTE_A4, 4, NOTE_GS4, 2,
  NOTE_E4, 4, NOTE_GS4, 4, NOTE_FS4, 4, NOTE_E4, 4, NOTE_DS4, 4, NOTE_FS4, 4, NOTE_E4, 1,
  */
};

//Raya Song 4
const PROGMEM char rayaSong4[] = {
  REST, 1,

  NOTE_C4, 4, NOTE_G4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_D4, 8, NOTE_E4, 8, NOTE_C4, 4,
  NOTE_G4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_E4, 8, NOTE_F4, 8, NOTE_D4, 8, NOTE_C4, 8, NOTE_D4, 4,
  NOTE_A4, 8, NOTE_A4, 4, NOTE_A4, 4, NOTE_A4, 4,
  NOTE_B4, 8, NOTE_G4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 2,

  NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_A4, 2,
  NOTE_A4, 3, NOTE_G4, 8, NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4, NOTE_B4, 4, NOTE_C5, 2,
  NOTE_G4, 3, NOTE_G4, 8, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_D4, 2,
  NOTE_B3, 3, NOTE_C4, 8, NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_D4, 4, NOTE_E4, 3,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_F4, 4, NOTE_F4, 8, NOTE_G4, 2,

  NOTE_C4, 3, NOTE_C4, 8, NOTE_E4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_A4, 2,
  NOTE_A4, 3, NOTE_G4, 8, NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4, NOTE_B4, 4, NOTE_C5, 2,
  NOTE_G4, 3, NOTE_G4, 8, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_D4, 2,
  NOTE_B3, 3, NOTE_C4, 8, NOTE_D4, 4, NOTE_E4, 4, NOTE_F4, 4, NOTE_D4, 4, NOTE_C4, 2,
  REST, 2, REST, 4,
  
  NOTE_G4, 4, NOTE_G4, 8, NOTE_G4, 4, NOTE_A4, 4, NOTE_A4, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_C5, 2,
  NOTE_C5, 3, NOTE_G4, 8, NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_E4, 4, NOTE_D4, 2,
  NOTE_G4, 3, NOTE_G4, 8, NOTE_A4, 4, NOTE_A4, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_C5, 2,
  NOTE_C5, 3, NOTE_G4, 8, NOTE_B4, 4, NOTE_C5, 4, NOTE_D5, 4, NOTE_E5, 4, NOTE_D5, 2,

  NOTE_D5, 3, NOTE_E5, 8, NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4, NOTE_F5, 4, NOTE_E5, 2,
  NOTE_C5, 3, NOTE_E5, 8, NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_D5, 4, NOTE_C5, 2,
  NOTE_D5, 3, NOTE_E5, 8, NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4, NOTE_F5, 4, NOTE_E5, 2,
  NOTE_C5, 3, NOTE_E5, 8, NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4, NOTE_D5, 4, NOTE_C5, 1,
};

unsigned char leftTotal = 0;
unsigned char rightTotal = 0;
bool inGameMode = true;
bool firstRunMusic = true;
unsigned char firstRunTune = 0;

unsigned long lastLEDMillis = 0;
unsigned char LEDStatus = LOW;

unsigned char randomLEDSeq[23] = {
  0x00, 0x01, 0x02, 0x04, 0x08,
  0x10, 0x20, 0x40, 0xFF, 0x00,
  0xFF, 0x40, 0x20, 0x10, 0x08,
  0x04, 0x02, 0x01, 0x04, 0x10,
  0x40, 0x01, 0x00
};
unsigned char currentLEDPattern = 0;

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

void setup()
{
  initTomatoCube();

  for (int ledPatterni = 0; ledPatterni < 23; ledPatterni++) {
    pixelLED(randomLEDSeq[ledPatterni]);
    delay(150);
  }

  lastLEDMillis = millis();
}

void loop()
{
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

    pixelLED(((leftTotal == 1) ? 0x01 : (leftTotal == 2) ? 0x03 : (leftTotal == 3) ? 0x7 : 0x00) | ((rightTotal == 1) ? 0x08 : (rightTotal == 2) ? 0x28 : (rightTotal == 3) ? 0x38 : (rightTotal == 4) ? 0x78 : 0x00) );
  }
  else {
    scanTouchButton();
    if (firstRunMusic) {
      adjustTempo(400);
      sendMusicNotes(firstRunTune ? rayaSong1 : rayaSong2, firstRunTune ? sizeof(rayaSong1) : sizeof(rayaSong2));
      generateLEDSequence();
      firstRunMusic = false;
    }
    else if (getTouchB1Transition() == 1) {
      adjustTempo(400);
      if (getTouchB2State())
        sendMusicNotes(rayaSong4, sizeof(rayaSong4));
      else
        sendMusicNotes(rayaSong2, sizeof(rayaSong2));
      generateLEDSequence();
    }
    else if (getTouchB2Transition() == 1) {
      adjustTempo(400);
      if (getTouchB1State())
        sendMusicNotes(rayaSong3, sizeof(rayaSong3));
      else
        sendMusicNotes(rayaSong1, sizeof(rayaSong1));
      generateLEDSequence();
      //stopMusic();
    }

    if (!playMusic()) { // If music is not playing
      if (millis() - lastLEDMillis >= 500) {
        pixelLED(getRandomLED());
        lastLEDMillis = millis();
      }
//      if (millis() - lastLEDMillis >= 1000) {
//        pixelLED(0x00);
//        lastLEDMillis = millis();
//        LEDStatus = (LEDStatus == LOW)? HIGH: LOW;
//        pixelLED(LEDStatus? 0x01: 0x00);
//      }
    }
    else {
      if (millis() - lastLEDMillis >= 250) {
        pixelLED(getRandomLED());
        lastLEDMillis = millis();
      }
    }
  }
}
