unsigned int8 sb, sv=0, svt=1; 
unsigned int8 chuc=0, donvi=0, sv_cai, mp;
int1 tt_cai=0, tt_ss=0;

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

void lcd_hienthi_ena()
{
   lcd_goto_xy(1,12);
   lcd_data("ena");
}

void lcd_hienthi_dis()
{
   lcd_goto_xy(1,12);
   lcd_data("dis");
}

void lcd_ht_sv_cai(usi8 x,y) //so vong cai
{
   sv_cai = chuc*10 + donvi;
   lcd_gm_ht_2so_to_xvn(sv_cai,x,y,cx_vn);
}

void khoi_tao_ts() //ts = thong so
{
   stepmotor_onoff=1;
   tt_ss=1; //trang thai start stop
   lcd_ht_full_half();
   lcd_ht_for_inv();
   sb=0; sv=0;
}

void xu_ly_cac_phim()
{
   if(!tt_ss) //tt_ss=0
   {
      mp = key_4x4_dw();
      if(mp==0x0e)
      {
         tt_cai=enable;
         lcd_hienthi_ena();
      }
      else if(mp==0x0f)
      {
         tt_cai=disable;
         lcd_hienthi_dis();
      }
      else if((mp<10)&&(tt_cai))
      {
         chuc = donvi;  donvi = mp;
         lcd_ht_sv_cai(2,14);
      }
      else if((mp==0x0a)&&(sv_cai>0))
      {
         stepmotor_fh=1; //chon che do buoc du
         stepmotor_tn=1; //quay tuan
         khoi_tao_ts();
      }
      else if((mp==0x0b)&&(sv_cai>0))
      {
         stepmotor_fh=1; //chon che do buoc du
         stepmotor_tn=0; //chon che do quay nghich
         khoi_tao_ts();
      }
      else if((mp==0x0c)&&(sv_cai>0))
      {
         stepmotor_fh=0; //quay nua buoc
         stepmotor_tn=1; //quay thuan
         khoi_tao_ts();
      }
      else if((mp==0x0d)&&(sv_cai>0))
      {
         stepmotor_fh=0;
         stepmotor_tn=0;
         khoi_tao_ts();
      }
   }
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
   if(ht_tp)  lcd_hien_thi_3so_tp_nho(sb,x,y+6);
}

void hienthi_sb_sv_l7d()
{
   md4l7d_giaima_3so_vitri_vn(sb,3,cx_vn);
   
   dl_4l7d[0] = ma7doan[sv%10]&0x7f; //hang don vi, and 0x7f cho dau cham sang o led thu 0
   xuat_4led_7doan_4so();
}
