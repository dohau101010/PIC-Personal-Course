#include <tv_kit_vdk_pic_all.c>

void bai_32led_sangdich_ziczac_tnv(usi16 dl)
{
  usi32 u = 0;
  usi32 v = 0x00000001;
  usi32 led;
  usi8 k, i, n;
  xuat_32led_don_1dw(0);   delay_ms(dl); 
  for(k=32;k>0;k--)
   {
      if(k==32)
      {
          xuat_32led_don_1dw(1);   delay_ms(dl);  
      }
      u=u|v;
      for(n=k-1;n>0;n--)
      {
          v = v<<1;
          led = u|v;
          xuat_32led_don_1dw(led);     delay_ms(dl);
      }
      k--;
      u = u|v;
      for(i=k-1;i>0;i--)
      {
          v = v>>1;
          led = u|v;
          xuat_32led_don_1dw(led);     delay_ms(dl);
      }
   }
}

void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {     
      bai_32led_sangdich_ziczac_tnv(50);
   }      
} 
