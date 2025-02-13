//#include <tv_kit_vdk_pic_all.c>
unsigned int32 led, ttl;
signed tt_ct = 0;
unsigned int32 led_p, led_t;

void h327_32led_std_pst_if()
{
   if(ttl<32)
   {
      led = (led<<1)+1;
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else if(ttl<64)
   {
      led = led<<1;
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else
   {
      led = 0;
      ttl = 0;
      tt_ct++;
   }
}
void h327_32led_std_tsp_if()
{
   if(ttl<32)
   {
      led = (led>>1)|0x80000000;
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else if(ttl<64)
   {
      led = led>>1;
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else
   {
      led = 0;
      ttl = 0;
      tt_ct++;
   }
}
void h327_32led_std_tnv_if()
{
   if(ttl<16)
   {
      led_p = (led_p<<1)|0x00000001;
      led_t = (led_t>>1)|0x80000000;
      led = (led_p|led_t)|led;
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else if(ttl<32)
   {
      led_p = led_p<<1;
      led_t = led_t>>1;
      led = (led_p|led_t);
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else
   {
      led = 0;
      led_p = 0;
      led_t = 0;
      ttl = 0;
      tt_ct++;
   }
}
void h327_32led_std_ttr_if()
{
   if(ttl<16)
   {
      led_p = (led_p>>1)|0x8000;
      led_t = (led_t<<1)|0x10000;
      led = (led_p|led_t);
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else if(ttl<32)
   {
      led_p = (led_p>>1)&0xffff7fff;
      led_t = (led_t<<1)&0xfffeffff;
      led = (led_p|led_t);
      xuat_32led_don_1dw(led);
      ttl++;
   }
   else
   {
      led = 0;
      led_p = 0;
      led_t = 0;
      ttl = 0;
      tt_ct = 1;
   }
}
void bai338_32led_chay_td_4yc_dung_if()
{
   if(tt_ct==0)
   {  h327_32led_std_pst_if(); }  
   if(tt_ct==1)
   {  h327_32led_std_tsp_if(); }  
   if(tt_ct==2)
   {  h327_32led_std_tnv_if(); }  
   if(tt_ct==3)
   {  h327_32led_std_ttr_if(); }  
}
/*void main()
{
   set_up_port();
   led = 0;
   tt_ct = 0;
   xuat_32led_don_1dw(led);
   while(true)
   { 
      bai338_32led_chay_td_4yc_dung_if();
      delay_ms(150);
   }
}*/
