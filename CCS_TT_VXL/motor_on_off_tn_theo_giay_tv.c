int1 tt_qt = 1, tt_qn = 1, tt_n = 1;

void ht_on_off()
{
   if(dcmotor_onoff==1)
   {
      lcd_goto_xy(2,15);
      lcd_data("ON ");
   }
   else if(dcmotor_onoff==0)
   {
      lcd_goto_xy(2,15);
      lcd_data("OFF");
   }
} 

void ht_quay_thuan()
{
   lcd_goto_xy(3,15);
   lcd_data("FOR ");
}

void ht_quay_nghich()
{
   lcd_goto_xy(3,15);
   lcd_data("REV ");
}


void dkdc_theo_giay(usi8 giay)
{
   if(giay>=x&&giay<=y)
   {
      if(tt_qt==1)
      {
         // Dc Motor
         dcmotor_tn=1;
         dc_motor_ktao_ccpx();
         pwm_duty=250;
         dc_motor_set_pwmx_duty();
         tt_qt=0; tt_qn=1;  tt_n=1;  
         // Step Motor
         stepmotor_onoff=1;
         stepmotor_tn = 0;
         // hien thi len LCD
         ht_on_off();
         ht_quay_thuan();
      }
   }
   else if(z<=giay&&giay<=v)
   {
      if(tt_qn==1)
      {
         // Dc Motor
         dcmotor_tn=0;  // chay nghich
         dc_motor_ktao_ccpx();
         pwm_duty = 250;
         dc_motor_set_pwmx_duty();
         tt_qn=0; tt_qt=1;tt_n=1;
         // Step Motor
         stepmotor_onoff=1;
         stepmotor_tn = 1;
         // hien thi len LCD
         ht_on_off();
         ht_quay_nghich();
         dl_4l7d[0]=ma7doan[tt_qn%10];
      }
   }
   else
   {
      if(tt_n==1)
      {
         // Dc Motor
         pwm_duty=0;
         dc_motor_set_pwmx_duty();
         dc_motor_pwm_ccp1_ccp2_stop();
         tt_qt=1; tt_qn=1;tt_n=0;  // Khoi tao lai trang thai de kt chay thuan nghich
         // Step Motor
         stepmotor_onoff=0;
         lcd_goto_xy(3,15);
         lcd_data("STOP");
      }
   }
}

void lcd_ht_sv_to_sb(usi8 x,y) // kiem tra xem so vong hay so buoc 
                                                  //co khac so truoc do hay ko
{
   if(so_vong_tam!=so_vong)
   {
      so_vong_tam=so_vong;
      lcd_goto_xy(2,0);
      lcd_gm_ht_2so_to_xvn(so_vong, x, y, kx_vn);
   }
   if(sbt!=sb)
   {
      sbt=sb;
      lcd_goto_xy(3,7);
      lcd_hien_thi_3so_tp_nho(sb,x+1,y+6);
   }
}
