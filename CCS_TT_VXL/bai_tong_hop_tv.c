unsigned int8 ds18a_ng,ds18a_ngt=0;
unsigned int16 ds18a_w,ds18a_tp,ds18a_tpt=50;
unsigned int8 ds18b_ng,ds18b_ngt=0;
unsigned int16 ds18b_w,ds18b_tp,ds18b_tpt=50;

unsigned INT16 lm35a_ng,lm35a_tp,lm35a_ngt=0;
unsigned INT16 lm35b_ng,lm35b_tp,lm35b_ngt=0;

usi8 hum_bl,hum_bh,tem_bl,tem_bh,sum, sum_ss; //hum: do am; tem: nhiet do byte thap. byte cao
usi8 hum_bht=0, tem_bht=0;
int1 presence;

#define hstd 20
unsigned int16 pwm_tdo = 0;
//signed int8 i;
int1 tt_onoff=0;

void ds18b20_a_ht_lcd()
{
    if(ds18a_ngt!=ds18a_ng)
    {
       ds18a_ngt=ds18a_ng;
       lcd_gm_ht_2so_to_xvn(ds18a_ng,0,0,kx_vn);
       //lcd_data(".");
    }
    if(ds18a_tpt!=ds18a_tp)
    {
       ds18a_tpt=ds18a_tp;
       //lcd_goto_xy(1,6);
       //lcd_data((ds18a_tp*625)/1000+0x30);
       //lcd_gm_ht_2so_nho_xvn((ds18a_tp*625)/10,2,0,kx_vn);
       lcd_hien_thi_1so_tp_nho((ds18a_tp*625)/10, 1, 6);
    }
}

void ds18b20_b_ht_lcd()
{
    if(ds18b_ngt!=ds18b_ng)
    {
       ds18b_ngt=ds18b_ng;
       lcd_gm_ht_2so_to_xvn(ds18b_ng,0,12,kx_vn);
       //lcd_data(".");
    }
    if(ds18b_tpt!=ds18b_tp)
    {
       ds18b_tpt=ds18b_tp;
       //lcd_goto_xy(1,19);
       //lcd_data((ds18b_tp*625)/1000+0x30);
       //lcd_gm_ht_2so_nho_xvn((ds18b_tp*625)/10,2,0,kx_vn);
       lcd_hien_thi_1so_tp_nho((ds18a_tp*625)/10, 1, 18);
    }
}

unsigned int16 ds18b20_read_temp_mr(int1 sel)
{
   unsigned int8 bl,bh;
   unsigned int16 w;
   touch_write_byte(match_rom); //goi byte ma lenh match_rom ra 2 vi mach Ds
   if(!sel) 
   {
      for(i=7;i>-1;i--)
         touch_write_byte(ds_a[i]);
   }
   else
   {
      for(i=7;i>-1;i--)
         touch_write_byte(ds_b[i]);
   }
   
   touch_write_byte(read_scratchpad); //goi ma lenh read_scrachpad cho vi mach dang con ket noi, vi mach con ket noi nhan ma lenh va goi ve vdk 
   bl = touch_read_byte();
   bh = touch_read_byte();
   w = make16(bh,bl);
   touch_present();
   touch_write_byte(skip_rom);
   touch_write_byte(convert_t);
   return w;
}

void ds18b20_a_doc_nhiet_do1()
{
    if(touch_present())
    {
       ds18a_w = ds18b20_read_temp_mr(0);
       ds18a_ng = ds18a_w>>4; //dich phai gia tri 4bit de tach phan nguyen
       ds18a_tp = ds18a_w & 0x000f; //tach phan thap phan,giu nguyen 4 bit thap, xoa di cac bit cao
       ds18b20_a_ht_lcd();
    }
    else ds18b20_no_ds18b();
}

void ds18b20_b_doc_nhiet_do1()
{
    if(touch_present())
    {
       ds18b_w = ds18b20_read_temp_mr(1);
       ds18b_ng = ds18b_w>>4; //dich phai gia tri 4bit de tach phan nguyen
       ds18b_tp = ds18b_w & 0x000f; //tach phan thap phan,giu nguyen 4 bit thap, xoa di cac bit cao
       ds18b20_b_ht_lcd();
    }
    else ds18b20_no_ds18b();
}

void h701_adc_lm35a_doc_xuly(usi8 sl) 
{
   FLOAT lm35a;
   lm35a = h701_adc_read (sl, chan_lm35a) ;
   lm35a = lm35a / 2.046;
   FLOAT_to_ng_2so_tp(lm35a);
   lm35a_ng = so_ng;
   lm35a_tp = so_tp;
}

void h701_adc_lm35a_ht_lcd(usi8 x,y,INT1 ht_lcd,ht_tp) 
{
   IF (lm35a_ngt != lm35a_ng)
   {
      lm35a_ngt = lm35a_ng;
      IF (ht_lcd) lcd_gm_ht_2so_to_xvn (lm35a_ng, x, y, kx_vn);
   }

   IF (ht_tp) lcd_hien_thi_1so_tp_nho (lm35a_tp, x+1, y + 6);
}

void h702_adc_lm35b_doc_xuly(usi8 sl) 
{
   FLOAT lm35b;
   lm35b = h701_adc_read (sl, chan_lm35b) ;
   lm35b = lm35b / 2.046;
   FLOAT_to_ng_2so_tp(lm35b);
   lm35b_ng = so_ng;
   lm35b_tp = so_tp;
}

void h702_adc_lm35b_ht_lcd(usi8 x,y,INT1 ht_lcd,ht_tp) 
{
   IF (lm35b_ngt != lm35b_ng)
   {
      lm35b_ngt = lm35b_ng;
      IF (ht_lcd) lcd_gm_ht_2so_to_xvn (lm35b_ng, x, y, kx_vn);
   }

   IF (ht_tp) lcd_hien_thi_1so_tp_nho (lm35b_tp, x+1, y + 6);
}

void dht11_read_temp_humi()
{
   dht11_start();
   presence = dht11_check_response(); //doc ket qua tra ve 1 bit
   if(!presence==true) //=0: co DHT11
   {
      hum_bh = dht11_read(); //doc byte dau tien
      hum_bl = dht11_read(); //doc byte tiep theo
      tem_bh = dht11_read();
      tem_bl = dht11_read();
      sum    = dht11_read();
      sum_ss = hum_bh+hum_bl+tem_bh+tem_bl; //so sanh
   }
   else  hien_thi_no_dht11();
}

void dht11_hthi_lcd_nd_da(usi8 x,y) //hien thi nhiet do do am
{
   if(sum==sum_ss) //sum doc ve tu DHT11, sum_ss duoc tinh toan boi vdk , neu chung bang nhau thi qua trinh nhan du lieu dung
   {
      if(hum_bht!=hum_bh) //do am byte cao tam
      {
         hum_bht=hum_bh;
         lcd_gm_ht_2so_to_xvn(hum_bh,x,y,kx_vn);
      }
      if(tem_bht!=tem_bh) //nhiet do byte cao tam
      {
         tem_bht=tem_bh; //neu khac nhau thi cap nhat
         lcd_gm_ht_2so_to_xvn(tem_bh,x,y+14,kx_vn);
      }
      //else hien_thi_sai_dht11();
   }
}

void xoa_man_hinh(si8 x,y)
{
   //si8 x,y;
   lcd_xoa_so_to(x, y);
   lcd_xoa_so_to(x, y+3);
   lcd_xoa_so_to(x, y+12);
   lcd_xoa_so_to(x, y+15);
   lcd_goto_xy(x,y+6);
   lcd_data("  ");
   lcd_goto_xy(x,y+18);
   lcd_data("  ");
}

void phim_up()
{
    if((phim_up_c2(10))&&(pwm_tdo<50))
    {
        pwm_tdo++;
        pwm_duty = pwm_tdo*hstd;
        set_pwm1_duty(pwm_duty);
        tt_onoff = 1;    // cho chay 
        delay_ms(200);
    }
}

void phim_dw()
{
     if((phim_dw_c2(10))&&(pwm_tdo>0))
     {
        pwm_tdo--;
        pwm_duty = pwm_tdo*hstd;
        set_pwm1_duty(pwm_duty);
        delay_ms(200);
     }
}

void phim_stop()
{
     if((!input(stop))&&(tt_onoff))
     {
        tt_onoff = 0;
        pwm_tdo = 0;
        pwm_duty = pwm_tdo*hstd;
        set_pwm1_duty(pwm_duty);
     }
}

//!void phim_up_c3()
//!{
//! if((mp==3)&&(pwm_tdo<50))
//! {
//!  pwm_tdo++;
//!  pwm_duty = pwm_tdo*hstd;
//!  set_pwm1_duty(pwm_duty);
//!  tt_onoff = 1;    // cho chay 
//!  
//! }
//!}
//!
//!void phim_dw_c3()
//!{
//!  if((mp==4)&&(pwm_tdo>0))
//!  {
//!  pwm_tdo--;
//!  pwm_duty = pwm_tdo*hstd;
//!  set_pwm1_duty(pwm_duty);
//!  
//!  }
//!}
//!
//!void phim_stop_c3()
//!{
//!  if((mp==5)&&(tt_onoff))
//!  {
//!  tt_onoff = 0;
//!  pwm_tdo = 0;
//!  pwm_duty = pwm_tdo*hstd;
//!  set_pwm1_duty(pwm_duty);
//!  }
//!}


