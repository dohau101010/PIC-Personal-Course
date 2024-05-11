#include <tv_kit_vdk_pic_all.c> 
#include <bai_615_clock_ds1307_lcd_tv.c> 
#include <chuong3_32led_if_no_delay.c>
#include<tv_06_glcd.c>
unsigned INT8 t0, t0_tam,g_han; 
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
usi8 giay_tam; 
void giai_ma_8led_quet() 
{
   md8l7d_gma_so_bcd_vitri_vn (giay_ds, 0, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn (phut_ds, 3, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn (gio_ds, 6, cx_vn);
}

void main() 
{
   set_up_port ();
   
   setup_glcd(glcd_text_mode);
   delay_ms(10);
   
   setup_glcd(glcd_graphic_mode);
   glcd_mau_nen (0);
   glcd_xuat_anh(64,64,32,0);
   gdram_vdk_to_gdram_glcd_all();
   
   setup_timer_0(t0_ext_l_to_h|t0_div_1); 
   set_timer0(0);
   g_han=50;
   t0_tam=1;
   ds1307_kiem_tra_ma ();
   
   lcd_setup () ;
   lcd_khoi_tao_cgram_so_to ();
   lcd_goto_xy (0, 0);
   ds1307_hthi_text_lcd ();
   ds1307_hthi_thu_lcd ();
   ds1307_hthi_giay_lcd_soto () ;
   ds1307_hthi_phut_lcd_soto () ;
   ds1307_hthi_gio_lcd_soto () ;
   ds1307_hthi_ntn_lcd () ;
   
   b411_hienthi_4led7doan();

   WHILE (true)
   {
     b339_32led_tong_hop_tu_dong_if();
     b411_dem_xung_ngoai_t0();
     for(int8 i=0;i<15;i++) hien_thi_8led_7doan_quet();
     ds1307_doc_time(8);
     
     if(giay_tam!=giay_ds)
     {
      giay_tam=giay_ds;
      giai_ma_8led_quet();
      ds1307_hthi_lcd_soto();
     }
   }
}
