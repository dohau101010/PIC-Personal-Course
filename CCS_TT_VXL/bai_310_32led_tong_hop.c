#include <tv_kit_vdk_pic_all.c>

void b303_32led_chop_tat(usi16 dl)          
{                                 
   xuat_32led_don_4byte(0,0,0,0);     delay_ms(dl);                                  
   xuat_32led_don_4byte(0xff,0xff,0xff,0xff);  delay_ms(dl);        
}

void b306_32led_std_tnv(usi16 dl)          
{                                 
   usi8 i;  usi16 LT; usi16 LP;
   LT=0; LP=0;
   for(i=0;i<16;i++)
   {
      LT = (LT>>1)+0x8000;
      LP = (LP<<1)+0x0001;
      xuat_32led_don_2word(LT, LP);
      delay_ms(dl);
      
   } 
   for(i=0;i<16;i++)
   {
      LT = (LT>>1);
      LP = (LP<<1);
      xuat_32led_don_2word(LT, LP);
      delay_ms(dl);
      
   } 
}

void b307_32led_std_ttr(usi16 dl)          
{                                 
   usi8 i;  usi16 LT; usi16 LP;
   LT=0; LP=0;
   for(i=0;i<16;i++)
   {
      LT = (LT<<1)+0x0001;
      LP = (LP>>1)+0x8000;
      xuat_32led_don_2word(LT, LP);
      delay_ms(dl);
      
   } 
   for(i=0;i<16;i++)
   {
      LT = (LT<<1);
      LP = (LP>>1);
      xuat_32led_don_2word(LT, LP);
      delay_ms(dl);
      
   } 
}
void b308_32led_std_pst(usi16 dl)          
{                                 
   usi8 i;  usi32 x;
   x=0;
   for(i=0;i<32;i++)
   {
      x = (x<<1)+1;
      xuat_32led_don_1dw(x);  delay_ms(dl);        
   } 
   for(i=0;i<32;i++)
   {
      x = (x<<1);
      xuat_32led_don_1dw(x);  delay_ms(dl);        
   } 
}

void b309_32led_std_tsp(usi16 dl)          
{                                 
   usi8 i;  usi32 x;
   x=0;
   for(i=0;i<32;i++)
   {
      x = (x>>1)+0x80000000;
      xuat_32led_don_1dw(x);  delay_ms(dl);        
   } 
   for(i=0;i<32;i++)
   {
      x = (x>>1);
      xuat_32led_don_1dw(x);  delay_ms(dl);        
   } 
}

void h310_32led_chop_tat_nlan(int8 n, usi16 dl)
{
   for(int8 j=0;j<n;j++)
      b303_32led_chop_tat(dl);
}

void h310_32led_std_pst_nlan(int8 n, usi16 dl)
{
   for(int8 j=0;j<n;j++)
      b308_32led_std_pst(dl);
}

void h310_32led_std_tsp_nlan(int8 n, usi16 dl)
{
   for(int8 j=0;j<n;j++)
      b309_32led_std_tsp(dl);
}

void h310_32led_std_tnv_nlan(int8 n, usi16 dl)
{
   for(int8 j=0;j<n;j++)
      b306_32led_std_tnv(dl);
}

void h310_32led_std_ttr_nlan(int8 n, usi16 dl)
{
   for(int8 j=0;j<n;j++)
      b307_32led_std_ttr(dl);
}

void main()
{
   set_up_port();
   while(true)
   {
      h310_32led_chop_tat_nlan(5, 100);
      h310_32led_std_pst_nlan(2, 20);
      h310_32led_chop_tat_nlan(5, 100);
      h310_32led_std_tsp_nlan(2, 20);
      h310_32led_chop_tat_nlan(5, 100);
      h310_32led_std_tnv_nlan(2, 20);
      h310_32led_chop_tat_nlan(5, 100);
      h310_32led_std_ttr_nlan(2, 20);
   }
}




