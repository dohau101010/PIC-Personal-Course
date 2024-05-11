#include <tv_kit_vdk_pic_all.c> 
usi32 k;

void sdan_pst(usi32 dl, usi32 k)
{
   usi8 i; usi32 led; led=0; 
   for(i=0;i<k; i++) 
{
   led=(led<<1)+0x00000001;
   xuat_32led_don_1dw(led); delay_ms(dl);
}
   for(i=0;i<32; i++) 
   {
      led=(led<<1);
      xuat_32led_don_1dw(led|0x80000000); delay_ms(dl);
   } 
}

void main()
{   
   set_up_port ();
    while(true)
      {
       for(k=0;k<32;k++)
             sdan_pst(20,k);
      }
}
         
      
 
