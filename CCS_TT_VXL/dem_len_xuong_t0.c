#include <tv_kit_vdk_pic_all.c>
int1 ud=0;
unsigned int8 t0, t0_tam,g_han;
usi16 lt, lp;
int1 mode_1, mode_2, tt=0;
usi8 mp;

void phim_ud()
{
   if(mp==2)
   {
     t0=g_han-t0;
     set_timer0(t0);
     mode_2=1;
     //mode_1=0;
      
     lt=~lt;
     xuat_32led_don_2word(lt,lp);
   }
}

void phim_stop()
{
   if(phim_bt1_c2(100)==co_nhan)
   {
       setup_timer_0(t0_off);
       lp=0;
       xuat_32led_don_2word(0,lp);
   }
}

void phim_run()
{
    if(mp==1)
    {
       //mode=0;
       mode_2=0;
       mode_1=0;
       setup_timer_0(t0_ext_l_to_h|t0_div_1);
       lp=0xffff;    
       lt=0x00ff;
       xuat_32led_don_2word(lt,lp);
       delay_ms(100);
    }
}

void b413_hienthi_t0_4l7d()
{
   if(mode==0)
   {
      md4l7d_giaima_2so_vitri_vn(t0,3,cx_vn);
   }
   else
   {
       md4l7d_giaima_2so_vitri_vn((g_han-t0),3,cx_vn);
   }
   md4l7d_giaima_2so_vitri_vn(g_han,1,cx_vn);
   xuat_4led_7doan_4so();
}

void b413_dem_xung_ngoai_t0()
{
   t0= get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam=t0;
      if(t0>g_han)
      {
         set_timer0(0);
        // buzzer_on_off(300);
      }
      b413_hienthi_t0_4l7d();
   }
}

void main()
{
   set_up_port();
   setup_timer_0(t0_off);
   set_timer0(0);  t0_tam=1;
   g_han=50;   lt=0x00ff;
   while(true)
   {
      mp=key_nhan();
//!      if(mp==0)   tt=1;
//!      if(mp==1)   tt=2;
//!      if(mp==2)   tt=3;
      
      b413_dem_xung_ngoai_t0();
      phim_run();
      phim_stop();
      phim_ud();
   }
}
