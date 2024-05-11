
#include <tv_kit_vdk_pic_all.c> 

signed INT8 g_han; 
void b406_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn (g_han, 3, cx_vn) ;
   xuat_4led_7doan_4so ();
}

void b406_up_dw_g_han() 
{
   IF (phim_up_c2 (200) == co_nhan)
   {
      IF (g_han < 99)
      {
         g_han++; b406_hienthi_4led7doan ();
      }
   }

   IF (phim_dw_c2 (200) == co_nhan)
   {
      IF (g_han > 0)
      {
         g_han--; b406_hienthi_4led7doan ();
      }
   }
}

void main() 
{
   set_up_port() ;
   g_han = 50;
   b406_hienthi_4led7doan () ;

   WHILE (true)
   {
      b406_up_dw_g_han ();
   }
}

