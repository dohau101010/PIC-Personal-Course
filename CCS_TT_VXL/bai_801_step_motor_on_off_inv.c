#include <tv_kit_vdk_pic_all.c>
#include <tv_08_step_motor.c> 
#include <bai_801_step_motor_tv.c> 
 
void main() 
{ 
    set_up_port(); 
    stepmotor_delay=5; //thoi gian delay giua 2 buoc
    stepmotor_tn = 1;  //chon chieu quay thuan
    stepmotor_fh = 1;  //chon buoc du
    while(true) 
    { 
       step_motor_on_off_inv();
       if(stepmotor_onoff)
       {
          step_motor_run_fs_hs();
          delay_ms(stepmotor_delay);
       }
    } 
}
