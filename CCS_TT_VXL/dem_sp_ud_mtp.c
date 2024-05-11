#include <tv_kit_vdk_pic_all.c> 
int1  tt_dem=0;
int1 tt_ht_t0 = 0;
unsigned int8 t0, t0ud, g_han = 50,t0_tam = 1, mp, mpt;

void tinh_tt_dem()
{
    if(tt_dem==0) t0ud=t0;  // dem len
    else      t0ud=g_han-t0; // dem xuong
}
 
void hienthi_lcd_counter()
{
   tinh_tt_dem();
   if(tt_ht_t0 == 0)
   {
      lcd_goto_xy(0,19);
       lcd_data(" ");
       lcd_xoa_so_to(0,16);
       lcd_hien_thi_so_to(t0ud/10,0,16);
       lcd_goto_xy(1,19);
       lcd_data(t0ud%10+0x30);
       delay_ms(100);
   }
   else if(tt_ht_t0 == 1)
   {  
      lcd_xoa_so_to(0,16);
      lcd_goto_xy(0,16);
      lcd_data(t0ud/10+0x30);
      lcd_hien_thi_so_to(t0ud%10,0,17);
      delay_ms(100);
   }
}   
void dem_xung_ngoai_t0()
{
    t0 = get_timer0();
    if(t0_tam!=t0)
    {
     t0_tam=t0;
     if(t0>g_han)
    {
      set_timer0(0);
   //buzzer_on_off(300);
    }
//!  hien_thi_4l7d();
    hienthi_lcd_counter();
 }
}
void main()
{ 
    set_up_port();
    //------------ setup dong ho -----------------------------//
    lcd_setup();
    lcd_khoi_tao_cgram_so_to();
    setup_timer_0(t0_ext_l_to_h|t0_div_1); 
    set_timer0(0); 
    g_han = 50;
    
   while(true)
   {
   //---------------------------- dem sp---------------------//
      mp = key_4x4_dw();
      dem_xung_ngoai_t0();
      if(mp == 0x00)
      {
        tt_ht_t0 = ~ tt_ht_t0;
      }
      if(mp == 1) 
      {
         tt_dem = 0;
      }
      if(tt_dem == 0) 
      {
          t0 = t0;
          set_timer0(t0);
         if(t0_tam!=t0)
         {
            t0_tam=t0;
            if(t0>g_han)
            {
             set_timer0(0);
         //buzzer_on_off(300);
            }
         }
         if(mp == 2) 
         {  
            tt_dem = 1;
         }
      
         if(tt_dem == 1)
         {
            t0=g_han-t0;
            set_timer0(t0); 
            if(t0_tam!=t0)
            {
               t0_tam=t0;
               if(t0 == 0)
               {
                set_timer0(g_han);
               //buzzer_on_off(300);
               }
            }
            hienthi_lcd_counter();
         }
      }
   }
}
    
