#include <tv_kit_vdk_pic_all.c>
usi8 giay_tam,bdn,tt_ht=0;
#include <bai_521_ds1307_3key_tv.c>

#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}

void main()
{
   set_up_port();
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   
   bdn=0; tt_ht=0;
   gt_mod=0;
   
   ds1307_kiem_tra_ma();
   while(true)
   {
      if(bdn<10)
      {
         if(gt_mod!=0)  xu_ly_choptat();
         phim_chon_hthi();
         phim_mod(100);
         phim_up(40);
         phim_dw(40);
         hien_thi_8led_7doan_quet();
      }
      else 
      {
         bdn=0;
         if(tg_chinh<10)
            tg_chinh++;
         else gt_mod=0;
         
         ds1307_doc_time(8);
         if(giay_tam!=giay_ds)
         {
            giay_tam=giay_ds;
            giai_ma_gpg_ntn_8l7dq();
         }
      }
   }
}
