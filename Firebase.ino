//아두이노 Firebase 라이브러리
#include <ESP8266WiFi.h>                                               
#include <FirebaseArduino.h>  
//데이터베이스 호스트 이름
#define FIREBASE_HOST "fir-led-control-899a4.firebaseio.com"
//데이터베이스 비밀번호
#define FIREBASE_AUTH "vb5TYToFBfQZRxeHINcMWf1cOUtyQkjVEqb0WVbw"
//Wi-Fi 설정
#define WIFI_SSID "U+Net99D7"
#define WIFI_PASSWORD "0138011185"

String red_fireStatus = "";  // firebase DB로 부터 받은 값 저장
String blue_fireStatus = ""; 

int red_led = D4; // NodeMCU LED pin
int blue_led = D3;

void setup() 
{
  Serial.begin(9600);
  delay(1000);    
  pinMode(red_led, OUTPUT);  
  pinMode(blue_led, OUTPUT);
                 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                               
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // connect to firebase
  Firebase.setString("RED_LED_STATUS", "OFF"); //send initial string of led status
  Firebase.setString("BLUE_LED_STATUS", "OFF");//send initial string of led status
}
 
void loop() 
{
  red_fireStatus = Firebase.getString("RED_LED_STATUS");     // firebase에서 입력된 값을 가져온다
  if (red_fireStatus == "ON")   { // firebase에 RED_LED_STATUS가 ON이면
    Serial.println("RED LED Turned ON");                                                        
    digitalWrite(red_led, HIGH);          // Red led ON
  } 
  else if (red_fireStatus == "OFF") {    // firebase에 RED_LED_STATUS가 OFF이면
    Serial.println("RED LED Turned OFF");
    digitalWrite(red_led, LOW);      // Red led OFF
  } else {
    Serial.println("Command Error! Please send ON/OFF");
  }

  delay(2000);

  blue_fireStatus = Firebase.getString("BLUE_LED_STATUS");     // firebase에서 입력된 값을 가져온다
  if (blue_fireStatus == "ON")   { // firebase에 BLUE_LED_STATUS가 ON이면
    Serial.println("BLUE LED Turned ON");                                                        
    digitalWrite(blue_led, HIGH);          // Blue led ON
  } 
  else if (blue_fireStatus == "OFF") {    // firebase에 BLUE_LED_STATUS가 OFF이면
    Serial.println("BlUE LED Turned OFF");
    digitalWrite(blue_led, LOW);      // Blue led OFF
  } else {
    Serial.println("Command Error! Please send ON/OFF");
  }

  delay(2000);
}
