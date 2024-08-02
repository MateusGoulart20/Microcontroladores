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
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

void main()
{
   setup_adc_ports(AN0_AN1_AN3);
      setup_adc(ADC_CLOCK_DIV_16);
      setup_psp(PSP_DISABLED);
      setup_spi(SPI_SS_DISABLED);
      setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
      setup_timer_1(T1_DISABLED);
      setup_timer_2(T2_DIV_BY_16,255,1);
      setup_ccp1(CCP_PWM);
      
      setup_comparator(NC_NC_NC_NC);
      setup_vref(FALSE);
      
      set_adc_channel(0);delay_ms(50);
   // TODO: USER CODE!!
   int1 movimento = 0, lado = 1; 
   int8 percurso =0;
   // movimento{0:parado;1:movimentando}
   // lado{0:esquerda;1:direira}
   while(true){
      if(!(input(PIN_B0))){ // bot�o clicado
         if(movimento){ // se andando -> para e muda lado
            movimento = !movimento;
            lado = !lado;
         }else{
            movimento = !movimento; // se paradao -> anda
         }
         delay_ms(500);
      }
      if(movimento){
         percurso += -1+2*lado;
         /*
         if(lado){
            percurso++;
         }else{
            percurso--;
         }*/
      }
      if(percurso<1||percurso>254){
         if(movimento){
            movimento = !movimento;
            lado = !lado;
         }
         
      }
      // notas leds
      if(lado){
         output_high(PIN_B1);
      }else{
         output_low(PIN_B1);
      }
      if(movimento){
         output_high(PIN_B2);
      }else{
         output_low(PIN_B2);
      }
      output_d(percurso);
      set_pwm1_duty(percurso);
      delay_ms(10);
   }
}