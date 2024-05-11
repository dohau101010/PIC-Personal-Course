#define xt 96
#define yt 32
#define bks 20
#define bkm 17

signed int16 xs_ve, ys_ve, tgs45;
float xs_tinh, ys_tinh, goc_s;

signed int16 xm_ve, ym_ve, tgm45;
float xm_tinh, ym_tinh, goc_m;

void glcd_ve_cac_vong_tron_so()
{
   unsigned char glcd_text1[]={"Clock: UTE"}, glcd_12[]="12";
   unsigned char glcd_3[]="3", glcd_6[]="6", glcd_9[]="9";
   
   setup_glcd(glcd_graphic_mode);
   glcd_mau_nen(0);
   glcd_text57(0,0,glcd_text1, 1, 1);
   
   glcd_text57(xt-5,yt-29,glcd_12, 1, 1);
   glcd_text57(xt-3,yt+23,glcd_6, 1, 1);
   glcd_text57(xt-28,yt-3,glcd_9, 1, 1);
   glcd_text57(xt+24,yt-3,glcd_3, 1, 1);
   // ve 2 vong tron o tam
   glcd_circle(xt,yt,bks+11,no_fill,sang);
   glcd_circle(xt,yt,bks+2,no_fill,sang);
   // ve vong tron nho
   glcd_circle(xt+12,yt-23,+2,co_fill,sang);
   glcd_circle(xt+23,yt-12,+2,co_fill,sang);
   glcd_circle(xt+12,yt+23,+2,co_fill,sang);
   glcd_circle(xt+23,yt+12,+2,co_fill,sang);
   glcd_circle(xt-12,yt-23,+2,co_fill,sang);
   glcd_circle(xt-23,yt-12,+2,co_fill,sang);
   glcd_circle(xt-12,yt+23,+2,co_fill,sang);
   glcd_circle(xt-23,yt+12,+2,co_fill,sang);
}

void tinh_vi_tri_kim_giay(usi8 bk, usi16 tg)
{
   tgs45 = tg + 45;
   if(tgs45>60) tgs45 = tgs45-60;
   goc_s = tgs45*6;
   xs_tinh = bk*cos((goc_s*3.14)/180);
   ys_tinh = bk*sin((goc_s*3.14)/180);
   xs_ve = xt + (signed int16)(xs_tinh);
   ys_ve = yt + (signed int16)(ys_tinh);   
}

void tinh_vi_tri_kim_phut(usi8 bk, usi16 tg)
{
   tgm45 = tg + 45;
   if(tgm45>60) tgm45 = tgm45-60;
   goc_m = tgm45*6;
   xm_tinh = bk*cos((goc_m*3.14)/180);
   ym_tinh = bk*sin((goc_m*3.14)/180);
   xm_ve = xt + (signed int16)(xm_tinh);
   ym_ve = yt + (signed int16)(ym_tinh);   
}

void glcd_ve_kim_giay(usi8 bk, usi16 tg, int1 tt)
{
   glcd_command(glcd_graphic_mode);
   if(tt) glcd_line(xt, yt, xs_ve, ys_ve,tat);  // xoa hinh giay truoc do
   tinh_vi_tri_kim_giay(bk, tg);
   glcd_line(xt, yt, xs_ve, ys_ve, sang);   // ve kim giay 
   
   glcd_line(xt, yt, xm_ve, ym_ve, sang);   // ve kim phut
   glcd_circle(xt,yt,4,co_fill,sang);
   glcd_circle(xt,yt,2,no_fill,tat);
}

void glcd_ve_kim_phut(usi8 bk, usi16 tg, int1 tt)
{
   glcd_command(glcd_graphic_mode);
   if(tt) glcd_line(xt, yt, xm_ve, ym_ve,tat);  //xoa phut truoc do
   tinh_vi_tri_kim_phut(bk, tg);   // tinh phut moi
   //if(tg==59) 
   glcd_line(xt, yt, xm_ve, ym_ve,tat); //xoa giay 59
}

void glcd_dong_ho_so()
{
   const signed int8 maglcd[] = {"0123456789"};
   glcd_command(glcd_text_mode);
   glcd_command(glcd_addr_line1+1);
   glcd_data(maglcd[phut_ds/16]);
   glcd_data(maglcd[phut_ds%16]);  
   glcd_data(' ');
   glcd_data(maglcd[giay_ds/16]);
   glcd_data(maglcd[giay_ds%16]);
}


