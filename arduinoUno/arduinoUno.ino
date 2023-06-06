#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
//  Serial.print("Kelembaban : ");
  Serial.print(h);
  Serial.print(",");
  Serial.println(t);
//  Serial.println("°C ");
  delay(1000);
}
