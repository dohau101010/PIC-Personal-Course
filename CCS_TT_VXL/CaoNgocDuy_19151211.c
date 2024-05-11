#include<tv_kit_vdk_pic_all.c>
//#include<bai_711_ds18a_tv.c>
#include<tv_06_glcd.c>
#include<graphics.c>
#include<bai_630_ve_dong_ho_gio_phut_giay_tv.c>
#include<bai_701_lm35a_tv.c>
#include<bai_702_lm35b_tv.c>
#include<bai_721_dht11_tv.c>
#define hstd 50
signed int8 i,tt,bdn;
usi8 giay_tam,giay_bin,gio_bin,phut_bin,pwm_tdo=0;
unsigned int8 ds18a_ng,ds18a_ch,ds18a_dvi=0,t0,t0_tam,ch,dv;
unsigned int16 ds18a_w,ds18a_tp;
int1 t1=0;
unsigned int8 mp;
unsigned char tam;
unsigned char hang0[]={" CAONGOCDUY 19151211 "};
#int_timer3
void ngat()
{
   bdn++;
   set_timer3(3036);
}
void hang0_dich_phai()
{
   tam=hang0[19];
   for(i=19;i>0;i--)
      hang0[i] = hang0[i-1];
    hang0[0]=tam;
}
void hang0_dich_trai()
{
   tam=hang0[0];
   for(i=0;i<19;i++)
      hang0[i] = hang0[i+1];
    hang0[19]=tam;
}
void kiem_tra_dich_h0()
{
   if(tt==1)
   {
      hang0_dich_trai();
      lcd_puts(0,0,hang0);
   }
   else if(tt==2)
   {
      hang0_dich_phai();
      lcd_puts(0,0,hang0);
   }
}
void kiem_tra_phim()
{
   if(mp==0)
   {
      tt=2;
   }
   else if(mp==2) tt=1;
   else if(mp==1) tt=0;
   else if(mp==3) tt=3;
   else if(mp==4) tt=4;
   else if(mp==5) tt=5;
   else if(mp==6) tt=6;
   
}
void dongho()
{
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
            glcd_ve_kim_gio(bkm,gio_bin,1);
            }
         }
         glcd_ve_kim_giay(bks,giay_bin,1);
         gdram_vdk_to_gdram_glcd_all();
         glcd_dong_ho_so();
      }
}
void ds18b20_a_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp)
{
      if(ht_lcd) 
         {   
            if(tt==3)
            {
               lcd_xoa_so_to(x,y);
               lcd_goto_xy(x,y);lcd_data(ds18a_ch+0x30);
               lcd_hien_thi_so_to(ds18a_dvi,x,y+1);
            }
            else
               {
                  lcd_goto_xy(x,y+3);
                  lcd_data(ds18a_dvi+0x30);
                  lcd_goto_xy(3,3);lcd_data(" ");
                  lcd_hien_thi_so_to(ds18a_ch,x,y);
               }
         }
}
void ds18b20_doc_xuly_hthi()
{
   if(touch_present())
   {
      ds18a_w = ds18b20_read_temp();
      ds18a_ng = ds18a_w>>4;
      ds18a_ch=ds18a_ng/10;
      ds18a_dvi=ds18a_ng%10;
      ds18a_tp = ds18a_w & 0x000f;
      ds18b20_a_ht_lcd(2,0,1,1);
   }
   else ds18b20_no_ds18b();
}
void demsp()
{
   t0=get_timer0();
   ch = t0/10%10;        
   dv = t0%10;
   if(t0!=t0_tam)
   {
      t0_tam=t0;
      if(t1)
      {
         lcd_goto_xy(2,16);lcd_data(" ");
         lcd_goto_xy(2,19);lcd_data(" ");
         lcd_goto_xy(3,19);lcd_data(" ");
         lcd_hien_thi_so_to(ch,2,16);
         lcd_goto_xy(3,19);lcd_data(t0%10+0x30);
      }
      else
      {
         lcd_goto_xy(3,16);lcd_data(" ");
         lcd_hien_thi_so_to(dv,2,17);
         lcd_goto_xy(2,16);lcd_data(t0/10%10+0x30);
      }
      if(t0>24) 
      {
         t1=~t1;
         t0=4;
         set_timer0(4);
         
      }
   }
}
void dongco()
{
   if((tt==4)&&(pwm_tdo<20))
   {
      pwm_tdo++;
      pwm_duty=pwm_tdo*hstd;

   }
    if((tt==5)&&(pwm_tdo>0))
   {
      pwm_tdo--;
      pwm_duty=pwm_tdo*hstd;
   }
    if(tt==6)
   {

       pwm_duty=0;
       pwm_tdo=0;
      dc_motor_set_pwmx_duty();
   }
    dc_motor_set_pwmx_duty();
    md4l7d_giaima_2so_vitri_vn(pwm_tdo,2,kx_vn);
   xuat_4led_7doan_4so();
}
void main()
{
   set_up_port();
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   ds18b20_khoi_tao();
   setup_glcd(glcd_text_mode);
   delay_ms(10);
   setup_glcd(glcd_graphic_mode);
   glcd_mau_nen(0);
   ds1307_kiem_tra_ma();
   glcd_ve_cac_vong_tron_so();
   giay_bin=(giay_ds/16)*10+(giay_ds%16);
   glcd_ve_kim_giay(bks,giay_bin,0);
   giay_tam=0x60;
   phut_bin=(phut_ds/16)*10+(phut_ds%16);
   glcd_ve_kim_phut(bkm,phut_bin,1);
   gio_bin=(gio_ds/16)*10+(gio_ds%16);
   glcd_ve_kim_gio(bkh,gio_bin,1);
   dc_motor_enable();
   dcmotor_tn=0;
   dc_motor_ktao_ccpx();
   setup_timer_2(t2_div_by_16,249,1);
   lcd_puts(0,0,hang0);
   tt=0;
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0;
   setup_timer_0(t0_ext_h_to_l|t0_div_1);
   set_timer0(4);
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   lcd_hien_thi_so_to(t0/10%10,2,16);
   lcd_goto_xy(3,19);lcd_data(t0%10+0x30);
   while(true)
   {
      if(bdn<10)
      {
          ds1307_doc_time(8);
         dongho();
         mp=key_4x4_dw_c2(10);
         kiem_tra_phim();
         ds18b20_doc_xuly_hthi();
         demsp();
         dongco();
      }
      else 
      {
         bdn=0;
         kiem_tra_dich_h0();
      }
     
   }
}
