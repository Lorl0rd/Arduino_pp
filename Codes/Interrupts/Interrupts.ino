// A basic sketch showing interrupt capability...

const uint8_t interruptPin = 2;
volatile bool ledState = false;

unsigned int counter = 0;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin),
                    lightUpLedOnButtonPress, CHANGE);
    Serial.begin(115200);
}

void loop() {
    // nothing needed here...
    // try delaying for a really long time, and pressing the button in the midst
    // of it 
    delay(2000); // pressing the button is detected, even if we are in
    // delay() Serial.println(counter);
}

volatile void lightUpLedOnButtonPress(void) {
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);

    // counter++;
}
