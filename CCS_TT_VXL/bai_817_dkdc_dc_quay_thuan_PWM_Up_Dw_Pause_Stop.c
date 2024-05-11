#include <tv_kit_vdk_pic_all.c>
#include <tv_08_dc_motor.c>
#include <bai_817_dc_motor_tv.c>

void main()
{
   set_up_port();
   dc_motor_enable();
   dc_motor_ktao_ccp1_thuan();
   
   setup_timer_2(t2_div_by_16,249,1);
   pwm_duty=0;    pwm_tdo=0;
   set_pwm2_duty(pwm_duty);
   
   giai_ma_7doan_quet();
   dl_8l7dq[4]=0xbf;
   tt_onoff=0;
   tt_up=0; tt_dw=0;
   
   while(true)
   {
      phim_up();
      tang_toc_up();
      phim_stop();
      phim_dw();
      giam_toc_dw();
      for(i=0;i<2;i++)
         hien_thi_8led_7doan_quet();
   }
}
