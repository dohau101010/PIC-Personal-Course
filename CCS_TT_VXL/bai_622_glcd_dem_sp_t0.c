
#include <tv_kit_vdk_pic_all.c> 
#include <tv_06_glcd.c>
#include <bai_622_glcd_dem_sp_t0_tv.c>

void main()
{
   set_up_port ();
   setup_glcd (glcd_text_mode);
   glcd_command (glcd_addr_line0) ;
   glcd_data ("dem san pham:");
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);
   set_timer0 (0) ;
   t0_tam = 1;
   g_han = 50;

   WHILE (true)
   {
      b622_dem_sp_glcd_4l7d_t0 () ;
   }
}

