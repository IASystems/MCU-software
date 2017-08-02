#include <Servo.h>

#define POSITION_BUTTON_PIN 14
#define REED_RELAY_PIN 15
#define SERVO_PIN 5
#define BUTTON_UP_PIN 16
#define BUTTON_DOWN_PIN 17

Servo servo;
byte dir = 90;

void setup()
{
	//servo.attach(SERVO_PIN);
	//servo.write(180);
	//delay(100000);
	Serial.begin(9600);
	pinMode(POSITION_BUTTON_PIN, INPUT);
	pinMode(REED_RELAY_PIN, INPUT);
	
}

void loop()
{

  /* add main program code here */
	readButtons();
	printEndTriggers();
}

void readButtons() {

	if (digitalRead(BUTTON_UP_PIN) == HIGH) {
		servo.attach(SERVO_PIN);
		//Serial.print("U ");
		dir = 0;
		if (digitalRead(REED_RELAY_PIN) == LOW)
			servo.write(dir);
		else
			servo.detach();
	}

	else if (digitalRead(BUTTON_DOWN_PIN) == HIGH) {
		servo.attach(SERVO_PIN);
		//Serial.print("D ");
		dir = 180;
		if (digitalRead(POSITION_BUTTON_PIN) == HIGH)
			servo.write(dir);
		else
			servo.detach();
	}
	else if (digitalRead(BUTTON_DOWN_PIN) == LOW && digitalRead(BUTTON_UP_PIN) == LOW) {
		servo.detach();
		//Serial.print("N ");
	}
	//Serial.println(dir);
}

void printEndTriggers() {
	Serial.print(digitalRead(POSITION_BUTTON_PIN));
	Serial.print(" | ");
	Serial.println(digitalRead(REED_RELAY_PIN));
}