#include "E:\CCS VXL\THUC TAP VXL_SP\VXL_VIP_PRO\THU VIEN PIC 18F4550\tv_kit_vdk_pic_all.c"

si8 t0, t0_tam, g_han;
unsigned int1 status;
usi16 y;
void b411_hienthi_4led7doan()
{
   md4l7d_giaima_2so_vitri_vn(t0, 3, 1);
   md4l7d_giaima_2so_vitri_vn(g_han, 1, 1);
   xuat_4led_7doan_4so();
}
void b411_dem_xung_ngoai_t0()
{
   t0=get_timer0();
   if(t0 != t0_tam)
   {
      t0_tam=t0;
      b411_hienthi_4led7doan();
      if(t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}

void main()
{
   set_up_port(); 
   setup_timer_0(t0_ext_l_to_h|t0_div_1); 
   set_timer0(0);
   g_han=10;
   t0=0;
   t0_tam=1;
   b411_hienthi_4led7doan();
   while(true)
   {
     if(phim_bt0_c1(1,0)==1)
     {
         status==1;
         setup_timer_0(t0_ext_l_to_h|t0_div_1);
         xuat_32led_don_2word(0,0xff);
     }
     else if(phim_bt1_c1(1,0)==1)
     {
         setup_timer_0(t0_off); 
         xuat_32led_don_2word(0,0);
     } 
     else if(phim_bt2_c2(250)==1)
     {
         if(g_han<99) g_han++;
         else         g_han=0;
         b411_hienthi_4led7doan();
     }
     else if(phim_bt3_c2(250)==1)
     {
         if(g_han>0) g_han--;
         else         g_han=99;
         b411_hienthi_4led7doan();
     }
     if(status==1) b411_dem_xung_ngoai_t0();
   }
}
