usi8 hum_bl,hum_bh,tem_bl,tem_bh,sum, sum_ss; //hum: do am; tem: nhiet do byte thap. byte cao
usi8 hum_bht=0, tem_bht=0;
int1 presence;

void dht11_read_temp_humi()
{
   dht11_start();
   presence = dht11_check_response(); //doc ket qua tra ve 1 bit
   if(!presence==true) //=0: co DHT11
   {
      hum_bh = dht11_read(); //doc byte dau tien
      hum_bl = dht11_read(); //doc byte tiep theo
      tem_bh = dht11_read();
      tem_bl = dht11_read();
      sum    = dht11_read();
      sum_ss = hum_bh+hum_bl+tem_bh+tem_bl; //so sanh
   }
   else  hien_thi_no_dht11();
}

void dht11_hthi_lcd_5byte(usi8 x,y)
{
   lcd_hthi_byte(hum_bh,x,0);
   lcd_hthi_byte(hum_bl,x,y+3);
   lcd_hthi_byte(hum_bh,x,y+6);
   lcd_hthi_byte(hum_bl,x,y+9);
   lcd_hthi_byte(sum,x,y+12);
   
   lcd_goto_xy(x,y+15); lcd_data("(");
   lcd_hthi_byte(sum_ss,x,y+16);
   lcd_goto_xy(3,18);   lcd_data(")");
}

void dht11_hthi_lcd_nd_da(usi8 x,y) 
{
   if(sum==sum_ss) 
   {
         lcd_gm_ht_2so_to_xvn(hum_bh,x,y,kx_vn);
         lcd_gm_ht_2so_to_xvn(tem_bh,x,y+14,kx_vn);  
   }
}
