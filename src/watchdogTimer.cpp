/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/CTD_2023/watchdogTimer/src/watchdogTimer.ino"
void setup();
void loop();
void resetDisplay();
#line 1 "/Users/admin/CTD_2023/watchdogTimer/src/watchdogTimer.ino"
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