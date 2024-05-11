unsigned int16 lt=0, lp=0; 
unsigned int16 sb=0, sbt=1, sv=0, svt=1; //so buoc, so vong

void hienthi_sb_sv_l7d()
{
   md4l7d_giaima_3so_vitri_vn(sb,3,cx_vn);
   
   dl_4l7d[0] = ma7doan[sv%10]&0x7f; //hang don vi, and 0x7f cho dau cham sang o led thu 0
   xuat_4led_7doan_4so();
}

void lcd_ht_for_inv()
{
   lcd_goto_xy(1,0);
   if(stepmotor_tn)  lcd_data("FOR "); //bang 1 quay thuan, cho hien thi chu FOR
   else              lcd_data("REV "); //bang 0 quay nghich
}

void lcd_ht_stop()
{
   lcd_goto_xy(1,0);
   lcd_data("STOP");
}

void lcd_ht_full_half()
{
   lcd_goto_xy(1,5);
   if(stepmotor_fh)  lcd_data("FULL"); //bang 1: dang o che do buoc du
   else              lcd_data("HALF");
}
//ham hien thi so vong to, so buoc nho tren lcd
//khi goi ham nay thi phai trao cac thong so x,y: vi tri hien thi
//2 bien trang thai cho phep hien thi lcd, hthi so nho
void lcd_ht_sv_to_sb(usi8 x,y,int1 ht_lcd,ht_tp)
{
   if(svt!=sv)
   {
      svt=sv;
      if(ht_lcd)  lcd_gm_ht_2so_to_xvn(sv,x,y,cx_vn);
   }
   if(sbt!=sb)
   {
      sbt=sb;
      if(ht_tp)  lcd_hien_thi_3so_tp_nho(sb,x,y+6);
   }
}

void phim_bt3_fs_hs() //doi giua buoc du va nua buoc
{
   if(phim_bt3_c2(20))
   {
      if(stepmotor_onoff)
      {
         stepmotor_fh=~stepmotor_fh;
         lt=~lt;
         xuat_32led_don_2word(lt,lp);
         
         lcd_ht_full_half();
         
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
       lcd_ht_for_inv();
    }
    else
    if(!input(off)&&(stepmotor_onoff))
    {
       stepmotor_onoff=0; 
       lp=0;   lt=0;
       xuat_32led_don_2word(lt,lp); 
       lcd_ht_stop();
    } 
    else if(phim_inv_c2(20)) 
    { 
       if(stepmotor_onoff) //ktra bit onoff co bang 1 hay khong
       {
          stepmotor_tn=~stepmotor_tn;
          lp = ~lp; 
          xuat_32led_don_2word(lt,lp);
          
          lcd_ht_for_inv();
       }
       else buzzer_on_off(100);
    } 
}

