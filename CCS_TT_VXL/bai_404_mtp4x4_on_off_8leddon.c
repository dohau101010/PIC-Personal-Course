#include <tv_kit_vdk_pic_all.c>
unsigned int8 mp,y;

void dieu_khien_8led_on_off()
{
   mp= key_4x4_dw();
   if(mp<8)
   {
      y= y|(1<<mp);
      xuat_32led_don_4byte(0,0,0,y);
   }
   else if(mp<16)
   {
      y= y&(~(1<<(mp-8)));
      xuat_32led_don_4byte(0,0,0,y);
   }
}
void main() 
{ 
   set_up_port(); 
   y=0;
   while(true) 
   { 
      dieu_khien_8led_on_off();
   }
}
