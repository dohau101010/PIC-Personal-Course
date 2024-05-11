#include <tv_kit_vdk_pic_all.c>

void b301_16led_chop_tat(usi16 dl)          
{                                 
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl); //0000 0000 x4 = 32 bit 0                                 
   xuat_32led_don_4byte(0,0,0xff,0xff);  delay_ms(dl); //16 bit 0, 1111 1111: 8        
}    

void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      b301_16led_chop_tat(500);                                        
   }      
}  

