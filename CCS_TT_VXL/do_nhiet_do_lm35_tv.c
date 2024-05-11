unsigned int16 lm35a_ng, lm35a_tp, lm35a_ngt = 0;

void adc_lm35a_doc_xuly(usi8 solan)
{
   float lm35a;
   //lm35a = adc_read(solan,chan_lm35a);
   lm35a = lm35a/2.046;
   
   float_to_ng_2so_tp(lm35a);
   
   lm35a_ng = so_ng;        // Phan nguyen
   lm35a_tp = so_tp;        // Phan thap phan
}

void adc_lm35_ht_lcd(usi8 x,y,int1 ht_lcd, ht_tp)   // ht_tp la hien thi thap phan
{
   if(lm35a_ngt!=lm35a_ng)  // so sanh phan nguyen tam vs phan nguyen moi vua chuyen doi
   {
      lm35a_ngt=lm35a_ng;
      if(ht_lcd)  lcd_gm_ht_2so_to_xvn(lm35a_ng,x,y,cx_vn);
   }
   if(ht_tp)   lcd_hien_thi_2so_tp_nho(lm35a_tp,x,y+6);
}

void hthi_lcd_thi()
{
   if(lm35a_ngt!=lm35a_ng)  // so sanh phan nguyen tam vs phan nguyen moi vua chuyen doi
   {
      lm35a_ngt=lm35a_ng;
      lcd_gm_ht_2so_to_xvn(lm35a_ng/10,a,12,kx_vn);
      //lcd_gm_ht_1so_nho_xvn(lm35a_ng%10,a+1,12+6,kx_vn);
   }
}


