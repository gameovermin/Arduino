int green = D6;
int yellow = D7;
int red = D8;

void setup() {
  // put your setup code here, to run once:
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
//  blink_LED(green, 1000);
//  blink_LED(yellow, 1000);
//  blink_LED(red, 1000);
  int ran = random(1,4);
  Serial.println(ran);
  if(ran == 1){
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
    delay(1000);
  }
  if(ran == 2){
    digitalWrite(green,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    delay(1000);
  }
  if(ran == 3){
    digitalWrite(green,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(red,HIGH);
    delay(1000);
  }
}
//void blink_LED(int pinNo, int delayTime){
//  digitalWrite(pinNo, HIGH);
//  digitalWrite(pinNo, LOW);
//  delay(delayTime);
//}
