#include <ESP8266.h>

#define AP_NAME "Linksys13514"
#define AP_PASS "mrfwpuzyvs"
#define HOST_IP "10.206.113.132"
#define HOST_PORT 33333

ESP8266 wifi(Serial1,9600);

void setupWifi() 
{
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  
  if (!wifi.disableMUX()) 
  {
    Serial.println("Cannot disable MUX");
    return;
  }
  
  Serial.println("MUX disabled");
  
  if (!wifi.joinAP(AP_NAME,AP_PASS)) 
  {
    Serial.println("Cannot join AP successful");
    return;
  }
  
  Serial.println("Join AP successful");
}

void runWifi(char* value, int num) 
{
   if (!wifi.createTCP(HOST_IP,HOST_PORT)) 
  {
    Serial.println("Cannot establish TCP connection");
    return;
  }
  else
  {
    Serial.println("Send data");
    wifi.send((const uint8_t*)value, num);
    wifi.releaseTCP();
  }
}

String device = "WiFi2,Temperature,";
String data;
int value;
int num;
char charBuf[50];
  
void setup() 
{
  setupWifi();
}

void loop() 
{
  if(digitalRead(2))
  {
    digitalWrite(2, LOW);
  }
  else
  {
    digitalWrite(2, HIGH);
  }
  
  value = analogRead(A0);
  data = device + String(value);
  num = data.length();
  data.toCharArray(charBuf, 50);

  runWifi(charBuf,num);
  delay(300000);
}

