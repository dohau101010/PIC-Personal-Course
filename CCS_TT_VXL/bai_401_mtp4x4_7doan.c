#include <tv_kit_vdk_pic_all.c>
usi8 mp;
void main()
{ 
 set_up_port(); 
 while(true)
 { 
   mp = key_4x4_up(); 
   if(mp!= 0xff) 
   {
      xuat_32led_don_4byte(0,0,0,mp);
      dl_4l7d[3] = ma7doan[mp];
      xuat_4led_7doan_4so(); 
   }
 } 
}

