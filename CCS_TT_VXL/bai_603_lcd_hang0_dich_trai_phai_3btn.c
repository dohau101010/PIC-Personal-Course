#include <tv_kit_vdk_pic_all.c> 
signed int8 i,tt; unsigned char tam;
unsigned char hang0[]={"BT0 DICH TRAI HANG 3"};
unsigned char hang1[]={"BT2 DICH PHAI HANG 3"};
unsigned char hang2[]={"   BT1 NGUNG DICH   "};
unsigned char hang3[]={"  MANH DRAGON 2001  "};

signed int8 bdn;
#int_timer3
void timer3_interrupt()
{
   bdn++;
   set_timer3(3036);
}

void hang3_dich_trai()
{
   tam=hang3[0];
   for(i=0;i<19;i++)
      hang3[i]=hang3[i+1];
   hang3[19]=tam;
}

void hang3_dich_phai()
{
   tam=hang3[19];
   for(i=19;i>0;i--)
      hang3[i]=hang3[i-1];
   hang3[0]=tam;
}

void kiem_tra_dich_h3()
{
   if(tt==1)
   {
      hang3_dich_trai();
      lcd_puts(3,0,hang3); //goir mang hang 3 sau khi dich ra hang 3 cot 0
   }
   else if(tt==2)
   {
      hang3_dich_phai();
      lcd_puts(3,0,hang3);
   }
}

void phim_dich_trai()
{
   if(phim_bt0_c2(10))
   {
      tt=1; xuat_32led_don_1dw(0xff); //8led ben phai sang
   }
}

void phim_dich_phai()
{
   if(phim_bt2_c2(10))
   {
      tt=2; xuat_32led_don_1dw(0xff00); //8led ben trai sang
   }
}

void phim_ngung()
{
   if(phim_bt1_c2(10))
   {
      tt=0; xuat_32led_don_1dw(0);
   }
}

void main() 
{
   set_up_port();
   
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0;
   
   lcd_setup();
   lcd_puts(0,0,hang0);
   lcd_puts(1,0,hang1);
   lcd_puts(2,0,hang2);
   lcd_puts(3,0,hang3);
   tt=0;

   WHILE (true)
   {
      if(bdn<10)
      {
         phim_dich_trai();
         phim_dich_phai();
         phim_ngung();
         delay_ms(10); //them vao de giam bot do nhay
      }
      else
      {
         bdn=0;
         kiem_tra_dich_h3();
      }
   }
}

