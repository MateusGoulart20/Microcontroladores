#include <16F877A.h>
#device adc=8
#FUSES NOWDT //No Watch Dog Timer
#FUSES XT //Crystal osc <= 4mhz FOR PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES NOPUT //No Power Up Timer
#FUSES NOPROTECT //Code not protected from reading
#FUSES NODEBUG //No Debug mode FOR ICD
#FUSES BROWNOUT //Reset when brownout detected
#FUSES NOLVP //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD //No EE protection
#FUSES NOWRT //Program memory not write protected
#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
#ifndef lcd_enable
 #define lcd_enable pin_E1//pino enable DO LCD
 #define lcd_rs pin_E2//pino rs DO LCD
 //#define lcd_rw pin_e2//pino rw DO LCD
 #define lcd_d4 pin_d4//pino de dados d4 DO LCD
 #define lcd_d5 pin_d5//pino de dados d5 DO LCD
 #define lcd_d6 pin_d6//pino de dados d6 DO LCD
 #define lcd_d7 pin_d7//pino de dados d7 DO LCD
#endif
#include "C:\Alberto\IFMT 2023-II\Microcontroladores\Driver\mod_lcd.c"

void main()
{
   INT8 result;
   setup_adc_ports (NO_ANALOGS) ;
   setup_adc (ADC_OFF) ;
   setup_psp (PSP_DISABLED) ;
   setup_spi (SPI_SS_DISABLED) ;
   setup_timer_0 (RTCC_INTERNAL|RTCC_DIV_1) ;
   setup_timer_1 (T1_DISABLED) ;
   setup_timer_2 (T2_DISABLED,0,1) ;
   setup_comparator (NC_NC_NC_NC) ;
   setup_vref (FALSE) ;
   lcd_ini () ;
   delay_us (50) ;

   //TODO: USER CODE!!
   printf (lcd_escreve,"\f iniciando...");
   delay_ms (2000);
   write_eeprom (0,'A');//0x41
   result=read_eeprom (0) ;

   WHILE (true)
   {
      printf (lcd_escreve,"\f IFMT ");
      //printf ("\n\rTemp=%d",value) ;
      printf (lcd_escreve,"\n\rValor:%X",result);
      delay_ms (2000) ;
   }
}

