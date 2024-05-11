#include <tv_kit_vdk_pic_all.c>

void b311_8led_sd_pst_c2(usi16 dl)
{
   unsigned int32 led, z, v;
   signed int8 n, k;
   
   z=0;
   for(k=32; k>0; k--)
   {
      v=1;
      for(n=0; n<k; n++)
      {
         led = z|v;
         xuat_32led_don_1dw(led);
         delay_ms(dl);
         v=v<<1;
      }
      z=led;
   }
}

void main()
{
   set_up_port();
   while(true)
   {
      b311_8led_sd_pst_c2(100);
   }
}
