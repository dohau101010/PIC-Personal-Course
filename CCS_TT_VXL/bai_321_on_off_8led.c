#include <tv_kit_vdk_pic_all.c>
void main()
{ 
    set_up_port();
    xuat_32led_don_4byte(0,0,0,0);
    while(true)
    { 
       while(input(on)); 
       xuat_32led_don_4byte(0,0,0,0xff); 
       while(input(off)); 
       xuat_32led_don_4byte(0,0,0,0);
    } 
}

