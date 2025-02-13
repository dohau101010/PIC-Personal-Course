#include <tv_kit_vdk_pic_all.c>
void bai_32led_sd_tnv(usi16 dl)          
{                                 
   usi32 i, k;
   usi16 run1, run2, save1, save2, led1, led2;
   run1=0; run2=0; save1=0; save2=0; led1=0; led2=0;
   for(k=0; k<16; k++)
   {
      run1=0x8000;
      run2=0x0001;
      for(i=k; i<16; i++)  
      {
         led1=run1|save1;
         led2=run2|save2;
         xuat_32led_don_2word(led1, led2);  delay_ms(dl);   
         run1 = run1>>1;
         run2=run2<<1;
      } 
      save1=led1;
      save2=led2;
   }
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      bai_32led_sd_tnv(20);                                        
   }      
}  

