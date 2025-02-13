#include <tv_kit_vdk_pic_all.c> 

unsigned INT8 t0, t0_tam,g_han; 
//int1 tt_cai = enable;

void b411_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn (t0, 3, cx_vn) ;
   md4l7d_giaima_2so_vitri_vn (g_han, 1, cx_vn);
   xuat_4led_7doan_4so ();
}

void b411_dem_sp_t0()
{
   t0 = get_timer0 ();

   IF (t0_tam != t0)
   {
      t0_tam = t0;
      b411_hienthi_4led7doan ();

      IF (t0 >= g_han)
      {
         set_timer0 (0) ;
         buzzer_on_off (300);
      }
   }
}

void main() 
{ 
 set_up_port(); 
 setup_timer_0(t0_off); 
 set_timer0(0); t0_tam = 1; g_han=50; 
 xuat_32led_don_2word(0,0);

 while(true) 
 { 
   b411_dem_sp_t0();
   if(phim_run_c2(150)==co_nhan)
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1); 
      b411_dem_sp_t0(); 
      xuat_32led_don_2word(0,0xffff);
      //tt_cai = enable;
   }
   if(phim_stop_c2(150)==co_nhan)
   {
      //tt_cai = disable;
      xuat_32led_don_2word(0,0);
      setup_timer_0(t0_off);
   }
 } 
}
