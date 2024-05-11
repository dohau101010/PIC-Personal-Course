unsigned int8 t0,t0ud, t0_tam, g_han;
usi16 lt, lp;
int1 ud=0;
void lcd_hienthi_up()
{

   lcd_goto_xy (3,18); 
   lcd_data("UP");
}

void lcd_hienthi_dw ()

{
   lcd_goto_xy (3,18);  
   lcd_data("DW");
}

void lcd_hienthi_run()
{
   lcd_goto_xy (3,12);
   lcd_data("Run ");
}

void lcd_hienthi_stop()
{
   lcd_goto_xy (3,12);
   lcd_data("Stop");
}

void tinh_t0_ud()
{
   if (ud==0)
      t0ud=t0;
   else
      t0ud=g_han-t0;
}

void hienthi_4led7doan ()
{
   tinh_t0_ud();
   md4l7d_giaima_2so_vitri_vn (t0ud, 3, cx_vn) ;
   md4l7d_giaima_2so_vitri_vn (g_han,1,cx_vn) ;
   xuat_4led_7doan_4so();
}

void lcd_hienthi_gh_soto ()
{
   lcd_hien_thi_so_to((g_han/10%10),1,4);
   lcd_hien_thi_so_to((g_han%10),1,7);
}

void lcd_hienthi_t0_soto()
{
   tinh_t0_ud();
   lcd_gm_ht_2so_to_xvn(t0ud,1,14,cx_vn);
}
void dem_xung_ngoai_t0 ()
{
   t0 = get_timer0 () ;
   if (t0_tam!=t0)
   {
      t0_tam=t0;
      if (t0>g_han)
      {
         set_timer0(0); 
         buzzer_on_off (300);
      } 
      hienthi_4led7doan ();
      lcd_hienthi_t0_soto() ;
   }
}
void phim_ud()
{
   if(phim_bt2_c2(300)==co_nhan)
   {
      t0=g_han-t0;
      set_timer0(t0  );
      ud=~ud;
      lt=~lt;
      xuat_32led_don_2word (lt, lp);
      if (ud) lcd_hienthi_dw ();
      else lcd_hienthi_up();
   }
}
void phim_stop()
{
   if(phim_bt1_c2(100)==co_nhan)
   {
      setup_timer_0 (t0_off);
      lp=0;
      xuat_32led_don_2word(0,lp);
      lcd_hienthi_stop();
   }
}
void phim_run()
{
   if(phim_bt0_c2( 100)==co_nhan)
   {
      setup_timer_0 (t0_ext_l_to_h|t0_div_1); 
      lp=0xffff;
      xuat_32led_don_2word (lt, lp);
      lcd_hienthi_run();  
   }
}
