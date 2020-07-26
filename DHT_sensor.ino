#include <DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11


//DHT 객체 생성
DHT dht (DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print("    Humi : ");
  Serial.println(humi);
  delay(1000);
  
}
