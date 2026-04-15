#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TOTAL_CAPACITY 50

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

int occupancy = 0;

void updateDisplay() {
  int vacant = TOTAL_CAPACITY - occupancy;

  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);

  tft.setCursor(20, 30);
  tft.print("Capacity: ");
  tft.println(TOTAL_CAPACITY);

  tft.setCursor(20, 90);
  tft.print("Occupied: ");
  tft.println(occupancy);

  tft.setCursor(20, 150);
  tft.print("Vacant: ");
  tft.println(vacant);
}

void setup() {
  Serial.begin(115200);

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

  updateDisplay();
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "ENTRY" && occupancy < TOTAL_CAPACITY) {
      occupancy++;
    }

    if (input == "EXIT" && occupancy > 0) {
      occupancy--;
    }

    updateDisplay();
  }
}