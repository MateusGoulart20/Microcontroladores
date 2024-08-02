#include <ArduinoJson.h>
#include <IOXhop_FirebaseESP32.h>
#include <WiFi.h>

#include "RoboCore_MMA8452Q.h"

#define FIREBASE_HOST "https://acelero-cb785-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "7EK4s8wv1HnJHvIyFukt7keHEtnRobJGTgCGipYA"

#define WIFI_SSID "Galaxy A51 7C6A"
#define WIFI_PASSWORD "adez6361"


//Criamos a instancia que nos ajudara a fazer as leituras
MMA8452Q acel;

void setup() {
  
  //Iniciamos uma comunicacao serial para exibir os valores no Monitor Serial
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);     //inicia comunicação com wifi com rede definica anteriormente
  
  Serial.print("Conectando ao wifi\n");       //imprime "Conectando ao wifi"
  while (WiFi.status() != WL_CONNECTED)     //enquanto se conecta ao wifi fica colocando pontos
  {
    Serial.print(WiFi.status());
    delay(300);
  }
  Serial.println("--- Tudo Certo ---");                         //imprime pulo de linha

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   //inicia comunicação com firebase definido anteriormente


  //Inicializamos o acelerometro com uma funcao interna da biblioteca
  acel.init();

}

void loop() {
  
  //Com um unico comando fazemos a leitura do acelerometro e a partir dai ja temos as componentes X, Y e Z de uma forma simples para analise
  acel.read();
  float x = acel.x;
  Firebase.setFloat("/tres/a", x);
  float y = acel.y;
  Firebase.setFloat("/tres/b", y);
  float z = acel.z;
  Firebase.setFloat("/tres/c", z);

  Serial.print(acel.x);
  Serial.print(" - ");
  Serial.print(acel.y);
  Serial.print(" - ");
  Serial.println(acel.z);
  delay(500);
  //Se houver movimento no dispositivo, imprimimos no Monitor Serial uma mensagem
  //if((acel.x > 0.40) || (acel.y/ > 0.40) || (acel.z < 0.80)){
 //   Serial.println("ALERTA! MOVIMENTO DETECTADO");
//  }
  
}