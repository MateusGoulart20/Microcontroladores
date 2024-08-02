#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Firebase_ESP8266.h>
#include <esp32cam.h>


#define FIREBASE_HOST "seu-projeto.firebaseio.com"
#define FIREBASE_AUTH "sua-chave-de-autenticacao"

#define WIFI_SSID "seu-ssid"
#define WIFI_PASSWORD "sua-senha"

FirebaseData firebaseData;

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);

void setup() {
  Serial.begin(115200);

  // Conectar ao Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao Wi-Fi!");

  // Inicializar o acelerômetro
  if (!accel.begin()) {
    Serial.println("Não foi possível inicializar o acelerômetro. Verifique a conexão.");
    while (1);
  }

  // Inicializar o Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Ler os dados do acelerômetro
  sensors_event_t event;
  accel.getEvent(&event);

  // Enviar dados para o Firebase
  Firebase.setFloat(firebaseData, "/acelerometro/x", event.acceleration.x);
  Firebase.setFloat(firebaseData, "/acelerometro/y", event.acceleration.y);
  Firebase.setFloat(firebaseData, "/acelerometro/z", event.acceleration.z);

  if (Firebase.failed()) {
    Serial.println("Falha ao enviar dados para o Firebase.");
    Serial.println(Firebase.error());
    return;
  }

  Serial.println("Dados enviados para o Firebase com sucesso.");

  delay(1000); // Aguardar 1 segundo antes de enviar novamente
}
