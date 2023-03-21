
const uint8_t buttonPin = 2;
unsigned int counter = 0;
unsigned long int lastDebounceTime = 0;
unsigned long int previousTime = 0;
uint8_t currentButtonState = 0;
uint8_t previousButtonState = 0;
uint8_t ledState = 0;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);

    digitalWrite(LED_BUILTIN, ledState);
    Serial.begin(115200);
}

void loop() {
    currentButtonState = digitalRead(buttonPin);

    // value changed, so update our timer
    if (currentButtonState != previousButtonState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > 100) {
        // we waited for enough time, so act in accordance

        if (currentButtonState == LOW) {
            ledState = !ledState;
        }
    }

    digitalWrite(LED_BUILTIN, ledState);
    previousButtonState = currentButtonState;
}
