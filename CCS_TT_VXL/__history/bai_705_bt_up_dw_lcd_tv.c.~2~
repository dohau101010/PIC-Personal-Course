void hienthi_nd_tren()
{
   lcd_goto_xy(3,6);
   lcd_data(0x30+nd_tren/10%10);
   lcd_data(0x30+nd_tren%10);
}

void hienthi_nd_duoi()
{
   lcd_goto_xy(3,15);
   lcd_data(0x30+nd_duoi/10%10);
   lcd_data(0x30+nd_duoi%10);
}

void chinh_nd_tren()
{
   if(phim_bt0_c2(50))
   {
      if(nd_tren<39) nd_tren++;
      else           nd_tren=34; //cuon tron 
      hienthi_nd_tren();
   }
}

void chinh_nd_duoi()
{
   if(phim_bt1_c2(50))
   {
      if(nd_duoi>27) nd_duoi--;
      else           nd_duoi=32;
      hienthi_nd_duoi();
   }
}

