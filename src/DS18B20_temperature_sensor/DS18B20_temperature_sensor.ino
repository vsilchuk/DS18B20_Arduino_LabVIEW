// DS18B20 temperature sensor project

#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR_DATA_PIN 2

OneWire one_wire_connection(SENSOR_DATA_PIN);
DallasTemperature ds18b20_sensor(&one_wire_connection);

void setup(void)
{
  Serial.begin(9600);
  ds18b20_sensor.begin();
  ds18b20_sensor.setWaitForConversion(false);
}

void loop(void)
{
  ds18b20_sensor.requestTemperatures();

  delay(750);  // 750ms delay

  // 0 means the request to the first IC on the wire
  Serial.println(ds18b20_sensor.getTempCByIndex(0));  
}
