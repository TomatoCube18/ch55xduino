#define LED_1_PINOUT 15
#define LED_2_PINOUT 34

#define SWITCH1_PINOUT 11
#define SWITCH2_PINOUT 14
#define SWITCH3_PINOUT 32

uint8_t button1Buffer = 0x0F;
uint8_t button2Buffer = 0x0F;
uint8_t button3Buffer = 0x0F;

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
}

void loop()
{
    // Scenario #1: Turn ON Light Strip 1 by holding down the button 1
    button1Buffer = (button1Buffer << 1) | (digitalRead(SWITCH1_PINOUT) & 0x01); // Read 1 bit from button 1 and push it into the variable (LSB)

    if ((button1Buffer & 0x3F) == 0)
    { // If ButtonPressed is detected (comparing cumulative 6 bits for debouncing purpose)
        digitalWrite(LED_1_PINOUT, HIGH);
    }
    else
    {
        digitalWrite(LED_1_PINOUT, LOW);
    }

    // Scenario #2: Turn ON Light Strip 2 by pressing button 2
    button2Buffer = (button2Buffer << 1) | (digitalRead(SWITCH2_PINOUT) & 0x01); // Read 1 bit from button 1 and push it into the variable (LSB)

    if ((button2Buffer & 0x3F) == 0x0F)
    { // If ButtonPressed is detected (comparing cumulative 6 bits for debouncing purpose)
        digitalWrite(LED_2_PINOUT, HIGH);
    }

    // Scenario #3: Turn OFF Light Strip 2 by pressing button 3
    button3Buffer = (button3Buffer << 1) | (digitalRead(SWITCH3_PINOUT) & 0x01); // Read 1 bit from button 1 and push it into the variable (LSB)

    if ((button3Buffer & 0x3F) == 0x0F)
    { // If ButtonPressed is detected (comparing cumulative 6 bits for debouncing purpose)
        digitalWrite(LED_2_PINOUT, LOW);
    }
}
