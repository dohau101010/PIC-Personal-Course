#include "E:\CCS VXL\THUC TAP VXL_SP\VXL_VIP_PRO\CCS_TT_VXL\tv_kit_vdk_pic_all.c"


void bai_313asan_don_pst(usi16 dl)
{
   usi16 led,v,z;
   si16 i,k;
   v=0; z=0; led=0;
   for(k=16;k>0; k--)
   {
      v=1;
      for(i=0;i<k;i++)
      {
         led=v|z;
         xuat_32led_don_2word(0x0000,led);
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
      bai_313asan_don_pst(100);
   }
}

