#include <tv_kit_vdk_pic_all.c>
#include <tv_06_glcd.c>
#include <graphics.c>
#include <bai_631_glcd_kim_giay_tv.c>
usi8 giay_tam, giay_bin;

#include <tv_08_dc_motor.c>
#include <bai_812_dc_motor_tv.c>

void main()
{
   set_up_port();
   //glcd_setup(glcd_text_mode);
   setup_glcd(glcd_text_mode);
   delay_ms(10);
   
   setup_glcd(glcd_graphic_mode);
   glcd_mau_nen(0);
   ds1307_kiem_tra_ma();
   
   glcd_ve_cac_vong_tron_so();
   giay_bin=(giay_ds/16)*10+(giay_ds%16);
   glcd_ve_kim_giay(bks,giay_bin,0);
   giay_tam = 0x60;
   
   dc_motor_enable();
   dc_motor_stop();
   
   while(true)
   {
      phim_on_off();
      dkdc_theo_giay(giay_bin); //giay nhi phan
      ds1307_doc_time(8); //doc time 8byte
      if(giay_tam!=giay_ds)
      {
         giay_tam=giay_ds;
         giay_bin=(giay_ds/16)*10+(giay_ds%16);
         glcd_ve_kim_giay(bks,giay_bin,1);
         
         gdram_vdk_to_gdram_glcd_all();
         glcd_dong_ho_so();
      }
   }
}
