#define ENTRY_SENSOR_PIN 14
#define DEBOUNCE_DELAY 300

unsigned long lastEntryTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ENTRY_SENSOR_PIN, INPUT_PULLUP);
}

void loop() {
  int entryState = digitalRead(ENTRY_SENSOR_PIN);

  if (entryState == LOW) {
    if (millis() - lastEntryTime > DEBOUNCE_DELAY) {
      Serial.println("ENTRY");
      lastEntryTime = millis();
    }
  }
}