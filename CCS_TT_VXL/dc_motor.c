#include <tv_kit_vdk_pic_all.c>
#include <tv_08_dc_motor.c>
#define hstd 20 //he so toc do
unsigned int16 pwm_tdo=0;
//int1 tt_onoff=0;
int1 tt_stop=0;
void quay_thuan_tang_toc()
{
   if(pwm_tdo<50)
   {
      dcmotor_tn=1; tt_stop=1;
      dc_motor_ktao_ccpx();
      pwm_tdo++;
      pwm_duty=pwm_tdo*hstd;
      dc_motor_set_pwmx_duty();
   }
}

void dong_co_giam_toc()
{
   if(pwm_tdo>0)
   {
      dcmotor_tn=1; tt_stop=1;
      dc_motor_ktao_ccpx();
      pwm_tdo--;
      pwm_duty=pwm_tdo*hstd;
      dc_motor_set_pwmx_duty();
   }
}

void motor_dc_stop()
{
   if(tt_stop)
   {
      tt_stop=0; pwm_tdo=0;
      dc_motor_set_pwmx_duty();
      dc_motor_pwm_ccp1_ccp2_stop();
   }
}

void main()
{
   set_up_port();

   dc_motor_enable();
   setup_timer_2(t2_div_by_16,249,1);
   pwm_duty=0;    pwm_tdo=0;
   
   while(true)
   {
      if(phim_up_c2(1)==co_nhan)
         quay_thuan_tang_toc();
      else if(phim_dw_c2(1)==co_nhan)
         dong_co_giam_toc();
      else  motor_dc_stop();
   }
}
   
   
