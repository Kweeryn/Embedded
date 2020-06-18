static const int LED_PIN = 7;
static const int INTERRUPT_PIN = 2;
static const int TIME_DIFF = 70;

void switchLed();

volatile boolean ledFlag = false;
volatile unsigned long lastPressedTime;

void setup() {
   pinMode(LED_PIN, OUTPUT);
    pinMode(INTERRUPT_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), switchLed, RISING);
}

void loop() {
}

void switchLed() {
    if (millis() - lastPressedTime > TIME_DIFF) {
        if (ledFlag) {
            digitalWrite(LED_PIN, LOW);
            ledFlag = false;
        } else {
            digitalWrite(LED_PIN, HIGH);
            ledFlag = true;
        }
        lastPressedTime = millis();
    }