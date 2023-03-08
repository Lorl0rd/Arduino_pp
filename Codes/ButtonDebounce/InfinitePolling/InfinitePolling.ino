
const uint8_t buttonPin = 2;
unsigned int counter = 0;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    if (digitalRead(buttonPin) == HIGH) {
        digitalWrite(LED_BUILTIN, HIGH);
        counter++;
        Serial.println(counter);
    }
}
