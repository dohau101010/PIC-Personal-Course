
#include <tv_kit_vdk_pic_all.c> 
#include <tv_06_glcd.c> 
#include <graphics.c>//duoi tv_pic_glcd 
#include <bai_628_glcd_kim_giay_tv.c> 

usi8 giay_tam, giay_bin;

void main()
{
   set_up_port();
   setup_glcd (glcd_text_mode);
   delay_ms(1);
   setup_glcd (glcd_graphic_mode);
   glcd_mau_nen (0);
   ds1307_kiem_tra_ma ();
   glcd_ve_vong_tron_ht_so (giay_ds);

   WHILE (true)
   {
      ds1307_doc_time (8);

      IF (giay_tam != giay_ds)
      {
         giay_tam = giay_ds;
         giay_bin = (giay_ds / 16) * 10 + (giay_ds % 16);
         glcd_ve_kim (bks, giay_bin, 1);
         gdram_vdk_to_gdram_glcd_all ();
         glcd_dong_ho_so (giay_bin) ;
      }
   }
}

