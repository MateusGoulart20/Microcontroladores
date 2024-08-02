#include <16F877A.h>
#device adc=8
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz FOR PCM/PCH) (>10mhz for PCD)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NODEBUG                  //No Debug mode FOR ICD
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used FOR I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES RESERVED                 //Used to set the reserved FUSE bits
#use delay(clock=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

#ifndef lcd_enable
 #define lcd_enable pin_E1 // pino enable do LCD
 #define lcd_rs pin_E2 // pino rs do LCD
 //#define lcd_rw pin_e2 // pino rw do LCD
 #define lcd_d4 pin_d4 // pino de dados d4 do LCD
 #define lcd_d5 pin_d5 // pino de dados d5 do LCD
 #define lcd_d6 pin_d6 // pino de dados d6 do LCD
 #define lcd_d7 pin_d7 // pino de dados d7 do LCD
#endif
#include "C:\Users\mateu\Desktop\2023-2\Microcontroladores\PICC\Drivers\mod_lcd.c"


      INT8 ler_teclado()
   {
         WHILE(true){
            
         output_low(PIN_B0);output_high(PIN_B1);output_high(PIN_B2);output_high(PIN_B3);delay_ms(10);
         if(input(PIN_D0)==0)RETURN-1;
         if(input(PIN_D1)==0)RETURN 7;
         if(input(PIN_D2)==0)RETURN 4;
         if(input(PIN_D3)==0)RETURN 1;
         
         output_high(PIN_B0);output_low(PIN_B1);delay_ms(10);
         if(input(PIN_D0)==0)RETURN 0;
         if(input(PIN_D1)==0)RETURN 8;
         if(input(PIN_D2)==0)RETURN 5;
         if(input(PIN_D3)==0)RETURN 2;
         
         output_high(PIN_B1);output_low(PIN_B2);delay_ms(10);
         if(input(PIN_D0)==0)RETURN-2;
         if(input(PIN_D1)==0)RETURN 9;
         if(input(PIN_D2)==0)RETURN 6;
         if(input(PIN_D3)==0)RETURN 3;
         output_high(PIN_B2);delay_ms(10);
         //return -3;
         }
   }

   VOID feedbackTeclado(INT8 x)
   {
      SWITCH(x)
      {
         CASE 1:
         output_low(PIN_B4);
         output_low(PIN_B5);
         output_low(PIN_B6);
         output_high(PIN_B7);
         BREAK;

         CASE 2:
         output_low(PIN_B4);
         output_low(PIN_B5);
         output_high(PIN_B6);
         output_low(PIN_B7);
         BREAK;

         CASE 3:
         output_low(PIN_B4);
         output_low(PIN_B5);
         output_high(PIN_B6);
         output_high(PIN_B7);
         BREAK;

         CASE 4:
         output_low(PIN_B4);
         output_high(PIN_B5);
         output_low(PIN_B6);
         output_low(PIN_B7);
         BREAK;

         CASE 5:
         output_low(PIN_B4);
         output_high(PIN_B5);
         output_low(PIN_B6);
         output_high(PIN_B7);
         BREAK;

         CASE 6:
         output_low(PIN_B4);
         output_high(PIN_B5);
         output_high(PIN_B6);
         output_low(PIN_B7);
         BREAK;

         CASE 7:
         output_low(PIN_B4);
         output_high(PIN_B5);
         output_high(PIN_B6);
         output_high(PIN_B7);
         BREAK;

         CASE 8:
         output_high(PIN_B4);
         output_low(PIN_B5);
         output_low(PIN_B6);
         output_low(PIN_B7);
         BREAK;

         CASE 9:
         output_high(PIN_B4);
         output_low(PIN_B5);
         output_low(PIN_B6);
         output_high(PIN_B7);
         BREAK;

         CASE 0:
         output_high(PIN_B4);
         output_low(PIN_B5);
         output_high(PIN_B6);
         output_low(PIN_B7);
         BREAK;

         CASE-1:
         output_high(PIN_B4);
         output_low(PIN_B5);
         output_high(PIN_B6);
         output_high(PIN_B7);
         BREAK;

         CASE-2:
         output_high(PIN_B4);
         output_high(PIN_B5);
         output_low(PIN_B6);
         output_low(PIN_B7);
         BREAK;

         CASE-3:
         output_high(PIN_B4);
         output_high(PIN_B5);
         output_high(PIN_B6);
         output_low(PIN_B7);
         BREAK;
      }
   }

   Int8 toPWM255(int8 x){
      switch(x){
         case 0: return 0;
         case 1: return 25;
         case 2:return 51;
         case 3:return 76;
         case 4:return 102;
         case 5: return 127;
         case 6:return 153;
         case 7:return 178;
         case 8:return 204;
         case 9:return 229;
         case -1:return 255;
      }
   }

   VOID main()
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
      
      set_adc_channel(0);
      delay_us(50);
      
      lcd_ini();
      delay_ms(50);
      
      //another config
      output_low(PIN_B4);
      output_low(PIN_B5);
      output_low(PIN_B6);
      output_low(PIN_B7);
      output_low(PIN_D4);
      output_low(PIN_D5);
      output_low(PIN_D6);
      output_low(PIN_D7);

      //TODO: USER CODE!!
      int8 cont=0;
      double volt;
      WHILE(true)
      {
         cont = toPWM255(ler_teclado());
         if(cont != -3){
            set_pwm1_duty(cont);
         }
         volt = cont;
         volt /=51;
         lcd_escreve ('\f'); // Apaga (limpa) o display 
         printf(lcd_escreve," IFMT 2023 \r\n");
         printf (lcd_escreve," Tensão = %f",volt);
         //fprintf(Wireless,"%u \n",cont); // Formato para enviar para o 
         // BasicRealtimePlotter - Processing
         //cont++;
         //if(cont == 10) cont=0;
         //feedbackTeclado(ler_teclado());
         //set_pwm1_duty(read_adc());
         
      }
   }

   /*
      UNSIGNED char tmp;
      setup_adc_ports(NO_ANALOGS);
      setup_adc(ADC_OFF);
      setup_psp(PSP_DISABLED);
      setup_spi(SPI_SS_DISABLED);
      setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
      setup_timer_1(T1_DISABLED);
      setup_timer_2(T2_DISABLED,0,1);
      setup_comparator(NC_NC_NC_NC);
      setup_vref(FALSE);
      lcd_ini();//Inicializa LCD
      delay_ms(10);
      printf(lcd_escreve,"\fIFMT ... 2022");
      delay_ms(1000);
      printf(lcd_escreve,"\f TECLADO ");
      delay_ms(2000);

   */
