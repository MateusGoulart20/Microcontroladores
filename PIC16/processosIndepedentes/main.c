#include <16F877A.h>
#device adc=8

#FUSES NOWDT //No Watch Dog Timer
#FUSES XT //Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES NOPUT //No Power Up Timer
#FUSES NOPROTECT //Code not protected from reading
#FUSES NODEBUG //No Debug mode for ICD
#FUSES BROWNOUT //Reset when brownout detected
#FUSES NOLVP //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD //No EE protection
#FUSES NOWRT //Program memory not write protected
#FUSES RESERVED //Used to set the reserved FUSE bits

#use delay(clock=4000000)

unsigned int cont_t0=0,cont_t1=0;
#int_RTCC
void RTCC_isr(void)
{
set_timer0(6);
if(++cont_t0>=10){
 cont_t0=0;
 output_toggle(PIN_D0);
}
}
#int_TIMER1
void TIMER1_isr(void)
{
 set_timer0(15536);
 if(++cont_t1>=2){
 cont_t1=0;
 output_toggle(PIN_D1);
 }
}
void main()
{
 setup_adc_ports(NO_ANALOGS);
 setup_adc(ADC_CLOCK_DIV_2);
 setup_psp(PSP_DISABLED);
 setup_spi(SPI_SS_DISABLED);
 setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
 setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);
 setup_timer_2(T2_DISABLED,0,1);
 setup_comparator(NC_NC_NC_NC);
 setup_vref(FALSE);
 enable_interrupts(INT_RTCC);
 enable_interrupts(INT_TIMER1);
 enable_interrupts(GLOBAL);
 while(true){
 }
}
