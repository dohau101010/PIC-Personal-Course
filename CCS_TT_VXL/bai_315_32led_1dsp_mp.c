#include <tv_kit_vdk_pic_all.c>

void bai32_led_md_tsp(usi16 dl)
{
   usi32 led, run, save;
   usi8 i, k;
   led=0xffffffff;
   xuat_32led_don_1dw(led); delay_ms(dl);
   save=0xfffffffe;
   for(i=0; i<32; i++)
   {
      run=0x00000001<<i;
      for(k=0; k<=i; k++)
      {
         run=run>>1;
         led=run|save;
         xuat_32led_don_1dw(led);
         delay_ms(dl);
      }
      save=save<<1;
   }
   
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      bai32_led_md_tsp(50);
   }
}  

