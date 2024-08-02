#include <16F628A.h>

#FUSES NOWDT
#FUSES HS
#FUSES NOPUT
#FUSES NOPROTECT
#FUSES BROWNOUT
#FUSES NOLVP
#FUSES NOCPD

#use delay(clock=4000000)

/*
void um(int i){
   OUTPUT_B(0b);
}
*/
void n0(int x){
   if(x){
      OUTPUT_B(0b11111110);
   }else{
      OUTPUT_B(0b11101110);
   }
}
void n1(int x){
   if(x){
      OUTPUT_B(0b00111000);
   }else{
      OUTPUT_B(0b00101000);
   }
}
void n4(int x){
   if(x){
      OUTPUT_B(0b00111011); 
   }else{
      OUTPUT_B(0b00101011);
   }
}
void n5(int x){
   if(x){
      OUTPUT_B(0b01110111);
   }else{
      OUTPUT_B(0b01100111);
   }
}

void main()
{

   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
//Setup_Oscillator parameter not selected from Intr Oscillator Config tab

   // TODO: USER CODE!!
   while(true){
      n4(0);
      delay_ms(10);
      n5(1);
      delay_ms(10);
      
   }
   
}
