#include <tv_kit_vdk_pic_all.c>

usi8 giay_tam,bdn,tt_ht=0, tt_htg, gt_mod, tg_chinh, tt_xoa;


#include<bai_616_clock_ds1307_lcd_tv.c>
#include<bai_616_ds1307_3key_tv.c>

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
   bdn=0; gt_mod=0; tt_ht=0;
   ds1307_kiem_tra_ma();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   
   ds1307_kiem_tra_ma(); //tai sao lai thuc hien 2 lan
   lcd_goto_xy(0,0);
   ds1307_hthi_text_lcd();
   ds1307_hthi_thu_lcd();
   ds1307_hthi_giay_lcd_soto();
   ds1307_hthi_phut_lcd_soto();
   ds1307_hthi_gio_lcd_soto();
   ds1307_hthi_ntn_lcd();
   
   while(true)
   {
      if(bdn<10)
      {
         xu_ly_choptat();
         phim_chon_hthi();
         phim_mod(80);
         phim_up(50);
         phim_dw(50);
         hien_thi_8led_7doan_quet();
      }
      else
      {
         bdn=0;
         
         if(tg_chinh<10)  tg_chinh++;
         else             tg_chinh=0;
         
         ds1307_doc_time(8);
         if(giay_tam!=giay_ds)
         {
             giay_tam=giay_ds;
             giai_ma_gpg_ntn_8l7dq();
             ds1307_hthi_lcd_soto();
         }
      }
   }  
}

