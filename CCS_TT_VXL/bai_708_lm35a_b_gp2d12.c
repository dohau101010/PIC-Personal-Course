#include <tv_kit_vdk_pic_all.c>
#define solan 50
#include <bai_708_lm35a_tv.c>
#include <bai_708_lm35b_tv.c>
#include <bai_701_bt3_lcd_tv.c>
#include <bai_708_gp2d12_tv.c>

void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   
   lcd_goto_xy(0,0);
   lcd_data("LM");
   lcd_goto_xy(1,0);
   lcd_data("A");
   lcd_goto_xy(2,0);
   lcd_data("LM");
   lcd_goto_xy(3,0);
   lcd_data("B");
   lcd_goto_xy(3,9);
   lcd_data("KC");
   
   lcd_goto_xy(0,12);
   lcd_data("BUZZ");
   
   buz_ena=0;
   lcd_ena_buz_off();
   
   while(true)
   {
      h701_adc_lm35a_doc_xuly(solan);
      h701_adc_lm35a_ht_lcd(0,2,1,1);
      h701_adc_lm35a_ht_7doan(1,1);
      
      h702_adc_lm35b_doc_xuly(solan);
      h702_adc_lm35b_ht_lcd(2,2,1,1);
      h702_adc_lm35b_ht_7doan(3,1);
      
      so_sanh_nd_dk_buzzer(lm35a_ng,lm35b_ng,3); //sel=3 so sanh or 2 nhiet do
      phim_bt3_tat_mo_buzz();
      
      h706_adc_gp2d12_doc_xuly(solan); 
      h706_adc_gp2d12_ht_lcd(2,11,1,1);
   }
}
