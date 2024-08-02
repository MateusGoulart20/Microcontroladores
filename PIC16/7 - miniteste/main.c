#include <16F877A.h>
#device adc=8

#FUSES NOWDT
#FUSES XT
#FUSES NOPUT
#FUSES NOPROTECT
#FUSES NODEBUG
#FUSES BROWNOUT
#FUSES NOLVP
#FUSES NOCPD
#FUSES NOWRT

#use delay(clock=6000000)


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
   
   delay_ms(100);
   int16 led3=1111, led4=625, led5=434;
   output_high(PIN_D1);
   while(true){
      if(!input(PIN_B0)){
         output_high(PIN_D2);   
      }else{
         output_low(PIN_D2);
      }
      delay_us(100);
      led3--; led4--; led5--;
      if(led3==0){
      output_toggle(PIN_D3); led3=55;
      }
      if(led4==0){
      output_toggle(PIN_D4); led4=31;
      }
      if(led5==0){
      output_toggle(PIN_D5); led5=21;
      }
      
   }
   output_low(PIN_D1);
}
