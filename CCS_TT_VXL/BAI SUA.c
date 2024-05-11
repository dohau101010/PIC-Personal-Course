#include "C:\THU VIEN CAC MODULE\tv_kit_vdk_pic_all.c"
usi16 sp, gh, mp, chuc, donvi, QN;  //can toi uu bo nho boi usi8
unsigned int1 status;  //chu y kieu 1 bit la int1
usi16 lm35a_ng,lm35a_tp,lm35b_ng,lm35b_tp; 

void adc_lm35a_doc_xuly(usi8 sl)
{
   float lm35a; 
   lm35a=h701_adc_read(sl,chan_lm35a); 
   lm35a = lm35a/2.046;
   float_to_ng_2so_tp(lm35a); 
   lm35a_ng = so_ng;
   lm35a_tp = so_tp;
}

void adc_lm35b_doc_xuly(usi8 sl)
{
   float lm35b; 
   lm35b=h701_adc_read(sl,chan_lm35b); 
   lm35b = lm35b/2.046;
   float_to_ng_2so_tp(lm35b); 
   lm35b_ng = so_ng;
   lm35b_tp = so_tp;
}

void dem_sp()
{
   sp= get_timer0();
   if(sp >= gh)
   {
      set_timer0(0) ; //bo sung them sp=0;
   }
}

void gioihan()
{
   gh=chuc*10+donvi;
   lcd_goto_xy(2,0);
   lcd_data("SP: ");
   printf(lcd_data,"%02lu",sp);
   lcd_goto_xy(2,7);
   lcd_data("GH: ");
   printf(lcd_data,"%02lu",gh);
}

void led7doan()
{
   if(status == 0)
   {
      dl_4l7d[0]=ma7doan[sp/10];
      dl_4l7d[1]=ma7doan[sp%10];
      dl_4l7d[1]=dl_4l7d[1]-128;
      dl_4l7d[2]=0xff-1-32-8-4-64;
      dl_4l7d[3]=0xff-1-2-64-32-16;
      xuat_4led_7doan_4so();
   }
   else if(status == 1)
   {
      md4l7d_giaima_2so_vitri_vn(sp, 3, 0);
      dl_4l7d[0]=0xff-1-32-8-4-64;
      dl_4l7d[1]=0xff-1-2-64-32-16-128;
      xuat_4led_7doan_4so();
   }
}

void hienthi()
{
   md8l7d_gma_so_bcd_vitri_vn (ngay_ds, 6, 0);
   md8l7d_gma_so_bcd_vitri_vn (thang_ds, 3, 0) ;
   md8l7d_gma_so_bcd_vitri_vn (nam_ds, 0, 1);
   hien_thi_8led_7doan_quet ();
   
   lcd_gm_ht_2so_to_xvn(lm35a_ng,0,0,0);
   lcd_gm_ht_2so_to_xvn(lm35b_ng,0,13,0);
   
   
}

void xuly()
{
   if(lm35a_ng > 35 || lm35b_ng > 35)
   {
      buzzer_on();
      triac_2_off();
      xuat_32led_don_1dw(0xffffffff);
   }
   else
   {
      buzzer_off();
      triac_2_on();
      xuat_32led_don_1dw(0x00000000);
   }
}

void dongco()
{
   if(lm35a_ng > 35)
   {
      dc_motor_ktao_ccp1_thuan();
      QN=lm35a_ng%100;// ??????????????
      pwm_duty=QN * 100;//vi du QN=50-->dong co quay 50%-->50%.1000=500-->pwm_duty=QN*10;
      set_pwm1_duty(pwm_duty);
   }
   else if(lm35b_ng > 35) // hai gia tri khac nhau lm35a va lm35b nen toi lm35b sai if thoi, k else if
   {
      step_motor_quay_nghich_hs();
      delay_ms(20);
   }
   else if(lm35a_ng < 35 ) //xu ly het a roi han toi b
   {
      dc_motor_ktao_ccp1_thuan();
      pwm_duty=0;
      set_pwm1_duty(pwm_duty);
      
   }
   lcd_goto_xy(3,0);
   lcd_data("PWM: ");
   printf(lcd_data,"%03lu",pwm_duty);
}

void main()
{
   set_up_port(); 
   setup_timer_0(t0_ext_l_to_h|t0_div_1); 
   set_timer0(0);
   set_up_port ();
   lcd_setup(); 
   ds1307_kiem_tra_ma ();
   lcd_khoi_tao_cgram_so_to();
   dc_motor_enable();
   setup_timer_2(t2_div_by_16,249,1);
   dc_motor_pwm_ccp1_ccp2_stop();
   
   while(true)
   {
      mp=key_4x4_dw();
      if(mp < 10)
      {
         chuc = donvi;
         donvi= mp;
      }
      if(mp == 0x0f)
      {
         status =~status; //bo them led 7 doan vao trong day de khi nhan no chuyen lien nha
      }
      dem_sp();
      gioihan();
      adc_lm35a_doc_xuly(10);
      adc_lm35b_doc_xuly(10);
      led7doan();
      ds1307_doc_time(8);
      xuly();
      hienthi();
      dongco();
   }
}
