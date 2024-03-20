#define pin A0
int deger, aci, tur, edeger;

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  deger = analogRead(pin);
  aci = map(deger, 0, 1023, 0, 360);
  if (deger < 100 && edeger > 900) {
    tur++;
  }
  Serial.println("Aci: " + String(aci));
  Serial.println("Deger: " + String(deger));
  Serial.println("Tur:  " + String(tur) + "\n");
  edeger = deger;
  delay(100);
}
