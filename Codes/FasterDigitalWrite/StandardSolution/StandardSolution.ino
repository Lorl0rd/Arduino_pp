
bool ledState = true;

void setup() { pinMode(LED_BUILTIN, OUTPUT); }

void loop() {
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
}