//#include <Wire.h>
//#include <Adafruit_Sensor.h>
//#include <Adafruit_MMA8451.h>
/*#include <esp32cam.h>

//#define SDA_PIN 13   // Pino SDA do MMA8453 conectado ao GPIO 5 do ESP32-CAM
//#define SCL_PIN 14  // Pino SCL do MMA8453 conectado ao GPIO 4 do ESP32-CAM

//Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup() {
  Serial.begin(9600);

 
}

void loop() {delay(500);}*/
#include "Arduino.h"
#include "esp_camera.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>
//#include <Adafruit_BME280.h>

// -----------------I2C-----------------
#define I2C_SDA 14 // SDA Connected to GPIO 14
#define I2C_SCL 15 // SCL Connected to GPIO 15
TwoWire I2CSensors = TwoWire(0);

// BME 280 (Using I2C)
Adafruit_BME280 bme;

// Sensor Variable (BME280)
float temperature, humidity;

void setup()
{
  Serial.begin(115200);

  I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);

  // BME 280 (0x77 or 0x76 will be the address)
  if (!bme.begin(0x76, &I2CSensors))
  {
    Serial.println("Couldn't Find BME280 Sensor");
    while (1)
      ;
  }
  else
  {
    Serial.println("BME280 Sensor Found");
  }
}

void loop()
{
  // -------------Temperature (C)------------------

  temperature = bme.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print(" *C - ");

  // ----------------------------------------------

  // ---------------Humidity (%)-------------------

  humidity = bme.readHumidity();
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  // ----------------------------------------------

  delay(1000);
}