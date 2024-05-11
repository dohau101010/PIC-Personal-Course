#include <tv_kit_vdk_pic_all.c>

void b306_32led_std_tnv(usi16 dl)          
{                                 
   usi8 i;  usi16 LT; usi16 LP;
   LT=0;
   LP=0;
   for(i=0;i<16;i++)
   {
      LT = (LT>>1)+0x8000;
      LP = (LP<<1)+0x0001;
      xuat_32led_don_2word(LT, LP);
      delay_ms(dl);
      
   } 
   for(i=0;i<16;i++)
   {
      LT = (LT>>1);
      LP = (LP<<1);
      xuat_32led_don_2word(LT, LP);
      delay_ms(dl);
      
   } 
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      b306_32led_std_tnv(100);                                        
   }      
}  

