#define LED_1_PINOUT 15
#define LED_2_PINOUT 34

#define SWITCH1_PINOUT 11
#define SWITCH2_PINOUT 14
#define SWITCH3_PINOUT 32

#define MUSIC_KA0_PINOUT 16 // One Song PerPress  - Active Low
#define MUSIC_KA1_PINOUT 17 // Hold Low to Play - Active Low
#define MUSIC_KB0_PINOUT 30 // PlayBack Status - Active Low

uint8_t button1Buffer = 0x0F;
uint8_t button2Buffer = 0x0F;
uint8_t button3Buffer = 0x0F;

uint8_t music_state = LOW;

void setup()
{
      // initialize digital pin LED_BUILTIN as an output.
      pinMode(LED_1_PINOUT, OUTPUT);
      pinMode(LED_2_PINOUT, OUTPUT);
      digitalWrite(LED_1_PINOUT, LOW);
      digitalWrite(LED_2_PINOUT, LOW);

      pinMode(SWITCH1_PINOUT, INPUT_PULLUP);
      pinMode(SWITCH2_PINOUT, INPUT_PULLUP);
      pinMode(SWITCH1_PINOUT, INPUT_PULLUP);

      pinMode(MUSIC_KA0_PINOUT, OUTPUT);
      pinMode(MUSIC_KA1_PINOUT, OUTPUT);
      digitalWrite(MUSIC_KA0_PINOUT, HIGH);
      digitalWrite(MUSIC_KA1_PINOUT, HIGH);
      pinMode(MUSIC_KB0_PINOUT, INPUT_PULLUP);
}

void loop()
{

      button1Buffer = (button1Buffer << 1) | (digitalRead(SWITCH1_PINOUT) & 0x01); // Read 1 bit from button 1 and push it into the variable (LSB)
      button2Buffer = (button2Buffer << 1) | (digitalRead(SWITCH2_PINOUT) & 0x01);
      button3Buffer = (button3Buffer << 1) | (digitalRead(SWITCH3_PINOUT) & 0x01);

      if ((button1Buffer & 0x1F) == 0x0F)
      {
            // Play one music only (uninterrupted during playing), press again to play next song
            digitalWrite(MUSIC_KA0_PINOUT, LOW);
            digitalWrite(MUSIC_KA1_PINOUT, HIGH);
      }
      else if ((button2Buffer & 0x1F) == 0x0F)
      {
            // Play music in continuos mode
            digitalWrite(MUSIC_KA0_PINOUT, HIGH);
            digitalWrite(MUSIC_KA1_PINOUT, LOW);
      }
      else if ((button3Buffer & 0x1F) == 0x0F)
      {
            // Stop the continous music
            digitalWrite(MUSIC_KA0_PINOUT, HIGH);
            digitalWrite(MUSIC_KA1_PINOUT, HIGH);
      }

      // Turn ON Light Strip along with the music status
      music_state = digitalRead(MUSIC_KB0_PINOUT);
      digitalWrite(LED_1_PINOUT, music_state);
      digitalWrite(LED_2_PINOUT, music_state);
}
