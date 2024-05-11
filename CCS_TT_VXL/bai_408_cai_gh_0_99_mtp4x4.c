
#include <tv_kit_vdk_pic_all.c> 

unsigned INT8 mp;
signed INT8 donvi,chuc,g_han; 
int1 status=1;

void b408_hienthi_4led7doan()
{
   g_han = chuc * 10 + donvi;
   md4l7d_giaima_2so_vitri_vn(g_han, 3, 1) ;
   xuat_4led_7doan_4so ();
}

void main() 
{
   set_up_port ();
   donvi = 0; chuc = 5;
   b408_hienthi_4led7doan ();

   WHILE (true)
   {
      mp = key_4x4_dw ();
       if(mp == 0x0f) status=0;
       if(mp == 0x0e) status=1;
      if (mp < 10)&& (status==0))
    { chuc = donvi; donvi = mp;}
     else if (mp == 0x0c)
      {
         donvi = 0; chuc = 0;
      }

      b408_hienthi_4led7doan ();
   }
}

