#include <tv_kit_vdk_pic_all.c>
usi8 k;

void b335_32led_kds_dich_pst(usi16 dl,k) //2 bien delay:16bit, k: 8bit
{
   usi8 i; usi32 x;
   x=0;
   
   if(k!=0)
   {
      for(i=0;i<k;i++)  //dich diem sang vao trong bien X lan luot xuat hien ra cho den khi du so bit 1
      {
         x=(x<<1)+1; //dich lan luot so 1 vao tan cung ben tay phai
         xuat_32led_don_1dw(x);
         delay_ms(dl);
      }
      for(i=0;i<32;i++) //dich du lieu dang co trong bien X mat di va dich tu phai sang trai
      {
         x=(x<<1);
         xuat_32led_don_1dw(x);
         delay_ms(dl);  
      }
   }
}

void main()
{
   set_up_port();
   while(true)
   {
      for(k=1;k<33;k++)
      {
         b335_32led_kds_dich_pst(10,k); //trao cho ham con bien k, bien k thay doi
      }
   }
}

