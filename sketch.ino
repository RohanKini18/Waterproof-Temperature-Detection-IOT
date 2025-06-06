#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(2);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
}

void loop() {
  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");
  delay(1000);
}