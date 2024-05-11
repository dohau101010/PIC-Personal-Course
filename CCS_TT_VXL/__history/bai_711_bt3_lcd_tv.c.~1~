void lcd_ena_buz_on()
{
   lcd_goto_xy(0,17);
   lcd_data("ON ");
}

void lcd_ena_buz_off()
{
   lcd_goto_xy(0,17);
   lcd_data("OFF");
}

void phim_bt3_tat_mo_buzz()
{
   if(phim_bt3_c2(50))
   {
      buz_ena = ~buz_ena;
      if(buz_ena) lcd_ena_buz_on();
      else 
      {
         lcd_ena_buz_off();
         buzzer_off();
      }
      delay_ms(200);
   }
}
