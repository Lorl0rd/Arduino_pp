// The best debouncer in my opinion...

// Defines
#define MASK 0b11000111

// Variables
const uint8_t buttonPin = 2;  // 2U meaning?...
uint8_t buttonHistory = 0;
uint8_t ledState = 0;
unsigned int counter = 0;

// Function declarations
volatile void updateButton(uint8_t& buttonHistory, uint8_t buttonPin);
uint8_t isButtonPressed(uint8_t& buttonHistory);
uint8_t isButtonReleased(uint8_t& buttonHistory);
uint8_t isButtonDown(uint8_t& buttonHistory);
uint8_t isButtonUp(uint8_t& buttonHistory);

void setup() {
    // timer interrupt for better button debouncing (only for atmega328)
    cli();       // disable interrupts until initialization is complete
    TCCR1A = 0;  // set entire TCCR1A register to 0
    TCCR1B = 0;  // same for TCCR1B
    TCNT1 = 0;   // initialize counter value to 0
    // set compare match register for 5Hz increments
    OCR1A = 77;  // = (16*10^6) / (200*1024) - 1 (must be < 65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // set CS10 and CS12 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei();  // allow interrupts
}

void loop() {
    if (isButtonPressed(buttonHistory)) {
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState);

        counter++;
        Serial.println(counter);
    }
}

// timer interrupt service routine
ISR(TIMER1_COMPA_vect) { updateButton(buttonHistory, buttonPin); }

volatile void updateButton(uint8_t& buttonHistory, uint8_t buttonPin) {
    buttonHistory = (buttonHistory << 1);  // with buttonHistory as a pointer?
    buttonHistory |= digitalRead(buttonPin);
}

uint8_t isButtonPressed(uint8_t& buttonHistory) {
    uint8_t pressed = 0;
    if ((buttonHistory & MASK) == 0b00000111) {
        pressed = 1;
        buttonHistory = 0b11111111;  // = 0xFF
    }
    return pressed;
}
uint8_t isButtonReleased(uint8_t& buttonHistory) {
    uint8_t released = 0;
    if ((buttonHistory & MASK) == 0b11000000) {
        released = 1;
        buttonHistory = 0b00000000;  // = 0x00
    }
    return released;
}
uint8_t isButtonDown(uint8_t& buttonHistory) {
    return (buttonHistory == 0b11111111);  // = 0xFF
}

uint8_t isButtonUp(uint8_t& buttonHistory) {
    return (buttonHistory == 0b00000000);  // = 0x00
}
