#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MMA8451.h>
#include <esp32cam.h>


#define I2C_SDA 14   // Pino SDA do MMA8453 conectado ao GPIO 5 do ESP32-CAM
#define I2C_SCL 15  // Pino SCL do MMA8453 conectado ao GPIO 4 do ESP32-CAM
TwoWire I2CSensors = TwoWire(0);

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup() {
  Serial.begin(115200);

  I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);
  
  if (!mma.begin()) {
    Serial.println("Não foi possível encontrar o acelerômetro MMA8453. Verifique as conexões!");
    while (1);
  }

  Serial.println("Acelerômetro MMA8453 encontrado!");
}

void loop() {
  sensors_event_t event;

  mma.getEvent(&event);

  Serial.print("Aceleração X: "); Serial.print(event.acceleration.x); Serial.print(" m/s^2\t");
  Serial.print("Aceleração Y: "); Serial.print(event.acceleration.y); Serial.print(" m/s^2\t");
  Serial.print("Aceleração Z: "); Serial.print(event.acceleration.z); Serial.println(" m/s^2");

  delay(500);
}
