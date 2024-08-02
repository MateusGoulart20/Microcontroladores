#include <WiFi.h>         
#include <IOXhop_FirebaseESP32.h>                           
#include <ArduinoJson.h>                   

#define WIFI_SSID "Daniel's Galaxy S22+"                   
#define WIFI_PASSWORD "fktl2836"         
#define FIREBASE_HOST "https://acelerometro-d9175-default-rtdb.firebaseio.com/"    
#define FIREBASE_AUTH "x6nzxPoROZvoWdONQAzWWnHtUdGEeZypl9qmkWNA"   
#include "RoboCore_MMA8452Q.h"
float x, y, z;
MMA8452Q acel;
void setup() {
  Serial.begin(9600);
  Serial.println();
  acel.init();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  Serial.print("Conectando ao wifi");
  
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}






void loop() {
  
//Exemplo da função Get

/*
  Serial.println();
  Serial.print("Dono do quarto: ");
  Serial.print(Firebase.getString("/quarto/dono"));
  Serial.println();
  Serial.print("Luminosidade do quarto: ");
  Serial.print(Firebase.getInt("/quarto/luminosidade"));
  Serial.println();
  Serial.print("Temperatura do quarto: ");
  Serial.print(Firebase.getFloat("/quarto/temperatura"));
  Serial.println();
  Serial.print("O quarto está ocupado: ");
  Serial.print(Firebase.getBool("/quarto/ocupado"));
  Serial.println();
  Serial.print("Luminosidade da sala: ");
  Serial.print(Firebase.getInt("/sala/luminosidade"));
  Serial.println();
  delay(3000);
*/

//Exemplo da função Set


  /*Firebase.setFloat("/Aceletrometroo/anguloX", 20.25);
  Firebase.setFloat("/Aceletrometroo/anguloY", 30.35);
  Firebase.setFloat("/Aceletrometroo/anguloZ", 40.55);
  delay(3000);
  Firebase.setFloat("/Aceletrometroo/anguloX", 90.95);
  Firebase.setFloat("/Aceletrometroo/anguloY", 80.85);
  Firebase.setFloat("/Aceletrometroo/anguloZ", 70.75);
  delay(3000);
*/

//Exemplo da função Push

/*
  Firebase.pushString("/quarto/registro", "Matteo");
  delay(3000);
  Firebase.pushString("/quarto/registro", "Rebeca");
  delay(3000);
  Firebase.pushString("/quarto/registro", "Vanderson");
  delay(3000);
  Firebase.pushString("/quarto/registro", "Raquel");
  delay(3000);
*/
  acel.read();
  //Serial.print(acel.x);
  x = acel.x;
  //Serial.print(" - ");
  //Serial.print(acel.y);
  y = acel.y;
  //Serial.print(" - ");
  //Serial.println(acel.z);
  z = acel.z;
  Firebase.setFloat("/Aceletrometro/EixoX", x);
  Firebase.setFloat("/Aceletrometro/EixoY", y);
  Firebase.setFloat("/Aceletrometro/EixoZ", z);



  delay(1000);
  

}
