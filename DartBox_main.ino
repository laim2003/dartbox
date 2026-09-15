#include <rgb_lcd.h>

#include <DIYables_Keypad.h>

const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {8, 7, 6, 5};      // rows 1–4 (top → bottom)
byte colPins[COLS] = {12, 11, 10, 9};   // columns 1–4 (left → right)
DIYables_Keypad keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

rgb_lcd lcd;

void setup() { 
  Serial.begin(115200); 

  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  if (key) lcd.print(key);
}