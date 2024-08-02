const int sensor = T5;
const int ledPin = T3;
const int anaCond = 34; // + valor = desconectado -> - valor = curto
const int anaLux = 35; // - valor = + luz -> + valor = - luz

double minLux, maxLux, minCond, maxCond;
double trans, aLux, bLux, aCond, bCond;
double vLux, vCond;


void setup(){
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  delay(1000);
  // valores obtidos na zona de teste.
  trans = analogRead(anaLux);
  minLux = trans; //1507 maior intensidade obtida // 1700 começo regular
  maxLux = trans; //2480 menor intensidade obtida // 2300 começo regular
  trans = analogRead(anaCond);
  minCond = trans; //2185 maior sanalidade obtida// 2300 começo regular
  maxCond = trans; //2544 menor sanalidade obtida// 2400 começo regular
}

void atualizarLux(){
  aLux = 1/( (double)minLux - (double)maxLux );
  bLux = (double)maxLux / ( (double)maxLux - (double)minLux );
}
void atualizarCond(){
  aCond = 1/( (double)minCond - (double)maxCond );
  bCond = (double)maxCond /( (double)maxCond - (double)minCond );
}

void loop(){
  // balanceamento de luz
  vLux = analogRead(anaLux);
  vCond = analogRead(anaCond);
  delay(100);

  if(vLux > maxLux ){
    maxLux = vLux;
    atualizarLux();
  }
  if(vLux < minLux ){
    minLux = vLux;
    atualizarLux();
  }
  if(vCond > maxCond ){
    maxCond = vCond;
    atualizarCond();
  }
  if(vCond < minCond ){
    minCond = vCond;
    atualizarCond();
  }
  
  //Serial.println();
  //Serial.print("  Lux: ");
  //Serial.print(analogRead(anaLux));
  //Serial.print("  %: ");
  //Serial.print("1,0,");
  Serial.print("4095,0");
  //Serial.print(aLux*vLux+bLux,8);
  Serial.print(",");
  Serial.print(vLux);
  //Serial.print((-0.025)*trans+(66),8);
  //Serial.print("  M: ");
  Serial.print(",");
  Serial.print(maxLux);
  Serial.print(",");
  Serial.print(minLux);
  //Serial.print("  a: ");
  //Serial.print(aLux,6);
  //Serial.print("  b: ");
  //Serial.print(bLux);
  
  
  //Serial.println(touchRead(sensor));
  //Serial.println(analogRead(anaCond));
  //Serial.print("    Cond: ");
  //Serial.print(analogRead(anaCond));
  //Serial.print("  %: ");
  //Serial.println(aCond*vCond+bCond,8);
  Serial.print(",");
  Serial.print(vCond);
  //Serial.print("  M: ");
  Serial.print(",");
  Serial.print(maxCond);
  //Serial.print("  m: ");
  Serial.print(",");
  Serial.print(minCond);
  //Serial.print("  a: ");
  //Serial.print(aCond,6);
  //Serial.print("  b: ");
  //Serial.print(bCond);
  Serial.println();
  /*
  if(touchRead(sensor) > 30){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }*/
}