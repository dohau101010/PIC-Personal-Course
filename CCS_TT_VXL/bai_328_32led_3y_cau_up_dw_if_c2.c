
#include <tv_kit_vdk_pic_all.c> 
#include <bai_327_tv.c> 

//! INT1 phim_bt0_c2 (usi16 dl)  
//!{
//!    IF (!input (bt0))
//!    {
//!       dl_btn++; delay_us (500);
//!       IF (dl_btn >= dl)
//!       {
//!          dl_btn = 0;
//!          RETURN co_nhan;
//!       }
//!
//!       else RETURN khong_nhan;
//!    }
//!
//!    else RETURN khong_nhan;
//!}

 VOID b328_32led_std_pst_tsp_tat_3bt_if()
 {
    IF (phim_bt0_c2 (1) == co_nhan)
    {
       IF (tt_ct < 2)
       {
          tt_ct++;
          h327_reset_bien() ;
       }
    }

    IF (phim_bt1_c2 (1) == co_nhan)
    {
       IF (tt_ct > 0)
       {
          tt_ct--;
          h327_reset_bien() ;
       }
    }
 }

 VOID main()
 {
    set_up_port();
    tt_ct = 0;
    h327_reset_bien();

    WHILE (true)
    {
       b328_32led_std_pst_tsp_tat_3bt_IF () ;
       IF (tt_ct == 0) xuat_32led_don_1dw (0);
       IF (tt_ct == 1) h327_32led_std_pst_if ();
       IF (tt_ct == 2) h327_32led_std_tsp_if ();
       delay_ms (200);
    }
 }

