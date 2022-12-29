#define LED_1_PINOUT 15
#define LED_2_PINOUT 34

#define SWITCH1_PINOUT 11
#define SWITCH2_PINOUT 14
#define SWITCH3_PINOUT 32

#define SHAKER_PINOUT 31

#define IR_PINOUT 33

#define MUSIC_KA0_PINOUT 16 // One Song PerPress  - Active Low
#define MUSIC_KA1_PINOUT 17 // Hold Low to Play - Active Low
#define MUSIC_KB0_PINOUT 30 // PlayBack Status - Active Low

#define OLDSOUNDCHIP 0

volatile uint8_t i, nec_state = 0;
volatile unsigned int command, address;

volatile unsigned long nec_code;
volatile boolean nec_ok = false;
volatile unsigned long timer_value_old;
volatile unsigned long timer_value;

uint8_t button1Buffer = 0x0F;
uint8_t button2Buffer = 0x0F;
uint8_t button3Buffer = 0x0F;

uint8_t currentButtonDown = 0;

uint16_t shakerBuffer = 0x0000;
uint8_t shakerSum = 0;

uint8_t led1_mode = 0;
uint8_t led2_mode = 0;
uint8_t music_mode = 0;

uint8_t led1_state = LOW;
uint8_t led2_state = LOW;
unsigned long lastLed1Change = 0;
unsigned long lastLed2Change = 0;
unsigned long resetMusic = 0;
uint8_t singlePlayPressed = 0;

uint8_t led1_brightness = 255;
uint8_t led2_brightness = 255;
uint8_t ir_control_mode = 0;
uint8_t ir_control_overwrite = 0;

#pragma save
#pragma nooverlay
void int0Callback()
{
    timer_value = micros() - timer_value_old; // Store elapse timer value in microS

    switch (nec_state)
    {
    case 0: // standby:
        if (timer_value > 67500)
        {                               // Greater than one frame...
            timer_value_old = micros(); // Reset microS Timer
            nec_state = 1;              // Next state: end of 9ms pulse + LeadingSpace 4.5ms
            i = 0;
        }
        break;

    // Leading Mark = Leading pulse + leading space = 9000 + 4500 = 13500
    // max tolerance = 1000
    case 1: // startPulse:
        if (timer_value >= (13500 - 1000) && timer_value <= (13500 + 1000))
        { // its a Leading Mark
            i = 0;
            timer_value_old = micros();
            nec_state = 2;
        }
        else
            nec_state = 0;
        break;

    // Bit 0 Mark length = 562.5µs pulse + 562.5µs space = 1125
    // Bit 1 Mark length = 562.5µs pulse + 3 * 562.5µs space = 2250
    // max tolerance = (2250 - 1125)/2 = 562.5
    case 2: // receiving:
        if (timer_value < (1125 - 562) || timer_value > (2250 + 562))
            nec_state = 0; // error, not a bit mark
        else
        {                             // it's M0 or M1
            nec_code = nec_code << 1; // push a 0 from Right to Left (will be left at 0 if it's M0)
            if (timer_value >= (2250 - 562))
                nec_code |= 0x01; // it's M1, change LSB to 1
            i++;

            if (i == 32)
            { // all bits received
                nec_ok = true;
                //                    detachInterrupt(IR_RECV);   // Optional: Disable external interrupt to prevent next incoming signal
                nec_state = 0;
                timer_value_old = micros();
            }
            else
            {
                nec_state = 2; // continue receiving
                timer_value_old = micros();
            }
        }
        break;

    default:
        nec_state = 0;
        break;
    }
}
#pragma restore

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

    pinMode(SHAKER_PINOUT, INPUT_PULLUP);

    pinMode(IR_PINOUT, INPUT_PULLUP);

    pinMode(MUSIC_KA0_PINOUT, OUTPUT);
    pinMode(MUSIC_KA1_PINOUT, OUTPUT);
    digitalWrite(MUSIC_KA0_PINOUT, HIGH);
    digitalWrite(MUSIC_KA1_PINOUT, HIGH);
    pinMode(MUSIC_KB0_PINOUT, INPUT_PULLUP);

    // Initialize NEC IR receiver
    attachInterrupt(1, int0Callback, FALLING); // IR connected to P3.2 (IRQ 0) // if P3.3 (IRQ 1)

    // sets the LED PWM value (range from 0 to 255):
    //    analogWrite(LED_1_PINOUT, 123);
    //    analogWrite(LED_2_PINOUT, 123);

    // Initial State of Timer
    lastLed1Change = millis();
    lastLed2Change = millis();
    resetMusic = millis();
}

void loop()
{

    button1Buffer = (button1Buffer << 1) | (digitalRead(SWITCH1_PINOUT) & 0x01);
    button2Buffer = (button2Buffer << 1) | (digitalRead(SWITCH2_PINOUT) & 0x01);
    button3Buffer = (button3Buffer << 1) | (digitalRead(SWITCH3_PINOUT) & 0x01);

    shakerBuffer = (shakerBuffer << 1) | (digitalRead(SHAKER_PINOUT) & 0x01);
    //      shakerSum = (bitRead(shakerBuffer, 7) + bitRead(shakerBuffer, 6) + bitRead(shakerBuffer, 5) +
    //          bitRead(shakerBuffer, 4) + bitRead(shakerBuffer, 3) + bitRead(shakerBuffer, 2) +
    //          bitRead(shakerBuffer, 1) + bitRead(shakerBuffer, 0));
    shakerSum = 0;
    for (uint8_t Sumi = 0; Sumi < 15; Sumi++)
    {
        shakerSum += bitRead(shakerBuffer, Sumi);
    }

    if ((button1Buffer & 0x0F) == 0)
    { // If ButtonPressed is detected
        currentButtonDown = 1;
    }
    else if ((button2Buffer & 0x0F) == 0)
    { // If ButtonPressed is detected
        currentButtonDown = 2;
    }
    else if ((button3Buffer & 0x0F) == 0)
    { // If ButtonPressed is detected
        currentButtonDown = 3;
    }
    else if (((button1Buffer & 0x1F) == 0x0F) || ((button2Buffer & 0x1F) == 0x0F) || ((button3Buffer & 0x1F) == 0x0F))
    {

        ir_control_overwrite = 0;
        ir_control_mode = 0;

        // Detect Last Button Down (single choice)
        if (OLDSOUNDCHIP)
        {
            led1_mode = (currentButtonDown == 1) ? (led1_mode < 3) ? led1_mode + 1 : 0 : led1_mode;
            led2_mode = (currentButtonDown == 2) ? (led2_mode < 3) ? led2_mode + 1 : 0 : led2_mode;
        }
        else
        {
            led1_mode = (currentButtonDown == 1) ? (led1_mode < 4) ? led1_mode + 1 : 0 : led1_mode;
            led2_mode = (currentButtonDown == 2) ? (led2_mode < 4) ? led2_mode + 1 : 0 : led2_mode;
        }

        music_mode = (currentButtonDown == 3) ? (music_mode < 3) ? music_mode + 1 : 0 : music_mode;
        currentButtonDown = 0;
    }

    // Led1 Control
    switch (led1_mode)
    {
    case 0: // Led1 Off
        led1_state = LOW;
        break;
    case 1: // Slow Flash
        if (lastLed1Change + 1000 <= millis())
        {
            led1_state = !led1_state;
            lastLed1Change = millis();
        }
        break;
    case 2: // Fast Flash
        if (lastLed1Change + 500 <= millis())
        {
            led1_state = !led1_state;
            lastLed1Change = millis();
        }
        break;
    case 3: // On
        led1_state = HIGH;
        break;
    case 4: // Music
        led1_state = digitalRead(MUSIC_KB0_PINOUT);
        break;

    case 5: // Alternate Flash Light
        if (lastLed1Change + 1000 <= millis())
        {
            led1_state = !led1_state;
            lastLed1Change = millis();
        }
        break;

    default:
        led1_mode = 0;
        led1_state = LOW;
        break;
    }

    // Led2 Control
    switch (led2_mode)
    {
    case 0: // Led2 Off
        led2_state = LOW;
        break;
    case 1: // Slow Flash
        if (lastLed2Change + 1000 <= millis())
        {
            led2_state = !led2_state;
            lastLed2Change = millis();
        }
        break;
    case 2: // Fast Flash
        if (lastLed2Change + 500 <= millis())
        {
            led2_state = !led2_state;
            lastLed2Change = millis();
        }
        break;
    case 3: // On
        led2_state = HIGH;
        break;
    case 4: // Music
        led2_state = digitalRead(MUSIC_KB0_PINOUT);
        break;

    case 5: // Alternate Flash Light
        led2_state = !led1_state;
        break;

    default:
        led2_mode = 0;
        led2_state = LOW;
        break;
    }

    if (ir_control_overwrite == 1)
    {
        if (led1_state == HIGH)
            analogWrite(LED_1_PINOUT, led1_brightness);
        else
            digitalWrite(LED_1_PINOUT, led1_state);

        if (led2_state == HIGH)
            analogWrite(LED_2_PINOUT, led2_brightness);
        else
            digitalWrite(LED_2_PINOUT, led2_state);
    }
    else
    {
        digitalWrite(LED_1_PINOUT, led1_state);
        digitalWrite(LED_2_PINOUT, led2_state);
    }

    // Music Control
    switch (music_mode)
    {
    case 0: // Music Off
        if ((!singlePlayPressed) && (resetMusic <= millis()))
        { // Release previous Single Play Button
            singlePlayPressed = 0;
            digitalWrite(MUSIC_KA0_PINOUT, HIGH); // Stop Play
            digitalWrite(MUSIC_KA1_PINOUT, HIGH);
        }
        else if ((singlePlayPressed) && (resetMusic <= millis()))
        { // Release previous Single Play Button
            digitalWrite(MUSIC_KA0_PINOUT, HIGH);
            digitalWrite(MUSIC_KA1_PINOUT, HIGH);
            singlePlayPressed = 0;       // Release Single Button Press
            resetMusic = millis() + 250; // Reset Play Hack Music Input State in 250ms
        }
        else
        {
            digitalWrite(MUSIC_KA0_PINOUT, HIGH); // Continuous Play: Hack
            digitalWrite(MUSIC_KA1_PINOUT, LOW);
            singlePlayPressed = 0; // Release Single Button Press
        }
        break;
    case 1: // Music Play one piece on Shake
        if ((shakerSum > 13) && (!singlePlayPressed))
        {
            resetMusic = millis() + 250; // Reset Music Input State in 500ms
            singlePlayPressed = 1;       // Register Single Button Press
            digitalWrite(MUSIC_KA0_PINOUT, LOW);
            digitalWrite(MUSIC_KA1_PINOUT, HIGH);
        }
        else if ((singlePlayPressed) && (resetMusic <= millis()))
        {                          // Release previous Single Play Button
            singlePlayPressed = 0; // Release Single Button Press
            digitalWrite(MUSIC_KA0_PINOUT, HIGH);
            digitalWrite(MUSIC_KA1_PINOUT, HIGH);
        }
        break;
    case 2: // Music On - Continuous

        if ((singlePlayPressed) && (resetMusic <= millis()))
        {                                // Release previous Single Play Button
            singlePlayPressed = 0;       // Release Single Button Press
            resetMusic = millis() + 500; // Reset Music Input State in 500ms
        }
        else if ((!singlePlayPressed) && (resetMusic <= millis()))
        {
            singlePlayPressed = 0;
            digitalWrite(MUSIC_KA0_PINOUT, HIGH); // Continuous Play
            digitalWrite(MUSIC_KA1_PINOUT, LOW);
        }
        else if (!singlePlayPressed)
        { // Single Single Play Press is release properly
            singlePlayPressed = 0;
            digitalWrite(MUSIC_KA0_PINOUT, HIGH); // Stop Properly
            digitalWrite(MUSIC_KA1_PINOUT, HIGH);
        }

        break;
    default:
        music_mode = 0;
        break;
    }

    //// Reading Music Chip Status    // Play Music Off, Idle On
    //      digitalWrite(LED_2_PINOUT, digitalRead(MUSIC_KB0_PINOUT));
    //

    // Code for IR (NEC infrared remote)

    //      TomatoCube 3 Button IR { Addr: 255 }
    //      1. < Power >  Cmd: 2
    //      2. < UP >     Cmd: 152
    //      3. < Down >   Cmd: 24

    if (nec_ok)
    {                   // If a good NEC message is received
        nec_ok = false; // Reset decoding StateMachine

        address = nec_code >> 16;
        command = (nec_code & 0xFFFF) >> 8; // Remove inverted Bits
        if (address == 255)
        { // Switch Case for TomatoCube 3 Button IR
            switch (command)
            {
            case 2: // < Power >
                ir_control_mode = (ir_control_mode < 7) ? ir_control_mode + 1 : 1;
                switch (ir_control_mode)
                {
                case 1: // Turn ON Light 1 only
                    led1_mode = 3;
                    led2_mode = 0;
                    break;

                case 2: // Turn ON Light 2 only
                    led1_mode = 0;
                    led2_mode = 3;
                    break;

                case 3: // Turn ON Both Light
                    led1_mode = 3;
                    led2_mode = 3;
                    break;

                case 4: // Blink Light 1
                    led1_mode = 1;
                    led2_mode = 0;
                    break;

                case 5: // Blink Light 2
                    led1_mode = 0;
                    led2_mode = 1;
                    break;

                case 6: // Alternate Light Blinking
                    led1_mode = 5;
                    led2_mode = 5;
                    break;

                default: // Turn OFF both Lights
                    led1_mode = 0;
                    led2_mode = 0;
                    break;
                }

                ir_control_overwrite = 1;
                break;

            case 152: // < Up >
                led1_brightness = (led1_brightness <= 205) ? led1_brightness + 50 : 255;
                led2_brightness = (led2_brightness <= 205) ? led2_brightness + 50 : 255;
                break;

            case 24: // < Down >
                led1_brightness = (led1_brightness >= 50) ? led1_brightness - 50 : 0;
                led2_brightness = (led2_brightness >= 50) ? led2_brightness - 50 : 0;

                break;
            default:
                break;
            }
        }
    }
}
