#include <tv_kit_vdk_pic_all.c>

void b304_16led_phai_std_pst(usi16 dl)          
{                                 
   usi8 i;  usi16 LP;
   LP=0;
   for(i=0;i<16;i++)
   {
      LP = (LP<<1)+1;
      xuat_32led_don_2word(0, LP);  delay_ms(dl);        
   } 
   for(i=0;i<16;i++)
   {
      LP = (LP<<1);
      xuat_32led_don_2word(0, LP);  delay_ms(dl);        
   } 
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      b304_16led_phai_std_pst(40);                                        
   }      
}  

