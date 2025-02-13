unsigned int8 ds18a_ng, ds18a_ngt = 0; // ds18a_ng l� phan nguyen v� nguyen tam
unsigned int16 ds18a_w, ds18a_tp;

void ds18b20_a_ht_lcd(usi8 x,y,int1 ht_lcd)
{
   if(ds18a_ngt!=ds18a_ng)
   {
      ds18a_ngt = ds18a_ng;
      if(ht_lcd==1)
      {
         lcd_gm_ht_2so_nho_xvn(ds18a_ng/10,x,y,cx_vn);
         //lcd_gm_ht_1so_to_xvn(ds18a_ng%10,x,y+2,kx_vn);
      }
   }
}

void dk_led_don()
{
   if(ds18a_ng>=nd_tren)
      xuat_32led_don_1dw(0x000ff000);
   else if(ds18a_ng<nd_tren)
      xuat_32led_don_1dw(0);
}

void ds18b20_a_doc_xuly_hthi()
{
   if(touch_present())
   {
      ds18a_w = ds18b20_read_temp(); 
      ds18a_ng = ds18a_w>>4;
      ds18a_tp = ds18a_w&0x00f;
      ds18b20_a_ht_lcd(a,0,1);
   }
   else ds18b20_no_ds18b();
}

