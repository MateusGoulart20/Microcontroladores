#include <16F877A.h>
#device adc=8
#FUSES NOWDT //No Watch Dog Timer
#FUSES HS //High speed Osc (> 4mhz FOR PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT //No Power Up Timer
#FUSES NOPROTECT //Code not protected from reading
#FUSES NODEBUG //No Debug mode FOR ICD
#FUSES NOBROWNOUT //No brownout reset
#FUSES NOLVP //No low voltage prgming, B3(PIC16) or B5(PIC18) used FOR I/O
#FUSES NOCPD //No EE protection
#FUSES NOWRT //Program memory not write protected
#FUSES RESERVED //Used to set the reserved FUSE bits
#use delay(clock=20000000)

INT1 h_l=0;
unsigned INT16 ton=0,toff=0,pwm=40;

#INT_TIMER1
void TIMER1_isr(VOID)
{
   IF(h_l==0)
   {
      //Ton
      set_timer1(65536-pwm*50);//(65536-(pwm*10)/0.2)//63536
      h_l=1;
      output_high(PIN_D0);
      }ELSE{//Toff
      set_timer1(65536-(100-pwm)*50);//(65536-((100-pwm)*10)/0.2)//62536
      h_l=0;
      output_low(PIN_D0);
   }
}

void main()
{
   UNSIGNED int valor=0;
   FLOAT tensao=0;
   setup_adc_ports(AN0);//ajusta a porta A0 para entrada analógica
   setup_adc(ADC_CLOCK_DIV_16);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
   set_timer1(62536);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   output_low(PIN_D0);
   set_adc_channel(0);
   delay_us(50);

   WHILE(true)
   {
      valor=read_adc()*0.3922;//(100/255)=0,3922
      IF(valor>99)valor=100;
      IF(valor<1)valor=1;
      pwm=valor;
      delay_ms(100);
   }
}

