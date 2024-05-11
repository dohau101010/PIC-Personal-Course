#include <tv_kit_vdk_pic_all.c>
usi8 mp;
usi8 dich[8]={0xff, 0xff, 0xff, 0xff,0xff, 0xff, 0xff, 0xff};
usi8 i;

void hienthi()
{
     for(i=0; i<4; i++)
   {
      dl_4l7d[i]=dich[i+4];
   }
   xuat_4led_7doan_4so();
}
void dich_dl()
{
  mp=key_4x4_up();
   if(mp!=0xff)
   {
    if(mp<10)
    {
      for(i=0; i<7; i++)
      {
         dich[i]=dich[i+1];
      }
           dich[7]=ma7doan[mp];
           hienthi();
    } 
   else if(mp==11)
    {
     for(i=7; i>0; i--)
     {
      dich[i]=dich[i-1];
     }
          dich[0]=0xff;
          hienthi();
    }
   }
}

void main()
{
   set_up_port();
   while(true)
   {
      dich_dl();
   }
}
