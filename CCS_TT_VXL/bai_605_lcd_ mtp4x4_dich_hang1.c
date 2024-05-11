
#include <tv_kit_vdk_pic_all.c> 

unsigned INT8 hang1[20];
unsigned INT8 mp,i; 
void xoa_hang_1()
{
   FOR (i = 0; i < 20; i++) hang1[i] = " ";
}

void lcd_dich_ht_mp()
{
   FOR (i = 0; i < 19; i++) hang1[i] = hang1[i + 1];
   IF (mp < 10) hang1[19] = (mp + 0x30);
   ELSE hang1[19] = (mp + 0x37);
   lcd_GOTO_xy (1, 0);
   FOR (i = 0; i < 20; i++) lcd_data (hang1[i]);
}

void main() 
{
   set_up_port();
   lcd_setup ();
   lcd_GOTO_xy (0, 0);
   lcd_data ("hay nhan phim bat ky");
   xoa_hang_1 ();

   WHILE (true)
   {
      mp = key_4x4_dw ();

      IF (mp != 0xff)
      {
         lcd_dich_ht_mp () ;
         delay_ms (200); //de giam toc DO
      }
   }
}

