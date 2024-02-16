#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.clear();

}

void loop() {
  if (Serial.available() > 0) {
    String qr = Serial.readStringUntil('\n');
    Serial.print("ID : ");
    Serial.println(qr);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(qr);
    delay(10000);
  }

}
