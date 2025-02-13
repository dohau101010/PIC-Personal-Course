#include <tv_kit_vdk_pic_all.c> 
#include <tv_06_glcd.c> 
#include <graphics.c>//duoi tv_pic_glcd 
//#include <de1_donghoso_ds1307_tv.c> 
//--------------dem san pham len xuong-------------------------//
int1  tt_dem=0;
int1 tt_ht_t0 = 0;
unsigned int8 t0, t0ud, g_han = 50,t0_tam = 1, mp, mpt;
int1 tt_xoa = 0;
unsigned int8 ds18a_ng,ds18a_ngt=0;
unsigned int16 ds18a_w;
void kt_mp_ud()
{
   if(mp == 1) 
   {
      tt_dem = 0;
      mpt = mp;
   }
   if(mp == 2) 
   {  
      tt_dem = 1;
      mpt = mp;
   }
    if(mpt!= mp) 
    {
      t0 = g_han - t0;
      set_timer0(t0); 
    }
}  
void tinh_tt_dem()
{
  kt_mp_ud();
  if(tt_dem==0) t0ud = t0;  // dem len
  else      t0ud = g_han-t0; // dem xuong
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
   }
   else if(tt_ht_t0 == 1)
   {  
      lcd_xoa_so_to(0,16);
      lcd_goto_xy(0,16);
      lcd_data(t0ud/10+0x30);
      lcd_hien_thi_so_to(t0ud%10,0,16);
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
//-------------- do nhiet do 18b20-------------------------//
void ds18b20_a_ht_lcd()
{
  
    if(ds18a_ngt!=ds18a_ng)
    {
        ds18a_ngt=ds18a_ng;
       if(tt_xoa==0)
       {
          lcd_goto_xy(0,0);
          lcd_data("    ");
          lcd_hien_thi_so_to(ds18a_ng/10,0,0);
          lcd_goto_xy(1,3);
          lcd_data(ds18a_ng%10+0x30);
       }
       if(tt_xoa==1)
       {
         lcd_goto_xy(0,0);
         lcd_data("    ");
         lcd_goto_xy(1,0);
         lcd_data("    ");
         lcd_goto_xy(0,0);
         lcd_data(ds18a_ng/10+0x30);
         lcd_hien_thi_so_to(ds18a_ng%10,0,1);
       }
    }
}
void ds18b20_a_doc_xuly_hthi()
{
    if(touch_present())
    {
       ds18a_w = ds18b20_read_temp();
       ds18a_ng = ds18a_w>>4; //dich phai gia tri 4bit
       ds18b20_a_ht_lcd();
    }
    else ds18b20_no_ds18b();
}
void main()
{ 
    set_up_port();
    //------------ setup dong ho -----------------------------//
   //! setup_glcd(glcd_text_mode);
    lcd_setup();
    lcd_khoi_tao_cgram_so_to();
//! setup_glcd(glcd_graphic_mode); 
//! glcd_mau_nen(0);
//! glcd_xuat_anh(64,64,2,0);
//! gdram_vdk_to_gdram_glcd_all();
//! ds1307_kiem_tra_ma(); 
//! setup_dongho();
//! ds18b20_khoi_tao();
    tt_xoa = 0;
    setup_timer_0(t0_ext_l_to_h|t0_div_1); 
    set_timer0(0); 
   while(true)
   {
      //------------- ve va hien thi dong ho tren glcd------------------------//
//!   ds1307_doc_time(8); 
//!   if (giay_tam!=giay_ds) 
//!    { 
//!       giay_tam=giay_ds;
//!       giay_bin=(giay_ds/16)*10+(giay_ds%16);
//!       if(giay_ds==0)
//!       {
//!         phut_bin=(phut_ds/16)*10+(phut_ds%16);
//!         glcd_ve_kim_phut(bkm,phut_bin,1);
//!         if(phut_ds ==0)
//!         {
//!         gio_bin=(gio_ds/16)*10+(gio_ds%16);
//!         glcd_ve_kim_gio(bkh,gio_bin,1);
//!         }
//!       }
//!       glcd_ve_kim_giay(bks,giay_bin,1);
//!       gdram_vdk_to_gdram_glcd_all();
//!       glcd_dong_ho_so();
//!       }
//---------------------------- dem sp---------------------//
      mp = key_4x4_dw();
      if(mp == 0x00)
      {
         tt_ht_t0 = ~ tt_ht_t0;
      }
      dem_xung_ngoai_t0();
      if(mp == 0x03) 
      {
         tt_xoa=~tt_xoa; 
         ds18b20_a_doc_xuly_hthi();
         xuat_32led_don_2word(0xff00,0);
         md4l7d_giaima_2so_vitri_vn(tt_xoa,1,kx_vn);
         xuat_4led_7doan_4so();
     }
   }
}
    
