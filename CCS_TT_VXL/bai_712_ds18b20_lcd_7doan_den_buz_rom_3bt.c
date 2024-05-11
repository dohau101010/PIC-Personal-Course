#include <tv_kit_vdk_pic_all.c>
#include <bai_711_ds18a_tv.c>
#include <bai_711_bt3_lcd_tv.c>
#include <bai_712_bt_up_dw_lcd_tv.c>

void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   
   lcd_goto_xy(0,0);
   lcd_data("DS18A");
   ds18b20_khoi_tao();
   lcd_goto_xy(3,0);
   lcd_data("ROM:");
   ds18b20_doc_rom(3,4);
   
   lcd_goto_xy(1,12);
   lcd_data("High");
   lcd_goto_xy(1,17);
   lcd_data("Low");
   
   hienthi_nd_tren();
   hienthi_nd_duoi();
   
   lcd_goto_xy(0,6);
   lcd_data("BUZZ:");
   buz_ena=0;
   lcd_ena_buz_off();
   
   while(true)
   {
      ds18b20_a_doc_xuly_hthi();
      so_sanh_nd_dk_buzzer(ds18a_ng,0,1);
      phim_bt3_tat_mo_buzz();
      
      chinh_nd_tren();
      chinh_nd_duoi();
   }
}
