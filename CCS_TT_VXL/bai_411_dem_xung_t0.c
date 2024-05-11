#include <tv_kit_vdk_pic_all.c> 

usi8 sp, old_sp, g_han; 
void hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn (sp, 3, 1);
   md4l7d_giaima_2so_vitri_vn (g_han, 1, 1);
   xuat_4led_7doan_4so ();
}

void main() 
{ 
 set_up_port(); 
 setup_timer_0(t0_ext_l_to_h|t0_div_1); 
 set_timer0(0);
 gh=50;
 while(true) 
 { 
  sp= get_timer0();

   if(sp != old_sp)
   {
      old_sp=sp;
      hienthi_4led7doan ();
      if(sp >= g_han)
      {
         set_timer0(0) ;
         buzzer_on_off(300);
      }
   }
 } 
}


