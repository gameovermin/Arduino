int green = D6;
int yellow = D7;

void setup() {
  // put your setup code here, to run once:
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  delay(1000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000);
}
