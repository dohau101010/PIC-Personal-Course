#include <tv_kit_vdk_pic_all.c>

void bai_315_dsdpmd_32led(usi16 dl)
{
   unsigned int16 led1,led2,z,v,u,q,w,h;
   signed int8 n,k;
   z=0xfffe; u=0x0001;
   w=0x7fff; h=0x8000;
   for(k=0;k<16;k++)
   {
      v=u; q=h;
      for(n=k+1;n>0;n--)
      {
         v=v>>1;
         led1=z|v;
        
         q=q<<1;
         led2=w|q;
         
         xuat_32led_don_2word(led1,led2);
         delay_ms(dl);  
      }
      z=z<<1; u=u<<1;
      w=w>>1; h=h>>1;
   }
}

void main()
{
   set_up_port();
   while(true)
   {
      bai_315_dsdpmd_32led(100);
   }
}

