
#include <tv_kit_vdk_pic_all.c> 
const UNSIGNED char hang2[]={0,0x0a,0x15,0x11,0x11,0x0a,0x04,0
                             0,0x0a,0x1f,0x1f,0x1f,0x0e,0x04,0};
signed INT8 i;
void main()
{
   set_up_port();
   lcd_setup ();
   lcd_GOTO_xy (0, 0);
   lcd_data (" hien thi trai tim ");
   lcd_command (0x40); //thiet lap dia chi bat dau cgram
   FOR (i = 0; i < 16; i++) lcd_data (hang2[i]); //moi lan luu 1 byte tu dong tang dia chi len, truoc do 0x40 thi i=1 se len 0x41
   lcd_GOTO_xy (1, 10); 
   lcd_data (0);//hien thi ma trai tim la 0
   lcd_data (1); //trai tim to day
   
   lcd_goto_xy(2,0);
   for(i=0;i<20;i++)    lcd_data (0); //hien thi trai tim rong
   lcd_goto_xy(3,0);
   for(i=0;i<20;i++)    lcd_data (1);
   
   WHILE (true) ;
}


