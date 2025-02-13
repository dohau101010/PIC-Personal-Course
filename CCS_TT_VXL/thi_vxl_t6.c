#include <tv_kit_vdk_pic_all.c>
#include <tv_06_glcd.c>
#include <tv_08_dc_motor.c>
#include <graphics.c>//duoi tv_pic_glcd
#include <bai_633_glcd_kim_gio_phut_giay_tv.c>
usi8 ds_b[8]={0x8E,0X00,0X00,0X00,0XB8,0XC5,0X30,0X28};
usi8 ds_a[8]={0x16,0X00,0X00,0X00,0XB8,0XC5,0X40,0X28};
usi8 giay_tam, giay_bin,phut_bin,gio_bin;
unsigned char hang3[]={"  Nguyen Duc Manh   "};
signed int8 i,tt, tt_tam=5; unsigned char tam;
unsigned int8 mp;
unsigned int8 ds18a_ng,ds18a_ngt=0;
unsigned int16 ds18a_w,ds18a_tp;
unsigned INT8 t0, t0_tam,g_han; 

int1 mode=0, mode1=0;
#define hstd 50
unsigned int16 pwm_tdo = 0;
//signed int8 i;
int1 tt_onoff=0, tt_up=0, tt_dw=0;

signed int8 bdn;
#int_timer3
void timer3_interrupt()
{
   bdn++;
   set_timer3(3036);
}

void hang3_dich_trai()
{
   tam=hang3[0];
   for(i=0;i<19;i++)
      hang3[i]=hang3[i+1];
   hang3[19]=tam;
}

void hang3_dich_phai()
{
   tam=hang3[19];
   for(i=19;i>0;i--)
      hang3[i]=hang3[i-1];
   hang3[0]=tam;
}

void phim_dich_trai()
{
   if(mp==10)
   {
      if(tt!=tt_tam)
         tt=1;
      xuat_32led_don_1dw(0xff); //8led ben phai sang
   }
}

void phim_dich_phai()
{
   if(mp==8)
   {
      if(tt!=tt_tam)
         tt=2;
      xuat_32led_don_1dw(0xff00); //8led ben trai sang
   }
}

void phim_ngung()
{
   if(mp==9)
   {
      if(tt!=tt_tam)
         tt=0;
      xuat_32led_don_1dw(0);
   }
}

void kiem_tra_dich_h3()
{
   if(tt==1)
   {
      hang3_dich_trai();
      lcd_puts(3,0,hang3); //goir mang hang 3 sau khi dich ra hang 3 cot 0
   }
   else if(tt==2)
   {
      hang3_dich_phai();
      lcd_puts(3,0,hang3);
   }
}

void ds18b20_a_ht_lcd()
{
    if(ds18a_ngt!=ds18a_ng)
    {
       ds18a_ngt=ds18a_ng;
       if(mode==0)
       {
          lcd_goto_xy(0,0);
          lcd_data("    ");
          lcd_hien_thi_so_to(ds18a_ng/10,0,0);
          lcd_goto_xy(1,3);
          lcd_data(ds18a_ng%10+0x30);
       }
       if(mode==1)
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
       ds18a_tp = ds18a_w & 0x000f; //giu nguyen 4 bit thap, xoa di cac bit cao
       ds18b20_a_ht_lcd();
    }
    else ds18b20_no_ds18b();
}

void hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn (t0, 3, cx_vn) ;
   md4l7d_giaima_2so_vitri_vn (g_han, 1, cx_vn);
   xuat_4led_7doan_4so (); 
}

void dem_sp_t0()
{
   t0 = get_timer0 ();

   IF (t0_tam != t0)
   {
      t0_tam = t0;
      hienthi_4led7doan ();
      IF (t0 >= g_han)
      {
         mode1=~mode1;
         set_timer0 (5) ;
         buzzer_on_off (300);
      }
   }
}

void lcd_hienthi_tg_cai()
{
   lcd_hien_thi_so_to(t0/10,0,16);
   lcd_goto_xy(1,19);
   lcd_data(t0%10+0x30);
   
   if(mode1==0)
    {
       lcd_goto_xy(0,19);
       lcd_data(" ");
       lcd_xoa_so_to(0,16);
       lcd_hien_thi_so_to(t0/10,0,16);
       lcd_goto_xy(1,19);
       lcd_data(t0%10+0x30);
    }
    if(mode1==1)
    {
//!      lcd_goto_xy(0,16);
//!      lcd_data("    ");
//!      lcd_goto_xy(1,19);
//!      lcd_data("    ");
      lcd_xoa_so_to(0,16);
      lcd_goto_xy(0,16);
      lcd_data(t0/10+0x30);
      lcd_hien_thi_so_to(t0%10,0,17);
    }
}

//!void phim_up()
//!{
//!    if((mp==0x0c)&&(pwm_tdo<20))
//!    {
//!        pwm_tdo++;
//!        pwm_duty = pwm_tdo*hstd;
//!        set_pwm1_duty(pwm_duty);
//!        tt_onoff = 1;    // cho chay 
//!    }
//!}
//!
//!void phim_dw()
//!{
//!  if((mp==0x0d)&&(pwm_tdo>0))
//!  {
//!     pwm_tdo--;
//!     pwm_duty = pwm_tdo*hstd;
//!     set_pwm1_duty(pwm_duty);
//!  }
//!}
//!
//!void phim_stop()
//!{
//!  if((mp==0x0e)&&(tt_onoff))
//!  {
//!     tt_onoff = 0;
//!     pwm_tdo = 0;
//!     pwm_duty = pwm_tdo*hstd;
//!     set_pwm1_duty(pwm_duty);
//!  }
//!}

void giai_ma_7doan_quet()
{
   md8l7d_gma_4so_vitri_vn(pwm_duty,0,cx_vn);
   md8l7d_gma_2so_vitri_vn(pwm_tdo,5,cx_vn);
   //dl_8l7dq[4]=0xbf;
}

void tang_toc_up()
{
  if((tt_onoff==1)&&(tt_up==1))
  {
    if(pwm_tdo<20)
    {
      pwm_tdo++;
      pwm_duty=pwm_tdo*hstd;
      set_pwm1_duty(pwm_duty);
      giai_ma_7doan_quet();
      delay_ms(500);
    }
    else tt_up=0;
  }
}

void phim_up()
{
   if((mp==0x0c)&&(tt_up==0))
   {
      tt_onoff=1; tt_up=1;
   }
}

void giam_toc_dw()
{
   if((tt_onoff==1)&&(tt_dw==1))
   {
      if(pwm_tdo>0)
      {
         pwm_tdo--;
         pwm_duty=pwm_tdo*hstd;
         set_pwm1_duty(pwm_duty);
         giai_ma_7doan_quet();   
         delay_ms(500);
      }
      else 
      {
         tt_onoff=0; tt_dw=0;
      }
   }
}

void phim_dw()
{
   if((mp==0x0d)&&(tt_dw==0))
   {
      tt_dw=1;
   }
}

void phim_stop()
{
   if((mp==0x0e)&&(tt_onoff))
   {
      tt_onoff=0;
      tt_up=0;
      tt_dw=0;
      pwm_duty=0;
      pwm_tdo=0;
      giai_ma_7doan_quet();
      set_pwm1_duty(pwm_duty);
   }
}

void main()
{
   set_up_port();
   setup_glcd(glcd_text_mode);
   delay_ms(10);
   setup_glcd(glcd_graphic_mode);
   glcd_mau_nen(0);
   ds1307_kiem_tra_ma();
   
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0;
   
   setup_timer_0(t0_ext_l_to_h|t0_div_1); 
   set_timer0(5); t0_tam = 1; g_han=25;
   
   lcd_setup();
//!   lcd_goto_xy(3,0);
//!   lcd_data("Nguyen Duc Manh");
   lcd_puts(3,0,hang3);
   tt=0; mode=0;
   lcd_khoi_tao_cgram_so_to();
   ds18b20_khoi_tao();
   
//!   dc_motor_enable();
//!   setup_ccp1(ccp_pwm);
//!   setup_timer_2(t2_div_by_16,249,1);
//!   pwm_duty=0;  pwm_tdo=0;
//!   set_pwm1_duty(pwm_duty);
//!   dc_motor_stop();
//!   dc_motor_enable();
//!   dc_motor_ktao_ccp1_thuan();
//!   
//!   setup_timer_2(t2_div_by_16,249,1);
//!   pwm_duty=0;    pwm_tdo=0;
//!   set_pwm2_duty(pwm_duty);
//!   giai_ma_7doan_quet();
//!   dl_8l7dq[4]=0xbf;
//!   tt_onoff=0;
//!   tt_up=0; tt_dw=0;

    dc_motor_enable();
  dc_motor_ktao_ccp1_thuan();
  setup_timer_2(t2_div_by_16,249,1);
  pwm_duty=0;
  pwm_tdo=0;
  set_pwm1_duty(pwm_duty);
  giai_ma_7doan_quet();
  dl_8l7dq[4]=0xbf;
  tt_onoff=0;
  tt_up=0;
  tt_dw=0;   
   
   glcd_ve_cac_vong_tron_so();
   giay_bin=(giay_ds/16)*10+(giay_ds%16);
   glcd_ve_kim_giay(bks,giay_bin,0);
   giay_tam=0x60;
   
   phut_bin= (phut_ds/16)*10+(phut_ds%16);
   glcd_ve_kim_phut(bkm,phut_bin,1);
   
   gio_bin= (gio_ds/16)*10+(gio_ds%16);
   glcd_ve_kim_gio(bkh,gio_bin,1);
   
   while(true)
   {
      mp = key_4x4_dw_c2(10);
      if(bdn<10)
      {
         phim_dich_trai();
         phim_dich_phai();
         phim_ngung();
         delay_ms(10); //them vao de giam bot do nhay
      }
      else
      {
         bdn=0;
         kiem_tra_dich_h3();
      }
       
      ds18b20_a_doc_xuly_hthi();
      if(mp==0x0b)
      {
         mode=~mode; 
         ds18b20_a_doc_xuly_hthi();
         xuat_32led_don_2word(0xff00,0);
      }
      ds18a_ngt=0;
      
      dem_sp_t0();
      lcd_hienthi_tg_cai();
      
//!      phim_up();
//!      phim_dw();
//!      phim_stop();
      phim_up();
      tang_toc_up();
      phim_stop();
      phim_dw();
      giam_toc_dw();
      
      for(i=0;i<2;i++)
         hien_thi_8led_7doan_quet();
      
      ds1307_doc_time(8);
      if(giay_tam!=giay_ds)
      {
         giay_tam=giay_ds;
         giay_bin=(giay_ds/16)*10+(giay_ds%16);
         if(giay_ds==0)
         {
            phut_bin=(phut_ds/16)*10+(phut_ds%16);
            glcd_ve_kim_phut(bkm,phut_bin,1);
            
            if(phut_ds==0)
            {
               gio_bin=(gio_ds/16)*10+(gio_ds%16);
               glcd_ve_kim_gio(bkh,gio_bin,1);
            }
         }
         glcd_ve_kim_giay(bks,giay_bin,1);
         gdram_vdk_to_gdram_glcd_all();
         glcd_dong_ho_so();
      }
   }
}

