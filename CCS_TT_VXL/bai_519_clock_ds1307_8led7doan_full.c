
#include <tv_kit_vdk_pic_all.c> 

usi8 giay_tam,ngay_tam,thu_tam,gt_mod, i;
void b518_giai_ma_8led_quet() 
{
   md8l7d_gma_so_bcd_vitri_vn (giay_ds, 0, 0);
   md8l7d_gma_so_bcd_vitri_vn (phut_ds, 3, 0);
   md8l7d_gma_so_bcd_vitri_vn (gio_ds, 6, 1);
  for (i = 0; i < 10; i++) hien_thi_8led_7doan_quet ();
}

void b518_giai_ma_8led_quet_ntn()
{
   md8l7d_gma_so_bcd_vitri_vn (nam_ds, 0, 0);
   md8l7d_gma_so_bcd_vitri_vn (thang_ds, 3, 0);
   md8l7d_gma_so_bcd_vitri_vn (ngay_ds, 6, 1);
   for (i = 0; i < 10; i++) hien_thi_8led_7doan_quet ();
}

void b518_giai_ma_8led_quet_thu()
{
   md8l7d_gma_so_bcd_vitri_vn (thu_ds, 6, 0);
   dl_8l7dq[4]=0xff;
   dl_8l7dq[3]=0x7f;
   dl_8l7dq[1]=0xff;
   dl_8l7dq[0]=0x7f;
  for (i = 0; i < 10; i++) hien_thi_8led_7doan_quet ();
}

void phim_mod(usi8 dl)
{
   if(phim_bt3_c2 (dl))
   {
      gt_mod++;
      if(gt_mod>2) 
         gt_mod = 0;
   }
}

void main() 
{
   set_up_port ();
   ds1307_kiem_tra_ma ();
   gt_mod=0;
   WHILE (true)
   {
      ds1307_doc_time (8);
      phim_mod(5);
      if(gt_mod==0)
      b518_giai_ma_8led_quet ();
      if(gt_mod==1)
      b518_giai_ma_8led_quet_ntn();
      if(gt_mod==2)     
     b518_giai_ma_8led_quet_thu();
   }
}

