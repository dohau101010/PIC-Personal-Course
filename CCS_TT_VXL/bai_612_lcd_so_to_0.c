#include <tv_kit_vdk_pic_all.c>
void main()
{ 
 set_up_port(); 
 lcd_setup(); 
 
 lcd_goto_xy(0,0);
 lcd_data("hien thi so 0 hang 2"); 
 
 lcd_khoi_tao_cgram_so_to(); 
 lcd_hien_thi_so_to(9,1,9);
 while(true);
}
