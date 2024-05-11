unsigned int16 kc_ng,kc_tp,kc_ngt=0;
void h706_adc_gp2d12_doc_xuly(usi8 sl) 
{ 
    float kc; 
    kc=h701_adc_read(sl,chan_cbkc); //do, cong don ket qua chia trung binh
    kc = pow(4277/kc,1.106); //pow(x,y): x^y ham mu
    if(kc>80) kc=80; 
    float_to_ng_2so_tp(kc); 
    kc_ng = so_ng; 
    kc_tp = so_tp;
}
 
void h706_adc_gp2d12_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp) 
{ 
    if(kc_ngt!=kc_ng) 
    {
       kc_ngt=kc_ng; 
       if(ht_lcd)lcd_gm_ht_2so_to_xvn(kc_ng,x,y,kx_vn); 
    }
    if(ht_tp) lcd_hien_thi_2so_tp_nho(kc_tp,x,y+6); 
   }
 
void h706_adc_gp2d12_ht_7doan(usi8 z,int1 ht_l7d) 
{ 
    if(ht_l7d) 
    { 
       md4l7d_giaima_2so_vitri_vn(kc_ng,z,kx_vn);
       xuat_4led_7doan_4so();
    } 
} 
