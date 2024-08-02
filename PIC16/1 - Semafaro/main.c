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
   output_low(PIN_D1);
   output_low(PIN_D2);
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
   }
}
