#include <tv_kit_vdk_pic_all.c>

void bai_314_32led_sd_ttr(usi16 dl)          
{                                 
   usi8 i,j;  usi16 x, y, ttcd_T, ttcd_P, ttdc_T, ttdc_P; //trang thai dich chuyen
   x=0; y=0;
   ttcd_T=0; ttcd_P=0;//trang thai co dinh
   
   for(i=16;i>0;i--)
   {
      ttdc_T=0x0001; ttdc_P=0x8000;
      for(j=0; j<i; j++)  
      {
         x = ttcd_T|ttdc_T;  
         ttdc_T = ttdc_T<<1;
        //ttcd=x;
         y = ttcd_P|ttdc_P;
         ttdc_P = ttdc_P>>1;
         xuat_32led_don_2word(x,y);  delay_ms(dl);
      } 
      ttcd_T = x;
      ttcd_P = y;
   }
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      bai_314_32led_sd_ttr(200);                                        
   }      
}

