
#include <tv_kit_vdk_pic_all.c>

signed INT8 tt_ct; 
void b308_32led_std_pst(usi16 dl) 
{
   usi8 i; usi32 x;
   x = 0;
   FOR (i = 0; i < 32; i++)
   {
      x = (x << 1) + 1;
      xuat_32led_don_1dw (x); delay_ms (dl);
   }

   FOR (i = 0; i < 32; i++)
   {
      x = (x << 1);
      xuat_32led_don_1dw (x); delay_ms (dl);
   }
}

void b309_32led_std_tsp(usi16 dl) 
{
   usi8 i; usi32 x;
   x = 0;
   FOR (i = 0; i < 32; i++)
   {
      x = (x>>1) + 0x80000000;
      xuat_32led_don_1dw (x); delay_ms (dl);
   }

   FOR (i = 0; i < 32; i++)
   {
      x = (x>>1);
      xuat_32led_don_1dw (x); delay_ms (dl);
   }
}

void b326_32led_std_pst_tsp_tat_3bt() 
{
   IF (phim_bt0_c1 (c_ktnp, 0) == co_nhan)
   {
      IF (tt_ct < 2) tt_ct++;
   }

   IF (phim_bt1_c1 (c_ktnp, 0) == co_nhan)
   {
      IF (tt_ct > 0) tt_ct--;
   }

   IF (tt_ct == 0) xuat_32led_don_1dw (0);
   IF (tt_ct == 1) b308_32led_std_pst (200);
   IF (tt_ct == 2) b309_32led_std_tsp (200);
}

void main()
{
   set_up_port();
   tt_ct = 0;

   WHILE (true)
   {
      b326_32led_std_pst_tsp_tat_3bt ();
   }
}

