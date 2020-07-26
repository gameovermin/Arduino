int green = D6;
int yellow = D7;
int red = D8;

void setup() {
  // put your setup code here, to run once:
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  blink_LED(green, 1000);
  blink_LED(yellow, 1000);
  blink_LED(red, 1000);
}
void blink_LED(int pinNo, int delayTime){
  digitalWrite(pinNo, HIGH);
  digitalWrite(pinNo, LOW);
  delay(delayTime);
}
