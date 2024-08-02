#include <16F877A.h>
#device ADC=10
#FUSES NOWDT //No Watch Dog Timer
#FUSES NOBROWNOUT //No brownout reset
#FUSES NOLVP //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#use delay(crystal=20000000)
#define LED PIN_D2
int16 Ton=0;
int16 Toff=0;
void main()
{
 //Example blinking LED program
 while(true){
 int16 i;
 for( i=0;i<10000;i++){ // demorar 10 segundos
 output_high(LED);
 Ton=i/10;
 delay_us(Ton);
 output_low(LED);
 Toff=1000 - Ton;
 delay_us(Toff);
 }
 int16 j;
 for( j=10000;j>0;j--){ // demorar 10 segundos
 output_high(LED);
 Ton=j/10;
 delay_us(Ton);
 output_low(LED);
 Toff=1000 - Ton;
 delay_us(Toff);
 }
 }
}
