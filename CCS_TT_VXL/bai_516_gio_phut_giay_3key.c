#include <tv_kit_vdk_pic_all.c> 
si8  gio, phut, giay, bdn, mode, tg_chinh=0;

#int_timer3
void interrupt_timer3() 
{
   bdn++;
   set_timer3(3036);
}

void giai_ma_hien_thi() 
{
   md8l7d_gma_2so_vitri_vn (giay, 0, kx_vn);
   md8l7d_gma_2so_vitri_vn (phut, 3, kx_vn);
   md8l7d_gma_2so_vitri_vn (gio, 6, kx_vn);
   hien_thi_8led_7doan_quet ();
}

void tat_2led_chinh()
{
   IF (mode == 1) {dl_8l7dq[7] = 0xff; dl_8l7dq[6] = 0xff;}
   IF (mode == 2) {dl_8l7dq[4] = 0xff; dl_8l7dq[3] = 0xff;}
   IF (mode == 3) {dl_8l7dq[1] = 0xff; dl_8l7dq[0] = 0xff;}
   hien_thi_8led_7doan_quet ();
}

void phim_mod()
{
   if(phim_bt1_c1(1,0))
   {
      if(mode==3) mode=0;
      else        mode++;
      tg_chinh = 0;
   }
}

void phim_up() 
{
   if(phim_bt0_c1(1,0))
   {
      tg_chinh = 0;
     if(mode==1)
     {
      if(gio==23)    gio=0;
      else           gio++;
     }
     else if(mode==2)
     {
      if(phut==59)    phut=0;
      else            phut++;
     }
     else if(mode==3)
     {
      if(giay==59)    giay=0;
      else            giay++;
     }
   }
}

void phim_dw() 
{
   if(phim_bt2_c1(1,0))
   {
      tg_chinh = 0;
     if(mode==1)
     {
      if(gio==0)    gio=23;
      else           gio--;
     }
     else if(mode==2)
     {
      if(phut==0)    phut=59;
      else            phut--;
     }
     else if(mode==3)
     {
      if(giay==0)    giay=59;
      else            giay--;
     }
   }
}

void xu_ly_gpg() 
{
   if(bdn>=10)
   {
      bdn=bdn-10;
      giay++;
      if(giay>59)
      {
         giay=0; phut++;
      }
      if(phut>59)
      {
         phut=0; gio++;
      }
      if(gio>23) gio=0;
   }
}

void xu_ly_choptat() 
{
   if(mode !=  0)
   {
     if(bdn<5) giai_ma_hien_thi();
     else      tat_2led_chinh();
   }
   else giai_ma_hien_thi();
}


void main() 
{
   set_up_port ();
   setup_timer_3 (t3_internal|t3_div_by_8);
   set_timer3 (3036);
   enable_interrupts (global) ;
   enable_interrupts (INT_timer3) ;
   giay = 0; bdn = 0;
   phut = 0; gio = 0; mode = 0;
   while(true)
   {
      phim_mod();
      phim_up();
      phim_dw();
      xu_ly_gpg();
      xu_ly_choptat();
   }
}

