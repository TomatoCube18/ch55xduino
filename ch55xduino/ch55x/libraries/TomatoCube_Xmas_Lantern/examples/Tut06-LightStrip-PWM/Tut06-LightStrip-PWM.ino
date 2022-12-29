#define LED_1_PINOUT 15
#define LED_2_PINOUT 34

int brightness = 0;

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_1_PINOUT, OUTPUT);
    pinMode(LED_2_PINOUT, OUTPUT);
    digitalWrite(LED_1_PINOUT, LOW);
    digitalWrite(LED_2_PINOUT, LOW);
}

void loop()
{
    for (brightness = 0; brightness < 255; brightness++)
    {
        analogWrite(LED_1_PINOUT, brightness);
        delay(10);
    }

    for (brightness = 255; brightness > 0; brightness--)
    {
        analogWrite(LED_1_PINOUT, brightness);
        delay(10);
    }
}
