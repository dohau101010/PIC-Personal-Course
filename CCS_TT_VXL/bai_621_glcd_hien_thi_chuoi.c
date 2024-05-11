
#include <tv_kit_vdk_pic_all.c> 
#include <tv_06_glcd.c> //cac ham lcd

void h621_glcd_hien_thi_chuoi() 
{
   glcd_command (glcd_addr_line0) ;
   glcd_data ("Nhu co Bac ho ") ;
   glcd_command (glcd_addr_line1) ;
   glcd_data ("trong ngay vui ") ;
   glcd_command (glcd_addr_line2);
   glcd_data ("dai thang ") ;
   glcd_command (glcd_addr_line3) ;
   glcd_data ("thuc hanh vdk");
}

void main()
{
   set_up_port();
   setup_glcd (glcd_text_mode);

   WHILE (true)
   {
      h621_glcd_hien_thi_chuoi ();
      WHILE (true) ;
   }
}

