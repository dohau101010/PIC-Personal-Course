#include <tv_kit_vdk_pic_all.c>
#include <bai_338_32led_3y_chay_td_4yc_dung_if.c> 
#include <bai_411_t0_tv.c> 

void main() 
{ 
 set_up_port(); 
 setup_timer_0(t0_ext_l_to_h|t0_div_1); 
 set_timer0(0); t0_tam = 1; g_han=50; 
 while(true) 
 { 
   bai338_32led_chay_td_4yc_dung_if();
   b411_dem_sp_t0(); 
   delay_ms(20);
 } 
}
