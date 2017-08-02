#define REED_RELAY_PIN 18
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(REED_RELAY_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(REED_RELAY_PIN));
}
