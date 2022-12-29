#define LED_1_PINOUT 15
#define LED_2_PINOUT 34

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
    digitalWrite(LED_1_PINOUT, HIGH);
    digitalWrite(LED_2_PINOUT, HIGH);
    delay(1000);
    digitalWrite(LED_1_PINOUT, LOW);
    digitalWrite(LED_2_PINOUT, LOW);
    delay(1000);
}
