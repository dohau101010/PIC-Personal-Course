#include <tv_kit_vdk_pic_all.c>

void bai_316_32led_1dst_mp(usi16 dl)          
{                                 
   usi8 i,j;  usi32 x,ttcd,ttdc; //trang thai dich chuyen
   x=0xffffffff; //trang thai co dinh
   xuat_32led_don_1dw(x);
   
   ttcd = 0x7fffffff;
   for(i=0;i<32;i++)
   {  
      ttdc=0x80000000>>i; 
      for(j=0; j<i+1; j++)
      {
         ttdc = ttdc<<1;
         x = ttcd|ttdc;
         xuat_32led_don_1dw(x);  delay_ms(dl);   
      } 
      ttcd=ttcd>>1;
   }
}
void main()                                                        
{                                               
   set_up_port();       
   buzzer_on();
 //triac_2_on();
   while(true)                                        
   {                                                                   
      bai_316_32led_1dst_mp(200);                                        
   }      
}  

