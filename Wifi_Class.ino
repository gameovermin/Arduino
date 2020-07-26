#include <ESP8266WiFi.h>
#include "DHT.h"
const char* ssid = "MEGAcoffee";  //공유기 이름(핫스팟)
const char* password = "mg90609060";  //공유기 비밀번호(핫스팟비밀번호)
#define DHTPIN D4  // what pin we're connected to
#define DHTTYPE DHT11  // DHT 11
DHT dht(DHTPIN, DHTTYPE);

WiFiServer server(80); //웹서버용 포트 번호

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.print("Connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  dht.begin();

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // 웹서버 개시
  server.begin();
  Serial.println("HTTP server started");

  //접속할 IP 주소 표시
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}


void loop() {
  // put your main code here, to run repeatedly:
  // 클라이언트가 접속되었는지 확인
  WiFiClient client = server.available();
  //Serial.println(client);
  
  if(!client){
    return; //함수 실행 종료
  }
  // 클라이언트가 데이터를 보낼 때까지 기다림
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // 클라이언트 리퀘스트의 첫번째 줄을 읽어들임. http 요청
  String request = client.readStringUntil('\n');
  Serial.println(request);
  client.flush();
  // Client request 읽기

  //클라이언트 리퀘스트에 대한 응답 메시지를 시리얼 통신으로 클라이언트에 전송
  client.println("HTT/1.1 200 OK");
  client.println("Content-Type : text/html");
  client.println("Connection: closse");
  client.println();
  client.println("<!DOCTYPE HTML>");
  // Http response Header 보내기
  client.println("<html>");
  client.println("<meta htp-equvi=\"refresh\" content=\"5\">");
  client.println("<br />");
  client.println("");  // do net forget this one
  // Message 내용 보내기

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  client.print("<h2>Weather Station</h2>");
  client.print("Temperature (C) : ");
  client.println(t);
  client.println("<p />");

  client.print("Humidity (%) : ");
  client.println(h);
  client.println("<p />");

  client.println("</html>");
  delay(1);
  Serial.println("Client disconnected");
}
