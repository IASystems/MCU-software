void setup()
{
	Serial.begin(115200);
	Serial.println("Djla");
	pinMode(13, OUTPUT);
	while (true){
		digitalWrite(13, LOW);
		delay(1000);
		digitalWrite(13, HIGH);
		delay(1000);
	}
}

void loop()
{

  /* add main program code here */

}
