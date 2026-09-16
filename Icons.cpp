#include "Icons.h"

static const uint8_t ICON_BITMAPS[][8] = {
  { // ICON_NEXT (invertiertes >)
    0b10111,   // #.###
    0b11011,   // ##.##
    0b11101,   // ###.#
    0b11110,   // ####.
    0b11101,   // ###.#
    0b11011,   // ##.##
    0b10111,   // #.###
    0b11111    // #####
  },
  { // ICON_PREV (invertiertes <)
    0b11101,   // ###.#
    0b11011,   // ##.##
    0b10111,   // #.###
    0b01111,   // .####
    0b10111,   // #.###
    0b11011,   // ##.##
    0b11101,   // ###.#
    0b11111    // #####
  }
};

// Bricht das Kompilieren ab, wenn enum und Bitmaps nicht zusammenpassen
static_assert(sizeof(ICON_BITMAPS) / sizeof(ICON_BITMAPS[0]) == ICON_COUNT,
              "Anzahl der Bitmaps passt nicht zum enum Icon");

void loadIcons(rgb_lcd& lcd) {
  for (uint8_t i = 0; i < ICON_COUNT; i++) {
    lcd.createChar(i, const_cast<uint8_t*>(ICON_BITMAPS[i]));
  }
  lcd.setCursor(0, 0);   // Nach createChar() Cursor neu setzen
}