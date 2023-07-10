#define watchdogPetButton D8

#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup() {
  Watchdog.init(WatchdogConfiguration().timeout(5000));
  Watchdog.start();

  display.setup();
  resetDisplay();

  if (System.resetReason() == RESET_REASON_WATCHDOG) {
    display.print(RESET_REASON_WATCHDOG);
  } else {
    display.print("Normal Reset");
  }

  display.display();

  pinMode(watchdogPetButton, INPUT);
}

void loop() {
  display.loop();

  if (digitalRead(watchdogPetButton)) {
    Watchdog.refresh();
  }
}

void resetDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
}