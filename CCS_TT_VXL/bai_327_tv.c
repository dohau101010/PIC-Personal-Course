usi32 ttl;
si8 tt_ct;
usi16 z1, z2, v1, v2, ledtrai, ledphai, n,  z;
usi32 x, k, led, run, run1, save, v;
usi8 dir, i; 
void h327_reset_bien()
{
   ttl=0; x=0; z1=0; z2=0; v1=0x8000; v2=0x0001; n=0; k=32; z = 0; i = 0;
   ledtrai=0; ledphai=0; run=1; save=0, v=0; run1=0x80000000, led=0;
}

void h327_32led_std_tsp_if() //(1) 32 led sang tat dan tu trai sang phai
{
   if(ttl<32)
   {
      x=(x>>1)+0x80000000;
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else if(ttl<64)
   {
      x=(x>>1);
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else h327_reset_bien();
}

void h327_32led_std_pst_if() //(0) 32 led sang tat dan tu phai sang trai
{
   if(ttl<32)
   {
      x=(x<<1)+1;
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else if(ttl<64)
   {
      x=(x<<1);
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else h327_reset_bien();
}
void h329_32led_std_tnv_if() //(2) 32 led sang tat dan tu ngoai vao
{
   if(ttl<16)
   {
       ledtrai=(ledtrai>>1)+0x8000;
       ledphai=(ledphai<<1)+0x0001;
       xuat_32led_don_2word(ledtrai, ledphai);
       delay_ms(200);
       ttl++;
   } 
   else if(ttl<32)
   {
       ledtrai=(ledtrai>>1);
       ledphai=(ledphai<<1);
       xuat_32led_don_2word(ledtrai, ledphai);
       ttl++;
   } 
   else h327_reset_bien();
}
void h329_32led_std_ttr_if() //(3) 32 led sang tat dan tu trong ra
{  if(ttl<16)
   {
       ledtrai=(ledtrai<<1)+0x0001;
       ledphai=(ledphai>>1)+0x8000;
       xuat_32led_don_2word(ledtrai, ledphai);
       ttl++;
   } 
   else if(ttl<32)
   {
       ledtrai=(ledtrai>>1);
       ledphai=(ledphai<<1);
       xuat_32led_don_2word(ledtrai, ledphai);
       ttl++;
   } 
   else h327_reset_bien();
}
void h329_16led_tr_ph_std_pst_ss_if() //(4) 16 led trai va 16 led phai sang tat dan tu phai sang trai song song
{  
   if(ttl<16)
   {
       ledtrai=(ledtrai<<1)+0x0001;
       ledphai=(ledphai<<1)+0x0001;
       xuat_32led_don_2word(ledtrai, ledphai);
       ttl++;
   } 
   else if(ttl<32)
   {
       ledtrai=(ledtrai<<1);
       ledphai=(ledphai<<1);
       xuat_32led_don_2word(ledtrai, ledphai);
       ttl++;
   } 
   else h327_reset_bien();
}
void h329_16led_tr_ph_std_tsp_ss_if() //(5) 16 led trai va 16 led phai sang tat dan tu trai sang phai song song
{  
   if(ttl<16)
   {
       ledtrai=(ledtrai>>1)+0x8000;
       ledphai=(ledphai>>1)+0x8000;
       xuat_32led_don_2word(ledtrai, ledphai);
       ttl++;
   } 
   else if(ttl<32)
   {
       ledtrai=(ledtrai>>1);
       ledphai=(ledphai>>1);
       xuat_32led_don_2word(ledtrai, ledphai);
       ttl++;
   } 
   else h327_reset_bien();
}
void h331_32led_sd_pst_if(usi16 dl) //(6) 32 led sang don phai sang trai
{
    IF(k>0)
   {
      IF(i<k)
      {
         LED = SAVE|RUN;
         XUAT_32LED_DON_1DW(LED);
         DELAY_MS(DL);   
         RUN = RUN <<1;
         i++;
      }
      else IF (k==i) 
      {
         k--;
         i=0;         
         SAVE=LED;
         RUN = 1;
      }
      else h327_reset_bien();
   }
}
void h331_32led_sd_tsp_if(usi16 dl) //(6) 32 led sang don trai sang phai
{
   IF(k>0)
   {
      IF(i<k)
      {
         LED = SAVE|RUN1;
         XUAT_32LED_DON_1DW(LED);
         DELAY_MS(DL);   
         RUN1 = RUN1 >>1;
         i++;
      }
    else  IF (k==i) 
      {
         k--;
         i=0;         
         SAVE=LED;
         RUN1 = 0x80000000;
      }
      else h327_reset_bien();
   }
}





