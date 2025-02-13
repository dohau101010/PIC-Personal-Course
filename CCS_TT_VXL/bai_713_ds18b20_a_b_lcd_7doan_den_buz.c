#include <tv_kit_vdk_pic_all.c>
//co 2 mang chua ma ID cua 2 vi mach DS18A va DS18B
usi8 ds_a[8]={0xB2,0X00,0X00,0X05,0X22,0X53,0X12,0X28};
usi8 ds_b[8]={0xD7,0X00,0X00,0X05,0X1F,0X42,0X97,0X28};
si8 i;
#include <bai_711_bt3_lcd_tv.c>
#include <bai_711_2ds18_tv.c>

void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   
   lcd_goto_xy(0,0);
   lcd_data("DS18A BUZZ:    DS18B"); //20 ky tu
   
   lcd_goto_xy(1,0);
   ds18b20_khoi_tao();
   buz_ena=0;
   lcd_ena_buz_off();
   
   while(true)
   {
      ds18b20_a_doc_nhiet_do1();
      ds18b20_b_doc_nhiet_do1();
      
      so_sanh_nd_dk_buzzer(ds18a_ng,ds18b_ng,3);
      phim_bt3_tat_mo_buzz();
   }
}
