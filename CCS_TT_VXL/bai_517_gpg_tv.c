signed int8 gio,phut,giay,bdn,tg_chinh=0;
unsigned int8 ch_gio,dv_gio,ch_phut,dv_phut,ch_giay,dv_giay;
unsigned int8 mp, vt=0;

#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}

void buzzer_bip()
{
   buzzer_on();
   for(int8 k=0;k<20;k++)
      hien_thi_8led_7doan_quet();
   buzzer_off();
}

void giai_ma_8led_quet()
{
   md8l7d_gma_2so_vitri_vn (giay, 0, kx_vn);
   md8l7d_gma_2so_vitri_vn (phut, 3, kx_vn);
   md8l7d_gma_2so_vitri_vn (gio, 6, kx_vn);
}

void giai_ma_gpg()
{
   dl_8l7dq[7]=ma7doan[ch_gio];
   dl_8l7dq[6]=ma7doan[dv_gio];
   dl_8l7dq[4]=ma7doan[ch_phut];
   dl_8l7dq[3]=ma7doan[dv_phut];
   dl_8l7dq[1]=ma7doan[ch_giay];
   dl_8l7dq[0]=ma7doan[dv_giay];
}

void xoa_gpg()
{
   ch_gio=0;   dv_gio=0;
   ch_phut=0;  dv_phut=0;
   ch_giay=0;  dv_giay=0;
   vt=0;       tg_chinh=0;
   gio=0; phut=0; giay=0;
   giai_ma_8led_quet();
}

void tang_vt()
{
   vt++;
   if(vt>5) vt=0;
}

void tat_1led_chinh()
{
        if(vt==0)   dl_8l7dq[7]=0xff;
   else if(vt==1)   dl_8l7dq[6]=0xff;
   else if(vt==2)   dl_8l7dq[4]=0xff;
   else if(vt==3)   dl_8l7dq[3]=0xff;
   else if(vt==4)   dl_8l7dq[1]=0xff;
   else if(vt==5)   dl_8l7dq[0]=0xff;
}

void nhap_ch_dv_gio()
{
   if((vt==0)&&(mp<3))
   {
      ch_gio=mp;  tang_vt();
   }
   else if(vt==1)
   {
      if(ch_gio<2)
      {
         dv_gio=mp; tang_vt();
      }
      else if(mp<4)
      {
         dv_gio=mp; tang_vt();
      }
      else buzzer_bip();
   }
   else buzzer_bip();
}

void nhap_ch_dv_phut()
{
   if(vt==2)
   {
      if(mp<6)
      {
         ch_phut=mp;  tang_vt();
      }
      else buzzer_bip();
   }
   else if(vt==3)
   {
      dv_phut=mp; tang_vt();
   }
   else buzzer_bip();
}

void nhap_ch_dv_giay()
{
   if(vt==4)
   {
      if(mp<6)
      {
         ch_giay=mp;  tang_vt();
      }
      else buzzer_bip();
   }
   else if(vt==5)
   {
      dv_giay=mp; tang_vt();
   }
   else buzzer_bip();
}

void nhap_tinh_gpg()
{
        if(vt<2) nhap_ch_dv_gio();
   else if(vt<4) nhap_ch_dv_phut();
   else if(vt<6) nhap_ch_dv_giay();
   
   giay = ch_giay*10+dv_giay;
   phut = ch_phut*10+dv_phut;
   gio = ch_gio*10+dv_gio;
}

void chinh_gpg_mtp4x4()
{
   xuat_32led_don_1dw(0x00ffff00);
   do
   {
      dl_4l7d[3] = ma7doan[vt];
      xuat_4led_7doan_4so();
      mp=key_4x4_dw_c2(40);
      if(mp!=0xff)
      {
         dl_4l7d[0]=ma7doan[mp];
         if(mp==0x0c) xoa_gpg();
         else if(mp<10) nhap_tinh_gpg();
         tg_chinh=0;
      }
      if(bdn>9)
      {
         bdn=0;
         if(tg_chinh<12)
         {
            tg_chinh++;
            md4l7d_giaima_2so_vitri_vn(tg_chinh,2,cx_vn);
         }
      }
      
      if(bdn==0) tat_1led_chinh();
      if(bdn==5) giai_ma_8led_quet();
      hien_thi_8led_7doan_quet();
   }
   while((mp!=0x0f)&&(tg_chinh<10));
   xuat_32led_don_1dw(0);
   bdn=0;
}

void xu_ly_tang_gpg()
{
   bdn = bdn - 10;
   giay++;
   IF (giay == 60)
   {
      giay = 0; phut++;
      IF (phut == 60)
      {
         phut = 0; gio++;
         IF (gio == 24) gio = 0;
      }
   }
   giai_ma_8led_quet ();
}
