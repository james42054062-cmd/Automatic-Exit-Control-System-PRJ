#define EXIT_SENSOR_PIN 27
#define DEBOUNCE_DELAY 300

unsigned long lastExitTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(EXIT_SENSOR_PIN, INPUT_PULLUP);
}

void loop() {
  int exitState = digitalRead(EXIT_SENSOR_PIN);

  if (exitState == LOW) {
    if (millis() - lastExitTime > DEBOUNCE_DELAY) {
      Serial.println("EXIT");
      lastExitTime = millis();
    }
  }
}