#include <tv_kit_vdk_pic_all.c>

unsigned int16 y;
int1 tt=0; //UP-> tt=0: pst; tt=1: tsp

void phim_up()
{
   if(!input(up))
   {
      delay_ms(20);
      {
         if(!input(up))
         {
            if(tt==0)  y=(y<<1)+1;
            else       y=(y>>1)+0x8000;
            xuat_32led_don_2word(0,y);
            while(!input(up)); //cho nha phim
         }
      }
   }
}

void phim_dw()
{
   if(!input(dw))
   {
      delay_ms(20);
      {
         if(!input(dw))
         {
            if(tt==0)   y=(y>>1);
            else        y=(y<<1);
            xuat_32led_don_2word(0,y);
            while(!input(dw));
         }
      }
   }
}

void phim_clr()
{
   if(!input(clr))
   {
      delay_ms(20);
      {
         if(!input(clr))
         {
            y=0;  tt=~tt;
            xuat_32led_don_2word(0,y);
            while(!input(clr));
         }
      }
   }
}

void main()
{
   set_up_port();
   y = 0x00;
   
   while(true)
   {
      phim_up();
      phim_dw();
      phim_clr();
   }
}

