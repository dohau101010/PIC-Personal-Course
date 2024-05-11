#include <tv_kit_vdk_pic_all.c>
usi16 y=0;
void phim_up()
{ 
   if(!input(up))
   {
      delay_ms(20);
      {
         if(!input(up))
         {
            y=(y<<1)+1;
            xuat_32led_don_2word(0,y);
            while(!input(up)); 
         }
      }
   }
}

void phim_dw()
{
   usi16 y;
   if(!input(dw))
   {
      delay_ms(20);
      {
         if(!input(dw))
         {
            y=(y>>1);
            xuat_32led_don_2word(0,y);
            while(!input(dw));
         }
      }
   }
}

void phim_clr()
{
   usi16 y;
   if(!input(clr))
   {
      y=0;
      xuat_32led_don_2word(0,y);
   }
}

void main()
{
   set_up_port();

   y=0;
   while(true)
   {
      phim_up();
      phim_dw();
      phim_clr();
   }
}

