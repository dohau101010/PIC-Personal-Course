#include <tv_kit_vdk_pic_all.c>
const unsigned int8 ma_7doan[30]={0xFF,0XFF,0XFF,0XFF,0xFF,0XFF,0XFF,0XFF
                                 ,0xC6,0X88,0X8E,0X86,0xBF,0XC6,0XC0,0XC6,0X88,0XBF,0XC6,0XC0,0XC7,0X88
                                 ,0xFF,0XFF,0XFF,0XFF,0xFF,0XFF,0XFF,0XFF};
usi8 i,j,n,v,m;

void copy_8byte_hthi(usi8 k)
{
   for(i=k,n=7;i<k+8;i++,n--)
   {
      dl_8l7dq[n]=ma_7doan[i];
   }
}
//!void hthi_nguoc_lai(usi8 k)
//!{
//!   for(i=k,n=0;i<k+8;i++,n++)
//!   {
//!      dl_8l7dq[n]=ma_7doan[i];
//!   }
//!}

void main()
{
   set_up_port();
   
   while(true)
   {
      for(j=0;j<22;j++)
      {
         copy_8byte_hthi(j);
         for(v=0;v<50;v++)
               hien_thi_8led_7doan_quet();
         if((j==8)|(j==14)) //Ham chop tat tai cac vi tri 
         {
          for(m=0;m<5;m++)
          {
            for(v=0;v<50;v++)
               hien_thi_8led_7doan_quet();
            delay_ms(100);
          }
         }
      }
      for(j=22;j>0;j--)
      {
         copy_8byte_hthi(j);
         for(v=0;v<50;v++)
            hien_thi_8led_7doan_quet();
         if((j==14)|(j==8))
         {
          for(m=0;m<5;m++)
          {
            for(v=0;v<50;v++)
               hien_thi_8led_7doan_quet();
            delay_ms(100);
          }
         }
      }
//!      delay_ms(1000);
   }
}
