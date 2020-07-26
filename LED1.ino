int green = D6;

void setup() {
  // put your setup code here, to run once:
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  delay(1000);
}
