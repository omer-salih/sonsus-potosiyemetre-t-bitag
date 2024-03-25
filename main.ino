#include <LiquidCrystal_I2C_AvrI2C.h>

#define pin A0
int deger, aci, tur, edeger, mesafe;

LiquidCrystal_I2C_AvrI2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  deger = analogRead(pin);
  aci = map(deger, 0, 4095, 0, 360);
  if (deger < 100 && edeger > 900) {
    tur++;
  }

  lcd.setCursor(0,0);
  Serial.println("Aci:" + String(aci));
  lcd.print("Aci: " + String(aci));

  lcd.setCursor(9,0);
  Serial.println("Tur:" + String(tur));
  lcd.print("Tur: " + String(tur));

  mesafe = (tur * 66) + map(aci, 0, 360, 0, 66);
  lcd.setCursor(0,1);
  Serial.println("Mesafe:" + String(mesafe));
  lcd.print("Mesafe: " + String(mesafe));

  edeger = deger;
  delay(100);
}
