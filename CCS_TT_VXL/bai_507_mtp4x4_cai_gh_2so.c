#include <tv_kit_vdk_pic_all.c>

unsigned int8 mp, gh;
signed int8 i;
void hienthi()
{
   gh=chuc*10+donvi;
   md8l7d_gma_2so_vitri_vn(gh, 0, 1);
   hien_thi_8led_7doan_quet();
}
void main()
{
   set_up_port();
   while(true)
   {
      mp= key_4x4_dw();
      if(mp!=0xff)
      {
        chuc=donvi; donvi=mp;
      }
      hienthi();
   }
}
