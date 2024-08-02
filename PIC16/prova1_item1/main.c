#include <16F877A.h>
#device adc=8

#FUSES NOWDT
#FUSES HS
#FUSES NOPUT
#FUSES NOPROTECT
#FUSES NODEBUG
#FUSES BROWNOUT
#FUSES NOLVP
#FUSES NOCPD
#FUSES NOWRT

#use delay(clock=20000000)

byte const num[11]={
   0b00111111,  //0
   0b00000110,  //1
   0b01011011,  //2
   0b01001111,  //3
   0b01100110,  //4      
   0b01101101,  //5 
   0b01111101,  //6 
   0b00000111,  //7 
   0b01111111,  //8
   0b01101111   //9      
}; 
      

int passo(){
   int x= read_adc();
   int b = (x*200/255)+100;
   return b;
}

void time(int y, int x){
   if(y == 1){
      output_high(PIN_A2);
      output_d(num[x]);
      delay_us(500);
      output_low(PIN_A2);
   }
   if(y == 2){
      output_high(PIN_A3);
      output_d(num[x]);
      delay_us(500);
      output_low(PIN_A3);
   }
   if(y == 3){
      output_high(PIN_A4);
      output_d(num[x]);
      delay_us(500);
      output_low(PIN_A4);
   }
   if(y == 4){
      output_high(PIN_A5);
      output_d(num[x]);
      delay_us(500);
      output_low(PIN_A5);
   }
}
void timer(int x, int y){
   unsigned int16 ds, un, tempo, pas, adc;
   while(x>=y){
      ds = x/10;
      un = x%10;
      adc = read_adc();
      pas = (adc*200/255)+100;
      //pas = 1000; // máximo
      //pas = 3000; // máximo
      for(tempo=0;tempo<pas;tempo++){
         time(3,ds);
         output_toggle(PIN_B4);
         time(4,un);
         output_toggle(PIN_B4);
         // soma de 10ms = 0.001s = 10ms
      }
      output_toggle(PIN_B5);
      x--;
      if(x == -1) break;
   }
}
void timer(int x){
   timer(x,0);
}

void main()
{

   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   // TODO: USER CODE!!
   output_low(PIN_D0);
   output_low(PIN_D1);
   output_low(PIN_D2);
   output_low(PIN_D3);
   output_low(PIN_D4);
   output_low(PIN_D5);
   output_low(PIN_D6);
   output_low(PIN_D7);
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_low(PIN_B2);
   output_low(PIN_B3);
   output_low(PIN_B4);
   output_low(PIN_B5);
   output_low(PIN_B6);
   output_low(PIN_B7);
   
   output_low(PIN_A4);
   //output_low(PIN_A5);
   output_high(PIN_C2);
   output_high(PIN_C1);
   
   delay_ms(100);
      
   //unsigned int8 passo = 0;
   while(true){
     
      //passo = read_adc();
       //output_d(passo);
      
      
      timer(99); // tempo de troca

      
      
      
      
   }
}

