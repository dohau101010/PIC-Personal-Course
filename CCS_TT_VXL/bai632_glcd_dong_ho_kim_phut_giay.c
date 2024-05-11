#include <tv_kit_vdk_pic_all.c>
#include <tv_06_glcd.c>
#include <graphics.c>
#include <bai632_glcd_dong_ho_kim_phut_giay_tv.c>
usi16 giay_tam, giay_bin, phut_bin;

void main()
{
   set_up_port();   
   setup_glcd(glcd_text_mode);
   delay_ms(10);
   
   setup_glcd(glcd_graphic_mode);
   glcd_mau_nen(0);
   ds1307_kiem_tra_ma();
   
   glcd_ve_cac_vong_tron_so();
   giay_bin = (giay_ds/16)*10 + (giay_ds%16); //chuyen sang so nhi phan
   glcd_ve_kim_giay(bks, giay_bin, 0); 
   giay_tam = 0x60;
   
   phut_bin = (phut_ds/16)*10 + (phut_ds%16); //tinh phut nhi phan
   glcd_ve_kim_phut(bkm, phut_bin, 1); 
   
   while(true)
   {
      ds1307_doc_time(8);
      if(giay_tam!=giay_ds)
      {
         giay_tam = giay_ds;
         giay_bin = (giay_ds/16)*10 + (giay_ds%16);
         if(giay_ds==0)
         {
            phut_bin = (phut_ds/16)*10 + (phut_ds%16);
            glcd_ve_kim_phut(bkm, phut_bin, 1); 
         }
         glcd_ve_kim_giay(bks, giay_bin, 1);      
         gdram_vdk_to_gdram_glcd_all(); //ham cap nhat bo nho gdram cua vdk ra GLCD
         glcd_dong_ho_so();
      }
   }
}
