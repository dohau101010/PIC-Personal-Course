
void ds1307_hthi_text_lcd() 
{
   lcd_GOTO_xy (0, 0);
   lcd_data ("CLOCK DS1307 ");
}

void ds1307_hthi_thu_lcd() 
{
   lcd_GOTO_xy (3, 0);

   SWITCH (time_r[3])
   {
      CASE 1: lcd_data ("Sunday: "); break;
      CASE 2: lcd_data ("Monday: "); break;
      CASE 3: lcd_data ("Tuesday: "); break;
      CASE 4: lcd_data ("Wednesday:"); break;
      CASE 5: lcd_data ("Thursday: "); break;
      CASE 6: lcd_data ("Friday: "); break;
      CASE 7: lcd_data ("Saturday: "); break;
      DEFAULT: break;
   }
}

void ds1307_hthi_ntn_lcd()
{
   lcd_hthi_byte (ngay_ds, 3, 12) ; //hang 3-cot 12
   lcd_data (" - ");
   lcd_hthi_byte (thang_ds, 3, 15);
   lcd_data (" - ");
   lcd_hthi_byte (nam_ds, 3, 18);
}

void ds1307_hthi_giay_lcd_soto()
{
   lcd_hien_thi_so_to (giay_ds / 16, 1, 14);  //tach so BCD hang chuc giay hien thi tai hang 1 cot thu 14
   lcd_hien_thi_so_to (giay_ds % 16, 1, 17);
}

void ds1307_hthi_phut_lcd_soto()
{
   lcd_hien_thi_so_to (phut_ds / 16, 1, 7);
   lcd_hien_thi_so_to (phut_ds % 16, 1, 10);
}

void ds1307_hthi_gio_lcd_soto()
{
   lcd_hien_thi_so_to (gio_ds / 16, 1, 0) ;
   lcd_hien_thi_so_to (gio_ds % 16, 1, 3);
}

void ds1307_hthi_lcd_soto()
{
   ds1307_hthi_giay_lcd_soto () ;

   IF (giay_ds == 0) //dem xong 1 chu ky, giay tu 59 ve 0 thi phut da tang len 1
   {
      ds1307_hthi_phut_lcd_soto () ;

      IF (phut_ds == 0) //neu chua bang thi cac lenh hien thi gio va ntn thu ko can pai thay doi  
      {
         ds1307_hthi_gio_lcd_soto () ;

         IF (gio_ds == 0) //gio =0 hien thi ntn moi, thu thay doi 
         {
            ds1307_hthi_ntn_lcd();
            ds1307_hthi_thu_lcd () ;
         }
      }
   }
}

