#define hstd 50 //he so toc do
unsigned int16 pwm_tdo=0;
signed int8 i;

int1 tt_onoff=0, tt_up=0, tt_dw=0;
usi16 lt=0, lp=0;

void giai_ma_7doan_quet()
{
   md8l7d_gma_4so_vitri_vn(pwm_duty,0,cx_vn);
   md8l7d_gma_2so_vitri_vn(pwm_tdo,5,cx_vn);
   //dl_8l7dq[4]=0xbf;
}

void hthi_dlay_up_pause()
{
   for(i=0;i<100;i++)
   {
      hien_thi_8led_7doan_quet();
      if(!input(bt3))
      {
         tt_up=0;
         lt=00;
         xuat_32led_don_2word(lt,lp);
      }
   }
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
         hthi_dlay_up_pause();
      }
      else tt_up=0;
   }
}

void phim_up()
{
   if(phim_up_c2(10)&&(tt_up==0))
   {
      tt_onoff=1; tt_up=1;
      lt=0xff; lp=0xff;
      xuat_32led_don_2word(lt,lp);
   }
}

void hthi_dlay_dw_pause()
{
   for(i=0;i<100;i++)
   {
      hien_thi_8led_7doan_quet();
      if(!input(bt3))
      {
         tt_dw=0;
         lt=00;
         xuat_32led_don_2word(lt,lp);
      }
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
         hthi_dlay_dw_pause();
      }
      else 
      {
         tt_onoff=0; tt_dw=0;
         lt=0; lp=0;
         xuat_32led_don_2word(lt,lp);
      }
   }
}

void phim_dw()
{
   if(phim_dw_c2(10)&&(tt_dw==0))
   {
      tt_dw=1;
      lt=0xff00;
      xuat_32led_don_2word(lt,lp);
   }
}

void phim_stop()
{
   if(!input(stop)&&(tt_onoff))
   {
      tt_onoff=0; tt_up=0; tt_dw=0;
      pwm_duty=0;
      pwm_tdo=0;
      set_pwm2_duty(pwm_duty);
      lt=0; lp=0;
      xuat_32led_don_2word(lt,lp);
      giai_ma_7doan_quet();
   }
}
