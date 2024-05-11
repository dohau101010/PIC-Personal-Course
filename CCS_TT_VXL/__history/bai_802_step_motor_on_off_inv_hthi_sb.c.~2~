#include <tv_kit_vdk_pic_all.c>
#include <tv_08_step_motor.c> 
#include <bai_802_step_motor_tv.c> 
 
void main() 
{ 
    set_up_port(); 
    stepmotor_delay=20; //thoi gian delay giua 2 buoc
    stepmotor_tn = 1;  //chon chieu quay thuan
    stepmotor_fh = 1;  //chon buoc du
    sb=0;
    hthi_sobuoc_7doan();
    
    while(true)
    { 
       step_motor_on_off_inv();
       if(stepmotor_onoff)
       {
          step_motor_run_fs_hs();
          sb++;
          hthi_sobuoc_7doan();
          delay_ms(stepmotor_delay);
       }
    } 
}
