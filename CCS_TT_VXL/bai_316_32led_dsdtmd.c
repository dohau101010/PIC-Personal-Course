#include <tv_kit_vdk_pic_all.c>

void bai_316_dsdtmd_32led(usi16 dl)
{
   unsigned int32 led,z,v,u;
   signed int8 n,k;
   z=0x7fffffff; u=0x80000000;
   for(k=0;k<32;k++)
   {
      v=u;
      for(n=k+1;n>0;n--)
      {
         v=v<<1;
         led=z|v;
         xuat_32led_don_1dw(led);
         delay_ms(dl);
      }
      z=z>>1; u=u>>1;
   }
}

void main()
{
   set_up_port();
   while(true)
   {
      bai_316_dsdtmd_32led(100);
   }
}

