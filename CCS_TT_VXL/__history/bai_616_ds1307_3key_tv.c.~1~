signed int8  gt_mod=0, tg_chinh=0;
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
   ch=(x>>4);  dv=x&0x0f;
   y=ch*10+dv;
   if(sel==0)  y++;
   else        y--;
   ch=y/10; dv=y%10;
   v=(ch<<4)|dv;
   return(v);
}
void giai_ma_thu_8l7dq()
{
   dl_8l7dq[7]=0x87; //t
   dl_8l7dq[6]=0x8b; //h
   dl_8l7dq[5]=0xe3; //u
   dl_8l7dq[4]=0xff;
   dl_8l7dq[3]=ma7doan[thu_ds];
   dl_8l7dq[2]=0xff;
   dl_8l7dq[1]=0xff;
   dl_8l7dq[0]=0xff;
}

void giai_ma_gpg_8l7dq()
{
   md8l7d_gma_so_bcd_vitri_vn(giay_ds, 0, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(phut_ds, 3, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(gio_ds, 6, cx_vn);
   dl_8l7dq[5]=0xff;
}

void giai_ma_ntn_8l7dq()
{
   md8l7d_gma_so_bcd_vitri_vn(nam_ds, 0, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(thang_ds, 3, kx_vn);
   md8l7d_gma_so_bcd_vitri_vn(ngay_ds, 6, cx_vn);
}

void giai_ma_gpg_ntn_8l7dq()
{
   if(gt_mod==0)
   {
      if(tt_ht==0)   giai_ma_gpg_8l7dq();
      if(tt_ht==1)   giai_ma_ntn_8l7dq();
      if(tt_ht==2)   giai_ma_thu_8l7dq();
   }
   else
      if(gt_mod<4)        giai_ma_gpg_8l7dq();
      else if(gt_mod<7)   giai_ma_ntn_8l7dq();
      else if(gt_mod==7)  giai_ma_thu_8l7dq();
}

void phim_chon_hthi()
{
   if(phim_bt3_c2(50))
   {
      tt_ht++;
      if(tt_ht>2) tt_ht=0;
      giai_ma_gpg_ntn_8l7dq();
      dl_4l7d[0]=ma7doan[tt_ht];
      dl_4l7d[3]=ma7doan[gt_mod];
      xuat_4led_7doan_4so();
   }
}

void tat_2led_chinh()
{
   if((gt_mod==1)||(gt_mod==4))
   {
      dl_8l7dq[1]=0xff; dl_8l7dq[0]=0xff;
   }
   if((gt_mod==2)||(gt_mod==5)||(gt_mod==7))
   {
      dl_8l7dq[4]=0xff; dl_8l7dq[3]=0xff;
   }
   if((gt_mod==3)||(gt_mod==6))
   {
      dl_8l7dq[7]=0xff; dl_8l7dq[6]=0xff;
   }
}
void xu_ly_choptat()
{
   if(gt_mod!=0)
   {
      if((bdn==0)&&(input(up))&&(input(dw)))
         tat_2led_chinh();
      else if(bdn==5)
         giai_ma_gpg_ntn_8l7dq();
   }
}

void phim_mod(usi8 dl)
{
   if(phim_mode_c2(dl))
   {
      gt_mod++;
      if(gt_mod>7)
      {
         gt_mod = 0;
         giai_ma_gpg_ntn_8l7dq();
      }
      tg_chinh = 0;
      xuat_32led_don_4byte(0,0,0,gt_mod);
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

void tang_nam()
{
   if(nam_ds==0x99) nam_ds=0;
   else nam_ds=tang_or_giam_so_bcd(nam_ds,tang);
   ds1307_luu_vao_ds(6,nam_ds); 
}
void tang_thang()
{
   if(thang_ds==0x12) thang_ds=1;
   else thang_ds=tang_or_giam_so_bcd(thang_ds,tang);
   ds1307_luu_vao_ds(5,thang_ds); 
}

void tang_ngay()
{
   if(ngay_ds==0x31) ngay_ds=1;
   else ngay_ds=tang_or_giam_so_bcd(ngay_ds,tang);
   ds1307_luu_vao_ds(4,ngay_ds); 
}

void chinh_tang_ntn()
{
   switch(gt_mod)
   {
      case 4: tang_nam();    break;
      case 5: tang_thang();  break;
      case 6: tang_ngay();   break;
      default: break;
   }
}

void chinh_tang_thu()
{
   if(thu_ds==8)  thu_ds=2;
   else           thu_ds++;
   ds1307_luu_vao_ds(3,thu_ds);
}

void phim_up(usi8 dl)
{
   if(phim_up_c2(dl))
   {
      tg_chinh=0;
      if(gt_mod<4)         chinh_tang_gpg();
      else if(gt_mod<7)    chinh_tang_ntn();
      else if(gt_mod==7)   chinh_tang_thu();
      
      giai_ma_gpg_ntn_8l7dq();
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

void giam_nam()
{
   if(nam_ds==0) nam_ds=0x99;
   else nam_ds=tang_or_giam_so_bcd(nam_ds,giam);
   ds1307_luu_vao_ds(6,nam_ds); 
}
void giam_thang()
{
   if(thang_ds==1) thang_ds=0x12;
   else thang_ds=tang_or_giam_so_bcd(thang_ds,giam);
   ds1307_luu_vao_ds(5,thang_ds); 
}

void giam_ngay()
{
   if(ngay_ds==1) ngay_ds=0x31;
   else ngay_ds=tang_or_giam_so_bcd(ngay_ds,giam);
   ds1307_luu_vao_ds(4,ngay_ds); 
}

void chinh_giam_ntn()
{
   switch(gt_mod)
   {
      case 4: giam_nam();    break;
      case 5: giam_thang();  break;
      case 6: giam_ngay();   break;
      default: break;
   }
}

void chinh_giam_thu()
{
   if(thu_ds==2)  thu_ds=8;
   else           thu_ds--;
   ds1307_luu_vao_ds(3,thu_ds);
}

void phim_dw(usi8 dl)
{
   if(phim_dw_c2(dl))
   {
      tg_chinh=0;
      if(gt_mod<4)         chinh_giam_gpg();
      else if(gt_mod<7)    chinh_giam_ntn();
      else if(gt_mod==7)   chinh_giam_thu();
      
      giai_ma_gpg_ntn_8l7dq();
      hien_thi_8led_7doan_quet();
   }
}
