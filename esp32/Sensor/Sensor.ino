const int sensor = T5;
const int ledPin = T3;

void setup(){
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}
void loop(){
  Serial.println(touchRead(sensor));
  if(touchRead(sensor) > 30){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  delay(50);
}