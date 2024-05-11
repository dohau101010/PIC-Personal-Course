#include <tv_kit_vdk_pic_all.c>
usi8 y;
int1 status;
void phim_inv()
{
   if(!input(inv))
   {
      delay_ms (20) ;
      {
         if(!input(inv))
         {
            y = ~y;
            xuat_32led_don_4byte (0,0,0,y);
            while(!input(inv));
         }
      }
   }
}

void phim_on()
{
   if(!input(on))
   {
     status=0;
     y=0x0f;
     xuat_32led_don_4byte (0, 0, 0, y);
   }
}

void phim_off()
{
   if(!input(off))
   {
     status=1;
     xuat_32led_don_4byte (0, 0, 0, 0);
   }
}
void main()
{
   set_up_port();
   y = 0x00;
   xuat_32led_don_4byte (0, 0, 0, 0) ;
   while(true)
   {
     phim_on();
     phim_off();
     if(status==0)  phim_inv();
     else;
   }
}

