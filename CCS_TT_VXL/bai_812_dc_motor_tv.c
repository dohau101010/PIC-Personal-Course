unsigned int16 lt=0, lp=0;
int1 tt_qt=0, tt_qn=0, tt_n=0;
//trang thai quay thuan, quay nghich, ngung
void phim_on_off()
{
   if((!input(on))&&(!dcmotor_onoff)) //ktra dcmotor_onff: khi nhan on roi ma nhan on nua thi nho bit do se khoa ko cho lam lai cac cong viec da lam  
    {
       dcmotor_onoff=1; 
       lt=0xffff;
       tt_n=0; tt_qt=0; tt_qn=0;
       xuat_32led_don_2word(lt,lp); 
    } 
    else if((!input(off))&&(dcmotor_onoff))
    {
       dcmotor_onoff=0;
       dc_motor_run();
       lt=0;   lp=0;
       tt_n=0; tt_qt=0; tt_qn=0;
       xuat_32led_don_2word(lt,lp); 
    } 
}

void dkdc_theo_giay(usi8 giay)
{
   if(dcmotor_onoff) //ktra co bang 1 hay ko
   {
      if((4<giay)&&(giay<26))
      {
         if(tt_qt==0)
         {
            tt_qt=1; dcmotor_tn=0;
            dc_motor_run(); //dieu khien motor quay theo chieu thuan
            lp=0xff; tt_n=0;
            xuat_32led_don_2word(lt,lp);
         }
      }
      else
      if ((34<giay)&&(giay<56))
      {
         if(tt_qn==0)
         {
            tt_qn=1; dcmotor_tn=1; //chon chieu quay nghich
            dc_motor_run();
            lp=0xff00;  tt_n=0;
            xuat_32led_don_2word(lt,lp);
         }
      }
      else
      {
         if(tt_n==0)
         {
            tt_n=1;  dc_motor_stop();
            lp=0;
            xuat_32led_don_2word(lt,lp);
            tt_qt=0; tt_qn=0;
         }
      }
   }
}
