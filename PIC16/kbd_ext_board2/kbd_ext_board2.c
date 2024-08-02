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
#use delay(clock=20000000)
/*######################################################################
 Rotina utilizaçãoo DO teclado da placa PicSim board4
 Adaptada para o compilador CCS
 Autor: Alberto Willia Mascarenhas (adaptou para o compilador)
 FOR e - mail suggestions : awmascarenhas@gmail.com
######################################################################## */

void main()
{
   UNSIGNED char tc_tecla(UNSIGNED int timeout)
   {
      UNSIGNED int to = 0;
      UNSIGNED char k = 0;

      WHILE ( ( (to < timeout)|| ( ! timeout))&& ( ! k))
      {
         //-------------------------------------------------------------------------
         //inicio DO programa de varredura do teclado matricial
         //--------------------------------------------------------------------------
         //habilita primeira coluna DO teclado
         output_low (PIN_B0); output_high (PIN_B1); output_high (PIN_B2); output_high (PIN_B3) ;
         delay_ms (20);
         if (input (PIN_D0) == 0){WHILE (input (PIN_D0) == 0) ; k = '1'; };
         IF (input (PIN_D1) == 0)
         {
            WHILE (input (PIN_D1) == 0);
            k = '4';
         };

         if (input (PIN_D2) == 0){WHILE (input (PIN_D2) == 0) ; k = '7'; };
         if (input (PIN_D3) == 0){WHILE (input (PIN_D3) == 0) ; k = '*';  };
         //habilita segunda coluna DO teclado
         output_high (PIN_B0); output_low (PIN_B1); output_high (PIN_B2); output_high (PIN_B3) ;
         delay_ms (20);
         if (input (PIN_D0) == 0){WHILE (input (PIN_D0) == 0) ; k = '2'; };
         if (input (PIN_D1) == 0){WHILE (input (PIN_D1) == 0) ; k = '5'; };
         if (input (PIN_D2) == 0){WHILE (input (PIN_D2) == 0) ; k = '8'; };
         if (input (PIN_D3) == 0){WHILE (input (PIN_D3) == 0) ; k = '0'; };
         //habilita terceira coluna DO teclado
         output_high (PIN_B0); output_high (PIN_B1); output_low (PIN_B2); output_high (PIN_B3) ;
         delay_ms (20);
         if (input (PIN_D0) == 0){WHILE (input (PIN_D0) == 0) ; k = '3'; };
         if (input (PIN_D1) == 0){WHILE (input (PIN_D1) == 0) ; k = '6'; };
         if (input (PIN_D2) == 0){WHILE (input (PIN_D2) == 0) ; k = '9'; };
         if (input (PIN_D3) == 0){WHILE (input (PIN_D3) == 0) ; k = '#'; };
         //habilita quarta coluna DO teclado
         output_high (PIN_B0); output_high (PIN_B1); output_high (PIN_B2); output_low (PIN_B3) ;
         delay_ms (20);
         if (input (PIN_D0) == 0){WHILE (input (PIN_D0) == 0) ; k = 'A'; };
         if (input (PIN_D1) == 0){WHILE (input (PIN_D1) == 0) ; k = 'B'; };
         if (input (PIN_D2) == 0){WHILE (input (PIN_D2) == 0) ; k = 'C'; };
         if (input (PIN_D3) == 0){WHILE (input (PIN_D3) == 0) ; k = 'D'; };
         delay_ms (5);
         to += 5;
      }

      IF ( ! k) k = 255;
      RETURN k;
   }
}

