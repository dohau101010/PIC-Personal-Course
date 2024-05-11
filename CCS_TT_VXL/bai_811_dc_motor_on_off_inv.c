#include <tv_kit_vdk_pic_all.c>
#include <bai_811_dc_motor_tv.c>

void main()
{
   set_up_port();
   dc_motor_enable(); 
   dc_motor_stop();
   while(true)
   {
      phim_on_off_inv_dkdc();
   }
}
