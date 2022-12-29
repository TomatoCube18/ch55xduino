#define LED_1_PINOUT 15
#define LED_2_PINOUT 34

#define IR_PINOUT 33

volatile uint8_t i, nec_state = 0;
volatile unsigned int command, address;

volatile unsigned long nec_code;
volatile boolean nec_ok = false;
volatile unsigned long timer_value_old;
volatile unsigned long timer_value;

uint8_t LED_State = 0;

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
    pinMode(IR_PINOUT, INPUT_PULLUP);

    // Initialize NEC IR receiver
    attachInterrupt(1, int0Callback, FALLING); // IR connected to P3.2 (IRQ 0) // if P3.3 (IRQ 1)
}

void loop()
{
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
                // Turn ON both lights
                if (LED_State)
                {
                    digitalWrite(LED_1_PINOUT, LOW);
                    digitalWrite(LED_2_PINOUT, LOW);
                    LED_State = 0;
                }
                else
                {
                    digitalWrite(LED_1_PINOUT, HIGH);
                    digitalWrite(LED_2_PINOUT, HIGH);
                    LED_State = 1;
                }

                break;

            case 152: // < Up >
                // Turn ON light strip 1
                digitalWrite(LED_1_PINOUT, HIGH);
                digitalWrite(LED_2_PINOUT, LOW);
                LED_State = 1;

                break;

            case 24: // < Down >
                // Turn ON light strip 2
                digitalWrite(LED_1_PINOUT, LOW);
                digitalWrite(LED_2_PINOUT, HIGH);
                LED_State = 1;

                break;

            default:
                break;
            }
        }
    }
}
