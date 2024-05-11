#include "E:\CCS VXL\THUC TAP VXL_SP\VXL_VIP_PRO\CCS_TT_VXL\tv_kit_vdk_pic_all.c"

void b301_32led_chop_tat(usi16 dl)          
{                                 
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl); //0000 0000 x4 = 32 bit 0                                 
   xuat_32led_don_2word(0xffff,0xffff);  delay_ms(dl); //16 bit 0, 1111 1111: 8        
}    

void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      b301_32led_chop_tat(500);                                        
   }      
}  

