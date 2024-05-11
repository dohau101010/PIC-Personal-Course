#include <tv_kit_vdk_pic_all.c>
int1 status;
#int_rb
void ngat_portb()
{
   if(phim_bt1_c1(1,0)) 
   status=~status;
    clear_interrupt(int_rb);
}
void b308_32led_std_pst(usi16 dl) 
{
   usi8 i; usi32 x;
   x = 0;
   for(i = 0; i < 32; i++)
   {
      x = (x << 1) + 1;
      xuat_32led_don_1dw (x);
     delay_ms (dl);
      if(status!=0) break;
   }
   for(i = 0; i < 32; i++)
   {
      x = (x << 1);
      xuat_32led_don_1dw (x); 
     delay_ms (dl);
    if(status!=0) break;
   }
}

void b309_32led_std_tsp(usi16 dl) 
{
   usi8 i; usi32 x;
   x = 0;
   for(i = 0; i < 32; i++)
   {
      x = (x>>1) + 0x80000000;
      xuat_32led_don_1dw (x); 
    delay_ms (dl);
      if(status!=1) break;
   }
   for(i = 0; i < 32; i++)
   {
      x = (x>>1);
      xuat_32led_don_1dw (x); 
    delay_ms (dl);
      if(status!=1) break;
   }
}

void main()
{
   set_up_port();
   status=0;
  enable_interrupts(global);
   enable_interrupts(int_rb);

   while(true)
   {
      if(status == 0)
     b308_32led_std_pst (200);
      if(status == 1)
     b309_32led_std_tsp (200);
   }
}

