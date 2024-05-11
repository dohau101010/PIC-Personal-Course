
#include <tv_kit_vdk_pic_all.c> 
const UNSIGNED char hang2[]={0,0x0a,0x15,0x11,0x11,0x0a,0x04,0};
signed INT8 i;
void main()
{
   set_up_port();
   lcd_setup ();
   lcd_GOTO_xy (0, 6);
   LCD_DATA("|||      ");
   LCD_GOTO_XY(1,6);
   LCD_DATA("|||      ");
   lcd_GOTO_xy (2, 0);
   lcd_data ("((()))  ((())) ");
   lcd_command (0x40); //thiet lap dia chi bat dau cgram
   FOR (i = 0; i < 8; i++) lcd_data (hang2[i]); //moi lan luu 1 byte tu dong tang dia chi len, truoc do 0x40 thi i=1 se len 0x41
   lcd_GOTO_xy (3, 10); lcd_data (0);//hien thi ma trai tim la 0
   lcd_GOTO_xy (3, 9); lcd_data (0);
   WHILE (true) ;
}


