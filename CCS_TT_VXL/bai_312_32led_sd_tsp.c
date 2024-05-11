#include <tv_kit_vdk_pic_all.c>

void bai_312_32led_sd_tsp(usi16 dl)          
{                                 
   usi8 i,j;  usi32 x,ttcd,ttdc; //trang thai dich chuyen
   x=0;
   ttcd=0; //trang thai co dinh
   
   for(i=32;i>0;i--)
   {
      ttdc=0x80000000;
      for(j=0; j<i; j++)  
      {
         x = ttcd|ttdc;
         xuat_32led_don_1dw(x);  delay_ms(dl);   
         ttdc = ttdc>>1;
      } 
      ttcd=x;
   }
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      bai_312_32led_sd_tsp(30);                                        
   }      
}

