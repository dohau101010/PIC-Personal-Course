usi16 capdo=0;


void giai_ma_7doan_quet()
{
   md8l7d_gma_4so_vitri_vn(pwm_duty,0,cx_vn);
   md8l7d_gma_2so_vitri_vn(pwm_tdo,5,cx_vn);
   dl_8l7dq[4]=0xbf;
}

void phim_up()
{
   if(phim_bt0_c1(1,0)&&(capdo<50))
   {
      capdo++;
      pwm_duty=capdo*20;
      set_pwm1_duty(pwm_duty);
      giai_ma_7doan_quet();  
   }
}

void phim_dw()
{
   if(phim_bt2_c1(1,0)&&(capdo>0))
   {
      capdo--;
      pwm_duty=capdo*20;
      set_pwm1_duty(pwm_duty);
      giai_ma_7doan_quet();   
   }
}

void phim_stop()
{
   if(!input(stop))
   {
      capdo=0; pwm_duty=0;
      set_pwm1_duty(pwm_duty);
      giai_ma_7doan_quet();
   }
}
