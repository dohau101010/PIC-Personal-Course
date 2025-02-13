
unsigned INT16 lm35a_ng,lm35a_tp,lm35a_ngt=0;

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

   IF (ht_tp) lcd_hien_thi_2so_tp_nho (lm35a_tp, x, y + 6);
}

void h701_adc_lm35a_ht_7doan(usi8 z,INT1 ht_l7d) 
{
   IF (ht_l7d)
   {
      md4l7d_giaima_2so_vitri_vn (lm35a_ng, z, kx_vn) ;
      xuat_4led_7doan_4so () ;
   }
}

