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
   output_high(PIN_D2);
   output_low(PIN_D3);
   output_low(PIN_D4);
   output_low(PIN_D5);
   output_low(PIN_D6);
   output_low(PIN_D7);
   output_low(PIN_B0);
   output_low(PIN_B1);
   output_high(PIN_B2);
   output_low(PIN_B3);
   output_low(PIN_B4);
   output_low(PIN_B5);
   output_low(PIN_B6);
   output_low(PIN_B7);
   while(true){
      if( input(PIN_A0) ){
         output_high(PIN_D7); // Controle Bot�o
         
         /// Sinaleiro
         // verde -> amarelo
         output_low(PIN_D2);
         output_high(PIN_D1);
         delay_ms(3000); // 3s amarelo
         // amarelo -> red
         output_low(PIN_D1);
         output_high(PIN_D0);
         delay_ms(1000); // tempo de troca
         // verde pedrestr
         output_low(PIN_B1);
         output_high(PIN_B2);
         delay_ms(8000); // 8s para atravessar
         // vemrl pedest
         output_low(PIN_B2);
         output_high(PIN_B1);
         delay_ms(1000); // tempo de troca
         // verde carro
         output_low(PIN_D0);
         output_high(PIN_D2);
         
         delay_ms(20000); // intervalo para nova parada
         
      } else {
         output_low(PIN_D7);  // Controle Bot�o
      }      
      // Liga para conclusao
      output_high(PIN_B7);  // Controle While
      delay_ms(500);
      output_low(PIN_B7); // Controle While
      delay_ms(500);
   }
}
