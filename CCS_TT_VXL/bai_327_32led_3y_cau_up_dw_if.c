
#include <tv_kit_vdk_pic_all.c> 
#include <bai_327_tv.c> 

void b327_32led_std_pst_tsp_tat_3bt_IF() 
{
   IF (phim_bt0_c1 (1, 0) == 1)
   {
      IF (tt_ct < 2)
      {
         tt_ct++;
         h327_reset_bien() ;
      }
   }

   IF (phim_bt1_c1 (1, 0) == 1)
   {
      IF (tt_ct > 0)
      {
         tt_ct--;
         h327_reset_bien() ; 
      }
   }
}

void main()
{
   set_up_port();
   tt_ct = 0;
   h327_reset_bien() ;

   WHILE (true)
   {
      b327_32led_std_pst_tsp_tat_3bt_IF ();
      IF (tt_ct == 0) xuat_32led_don_1dw (0);
      IF (tt_ct == 1) h327_32led_std_pst_if ();
      IF (tt_ct == 2) h327_32led_std_tsp_if ();
      delay_ms (100);
   }
}

