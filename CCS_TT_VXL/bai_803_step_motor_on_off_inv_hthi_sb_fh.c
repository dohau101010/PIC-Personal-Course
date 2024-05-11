#include <tv_kit_vdk_pic_all.c>
#include <tv_08_step_motor.c> 
#include <bai_803_step_motor_tv.c> 
 
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
       step_motor_on_off_inv(); //ktra xem co nhan nut on,off,inv hay ko
       phim_bt3_fs_hs(); //xem co dao giua buoc du va nua buoc hay ko
       if(stepmotor_onoff) //co =1 hay ko, da nhan on
       {
          step_motor_run_fs_hs();
          delay_ms(stepmotor_delay);
          if(stepmotor_fh==0) //bit chon buoc du hay nua buoc, =0: quay che do nua buoc
          {
            step_motor_run_fs_hs();
            delay_ms(stepmotor_delay); //quay cho du 1 buoc du = 2 nua buoc
          }
          sb++;
          hthi_sobuoc_7doan();
       }
    } 
}
