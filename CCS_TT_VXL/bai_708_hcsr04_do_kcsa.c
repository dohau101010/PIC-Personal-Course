#include <tv_kit_vdk_pic_all.c> 

float kcs;

void tao_xung_trigger() 
{ 
    output_high(trig); 
    delay_us(20); 
    output_low(trig); 
 
    set_timer3(0); 
    while(!(input(echo))); 
    setup_timer_3(t3_internal|t3_div_by_8); 
    
    while(input(echo)); 
    setup_timer_3(t3_disabled);
    kcs = get_timer3();
} 
void cbkc_hc04() 
{ 
    usi16 kc_ng,kc_tp,kc_t;
    
    tao_xung_trigger();
    kcs=kcs*1.6; 
    kcs=(kcs/58); 
    
    float_to_ng_2so_tp(kcs); 
    kc_ng = so_ng;
    kc_tp = so_tp;
    if(kc_t!=kc_ng) 
    {
       kc_t=kc_ng;
       lcd_gm_ht_2so_to_xvn(kc_ng,2,0,kx_vn);
       md4l7d_giaima_4so_vitri_vn(kc_ng,3,kx_vn); 
       xuat_4led_7doan_4so();
    } 
    lcd_hien_thi_2so_tp_nho(kc_tp,3,6);
} 
 
void main() 
{ 
    set_up_port(); 
    lcd_setup();
    lcd_khoi_tao_cgram_so_to();
    lcd_hien_thi_hcsr04(); 
    while(true)
    { 
       cbkc_hc04(); 
       delay_ms(200);
    } 
}
