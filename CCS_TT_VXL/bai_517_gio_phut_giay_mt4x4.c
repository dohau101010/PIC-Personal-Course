#include <tv_kit_vdk_pic_all.c>
#include <bai_517_gpg_tv.c>

void main()
{
   set_up_port();
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   giay=0; bdn=0;
   phut=0; gio=0;
   xoa_gpg();
   
   while(true)
   {
      if(bdn<10)
      {
         mp=key_4x4_dw_c2(10);
         if(mp==0x0e)
         {
            xoa_gpg();
            chinh_gpg_mtp4x4();
         }
         hien_thi_8led_7doan_quet();
      }
      else  xu_ly_tang_gpg();
   }
}
