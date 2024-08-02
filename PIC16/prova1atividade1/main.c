#include <16F877A.h>
#device adc=8

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

#use delay(clock=20000000)



void setPosi(int8 x, int8 delay){
   switch (x){
      case 1:
         output_d(0b00000001);
         output_high(PIN_A5);
         delay_ms(delay);
         output_low(PIN_A5);
      break;
      case 2:
         output_d(0b00000010);
         output_high(PIN_A5);
         delay_ms(delay);
         output_low(PIN_A5);
      break;
      case 3:
         output_d(0b00000100);
         output_high(PIN_A5);
         delay_ms(delay);
         output_low(PIN_A5);
      break;
      case 4:
         output_d(0b00001000);
         output_high(PIN_A5);
         delay_ms(delay);
         output_low(PIN_A5);
      break;
      case 5:
         output_d(0b00001000);
         output_high(PIN_A4);
         delay_ms(delay);
         output_low(PIN_A4);
      break;
      case 6:
         output_d(0b00010000);
         output_high(PIN_A4);
         delay_ms(delay);
         output_low(PIN_A4);
      break;
      case 7:
         output_d(0b00100000);
         output_high(PIN_A4);
         delay_ms(delay);
         output_low(PIN_A4);
      break;
      case 8:
         output_d(0b00000001);
         output_high(PIN_A4);
         delay_ms(delay);
         output_low(PIN_A4);
      break;
      default: return;
   }
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
   output_d(0b01001111);
   output_low(PIN_A4);
   output_low(PIN_A5);
   
   
   
   unsigned int8 cont = 0, entrada = 0, max = 0, min = 1000;
   
   while(true){
      entrada = read_adc();
      entrada = (int8)(-0.44117647*entrada+125);
      cont++;
      setPosi(cont,entrada); // 125 = 1Hz ; 12,5 = 10Hz
      if(cont == 8) cont = 0;
   }

}
