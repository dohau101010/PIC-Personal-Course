
#include <tv_kit_vdk_pic_all.c>
#include <tv_06_glcd.c> //cac ham lcd

void main()
{
   set_up_port ();
   setup_glcd (glcd_text_mode) ;
   delay_ms (1) ;
   setup_glcd (glcd_graphic_mode);
   glcd_mau_nen (0) ;
   glcd_xuat_anh (64, 64, 64, 0) ;
   //glcd_xuat_anh (64, 64, 64, 0) ;
   gdram_vdk_to_gdram_glcd_all () ;
   WHILE (true) ;
}

