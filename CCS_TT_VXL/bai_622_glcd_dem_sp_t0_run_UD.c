#include <tv_kit_vdk_pic_all.c>
#include <tv_06_glcd.c>
#include <bai_622_t0_tv.c>
void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("Dem san pham dung T0 ");
   lcd_goto_xy(1,0);
   lcd_data("GHD");
   lcd_goto_xy(1,10);
   lcd_data("GTD");
   
   lcd_goto_xy(3,0);
   lcd_data("Trang thai: Stop  UP");
   lcd_khoi_tao_cgram_so_to();
   
   setup_timer_0 (t0_off);
   set_timer0(0);
   t0_tam=1;
   lt=0x00ff;
   g_han=50;
   lcd_hienthi_gh_soto ();
   
   setup_glcd(glcd_text_mode);
   glcd_command(glcd_addr_line0);
   glcd_data("Dem san pham T0");
   glcd_command(glcd_addr_line1);
   glcd_data("Gioi han dem: 10");
   glcd_command(glcd_addr_line2);
   glcd_data("Gia tri dem : ");
   while (true)
   {
      phim_run();
      phim_stop();
      phim_ud();
      dem_xung_ngoai_t0();
   }
}
