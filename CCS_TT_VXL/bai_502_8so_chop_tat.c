#include <tv_kit_vdk_pic_all.c>
usi8 i;

void hienthi()
{
   dl_8l7dq[0]=ma7doan[7];
   dl_8l7dq[1]=ma7doan[6];
   dl_8l7dq[2]=ma7doan[5];
   dl_8l7dq[3]=ma7doan[4];
   dl_8l7dq[4]=ma7doan[3];
   dl_8l7dq[5]=ma7doan[2];
   dl_8l7dq[6]=ma7doan[1];
   dl_8l7dq[7]=ma7doan[0];
   for(i=0; i<20; i++)
  hien_thi_8led_7doan_quet();
      
}
void tatled()
{
   for(i=0; i<8; i++)
   dl_8l7dq[i]=0xff;
   for(i=0; i<20; i++)
   hien_thi_8led_7doan_quet();
}
void main() 
{ 
   set_up_port();
   while(true) 
   { 
      hienthi();
      tatled();
   } 
}

