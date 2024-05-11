#include <tv_kit_vdk_pic_all.c>
#include <tv_08_step_motor.c> 
#include <bai_805_step_motor_tv.c> 
 
void main() 
{ 
    set_up_port(); 
    stepmotor_delay=20; //thoi gian delay giua 2 buoc
    stepmotor_tn = 1;  //chon chieu quay thuan
    stepmotor_fh = 1;  //chon buoc du
    sb=0;   sv=0;
    
    lcd_setup();
    lcd_khoi_tao_cgram_so_to();
    
    lcd_goto_xy(0,0);
    lcd_data("STEP MOTOR:");
    
    lcd_ht_stop();
    lcd_ht_full_half();
    
    lcd_ht_sv_to_sb(2,0,1,1); //goi ham lcd hthi so vong to so buoc tai hang 2 cot 0, cho phep hienthi ca so to so nho 
    hienthi_sb_sv_l7d();
    
    while(true)
    { 
       step_motor_on_off_inv(); //ktra xem co nhan nut on,off,inv hay ko
       phim_bt3_fs_hs(); //ktra xem co dao giua buoc du va nua buoc hay ko
       if(stepmotor_onoff) //co =1 hay ko, da nhan on
       {
          step_motor_run_fs_hs(); //ham dieu khien dong co buoc quay theo dung 1 trang thai theo chieu va buoc da chon
          delay_ms(stepmotor_delay);
          if(stepmotor_fh==0) //bit chon buoc du hay nua buoc, =0: quay che do nua buoc
          {
            step_motor_run_fs_hs(); //tien hanh quay them nua buoc nua
            delay_ms(stepmotor_delay); //quay cho du 1 buoc du = 2 nua buoc
          }
          sb++;
          if(sb==200) //du 1 vong =200 buoc
          {
            sb=0; sv++;
            if(sv==99)   sv=0;
          }
          lcd_ht_sv_to_sb(2,0,1,1);
          hienthi_sb_sv_l7d();
       }
    } 
}
