#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

DHT TEMP_SENSOR(DHT_PIN, DHT_TYPE);

float temp, hum;

void setup()
{
	Serial.begin(115200);
	/* add setup code here */
	Serial.println("Connection established!");
	TEMP_SENSOR.begin();
}

void loop()
{
	readDHT();
	printReadings();
	// CHECK TRIGGERS
}

/* Reads Temperature and Humidity sensor */
void readDHT() {
	temp = TEMP_SENSOR.readTemperature();
	hum = TEMP_SENSOR.readHumidity();
	delay(500);
}

void printReadings() {
// do nothing if sensor fails to read
	if (isnan(temp) || isnan(hum)) {
		Serial.println("Waiting for sensor readings!");
		delay(2000);
		return;
	}
// Print temperature
	Serial.print("Temperature: ");
	Serial.print(temp);
	Serial.println("*C");

// Print humidity
	Serial.print("Humidity: ");
	Serial.print(hum);
	Serial.println("%");

// Wait for 2 seconds before getting back into loop
	delay(500);
}