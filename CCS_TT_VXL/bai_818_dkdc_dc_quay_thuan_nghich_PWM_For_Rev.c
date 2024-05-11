#include <tv_kit_vdk_pic_all.c>
#include <tv_08_dc_motor.c>
#include <bai_818_dc_motor_tv.c>

void main()
{
   set_up_port();
   dc_motor_enable();
   setup_timer_2(t2_div_by_16,249,1);
   pwm_duty=0;    pwm_tdo=0;
   giai_ma_7doan_quet();
   dl_8l7dq[4]=0xbf;
   
   while(true)
   {
      if(phim_up_c2(1)==co_nhan)
         quay_thuan_tang_toc();
      else if(phim_dw_c2(1)==co_nhan)
         quay_thuan_tang_toc();
      else  motor_dc_stop();
      for(i=0;i<20;i++)
         hien_thi_8led_7doan_quet();
   }
}
