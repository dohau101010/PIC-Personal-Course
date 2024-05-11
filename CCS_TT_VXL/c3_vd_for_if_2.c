#include <tv_kit_vdk_pic_all.c>

usi16 soxung;
usi32 led;
void xulynutnhan()
{
   if(phim_bt0_c1(1,0))
   {
      setup_timer_1(t1_external_sync|t1_div_by_1);
      dcmotor_onoff=1;
      dc_motor_run();
   }
   if(phim_bt1_c1(1,0))
   {
      dc_motor_stop();
   }
   if(phim_bt2_c1(1,0))
   {
      led=~led;
      xuat_32led_don_1dw(led);
      dc_motor_stop();
      delay_ms(500);
      dcmotor_tn=~dcmotor_tn;
      dc_motor_run();
      
   }
}
void hienthi()
{
   soxung=get_timer1();
   md4l7d_giaima_3so_vitri_vn(soxung,3,0);
   xuat_4led_7doan_4so();
}
void main()
{
   set_up_port();
   setup_timer_1(t1_disabled);
   set_timer1(0);
    dc_motor_stop();
   while(true)
   {
      xulynutnhan();
      hienthi();
   }
}
