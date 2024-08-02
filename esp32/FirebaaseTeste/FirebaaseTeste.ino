#include <WiFi.h>
#include <Firebase_ESP32.h>
#include <ArduinoJson.h>

#define FIREBASE_HOST "acelero-cb785.firebaseapp.com"
#define FIREBASE_AUTH "AIzaSyATKxki4n_ukCwAURP3vvo54mox7o626VE"

#define WIFI_SSID "🐶🐶🐶🐶"
#define WIFI_PASSWORD "eleventwo"

#define CAM_PIN 5 // Pino da câmera no ESP32

void setup() {
  Serial.begin(115200);

  // Conectar-se à rede Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");

  // Inicializar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // Configurar pino da câmera
  pinMode(CAM_PIN, INPUT);
}

void loop() {
  // Ler valor do pino da câmera
  int sensorValue = digitalRead(CAM_PIN);

  // Enviar dados para o Firebase
  sendToFirebase(sensorValue);

  delay(5000); // Aguardar 5 segundos antes de enviar novamente
}

void sendToFirebase(int value) {
  // Criar objeto JSON para os dados a serem enviados
  DynamicJsonDocument jsonDocument(200);
  jsonDocument["camValue"] = value;

  // Converter JSON para string
  String jsonString;
  serializeJson(jsonDocument, jsonString);

  // Enviar dados para o Firebase
  Firebase.setString("caminho/para/seu/dado", jsonString);

  Serial.println("Dado enviado para o Firebase: " + jsonString);
}
