#include <tv_kit_vdk_pic_all.c>

unsigned int8 t0, t0_tam, g_han;
int1 mode=1;

void b413_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn(t0,3,cx_vn);
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
   xuat_4led_7doan_4so();
}

void b413_dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam != t0)
   {
      t0_tam = t0;
      b413_hienthi_4led7doan();
      if (t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}

void main()
{
   set_up_port();
   setup_timer_0(t0_off);
   set_timer0(0);
   t0_tam = 1; g_han=50;
   xuat_32led_don_2word(0,0);
   
   while(true)
   {
      b413_dem_sp_t0();
      if(phim_run_c2(150)==co_nhan)
      {
         setup_timer_0(t0_ext_l_to_h|t0_div_1); 
         b413_dem_sp_t0(); 
         xuat_32led_don_2word(0,0xffff);
      }
      if(phim_stop_c2(150)==co_nhan)
      {
         xuat_32led_don_2word(0,0);
         setup_timer_0(t0_off);
      }
      if(phim_ud_c2(300)==co_nhan)
      {
         mode = ~ mode;
         if(mode == 0)
         {
            t0 = get_timer0();
            if(t0_tam != t0)
            {
               t0_tam = t0;
            }
            t0++;
            b413_hienthi_4led7doan();
            if (t0>=g_han)
            {
               set_timer0(0);
               buzzer_on_off(300);
            }
            xuat_32led_don_4byte(0xff,0,0,0);
         }
         if(mode == 1)
         {
            t0 = get_timer0();
            if(t0_tam != t0)
            {
               t0_tam = t0;
            }
            md4l7d_giaima_2so_vitri_vn(g_han-t0,3,cx_vn);
            md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
            xuat_4led_7doan_4so();

            xuat_32led_don_4byte(0,0xff,0,0);
         }
      }
   }
}
