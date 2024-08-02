//#include "C:\Users\danie\Documents\Microcontroladores\Projeto\Codigomorse.h"
#include <16F877A.h>
#include <string.h>
//#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES RESERVED                 //Used to set the reserved FUSE bits

#use delay(clock=6000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

char morseletter[][] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-."
, "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"};
char const alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', 'E'};
char moresenumber[][] = {".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"};
char numbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

void dot() {
    output_high(PIN_D0);
    delay_ms(100);
    output_low(PIN_D0);
    delay_ms(100);
}

void dash() {
    output_high(PIN_D0);
    delay_ms(300);
    output_low(PIN_D0);
    delay_ms(100);
}
void main() {
    char message[] = "Hello";
    String MMessage = texttomorse(message);
}
String texttomorse(String message){
   String morsemessage = "";
   for(int i = 0; i<strlen(message); i++){
      char letter = message[i];
      
      for(int j = 0; j<27; j++){
         if(letter == alphabet[j]){
            MMessage +=morse[j];
            break;
         }
      }
   }
}
void gensignal(String MMessage){
   for (int i = 0; i< strlen(MMessage); i++){
      for(int j = 0; j< strlen(MMessage)[i];j++){
         if(MMessage[i][j]=="."){
            dot();
         }
         if(MMessage[i][j]=="-"){
            dash();
         }
      }
      
   }
}

