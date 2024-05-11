#include <tv_kit_vdk_pic_all.c>
usi8 hang123[60];
usi8 mp,chuc, donvi, time;
void hienthi()
{
   
}
void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("DIEU KHIEN BUZZER");
   while(true)
   {
      mp=key_4x4_dw();
      if(mp!=0xff)
      {
         chuc=donvi;
         donvi=mp;
      }
   }
}
