#include <tv_kit_vdk_pic_all.c> 
int8 i=0, j=0, n, mp;
int8 m;
const usi8 giaodien[]={0x00,0x00,0x15,0x0E,0x1F,0x0E,0x15, 0x00, //hoa tuyet
                       0x0E,0x0A,0x0E,0x04, 0x1F, 0x04, 0x0A, 0x11 //con ma
                       0x1F,0x1B,0x15,0x1B,0x15,0x1B,0x15, 0x1B,// cai thung
                       0x0A, 0x1F, 0x0E, 0x15,0x04,0x04,0x04,0x04,//cai cay 1
                       0x04,0x02, 0x07,0x0D,0x1F,0x17,0x14, 0x03, //con cua
                       0,0x0a,0x1f,0x1f,0x1f,0x0e,0x04,0,//trai tim
                       0x0E,0x1F, 0x1F,0x1F,0x0E,0x15, 0x15, 0x15 //bach tuot
                       0x11, 0x0E,0x04,0x15, 0x0E,0x04,0x15, 0x0E// cai cay 2
       };

void background()
{
   lcd_goto_xy(3,0);
   for(m=0; m<2; m++) lcd_data(2);
   lcd_goto_xy(3,4);
   lcd_data(2);
   lcd_data(0);
   lcd_goto_xy(3,6);
   for(m=0; m<4; m++) lcd_data(2);
   lcd_goto_xy(3,13);
   for(m=0; m<2; m++) lcd_data(2);
   lcd_goto_xy(3,16);
   lcd_data(2);
   lcd_goto_xy(3,19);
   lcd_data(5);
   
   lcd_goto_xy(2,1);
   lcd_data(7);
   lcd_goto_xy(2,7);
   lcd_data(7);
   lcd_goto_xy(2,10);
   lcd_data(0);
   lcd_goto_xy(2,14);
   lcd_data(7);
   lcd_goto_xy(2,19);
   lcd_data(4);

   lcd_goto_xy(1,0);
   lcd_data(3);
   lcd_goto_xy(1,2);
   lcd_data(0);
   lcd_goto_xy(1,7);
   lcd_data(3);
   lcd_goto_xy(1,11);
   lcd_data(0);
   lcd_goto_xy(1,14);
   lcd_data(3);
   lcd_goto_xy(1,15);
   lcd_data(0);
   lcd_goto_xy(1,19);
   lcd_data(7);
   
   lcd_goto_xy(0,2);
   lcd_data(0);
   lcd_goto_xy(0,10);
   lcd_data(6);
   lcd_goto_xy(0,12);
   lcd_data(0);
   lcd_goto_xy(0,19);
   lcd_data(3);
}
void go_to()
{
   lcd_goto_xy(i,j);
   lcd_data(1);
}
void clear_lcd()
{
    lcd_goto_xy(0,0);
    lcd_data("                    ");
    lcd_goto_xy(1,0);
    lcd_data("                    ");
    lcd_goto_xy(2,0);
    lcd_data("                    ");
    lcd_goto_xy(3,0);
    lcd_data("                    ");
}
void batdau()
{
    lcd_goto_xy(1,0);
    lcd_data("WELCOME TO.....");
    lcd_goto_xy(2,0);
    lcd_data("JOIN the GAME....");
    delay_ms(1000);
    clear_lcd();
    lcd_goto_xy(1,0);
    lcd_data("LOADING..........");
    lcd_goto_xy(2,0);
    for(m=0; m<17; m++)
   { lcd_data(255); delay_ms(200);}
    clear_lcd();
    background();
    go_to();
}
void win()
{
   if(j==19 && i==3)
   {
      clear_lcd();
      lcd_goto_xy(1,7);
      lcd_data("  WIN");
      lcd_goto_xy(2,1);
      lcd_data("  CONGRATULATION!");
      j=1;
   }
}
void lose()
{
   if(j==10 && i==0)
   {
      clear_lcd();
      lcd_goto_xy(1,7);
      lcd_data("  LOSE");
      lcd_goto_xy(2,1);
      lcd_data("  GOOD LUCK LATER!");
      j=1;
   }
}
void main()
{
    set_up_port();
    lcd_setup(); 
    lcd_command(0x40);
    for(n=0;n<64;n++) 
    lcd_data(giaodien[n]);
    batdau();
   while(true)
   {
     mp=key_4x4_up();
     if(mp!=0xff)
     {
     if(mp==0x0b)
     {
         i--;
         lcd_goto_xy(i+1, j);
         lcd_data(" ");
     }
     else if(mp==0x0e) 
     {
        j++;
        lcd_goto_xy(i, j-1);
        lcd_data(" ");
     }
     else if(mp==9)
     {
      i++;
      lcd_goto_xy(i-1, j);
      lcd_data(" ");
     }
     else if(mp==6) 
     {
      j--;
      lcd_goto_xy(i, j+1);
      lcd_data(" ");
     }
      go_to();
      win();
      lose();
     }
     
   }
}
