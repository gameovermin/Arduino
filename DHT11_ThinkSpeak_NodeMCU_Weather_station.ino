#include <DHT.h>
#include <ESP8266WiFi.h>
#define DHTPIN D3
#define DHTTYPE DHT11
#define REDPIN D4
// 와이파이 공유기의 SSID
const char* ssid = "U+Net99D7"; 
// 와이파이 공유기의 접속 비밀번호         
const char* password = "0138011185"; 

const char* server = "api.thingspeak.com";
String apiKey = "E3OMDF9SYDJN6768";

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE, D3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();
  Serial.println("ThingSpeak");

  pinMode(REDPIN, OUTPUT);
  
  // DHT11초기화
  dht.begin();
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);
  // Wi-Fi 초기화
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");

}

void loop() {
  // put your main code here, to run repeatedly:
  float t,h;
  t = dht.readTemperature();
  h = dht.readHumidity();

  if(isnan(h) || isnan(t)){
    Serial.println("Failed to read!!");
    return;
  }
  if(client.connect(server,80)){
    String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(t);  
           postStr +="&field2=";
           postStr += String(h);
           postStr += "\r\n\r\n";

    // Rest API POST 요청 : 웹서버에 resource 생성요청
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");

    //온도 데이터를 한번 전송하고 client와 연결을 끊고 15초 시간 지연 대기 한다.
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("Temp : ");
    Serial.print(t);
    Serial.print("\t Humidity : ");
    Serial.print(h);
    Serial.println("%. Send to Thingspeak.");
    
  }
  client.stop();

  digitalWrite(REDPIN, HIGH);
  delay(500);
  digitalWrite(REDPIN, LOW);
  delay(500);
  
  Serial.println("Waiting...");
  //ThingSpeak 무료계정은 업데이트 주기가 15초임
  delay(15000);

}
