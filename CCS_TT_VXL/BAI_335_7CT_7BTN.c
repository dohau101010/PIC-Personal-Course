#include <tv_pickit2_shift_1.c>
unsigned int32 led;
signed int8 tt_ct, k, mp;
unsigned int16 lp, lt;
void choptat_32led()
{
   xuat_32led_don_1dw(0xffffffff);
   delay_ms(400);
   xuat_32led_don_1dw(0);
   delay_ms(400);
}
void std_32led_pst()
{
   if(k<32)
   {
      led=(led<<1)+1;
      xuat_32led_don_1dw(led);
      delay_ms(100);
      k++;
   } 
   else if(k<64)
   {
      led=(led<<1);
      xuat_32led_don_1dw(led);
      delay_ms(100);
      k++;
   }
   else 
   {
      led=0;
      k=0;
   }
}
void std_32led_tsp()
{
   if(k<32)
   {
      led=(led>>1)+0x80000000;
      xuat_32led_don_1dw(led);
      delay_ms(100);
      k++;
   } 
   else if(k<64)
   {
      led=(led>>1);
      xuat_32led_don_1dw(led);
      delay_ms(100);
      k++;
   }
   else 
   {
      led=0;
      k=0;
   }
}
void std_32led_tu_ngoaivao()
{
    if(k<16)
   {
      lt=(lt>>1)+0x8000;
      lp=(lp<<1)+1;
      xuat_32led_don_2word(lt, lp);
      delay_ms(100);
      k++;
   } 
   else if(k<32)
   {
      lt=(lt>>1);
      lp=(lp<<1);
      xuat_32led_don_2word(lt, lp);
      delay_ms(100);
      k++;
   }
   else 
   {
      led=0;
      k=0;
   }
}
void std_32led_tu_trongra()
{
    if(k<16)
   {
      lt=(lt<<1)+1;;
      lp=(lp>>1)+0x8000;
      xuat_32led_don_2word(lt, lp);
      delay_ms(100);
      k++;
   } 
   else if(k<32)
   {
      lt=(lt<<1);
      lp=(lp>>1);
      xuat_32led_don_2word(lt, lp);
      delay_ms(100);
      k++;
   }
   else 
   {
      led=0;
      k=0;
   }
}
void reset()
{
   k=0;  led=0; 
   lt=0; lp=0;
}

void xu_ly_phim()
{
   mp=key_4x4_dw();
   if(mp==1)       choptat_32led();
   else if(mp==2)  std_32led_pst();
   else if(mp==3)  std_32led_tsp();
   else if(mp==4)  std_32led_tu_ngoaivao();
   else if(mp==5)  std_32led_tu_trongra();
}
void main()
{
   set_up_port_ic_chot();
   set_tris_b(0x3c);

   reset();
   tt_ct=1;
   while(true)
   {
     xu_ly_phim();
   }
}
