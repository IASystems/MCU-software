#define BUTTON_UP_PIN 16
#define BUTTON_DOWN_PIN 17
//#define BUTTON_

int stateUp = 0;
int stateDown = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_UP_PIN, INPUT);
  pinMode(BUTTON_DOWN_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readButtons();
}

void readButtons() {
	stateUp = digitalRead(BUTTON_UP_PIN);
	stateDown = digitalRead(BUTTON_DOWN_PIN);
	Serial.print(stateUp);
	Serial.println(stateDown);
	delay(200);
}