#include "E:\CCS VXL\THUC TAP VXL_SP\VXL_VIP_PRO\THU VIEN PIC 18F4550\tv_kit_vdk_pic_all.c"


usi32 ttl;
si8 tt_ct;
usi16 z1, z2, v1, v2, ledtrai, ledphai, n;
usi32 x, k, led, v, z, vx;
usi8 dir, i; // Bai 330
void h327_reset_bien()
{
   ttl=0; x=0; z1=0; z2=0; v1=0x8000; v2=0x0001; n=0; k=32; z = 0; i = 0;
   ledtrai=0; ledphai=0; led=0; v=1; vx=0x80000000;
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
   if (i<k)
   {
       led=z|v;
       xuat_32led_don_1dw(led);
       delay_ms(dl);
       v = v<<1;
       i++;
   }
   else if (i == k)
   {
       if (k > 0) {
           k--; // Giam k chi khi k > 0
       }
       i = 0;
       z = led;
       v = 1;
   }

}
void h331_32led_sd_tsp_if(usi16 dl) //(6) 32 led sang don trai sang phai
{
   if (i<k)
   {
       led=z|vx;
       xuat_32led_don_1dw(led);
       delay_ms(dl);
       vx = vx>>1;
       i++;
   }
   else if (i == k)
   {
       if (k > 0) {
           k--; // Giam k chi khi k > 0
       }
       i = 0;
       z = led;
       vx = 0x80000000;
   }
 
}




void b331_32led_8yeu_cau_2btn_ct()
{
   if(phim_bt0_c2(2) == co_nhan)
   {
      if(tt_ct<8) 
      {
         tt_ct++;
         h327_reset_bien();
      }
   }
   if(phim_bt1_c2(2) == co_nhan)
   {
      if(tt_ct>0) 
      {
         tt_ct--;
         h327_reset_bien();
      }
   }
   if(phim_bt2_c2(2) == co_nhan)
   {
        dir++;
        if (dir > 3)
        {
            dir = 0;
        }
        h327_reset_bien();
   }
}


void main()                                                        
{                                               
   set_up_port();  
   tt_ct=0;
   h327_reset_bien();
   while(true)                                        
   {                                                                   
     b331_32led_8yeu_cau_2btn_ct();
           if(tt_ct==0) h327_32led_std_pst_if(); // yeu cau (0) 
      else if(tt_ct==1) h327_32led_std_tsp_if(); // yeu cau (1) 
      else if(tt_ct==2)
                 {
                   if     (dir==0)     h329_32led_std_tnv_if(); // yeu cau (2)
                   else if(dir==1)     h329_32led_std_ttr_if(); // yeu cau (3)
                   else if(dir==2)     h329_16led_tr_ph_std_pst_ss_if(); // yeu cau (4)
                   else                h329_16led_tr_ph_std_tsp_ss_if(); // yeu cau (5)
                 }
      else if(tt_ct==3) h331_32led_sd_pst_if(100); // yeu cau (6)
      else if(tt_ct==4) h331_32led_sd_tsp_if(100); // yeu cau (7)*/
     
      delay_ms(100);
   }      
}  
  
