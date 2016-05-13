void setup()
{
  pinMode(PIN_PC4, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Bluetooth2,");
  Serial.print("Brightness,");
  Serial.println(analogRead(PIN_PC4));
  delay(300000);
}
