#pragma once
#include <Arduino.h>
#include <rgb_lcd.h>

// Slot-Nummern im LCD-Speicher (Reihenfolge = Reihenfolge der Bitmaps!)
enum Icon : uint8_t {
  ICON_ARROW_RIGHT_INVERTED,
  ICON_ARROW_LEFT_INVERTED,
  ICON_COUNT      // Anzahl der Icons, kein echtes Icon
};

static_assert(ICON_COUNT <= 8, "Das LCD unterstuetzt maximal 8 eigene Zeichen");

void loadIcons(rgb_lcd& lcd);   // Referenz, entspricht einem Objektparameter in Java