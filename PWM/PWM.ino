const int ledPin =12;

const int freq = 1000;
const int ledChannel = 1;
const int resolution = 8;
const int d = 5;
const float asc[45] =
{0.035, 0.07, 0.105, 0.139, 0.174
,0.208, 0.249, 0.276, 0.309, 0,342
,0.375, 0.407, 0.438, 0.469, 0.5
,0.53, 0.559, 0.588, 0.616, 0.643
,0.669, 0.695, 0.719, 0.735, 0.766
,0.788, 0.809, 0.829, 0.848, 0.866
,0.883, 0.899, 0.914, 0.927, 0.94
,0.951, 0.961, 0.97, 0.978, 0.985
,0.99, 0.995, 0.998, 0.999};

void setup(){
  ledcSetup(ledChannel, freq, resolution);

  ledcAttachPin(ledPin, ledChannel);
}


void loop(){
  ledcWrite(ledChannel, 127);
  delay(d);
  for (int posi = 0; posi <= 44; posi++){
    // 127 to 255
    ledcWrite(ledChannel, 127*(1+asc[posi]));
    delay(d);
  }
  ledcWrite(ledChannel, 255);
  delay(d);
  for (int posi = 44; posi >= 0; posi--){
    // 255 to 127
    ledcWrite(ledChannel, 127*(1+asc[posi]));
    delay(d);
  }
  ledcWrite(ledChannel, 127);
  delay(d);
  for (int posi = 0; posi <= 44; posi++){
    // 127 to 0
    ledcWrite(ledChannel, 127*(1-asc[posi]));
    delay(d);
  }
  ledcWrite(ledChannel, 0);
  delay(d);
  for (int posi = 44; posi >= 0; posi--){
    // 0 to 127
    ledcWrite(ledChannel, 127*(1-asc[posi]));
    delay(d);
  }
  /*
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){
    ledcWrite(ledChannel, dutyCycle);
    delay(5);
  }
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledChannel, dutyCycle);
    delay(5);
  }
  */


}