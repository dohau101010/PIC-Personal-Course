#include <tv_kit_vdk_pic_all.c> 
#define solan 100 
#include <bai_706_gp2d12_tv.c> 
void main() 
{ 
    set_up_port(); 
    lcd_setup(); 
    lcd_khoi_tao_cgram_so_to(); 
    
    lcd_goto_xy(0,10); 
    lcd_data("GP2D12"); 
    while(true) 
    { 
       h706_adc_gp2d12_doc_xuly(solan); 
       h706_adc_gp2d12_ht_lcd(1,10,1,1);
       h706_adc_gp2d12_ht_7doan(3,1);
       delay_ms(200);
    } 
}
