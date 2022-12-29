#define LED_1_PINOUT 15
#define LED_2_PINOUT 34

#define SHAKER_PINOUT 31

uint16_t shakerBuffer = 0x0000;
uint8_t shakerSum = 0;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_1_PINOUT, OUTPUT);
    pinMode(LED_2_PINOUT, OUTPUT);
    digitalWrite(LED_1_PINOUT, LOW);
    digitalWrite(LED_2_PINOUT, LOW);
    pinMode(SHAKER_PINOUT, INPUT_PULLUP);
}

void loop()
{
    shakerBuffer = (shakerBuffer << 1) | (digitalRead(SHAKER_PINOUT) & 0x01);
    shakerSum = 0;
    for (uint8_t i = 0; i < 15; i++)
    {
        shakerSum += bitRead(shakerBuffer, i);
    }

    if (shakerSum > 13) // Light up for 1 second when vibration detected
    {
        digitalWrite(LED_1_PINOUT, HIGH);
        digitalWrite(LED_2_PINOUT, HIGH);
        delay(1000);
    }
    else
    {
        digitalWrite(LED_1_PINOUT, LOW);
        digitalWrite(LED_2_PINOUT, LOW);
    }
}
