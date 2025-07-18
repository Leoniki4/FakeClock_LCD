#include <LiquidCrystal.h>


// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long TempoPrecedente = 0;
int secondi = 0;
int minuti = 0; 



void setup() {
  lcd.begin(16, 2);
  lcd.print("tempo");
}


void loop() {
  unsigned long TempoCorrente = millis();


if (TempoCorrente - TempoPrecedente >= 1000) {
  TempoPrecedente = TempoCorrente;
  secondi++; 
  if (secondi >= 60) {
    secondi = 0; 
    minuti++;
  }
  lcd.setCursor(0, 1);
  if (minuti < 10) lcd.print("0");
  lcd.print(minuti);
  lcd.print(":");
  if (secondi < 10) lcd.print("0");
  lcd.print(secondi);
}

