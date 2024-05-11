
#include <tv_kit_vdk_pic_all.c> 

unsigned INT8 mp;
signed INT16 donvi,chuc,tram,g_han; 
int1 tt_cai = enable;

void b408_hienthi_4led7doan()
{
   g_han = tram*100 + chuc * 10 + donvi;
   md4l7d_giaima_3so_vitri_vn (g_han, 3, cx_vn) ;
   xuat_4led_7doan_4so ();
}

void main() 
{
   set_up_port ();
   donvi = 0; chuc = 5; tram = 5;
   b408_hienthi_4led7doan ();

   WHILE (true)
   {
      mp = key_4x4_dw ();

      IF ( (mp < 10)&& (tt_cai == enable))
      {
         tram = chuc; chuc = donvi; donvi = mp;
      }

      IF (mp == 0x0c)
      {
         donvi = 0; chuc = 0; tram = 0;
      }

      IF (mp == 0x0f) tt_cai = enable;
      IF (mp == 0x0e) tt_cai = disable;
      b408_hienthi_4led7doan ();
   }
}

