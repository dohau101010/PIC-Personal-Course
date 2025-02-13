#define xt  96
#define yt  32
#define bks 20
signed int16 xs_ve,ys_ve,tgs45,tg;
float xs_tinh,ys_tinh,goc_s;

void glcd_ve_cac_vong_tron_so()
{
    unsigned char glcd_text1[]={"Clock: UTE"}, glcd_12[]="12";
    unsigned char glcd_9[]="9",glcd_6[]="6",glcd_3[]="3";
    
    setup_glcd(glcd_graphic_mode);
    glcd_mau_nen(0);
    glcd_text57(0,0,glcd_text1,1,1);
   
    glcd_text57(xt-5,yt-29,glcd_12,1,1);
    glcd_text57(xt-3,yt+23,glcd_6,1,1);
    glcd_text57(xt-28,yt-3,glcd_9,1,1);
    glcd_text57(xt+24,yt-3,glcd_3,1,1);
    
    glcd_circle(xt,yt,bks+11,no_fill,sang);
    glcd_circle(xt,yt,bks+2,no_fill,sang);
    
    glcd_circle(xt+12,yt-23,+2,co_fill,sang);
    glcd_circle(xt+23,yt-12,+2,co_fill,sang);
    glcd_circle(xt+12,yt+23,+2,co_fill,sang);
    glcd_circle(xt+23,yt+12,+2,co_fill,sang);
    glcd_circle(xt-12,yt-23,+2,co_fill,sang);
    glcd_circle(xt-23,yt-12,+2,co_fill,sang);
    glcd_circle(xt-12,yt+23,+2,co_fill,sang);
    glcd_circle(xt-23,yt+12,+2,co_fill,sang);
}

void tinh_vi_tri_kim_giay(usi8 bk,usi16 tg)
{
    tgs45 = tg + 45;
    if(tgs45>60) tgs45 = tgs45-60;
    goc_s = tgs45*6;
    xs_tinh = bk*cos((goc_s*3.14)/180);
    ys_tinh = bk*sin((goc_s*3.14)/180);
    xs_ve = xt + (signed int16)(xs_tinh);
    ys_ve = yt + (signed int16)(ys_tinh);
}

void glcd_ve_kim_giay(usi8 bk,usi16 tg, int1 tt)
{
    glcd_command(glcd_graphic_mode);
    if(tt) glcd_line(xt,yt,xs_ve,ys_ve,tat); // xoa kim giay da hien thi truoc do 
    
    tinh_vi_tri_kim_giay(bk,tg);
    glcd_line(xt,yt,xs_ve,ys_ve,sang);
    
    glcd_circle(xt,yt,4,co_fill,sang);
    glcd_circle(xt,yt,2,no_fill,tat);
}

void glcd_dong_ho_so()
{
    const signed int8 maglcd[]={"0123456789"}; //khai bao mang chua cac con so tu 0-9
    glcd_command(glcd_text_mode); //khoi tao LCD o che do text
    glcd_command(glcd_addr_line1+2); //khoi tao dia chi o hang 2
    glcd_data(maglcd[giay_ds/16]); //tach hang chuc giay dang so BCD-> lay ma ascii tuong ung goi ra lcd hien thi hang chuc giay
    glcd_data(maglcd[giay_ds%16]);
}
