#include <tv_kit_vdk_pic_all.c> 
#include <chuong3_32led_if_no_delay.c>


void main()
{ 
   set_up_port(); 
   tt_ct=0;
   while(true) 
   { 
      IF (tt_ct == 0) xuat_32led_don_1dw (0);
       IF (tt_ct == 1) h327_32led_std_pst_if ();
       IF (tt_ct == 2) h327_32led_std_tsp_if ();
       IF (tt_ct == 3) h327_16led_tp_std_pst_songsong();
       IF (tt_ct == 4) h327_16led_tp_std_tsp_songsong();
       tt_ct++;
       if(tt_ct>4) tt_ct=0;
      delay_ms(100);
   }
}
