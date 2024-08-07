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
      



void time(int y, int x){
   if(y == 1){
      output_high(PIN_A2);
      output_d(num[x]);
      delay_ms(5);
      output_low(PIN_A2);
   }
   if(y == 2){
      output_high(PIN_A3);
      output_d(num[x]);
      delay_ms(5);
      output_low(PIN_A3);
   }
   if(y == 3){
      output_high(PIN_A4);
      output_d(num[x]);
      delay_ms(5);
      output_low(PIN_A4);
   }
   if(y == 4){
      output_high(PIN_A5);
      output_d(num[x]);
      delay_ms(5);
      output_low(PIN_A5);
   }
}
void timeP(int y, int x){
   if(y == 1){
      output_high(PIN_A2);
      output_d(num[x]);
      delay_ms(1);
      output_low(PIN_A2);
      delay_ms(4);
   }
   if(y == 2){
      output_high(PIN_A3);
      output_d(num[x]);
      delay_ms(1);
      output_low(PIN_A3);
      delay_ms(4);
   }
   if(y == 3){
      output_high(PIN_A4);
      output_d(num[x]);
      delay_ms(1);
      output_low(PIN_A4);
      delay_ms(4);
   }
   if(y == 4){
      output_high(PIN_A5);
      output_d(num[x]);
      delay_ms(1);
      output_low(PIN_A5);
      delay_ms(4);
   }
}
void timer(int x, int y){
   int ds, un, tempo;
   while(x>=y){
      ds = x/10;
      un = x%10;
      for(tempo=0;tempo<100;tempo++){
         time(3,ds);
         time(4,un);
      }
      x--;
      if(x == -1) break;
   }
}
void timer(int x){
   timer(x,0);
}

void timerP(int x, int y){
   int ds, un, tempo;
   while(x>=y){
      ds = x/10;
      un = x%10;
      for(tempo=0;tempo<100;tempo++){
         timeP(3,ds);
         timeP(4,un);
         if(!(tempo%50)) output_toggle(PIN_B6);
      }
      x--;
      if(x == -1) break;
   }
}
void timerP(int x){
   timerP(x,0);
}

void main()
{

   setup_adc_ports(NO_ANALOGS);
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

   output_low(PIN_B2);
   output_low(PIN_B3);
   output_high(PIN_B4); // verde para carro
   output_low(PIN_B5);
   output_high(PIN_B6); // vermelho para pedestre
   output_low(PIN_B7);
   
   output_low(PIN_A4);
   //output_low(PIN_A5);
   output_high(PIN_C2);
   output_high(PIN_C1);
   
   delay_ms(100);
   while(true){
      
      /*
      output_high(PIN_A0);
      delay_ms(1000);
      output_high(PIN_A1);
      delay_ms(1000);
      output_low(PIN_A0);
      delay_ms(1000);
      output_low(PIN_A1);
      output_toggle(PIN_B7);
      */
      //*
      
      
      if( !input(PIN_B0) ){
         output_high(PIN_B7); // Controle Bot�o
         
         /// Sinaleiro
         // verde -> amarelo
         timer(14,4);
         //output_low(PIN_B4);
         //output_high(PIN_B3);
         output_high(PIN_B3);
         timer(3,1);// 3s amarelo
         
         // amarelo -> red
         output_low(PIN_B4);
         //output_high(PIN_B2);
         timer(0); // tempo de troca
         // verde pedrestr
         output_low(PIN_B6);
         output_high(PIN_B5);
         timer(15,5); // 8s para atravessar
         // vemrl pedest
         output_low(PIN_B5);
         timerP(5); // tempo de troca
         output_high(PIN_B6);
         delay_ms(1000);
         // verde carro
         output_low(PIN_B3);
         output_high(PIN_B4);
         
         delay_ms(20000); // intervalo para nova parada
         
      } else {
         output_low(PIN_B7);  // Controle Bot�o
      }//*/
      
      
      
      
   }
}
/*
      
      /*
       // 5s Verde
      output_high(PIN_D0);
      delay_ms(5000);
      output_low(PIN_D0);
      // 3s Amarelo
      output_high(PIN_D1);
      delay_ms(3000);   
      output_low(PIN_D1);
      // 1s Vermelho
      output_high(PIN_D2);
      delay_ms(1000);
      // Troca de via A->B
      output_low(PIN_B2);
      // 5s Verde
      output_high(PIN_B0);
      delay_ms(5000);
      output_low(PIN_B0);
      // 3s Amarelo
      output_high(PIN_B1);
      delay_ms(3000);
      output_low(PIN_B1);
      // 1s Vermelho
      output_high(PIN_B2);
      delay_ms(1000);
      // Troca de via B->A
      output_low(PIN_D2);
      */
      
      
      /* Liga para conclusao
      output_high(PIN_B7);  // Controle While
      delay_ms(500);
      output_low(PIN_B7); // Controle While
      delay_ms(500);*/
