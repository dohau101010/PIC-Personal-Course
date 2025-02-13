
signed INT8 gio,phut,giay,bdn,gt_mod,tg_chinh=0;

#INT_timer3

void interrupt_timer3() 
{
   bdn++;
   set_timer3 (3036);//63036-div=1
}

void giai_ma_8led_quet() 
{
   md8l7d_gma_2so_vitri_vn (giay, 0, kx_vn);
   md8l7d_gma_2so_vitri_vn (phut, 3, kx_vn);
   md8l7d_gma_2so_vitri_vn (gio, 6, kx_vn);
   IF (gt_mod == 1) dl_8l7dq[6] = dl_8l7dq[6]&0x7f;
   IF (gt_mod == 2) dl_8l7dq[3] = dl_8l7dq[3]&0x7f;
   IF (gt_mod == 3) dl_8l7dq[0] = dl_8l7dq[0]&0x7f;
}

void tat_2led_chinh()
{
   IF (gt_mod == 1) {dl_8l7dq[7] = 0xff; dl_8l7dq[6] = 0xff;}
   IF (gt_mod == 2) {dl_8l7dq[4] = 0xff; dl_8l7dq[3] = 0xff;}
   IF (gt_mod == 3) {dl_8l7dq[1] = 0xff; dl_8l7dq[0] = 0xff;}
}

void phim_mod(usi8 dl)
{
   IF (phim_mode_c2 (dl))
   {
      gt_mod++;
      IF (gt_mod >= 4) gt_mod = 0;
      tg_chinh = 0;
   }
}

void phim_up(usi8 dl) 
{
   IF (phim_up_c2 (dl))
   {
      tg_chinh = 0;

      SWITCH (gt_mod)
      {
         case 1: IF (gio == 23) gio = 0;
         ELSE gio++;
         BREAK;
         case 2: IF (phut == 59) phut = 0;
         ELSE phut++;
         BREAK;
         case 3: IF (giay == 59) giay = 0;
         ELSE giay++;
         BREAK;
         DEFAULT: break;
      }

      giai_ma_8led_quet ();
      hien_thi_8led_7doan_quet ();
   }
}

void phim_dw(usi8 dl)
{
   IF (phim_dw_c2 (dl))
   {
      tg_chinh = 0;

      SWITCH (gt_mod)
      {
         case 1: IF (gio == 0) gio = 23;
         ELSE gio--;
         BREAK;
         case 2: IF (phut == 0) phut = 59;
         ELSE phut--;
         BREAK;
         case 3: IF (giay == 0) giay = 59;
         ELSE giay--;
         BREAK;
         DEFAULT: break;
      }

      giai_ma_8led_quet ();
      hien_thi_8led_7doan_quet ();
   }
}

void bai_516_xu_ly_gpg() 
{
   bdn = bdn - 10;
   tg_chinh++;
   IF (tg_chinh == 10) gt_mod = 0;
   giay++;

   IF (giay == 60)
   {
      giay = 0; phut++;
      IF (phut == 60)
      {
         phut = 0; gio++;
         IF (gio == 24) gio = 0;
      }
   }

   giai_ma_8led_quet ();
}

void xu_ly_choptat() 
{
   IF (gt_mod !=  0)
   {
      IF ( (bdn == 0)&& (input (up))&& (input (dw)))
      tat_2led_chinh ();

      else IF (bdn == 5)
         giai_ma_8led_quet ();
   }
}

