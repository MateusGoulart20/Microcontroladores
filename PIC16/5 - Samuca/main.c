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


   // D0 = Vermelho
      // D1 = Amarelo
      // D2 = Verde1
      
      // B0 = Vermelho
      // B1 = Amarelo
      // B2 = Verde
      
      output_low(PIN_D0);
      output_low(PIN_D1);
      output_low(PIN_D3);
      output_low(PIN_D4);
      output_low(PIN_D5);
      output_low(PIN_D6);
      output_low(PIN_D7);
      output_low(PIN_B1);
      output_low(PIN_B2);
      output_low(PIN_B3);
      output_low(PIN_B4);
      output_low(PIN_B5);
      output_low(PIN_B6);
      output_low(PIN_B7);
      
      output_high(PIN_D2); // Acende Luz Verde
      output_high(PIN_B0); // Luz vermelha para os Pedestres
      //delay_ms(1000);
      
   while(true){
      
      if(input(PIN_B0)){
         //output_toggle(PIN_B6);
         delay_ms(500);
         output_low(PIN_D2);
         output_high(PIN_D1);
         delay_ms(3000);
         output_low(PIN_D1);
         output_low(PIN_B1);
         output_high(PIN_D0);
         output_high(PIN_B2);
         delay_ms(10000);
         int i = 0;
         for(i=0; i<4; i++){
            output_low(PIN_B1);
            delay_ms(500);
            output_high(PIN_B2);
            delay_ms(500);
         }
         delay_ms(1000);
         output_low(PIN_D0);
         output_high(PIN_D2);//*/
      }
   }
}
