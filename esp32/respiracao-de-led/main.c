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
#use delay(clock=6000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

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
  

   //TODO: USER CODE!!
   WHILE(true)
   {
      set_pwm1_duty(3);delay_ms(25);
      set_pwm1_duty(4);delay_ms(25);
      set_pwm1_duty(5);delay_ms(25);
      set_pwm1_duty(6);delay_ms(25);
      set_pwm1_duty(7);delay_ms(25);
      set_pwm1_duty(8);delay_ms(25);
      set_pwm1_duty(11);delay_ms(25);
      set_pwm1_duty(13);delay_ms(25);
      set_pwm1_duty(15);delay_ms(25);
      set_pwm1_duty(17);delay_ms(25);
      set_pwm1_duty(20);delay_ms(25);
      set_pwm1_duty(24);delay_ms(25);
      set_pwm1_duty(28);delay_ms(25);
      set_pwm1_duty(31);delay_ms(25);
      set_pwm1_duty(34);delay_ms(25);
      set_pwm1_duty(39);delay_ms(25);
      set_pwm1_duty(44);delay_ms(25);
      set_pwm1_duty(48);delay_ms(25);
      set_pwm1_duty(53);delay_ms(25);
      set_pwm1_duty(58);delay_ms(25);
      set_pwm1_duty(63);delay_ms(25);
      set_pwm1_duty(70);delay_ms(25);
      set_pwm1_duty(78);delay_ms(25);
      set_pwm1_duty(85);delay_ms(25);
      set_pwm1_duty(99);delay_ms(25);
      set_pwm1_duty(113);delay_ms(25);     
      set_pwm1_duty(127);delay_ms(25);
      set_pwm1_duty(131);delay_ms(25);
      set_pwm1_duty(136);delay_ms(25);
      set_pwm1_duty(140);delay_ms(25);
      set_pwm1_duty(146);delay_ms(25);
      set_pwm1_duty(152);delay_ms(25);
      set_pwm1_duty(159);delay_ms(25);
      set_pwm1_duty(167);delay_ms(25);
      set_pwm1_duty(176);delay_ms(25);
      set_pwm1_duty(184);delay_ms(25);
      set_pwm1_duty(189);delay_ms(25);
      set_pwm1_duty(194);delay_ms(25);
      set_pwm1_duty(199);delay_ms(25);
      set_pwm1_duty(207);delay_ms(25);
      set_pwm1_duty(213);delay_ms(25);
      set_pwm1_duty(219);delay_ms(25);
      set_pwm1_duty(226);delay_ms(25);
      set_pwm1_duty(232);delay_ms(25);
      set_pwm1_duty(237);delay_ms(25);
      set_pwm1_duty(242);delay_ms(25);
      set_pwm1_duty(247);delay_ms(25);
      set_pwm1_duty(252);delay_ms(25);
      // Platô
      set_pwm1_duty(255);delay_ms(200);

      // Descida 2,4
      set_pwm1_duty(240);delay_ms(25);
      set_pwm1_duty(230);delay_ms(25);
      set_pwm1_duty(220);delay_ms(25);
      set_pwm1_duty(190);delay_ms(25);
      set_pwm1_duty(180);delay_ms(25);
      set_pwm1_duty(170);delay_ms(25);
      set_pwm1_duty(164);delay_ms(25);
      set_pwm1_duty(159);delay_ms(25);
      set_pwm1_duty(151);delay_ms(25);
      set_pwm1_duty(148);delay_ms(25);
      set_pwm1_duty(143);delay_ms(25);
      set_pwm1_duty(138);delay_ms(25);
      set_pwm1_duty(133);delay_ms(25);
      set_pwm1_duty(127);delay_ms(25);
      set_pwm1_duty(100);delay_ms(25);
      set_pwm1_duty(80);delay_ms(25);
      set_pwm1_duty(71);delay_ms(25);
      set_pwm1_duty(63);delay_ms(25);
      set_pwm1_duty(50);delay_ms(25);
      set_pwm1_duty(40);delay_ms(25);
      set_pwm1_duty(31);delay_ms(25);
      set_pwm1_duty(29);delay_ms(25);
      set_pwm1_duty(27);delay_ms(25);
      set_pwm1_duty(25);delay_ms(25);
      set_pwm1_duty(23);delay_ms(25);
      set_pwm1_duty(19);delay_ms(25);
      set_pwm1_duty(17);delay_ms(25);
      set_pwm1_duty(15);delay_ms(25);
      set_pwm1_duty(14);delay_ms(50);
      set_pwm1_duty(13);delay_ms(25);
      set_pwm1_duty(12);delay_ms(50);
      set_pwm1_duty(11);delay_ms(25);
      set_pwm1_duty(10);delay_ms(100);
      set_pwm1_duty(9);delay_ms(100);
      set_pwm1_duty(8);delay_ms(100);
      set_pwm1_duty(7);delay_ms(125);
      set_pwm1_duty(6);delay_ms(100);
      set_pwm1_duty(5);delay_ms(100);
      set_pwm1_duty(4);delay_ms(100);
      set_pwm1_duty(3);delay_ms(150);

   }
}

