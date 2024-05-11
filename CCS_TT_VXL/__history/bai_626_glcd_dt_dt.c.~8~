#include <tv_kit_vdk_pic_all.c> 
#include <tv_06_glcd.c> 
#include <graphics.c>

void b627_glcd_line_rect_bar_circle_text() 
{
    unsigned char glcd_text_cir[]={"graphic"};
    setup_glcd(glcd_graphic_mode);
    glcd_mau_nen(0);
    glcd_text57(0, 0,glcd_text_cir, 1, 1); 
    glcd_line(0,10,30,30,sang); 
    glcd_rect(0, 40, 20, 60,no_fill,sang); 
    glcd_rect(30, 40, 50, 60,co_fill,sang); 
 
    glcd_circle(60,10,10,no_fill,sang);
    glcd_circle(90,10,10,co_fill,sang);
    
    glcd_bar(90,40,100,60,5,1);
    glcd_bar(70,40,70,60,5,sang);
    gdram_vdk_to_gdram_glcd_all(); 
} 

void main()
{ 
    set_up_port(); 
    setup_glcd(glcd_text_mode);
    delay_ms(10);
    
    setup_glcd(glcd_graphic_mode);
    glcd_mau_nen(0) ; 
    while(true)
    { 
    b627_glcd_line_rect_bar_circle_text();
    while(true);
    } 
}
