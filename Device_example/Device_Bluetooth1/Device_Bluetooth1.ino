
void setup()
{
  pinMode(PIN_PC2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(PIN_PC0, HIGH);
  Serial.print("Bluetooth1,");
  Serial.print("Temperature,");
  Serial.println(analogRead(PIN_PC2));
  delay(300000);
}
