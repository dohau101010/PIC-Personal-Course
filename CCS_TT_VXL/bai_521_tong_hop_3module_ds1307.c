
#include <tv_kit_vdk_pic_all.c>
#include <bai_338_32led_3y_chay_td_4yc_dung_if.c> 
#include <bai_411_t0_tv.c> 

usi8 giay_tam; 
void b516_giai_ma_8led_quet() 
{
   md8l7d_gma_so_bcd_vitri_vn (giay_ds, 0, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn (phut_ds, 3, kx_vn) ;
   md8l7d_gma_so_bcd_vitri_vn (gio_ds, 6, cx_vn);
}

void main() 
{
   set_up_port();
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);
   set_timer0 (0); t0_tam = 1; g_han = 50;
   ds1307_kiem_tra_ma ();

   WHILE (true)
   {
      bai338_32led_chay_td_4yc_dung_if();
      b411_dem_sp_t0 ();
      for (INT8 i = 0; i < 10; i++) hien_thi_8led_7doan_quet ();
      ds1307_doc_time (8) ;

      IF (giay_tam != giay_ds)
      {
         giay_tam = giay_ds;
         b516_giai_ma_8led_quet ();
      }
   }
}

