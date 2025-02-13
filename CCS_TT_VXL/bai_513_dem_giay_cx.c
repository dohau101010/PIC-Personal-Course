
#include <tv_kit_vdk_pic_all.c>

signed INT8 giay,bdn;

#INT_timer3

void interrupt_timer3() 
{
   bdn++;
   set_timer3 (3036);
}

void main() 
{
   set_up_port ();
   setup_timer_3 (t3_internal|t3_div_by_8);
   set_timer1 (3036);
   enable_interrupts (global) ;
   enable_interrupts (INT_timer3);
   giay = 0; bdn = 0;
   md8l7d_gma_2so_vitri_vn (giay, 0, kx_vn) ;

   WHILE (true)
   {
      hien_thi_8led_7doan_quet ();

      IF (bdn >= 10)
      {
         bdn = bdn - 10; giay++;
         IF (giay == 60) giay = 0;
         md8l7d_gma_2so_vitri_vn (giay, 0, kx_vn) ;
      }
   }
}

