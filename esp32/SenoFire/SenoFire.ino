#include <WiFi.h>
//#include <FirebaseESP8266.h>

#define FIREBASE_HOST "acelero-cb785.firebaseapp.com"
#define FIREBASE_AUTH "AIzaSyATKxki4n_ukCwAURP3vvo54mox7o626VE"

#define WIFI_SSID "Bat sinal"
#define WIFI_PASSWORD "123456789"

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);

  // Conectar ao Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao Wi-Fi!");

  // Inicializar o Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // Gerar três formas de onda senoidais com frequências diferentes
  float freq1 = 1.0;  // Frequência em Hz
  float freq2 = 2.0;
  float freq3 = 3.0;

  float value1 = sin(2 * PI * freq1 * millis() / 1000.0);
  float value2 = sin(2 * PI * freq2 * millis() / 1000.0);
  float value3 = sin(2 * PI * freq3 * millis() / 1000.0);

  // Enviar dados para o Firebase
  Firebase.setFloat(firebaseData, "/senoides/seno1", value1);
  Firebase.setFloat(firebaseData, "/senoides/seno2", value2);
  Firebase.setFloat(firebaseData, "/senoides/seno3", value3);

  if (Firebase.failed()) {
    Serial.println("Falha ao enviar dados para o Firebase.");
    Serial.println(Firebase.error());
    return;
  }

  Serial.println("Dados enviados para o Firebase com sucesso.");

  delay(1000); // Aguardar 1 segundo antes de enviar novamente
}
