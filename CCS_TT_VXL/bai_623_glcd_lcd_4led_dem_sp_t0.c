#include <tv_kit_vdk_pic_all.c> 
#include <tv_06_glcd.c>

unsigned INT8 t0, t0_tam,g_han; 
void b622_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn (t0, 3, cx_vn) ;
   md4l7d_giaima_2so_vitri_vn (g_han, 1, cx_vn);
   xuat_4led_7doan_4so ();
}

void h622_lcd_gma_hthi()
{
   lcd_khoi_tao_cgram_so_to();
   lcd_hien_thi_so_to(t0/10%10,2,0);
   lcd_hien_thi_so_to(t0%10,2,4);
   if(t0/10%10==0)   lcd_xoa_so_to(2,0);
}

void h622_glcd_gma_hthi(usi8 addr,usi8 x)
{
   UNSIGNED int8 tram, chuc, donvi;
   tram = x / 100; chuc = x / 10 % 10; donvi = x  % 10;
   glcd_command (addr) ;

   IF (tram == 0)
   {
      glcd_data (' ');
      IF (chuc == 0) glcd_data (' ');
      ELSE glcd_data (chuc + 0x30) ;
   }

   ELSE
   {
      glcd_data (tram + 0x30) ;
      glcd_data (chuc + 0x30);
   }

   glcd_data (donvi + 0x30) ;
}

void b622_dem_sp_glcd_lcd_4l7d_t0()
{
   t0 = get_timer0 ();

   IF (t0_tam != t0)
   {
      t0_tam = t0;
      b622_hienthi_4led7doan () ;
      h622_glcd_gma_hthi (glcd_addr_line1, t0);
      h622_lcd_gma_hthi();
      
      IF (t0 >= g_han)
      {
         set_timer0 (0) ;
         buzzer_on_off (300);
      }
   }
}

void main()
{
   set_up_port ();
   
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("Hien thi san pham: ");
   
   setup_glcd (glcd_text_mode);
   glcd_command (glcd_addr_line0) ;
   glcd_data ("dem san pham:");
   setup_timer_0 (t0_ext_l_to_h|t0_div_1);
   set_timer0 (0) ;
   t0_tam = 1;
   g_han = 50;

   WHILE (true)
   {
      b622_dem_sp_glcd_lcd_4l7d_t0() ;
   }
}

