// A basic sketch showing interrupt capability...

const uint8_t interruptPin = 2;
volatile bool ledState = false;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin),
                    lightUpLedOnButtonPress, CHANGE);
}

void loop() {
    // nothing needed here...
}

volatile void lightUpLedOnButtonPress(void) {
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
}
