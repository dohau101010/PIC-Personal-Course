
#include <tv_kit_vdk_pic_all.c> 
#define solan 100 
#include <bai_701_lm35a_tv.c> 
#include <bai_701_bt3_lcd_tv.c>

void main() 
{
   set_up_port ();
   lcd_setup () ;
   lcd_khoi_tao_cgram_so_to ();
   
   lcd_GOTO_xy (0, 0);
   lcd_data ("LM35A BUZZ:");  //11 ky tu
   buz_ena=0;
   lcd_ena_buz_off(); //ham hien thi chu off
   
   WHILE (true)
   {
      h701_adc_lm35a_doc_xuly (solan);
      h701_adc_lm35a_ht_lcd (1, 0, 1, 1) ; //toa do hang 1 cot 0 , cho phep hien thi so to phan nguyen, cho phep hien thi so thap phan so nho
      h701_adc_lm35a_ht_7doan (1, 1) ;  //tai led 1 vs led 0 , cho phep hien thi
      //so_sanh_1nd_dk_buzzer (lm35a_ng % 256);
      so_sanh_nd_dk_buzzer(lm35a_ng,0,1); //nd2=0, chon che do so sanh la 1 <=> so sanh 1nd
      phim_bt3_tat_mo_buzz();
      //delay_ms (200) ;
      //IF ( ! input (bt3)) buzzer_off ();
   }
}

