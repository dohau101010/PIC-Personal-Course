#include <tv_kit_vdk_pic_all.c>
usi8  bdn, sp, mp, gh, chuc, donvi;
int1 status;
#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}
void hienthi_gpg()
{
   lcd_hien_thi_so_to(gio_ds/16, 0, 0);
   lcd_hien_thi_so_to(gio_ds%16, 0, 3);
   lcd_hien_thi_so_to(phut_ds/16, 0, 7);
   lcd_hien_thi_so_to(phut_ds%16, 0, 10);
   lcd_hien_thi_so_to(giay_ds/16, 0, 14);
   lcd_hien_thi_so_to(giay_ds%16, 0, 17);
}
void hienthi_dem()
{
   lcd_gm_ht_2so_to_xvn(sp,2,13,0);
}
void hienthi_cai()
{
      gh=chuc*10+donvi;
   
   lcd_gm_ht_2so_to_xvn(gh,2,0,0);
}
void dem_sp()
{
   sp=get_timer0();
   if(sp>gh)
   {
      set_timer0(1);
      sp=1;
   }
}
void hienthi_on()
{
   lcd_goto_xy(2,8);
   lcd_data("ON ");
}
void hienthi_off()
{
   lcd_goto_xy(2,8);
   lcd_data("OFF");
}
void main()
{
   set_up_port();
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   setup_timer_0(t0_off);
   set_timer0(0);
   ds1307_kiem_tra_ma();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   hienthi_dem();
   hienthi_off();
   hienthi_cai();
   while(true)
   {
      if(bdn>=10)
      {
         bdn=0;
         ds1307_doc_time(8);      
         hienthi_gpg();
      } 
      else
      {
         mp=key_4x4_dw();
         if(mp<10) 
         {
            chuc=donvi; donvi=mp;
            hienthi_cai();
         }
         else if(mp==0x0a)
         {
            setup_timer_0(t0_ext_l_to_h|t0_div_1);
            status=1;
            hienthi_on();
         } 
         else if(mp==0x0c)
         {
            status=0;
            setup_timer_0(t0_off);
            hienthi_off();
         }
         if(status==1) 
         {
            dem_sp();
            hienthi_dem();
         }
      }
   }
}
