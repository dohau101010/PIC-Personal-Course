#include <tv_kit_vdk_pic_all.c> 
unsigned INT8 t0, t0_tam,g_han; 
void b608_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn (t0, 3, cx_vn) ;
   md4l7d_giaima_2so_vitri_vn (g_han, 1, cx_vn);
   xuat_4led_7doan_4so ();
}

void b608_dem_sp_t0()
{
   t0 = get_timer0 ();
   IF (t0_tam != t0)
   {
      t0_tam = t0;
      b608_hienthi_4led7doan ();
      IF (t0 >= g_han)
      {
         set_timer0 (0) ;
         buzzer_on_off (300);
      }
   }
}

void lcd_hienthi_tg_cai()
{
   lcd_goto_xy(0,15);
   //g_han = chuc*10+donvi;
   lcd_data(t0/10%10+0x30);
   lcd_data(t0%10+0x30);
}

void main() 
{ 
    set_up_port(); 
    setup_timer_0(t0_ext_l_to_h|t0_div_1); 
    set_timer0(0); t0_tam = 1; g_han=26; 
    
    lcd_setup();
    lcd_goto_xy(0,0);
    lcd_data("HIEN THI TIME:      ");
    while(true) 
    { 
      b608_dem_sp_t0();
      lcd_hienthi_tg_cai();
      delay_ms(200);
    } 
}


