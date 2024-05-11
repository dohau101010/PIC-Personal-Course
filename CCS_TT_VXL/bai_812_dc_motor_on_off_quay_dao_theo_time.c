#include <tv_kit_vdk_pic_all.c>
#include <tv_08_dc_motor.c>
#include <bai_812_dc_motor_tv.c>
signed int8 giay, bdn;

#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}

void tang_giay()
{
   bdn = bdn-10;  giay++;
   if(giay==60)   giay=0;
   md8l7d_gma_2so_vitri_vn(giay,0,kx_vn);
}

void main()
{
   set_up_port();
   
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   
   giay=0;
   bdn=0;
   
   md8l7d_gma_2so_vitri_vn(giay,0,kx_vn);
   dc_motor_enable();
   dc_motor_stop();
   
   while(true)
   {
      if(bdn<10)
      {
         hien_thi_8led_7doan_quet();
         phim_on_off();
         dkdc_theo_giay(giay);
      }
      else tang_giay();
   }
}
