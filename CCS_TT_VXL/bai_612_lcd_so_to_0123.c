#include <tv_kit_vdk_pic_all.c>
void main()
{ 
 set_up_port(); 
 lcd_setup(); 
 
 lcd_goto_xy(0,0);
 lcd_data("hien thi so 0123 "); 
 
 lcd_khoi_tao_cgram_so_to(); 
 lcd_hien_thi_so_to(0,2,0);
 lcd_hien_thi_so_to(1,2,4);
 lcd_hien_thi_so_to(2,2,8);
 lcd_hien_thi_so_to(3,2,12);
 while(true);
}
