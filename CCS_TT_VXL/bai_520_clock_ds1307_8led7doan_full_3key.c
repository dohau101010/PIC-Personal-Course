#include <tv_kit_vdk_pic_all.c> 
usi8 giay_tam,bdn; 
signed int8 gt_mod=0, tg_chinh=0;
#define tang 0
#define giam 1
/*Ham co chuc nang nhan dia chi va du lieu de luu vao dia chi tuong ung roi thuc hien*/
void ds1307_luu_vao_ds(usi8 dcdt,dt)
{
   i2c_start();
   i2c_write(ds13_addr_wr);
   i2c_write(dcdt); //dia chi doi tuong
   i2c_write(dt); //goi doi tuong (giay_ds) ra ds1307
   i2c_stop();
}

unsigned int8 tang_or_giam_so_bcd(usi8 x, int1 sel)
{
   unsigned int8 y,dv,ch,v;
   ch=(x>>4);  dv=x&0x0f; //tach hang chuc va hang don vi cua bien x gan cho ch va dv dang nam o 4 bit thap
   y=ch*10+dv; //y la so nhi phan- x la so BCD
   if(sel==0)  y++;
   else        y--;
   ch=y/10;    dv=y%10;
   v=(ch<<4)|dv; //v la so BCD
   return(v);
}

void tat_2led_chinh()
{
   IF (gt_mod == 1) {dl_8l7dq[1] = 0xff; dl_8l7dq[0] = 0xff;}
   IF (gt_mod == 2) {dl_8l7dq[4] = 0xff; dl_8l7dq[3] = 0xff;}
   IF (gt_mod == 3) {dl_8l7dq[7] = 0xff; dl_8l7dq[6] = 0xff;}
}

void giai_ma_gpg_8l7dq() 
{
   md8l7d_gma_so_bcd_vitri_vn (giay_ds, 0, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn (phut_ds, 3, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn (gio_ds, 6, cx_vn);
   dl_8l7dq[5]=0xff;//de tat dien
}

void xu_ly_choptat() 
{
   IF (gt_mod !=  0)
   {
      IF ((bdn == 0)&& (input (up))&& (input (dw)))   tat_2led_chinh ();
      else IF (bdn == 5)   giai_ma_gpg_8l7dq();
   }
}

void phim_mod(usi8 dl)
{
   IF (phim_mode_c2 (dl))
   {
      gt_mod++;
      IF (gt_mod >3) gt_mod = 0;
      tg_chinh = 0;
   }
}

void tang_giay()
{
   if(giay_ds==0x59) giay_ds=0;
   else giay_ds=tang_or_giam_so_bcd(giay_ds,tang);
   ds1307_luu_vao_ds(0,giay_ds); //0-la dia chi cua giay; tham so giay_ds moi vua tang xong
   //trao 2 tham so: ... thong so 2 la gia tri cua giay can luu tru vao o nho co dia chi 0
}

void tang_phut()
{
   if(phut_ds==0x59) phut_ds=0;
   else phut_ds=tang_or_giam_so_bcd(phut_ds,tang);
   ds1307_luu_vao_ds(1,phut_ds); //1-dia chi cua phut
}

void tang_gio()
{
   if(gio_ds==0x23) gio_ds=0;
   else gio_ds=tang_or_giam_so_bcd(gio_ds,tang);
   ds1307_luu_vao_ds(2,gio_ds); //2-dia chi cua gio
}

void chinh_tang_gpg()
{
   switch(gt_mod)
   {
      case 1: tang_giay();
              break;
      case 2: tang_phut();
              break;
      case 3: tang_gio();
              break;
      default:break;
   }
}

void phim_up(usi8 dl) 
{
   IF (phim_up_c2 (dl))
   {
      tg_chinh = 0;
      chinh_tang_gpg();
      giai_ma_gpg_8l7dq();
      hien_thi_8led_7doan_quet();
   }
}

void giam_giay()
{
   if(giay_ds==0) giay_ds=0x59;
   else giay_ds=tang_or_giam_so_bcd(giay_ds,giam); //tra ve so BCD bang giay_ds(bCD) tang len 1
   ds1307_luu_vao_ds(0,giay_ds); //0-la dia chi giay; tham so giay_ds moi vua tang xong
}

void giam_phut()
{
   if(phut_ds==0) phut_ds=0x59;
   else phut_ds=tang_or_giam_so_bcd(phut_ds,giam);
   ds1307_luu_vao_ds(1,phut_ds); //1-la dia chi giay; tham so giay_ds moi vua tang xong
}

void giam_gio()
{
   if(gio_ds==0) gio_ds=0x23;
   else gio_ds=tang_or_giam_so_bcd(gio_ds,giam);
   ds1307_luu_vao_ds(2,gio_ds); //2-la dia chi giay; tham so giay_ds moi vua tang xong
}

void chinh_giam_gpg()
{
   switch(gt_mod)
   {
      case 1: giam_giay();
              break;
      case 2: giam_phut();
              break;
      case 3: giam_gio();
              break;
      default:break;
   }
}

void phim_dw(usi8 dl) 
{
   IF (phim_dw_c2 (dl))
   {
      tg_chinh = 0;
      chinh_giam_gpg();
      giai_ma_gpg_8l7dq();
      hien_thi_8led_7doan_quet();
   }
}


#int_timer3
void interrupt_timer3()
{
   bdn++;
   set_timer3(3036);
}

void main() 
{
   set_up_port();
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   
   bdn=0;
   gt_mod=0;
   
   ds1307_kiem_tra_ma();
   while(true)
   {
      if(bdn<10)
      {
         if(gt_mod!=0)  xu_ly_choptat();
         hien_thi_8led_7doan_quet();
         phim_mod(100);
         phim_up(40);
         phim_dw(40);
      }
      else
      {
         bdn=0;
         if(tg_chinh<10)
            tg_chinh++;
         else gt_mod=0; //thoat khoi che do dang chinh
         ds1307_doc_time(8);
         if(giay_tam!=giay_ds)
         {
            giay_tam=giay_ds;
            giai_ma_gpg_8l7dq();
         }
      }
   }
}

   
      
 


