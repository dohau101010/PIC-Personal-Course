unsigned int16 lp=0; 

void phim_on_off_inv_dkdc()
{ 
    if((!input(on))&&(!dcmotor_onoff)) //ktra dcmotor_onff: khi nhan on roi ma nhan on nua thi nho bit do se khoa ko cho lam lai cac cong viec da lam  
    {
       dcmotor_onoff=1; 
       dc_motor_run();
       lp=0xff;
       xuat_32led_don_2word(0,lp); 
    } 
    else
    if((!input(off))&&(dcmotor_onoff))
    {
       dcmotor_onoff=0;
       dc_motor_run();
       lp=0;
       xuat_32led_don_2word(0,lp); 
    } 
    else if(phim_inv_c2(50)) 
    { 
      if(dcmotor_onoff)
      {
          dc_motor_stop();
          lp = ~lp;
          xuat_32led_don_2word(0,lp);
          delay_ms(500);//delay de cho dong co ngung han
          dcmotor_tn=~dcmotor_tn;
          dc_motor_run();
      }
      else  buzzer_on_off(100);
    } 
}
