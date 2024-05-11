#include <tv_kit_vdk_pic_all.c>
signed INT8 giay,bdn,phut,gio;
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
   set_timer3 (3036);
   enable_interrupts (global) ;
   enable_interrupts (INT_timer3);
   giay = 0; bdn = 0; phut=0; gio=0;
   md8l7d_gma_2so_vitri_vn (giay, 0, kx_vn) ;
   md8l7d_gma_2so_vitri_vn (phut, 3, kx_vn) ;
   md8l7d_gma_2so_vitri_vn (gio, 6, kx_vn) ;
   dl_8l7dq[2] = 0xbf; 
   dl_8l7dq[5] = 0xbf;
   WHILE (true)
   {
      hien_thi_8led_7doan_quet ();

      IF (bdn >= 10)
      {
         bdn = bdn - 10; giay++;
         IF (giay == 60) 
         { 
            giay = 0;
            phut ++;
            if (phut == 60)   gio++;
         }
         md8l7d_gma_2so_vitri_vn (giay, 0, kx_vn) ;
         md8l7d_gma_2so_vitri_vn (phut, 3, kx_vn) ;
         md8l7d_gma_2so_vitri_vn (gio, 6, kx_vn) ;
         dl_8l7dq[2] = 0xbf;
         dl_8l7dq[5] = 0xbf;
      }
   }
}

