#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  // lcd init
  lcd.begin();
  // lcd back light on
  lcd.backlight();
  //lcd.print("Test");
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" Humi: ");
  Serial.println(humi);
  
  // LCD Display
  // LCD Cursor change to (0,0)
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  // LCD Cursor change to (0,1)
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(humi);
  
  delay(1000);
}
