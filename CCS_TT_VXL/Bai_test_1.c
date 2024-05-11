#include <tv_kit_vdk_pic_all.c>

usi16 giay_tam, giay_bin, phut_bin, gio_bin;
unsigned int8 a=0, b=2;
#define solando 100
unsigned int8 x = 1, y = x+15, z = 31, v = z+15;

// Step motor
unsigned int16 sb=0, sbt;
unsigned int8 so_vong=0, so_vong_tam;

#include <tv_06_glcd.c>
#include <graphics.c>
#include <glcd_dong_ho_kim_gio_phut_giay_tv.c>
#include <ds18b20_do_ndo_lcd_tv.c>
#include <do_nhiet_do_lm35_tv.c>

// thu vien giay, dc Motor and step Motor
#include <tv_08_dc_motor.c>
#include <tv_08_step_motor.c>
#include <motor_on_off_tn_theo_giay_tv.c>


void main()
{
   set_up_port();  
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();

   // setup glcd 
   setup_glcd(glcd_text_mode);
   delay_ms(10);
   sb = 0;
   sbt = 10;
   so_vong = 0;
   so_vong_tam = 10;
   dcmotor_onoff = 1;
   dcmotor_tn=1;
   // khoi tao ban dau cho Stepmotor
   stepmotor_delay=5;
   stepmotor_onoff=0;
   stepmotor_tn = 1;
   stepmotor_fh = 1;
   dc_motor_stop();
   
   ht_on_off();
   lcd_ht_sv_to_sb(b,0);
   
   //Setup ADC
   setup_adc(adc_clock_div_8);
   setup_adc_ports(AN0|Vss_Vdd);
   set_adc_channel(0);
   
   setup_glcd(glcd_graphic_mode);
   delay_ms(10);
   glcd_mau_nen(0);
   ds1307_kiem_tra_ma();
   //ds1307_cap_nhat_time(1);
   
   glcd_ve_cac_vong_tron_so();
   giay_bin = (giay_ds/16)*10 + (giay_ds%16); //chuyen Giay sang so nhi phan
   glcd_ve_kim_giay(bks, giay_bin, 1);  // xoa
   giay_tam = 0x60;
   
   phut_bin = (phut_ds/16)*10 + (phut_ds%16); //chuyen Phut sang so nhi phan
   glcd_ve_kim_phut(bkm, phut_bin, 1); // xoa
   
   gio_bin = (gio_ds/16)*10 + (gio_ds%16); //chuyen Gio sang so nhi phan
   glcd_ve_kim_gio(bkh, gio_bin, 1); // xoa
   
   // Setup PWM
   dc_motor_enable();
   setup_timer_2(t2_div_by_16,249,1);
   pwm_duty=0;
   
   while(true)
   {
      ds1307_doc_time(8);
      if(giay_tam!=giay_ds)
      {
         giay_tam = giay_ds;
         giay_bin = (giay_ds/16)*10 + (giay_ds%16);
         if(giay_ds==0)
         {
            phut_bin = (phut_ds/16)*10 + (phut_ds%16);
            glcd_ve_kim_phut(bkm, phut_bin, 1); 
            if(phut_ds==0)
            {
               gio_bin = (gio_ds/16)*10 + (gio_ds%16);
               glcd_ve_kim_gio(bkh, gio_bin, 1);   
            }
         }
         glcd_ve_kim_giay(bks, giay_bin, 1);      
         gdram_vdk_to_gdram_glcd_all(); // lay data tu vdk qua gdram glcd
         glcd_dong_ho_so();
     }
     
     // do và hien thi nhiet do ds18b20
     ds18b20_a_doc_xuly_hthi();
     
     // do và hien thi nhiet do lm35
     adc_lm35a_doc_xuly(10);
     hthi_lcd_thi();
     
     // Dong co step and DC motor
     dkdc_theo_giay(giay_bin);
     if(stepmotor_onoff)
     {
         step_motor_run_tn_fs();
         delay_ms(stepmotor_delay);
         sb++;
         if(sb>=200)
         {
            sb = 0;
            so_vong++;
            if(so_vong==100)
               so_vong = 0;
         }
         lcd_ht_sv_to_sb(b,0);
     }
     // hien thi giay ds1307 len 4led7 doan
     md4l7d_giaima_2so_vitri_vn(giay_bin,3,kx_vn);
     xuat_4led_7doan_4so();
   }
}
