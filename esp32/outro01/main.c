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
   
   while(true){
      output_high(PIN_D0);
      delay_ms(1000);
      output_high(PIN_D1);
      delay_ms(1000);
      output_high(PIN_D2);
      delay_ms(1000);
      output_high(PIN_D3);
      delay_ms(1000);
      output_high(PIN_D4);
      delay_ms(1000);
      output_high(PIN_D5);
      delay_ms(1000);
      output_high(PIN_D6);
      delay_ms(1000);
      output_high(PIN_D7);
      delay_ms(1000);
      output_low(PIN_D0);
      delay_ms(1000);
      output_low(PIN_D1);
      delay_ms(1000);
      output_low(PIN_D2);
      delay_ms(1000);
      output_low(PIN_D3);
      delay_ms(1000);
      output_low(PIN_D4);
      delay_ms(1000);
      output_low(PIN_D5);
      delay_ms(1000);
      output_low(PIN_D6);
      delay_ms(1000);
      output_low(PIN_D7);
      delay_ms(1000);
   }
}
