
const uint8_t buttonPin = 2;
unsigned int counter = 0;

void setup() {
    // we use the builtin pull-up resistor in microcontroller, so we do not need
    // additional components, just a pushbutton and a pair of wires
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    // pressing the button will result in a grounded state, if we use the
    // builtin pull-up resistor
    if (digitalRead(buttonPin) == LOW) {
        if (!ledState) {
            digitalWrite(LED_BUILTIN, HIGH);
            // Did we really press it only once?...
            // counter++;
            // Serial.println(counter);
            delay(10);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}
