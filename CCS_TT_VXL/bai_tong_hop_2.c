#include <tv_kit_vdk_pic_all.c>
#include <tv_06_glcd.c>
#include <tv_08_dc_motor.c>
#include <graphics.c>//duoi tv_pic_glcd
#include <bai_633_glcd_kim_gio_phut_giay_tv.c>
//!usi8 ds_b[8]={0x8E,0X00,0X00,0X00,0XB8,0XC5,0X30,0X28};
//!usi8 ds_a[8]={0x16,0X00,0X00,0X00,0XB8,0XC5,0X40,0X28};
usi8 ds_a[8]={0xF5,0X00,0X00,0X05,0X1E,0XA9,0X27,0X28};
usi8 ds_b[8]={0xCA,0X00,0X00,0X05,0X23,0X29,0X8B,0X28};
//!usi8 ds_a[8]={0XB2,0X00,0X00,0X05,0X22,0X53,0X12,0X28};
//!usi8 ds_b[8]={0XD7,0X00,0X00,0X05,0X1F,0X42,0X97,0X28};
si8 i;
unsigned int8 solan=50;
#include <bai_tong_hop_tv.c>
usi8 giay_tam, giay_bin,phut_bin,gio_bin;
unsigned int8 mp; 
int1 mode_1=0, mode_2=0, mode_3=0;

void phim_up_c3()
{
    if((mp==0x0c)&&(pwm_tdo<50))
    {
        pwm_tdo++;
        pwm_duty = pwm_tdo*hstd;
        set_pwm1_duty(pwm_duty);
        tt_onoff = 1;    // cho chay 
    }
}

void phim_dw_c3()
{
  if((mp==0x0d)&&(pwm_tdo>0))
  {
     pwm_tdo--;
     pwm_duty = pwm_tdo*hstd;
     set_pwm1_duty(pwm_duty);
  }
}

void phim_stop_c3()
{
  if((mp==0x0e)&&(tt_onoff))
  {
     tt_onoff = 0;
     pwm_tdo = 0;
     pwm_duty = pwm_tdo*hstd;
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
   
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   ds18b20_khoi_tao();
   
   lcd_goto_xy(1,0);
   lcd_data("NGUYEN DUC MANH");
   lcd_goto_xy(2,0);
   lcd_data("19151253");
   
   dc_motor_enable();
   setup_ccp1(ccp_pwm);
   setup_timer_2(t2_div_by_16,249,1);
   pwm_duty=0;  pwm_tdo=0;
   set_pwm1_duty(pwm_duty);
   dc_motor_stop();
   
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
       //mp = key_4x4_dw(); //nhan nha chong doi
       mp=key_nhan();
       if(mp==0)  
       {
         mode_1=1;
         mode_2=0;
         mode_3=0;
         lcd_clear();
       }
       if(mp==1)
       { 
         mode_2=1;
         mode_1=0;
         mode_3=0;
         lcd_clear();
       }
       if(mp==2)
       {
         mode_3=1;
         mode_1=0;
         mode_2=0;
         lcd_clear();
       }
       if(mode_1==1)
       {
           //lcd_clear();
           ds18b20_a_doc_nhiet_do1();
           ds18b20_b_doc_nhiet_do1();
       }
       if(mode_2==1)
       {
         //lcd_clear();
         h701_adc_lm35a_doc_xuly(solan);
         h701_adc_lm35a_ht_lcd(1,0,1,1);
            
         h702_adc_lm35b_doc_xuly(solan);
         h702_adc_lm35b_ht_lcd(1,12,1,1);
         //delay_ms(500);
       }
       if(mode_3==1)
       {
         //lcd_clear();
         dht11_read_temp_humi();
         dht11_hthi_lcd_nd_da(2,0);
       }
       phim_up_c3();
       phim_dw_c3();
       phim_stop_c3();
       
       //reset cac bien trang thai
      ds18a_ngt=0;
      ds18b_ngt=0;
      lm35a_ngt=0;
      lm35b_ngt=0;
      hum_bht=0;
      tem_bht=0;
     
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


