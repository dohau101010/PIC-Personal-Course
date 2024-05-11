#include <tv_kit_vdk_pic_all.c>

void b305_16led_phai_std_tsp(usi16 dl)          
{                                 
   usi8 i;  usi16 LT;
   LT=0;
   for(i=0;i<16;i++)
   {
      LT = (LT>>1)+0x8000;
      xuat_32led_don_2word(LT, 0);  delay_ms(dl);        
   } 
   for(i=0;i<16;i++)
   {
      LT = (LT>>1);
      xuat_32led_don_2word(LT, 0);  delay_ms(dl);        
   } 
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      b305_16led_phai_std_tsp(40);                                        
   }      
}  

