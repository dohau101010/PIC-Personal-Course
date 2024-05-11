unsigned int8 ds18a_ng,ds18a_ngt=0;
unsigned int16 ds18a_w,ds18a_tp,ds18a_tpt=50;
unsigned int8 ds18b_ng,ds18b_ngt=0;
unsigned int16 ds18b_w,ds18b_tp,ds18b_tpt=50;

void ds18b20_a_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp)
{
    if(ds18a_ngt!=ds18a_ng)
    {
       ds18a_ngt=ds18a_ng;
       if(ht_tp) 
       {
          lcd_gm_ht_2so_to_xvn(ds18a_ng,x,y,kx_vn);
          lcd_data(".");
       }
    }
    if(ds18a_tpt!=ds18a_tp)
    {
       ds18a_tpt=ds18a_tp;
       if(ht_tp) lcd_gm_ht_3so_nho_xvn((ds18a_tp*625)/10,x+1,y+7,kx_vn);
    }
}

void ds18b20_b_ht_lcd(usi8 x,y,int1 ht_lcd,ht_tp)
{
    if(ds18b_ngt!=ds18b_ng)
    {
       ds18b_ngt=ds18b_ng;
       if(ht_tp) 
       {
          lcd_gm_ht_2so_to_xvn(ds18b_ng,x,y,kx_vn);
          lcd_data(".");
       }
    }
    if(ds18b_tpt!=ds18b_tp)
    {
       ds18b_tpt=ds18b_tp;
       if(ht_tp) lcd_gm_ht_3so_nho_xvn((ds18b_tp*625)/10,x+1,y+7,kx_vn);
    }
}

void ds18b20_a_ht_7doan(usi8 z,int1 ht_l7d)
{
    if(ht_l7d)
    {
       md4l7d_giaima_2so_vitri_vn(ds18a_ng,z,kx_vn);
       xuat_4led_7doan_4so();
    }
}

void ds18b20_b_ht_7doan(usi8 z,int1 ht_l7d)
{
    if(ht_l7d)
    {
       md4l7d_giaima_2so_vitri_vn(ds18b_ng,z,kx_vn);
       xuat_4led_7doan_4so();
    }
}

unsigned int16 ds18b20_read_temp_mr(int1 sel)
{
   unsigned int8 bl,bh;
   unsigned int16 w;
   touch_write_byte(match_rom); //goi byte ma lenh match_rom ra 2 vi mach Ds
   if(!sel) 
   {
      for(i=7;i>-1;i--)
         touch_write_byte(ds_a[i]);
   }
   else
   {
      for(i=7;i>-1;i--)
         touch_write_byte(ds_b[i]);
   }
   
   touch_write_byte(read_scratchpad); //goi ma lenh read_scrachpad cho vi mach dang con ket noi, vi mach con ket noi nhan ma lenh va goi ve vdk 
   bl = touch_read_byte();
   bh = touch_read_byte();
   w = make16(bh,bl);
   touch_present();
   touch_write_byte(skip_rom);
   touch_write_byte(convert_t);
   return w;
}

void ds18b20_a_doc_nhiet_do1()
{
    if(touch_present())
    {
       ds18a_w = ds18b20_read_temp_mr(0);
       ds18a_ng = ds18a_w>>4; //dich phai gia tri 4bit de tach phan nguyen
       ds18a_tp = ds18a_w & 0x000f; //tach phan thap phan,giu nguyen 4 bit thap, xoa di cac bit cao
       ds18b20_a_ht_lcd(1,0,1,1);
       ds18b20_a_ht_7doan(1,1);
    }
    else ds18b20_no_ds18b();
}

void ds18b20_b_doc_nhiet_do1()
{
    if(touch_present())
    {
       ds18a_w = ds18b20_read_temp_mr(1);
       ds18a_ng = ds18a_w>>4; //dich phai gia tri 4bit de tach phan nguyen
       ds18a_tp = ds18a_w & 0x000f; //tach phan thap phan,giu nguyen 4 bit thap, xoa di cac bit cao
       ds18b20_a_ht_lcd(1,10,1,1);
       ds18b20_a_ht_7doan(3,1);
    }
    else ds18b20_no_ds18b();
}
//H�m doc nhien do tu DS18B20 
//�p dung cho he thong co nhieu to
//!unsigned int16 ds18b20_read_temp_mr(int1 sel)
//!{
//!   unsigned int8 bl,bh;
//!   unsigned int16 w;
//!   touch_write_byte(match_rom); //goi byte ma lenh match_rom ra 2 vi mach Ds
//!   if(!sel) 
//!   {
//!      for(i=7;i>-1;i--)
//!         touch_write_byte(ds_a[i]);
//!   }
//!   else
//!   {
//!      for(i=7;i>-1;i--)
//!         touch_write_byte(ds_b[i]);
//!   }
//!   
//!   touch_write_byte(read_scrachpad); //goi ma lenh read_scrachpad cho vi mach dang con ket noi, vi mach con ket noi nhan ma lenh va goi ve vdk 
//!   bl = touch_read_byte();
//!   bh = touch_read_byte();
//!   w = make16(bh,bl);
//!   touch_present();
//!   touch_write_byte(skip_rom);
//!   touch_write_byte(convert_t);
//!   return w;
//!}

