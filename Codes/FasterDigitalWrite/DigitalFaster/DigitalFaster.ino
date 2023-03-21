uint8_t state = 0;  // typedef byte uint8_t; typedef uint8_t unsigned char;

void setup() {
    // set LED_BUILTIN (D13 on Uno) to output mode
    DDRB = 0b00100000;  // data direction register (I/O ~ 0/1)
    while (true) {
        // measure this with an oscilloscope
        // digitalWrite(LED_BUILTIN, HIGH);
        PORTB = 0b00100000;
        // digitalWrite(LED_BUILTIN, LOW);
        PORTB = 0b00000000;
    }
}

void loop() {}