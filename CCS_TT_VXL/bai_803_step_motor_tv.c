unsigned int16 lt=0, lp=0; 
unsigned int16 sb; //so buoc

void hthi_sobuoc_7doan()
{
   md4l7d_giaima_4so_vitri_vn(sb,3,cx_vn);
   xuat_4led_7doan_4so();
}

void phim_bt3_fs_hs()
{
   if(phim_bt3_c2(20))
   {
      if(stepmotor_onoff)
      {
         stepmotor_fh=~stepmotor_fh;
         lt=~lt;
         xuat_32led_don_2word(lt,lp);
         delay_ms(100);
      }
      else  buzzer_on_off(100);
   }
}

void step_motor_on_off_inv()
{ 
    if(!input(on)&&(!stepmotor_onoff)) //them dieu kien bit onoff bang 0 moi cho cac cong viec lam, tranh khong pai lam lai
    {
       stepmotor_onoff=1; 
       lp=0xff; lt=0xff;
       xuat_32led_don_2word(lt,lp);
    }
    else
    if(!input(off)&&(stepmotor_onoff))
    {
       stepmotor_onoff=0; 
       lp=0;   lt=0;
       xuat_32led_don_2word(lt,lp); 
    } 
    else if(phim_inv_c2(20)) 
    { 
       if(stepmotor_onoff) //ktra bit onoff co bang 1 hay khong
       {
          stepmotor_tn=~stepmotor_tn;
          lp = ~lp; 
          xuat_32led_don_2word(lt,lp);
       }
       else buzzer_on_off(100);
    } 
}
