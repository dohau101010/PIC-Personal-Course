#include <tv_kit_vdk_pic_all.c>

void bai_32led_sd_pst(usi16 dl)          
{                                 
   usi32 i, k;
   usi32 run, save, led;
   run=0; save=0; led=0;
   for(k=0; k<32; k++)
   {
      run=0x00000001;
      for(i=k; i<32; i++)  
      {
         led=run|save;
         xuat_32led_don_1dw(led);  delay_ms(dl);   
         run = run<<1;
      } 
      save=led;
   }
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      bai_32led_sd_pst(20);                                        
   }      
}  

