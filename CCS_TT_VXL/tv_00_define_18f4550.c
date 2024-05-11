//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//NGUYEN DINH PHU SU PHAM KY THUAT TP HCM
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cau hinh vi dieu khien pic       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#include <18f4550.h>
#device  adc=10
#fuses   nowdt,put,hs,noprotect,nolvp,cpudiv1,NOUSBDIV,    
#use     delay(clock=20000000)                                                      
#use     i2c(master,slow,sda=pin_b0,scl=pin_b1)    
#use     rs232(baud=9600, xmit=pin_c6,rcv=pin_c7)    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//dinh nghia lai ten cac kieu du lieu cho gon
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define usi8  unsigned int8     
#define usi16 unsigned int16                          
#define usi32 unsigned int32                                                                    
#define si8   signed   int8                                
#define si16  signed   int16 
#define si32  signed   int32
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dinh nghia 1 so tu thuong dung
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define co_reset true
#define no_reset false 

#define tt_on    1          
#define tt_off   0                    
#define enable   1                        
#define disable  0
#define sang     1          
#define tat      0  
#define tat_l7d  0xff     
#define cx_vn    true     //co xoa so 0 vo nghia        
#define kx_vn    false    //khong xoa so 0 vo nghia          
#define co_fill  true
#define no_fill  false 
#define c_reset  1          
#define k_reset  0                                         
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dinh nghia ten cho 4 nut nhan 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#ifndef bt0
#define bt0    pin_b5
#endif 

#ifndef bt1    
#define bt1    pin_b4
#endif 
                  
#ifndef bt2    
#define bt2    pin_b3
#endif 

#ifndef bt3
#define bt3    pin_b2
#endif 

#define on     bt0    //dk led don, motor 
#define off    bt1
#define inv    bt2
                               
#define up     bt0    //dk led don
#define mod    bt1
#define dw     bt2
#define clr    bt3

#define stop   bt1

#define on1    bt0     
#define off1   bt1
#define on2    bt2       
#define off2   bt3             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//dinh nghia port giao tiep cam bien sieu am hcsr-04 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
#define trig   pin_e1           
#define echo   pin_a3                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//dinh nghia port giao tiep CB nhiet va do am 1 day DHT11   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
#define dht11 pin_d1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//dinh nghia port giao tiep noi tiep 6 module
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                       
#define ssdo      pin_e2         
#define ssck      pin_e0         

#define rck_mtl   pin_d7
#define rck_4l7d  pin_d6          
#define rck_8l7dq pin_d5        
#define rck_32led pin_d4
#define rck_rlb   pin_d3             
#define rck_lcd   pin_d2         

#define g_all     pin_d0          
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//khai bao  module relay, triac, buzzer, dong co
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
unsigned int16 rbdc;                          
#bit step_motor_enable = rbdc.0    
#bit step_motor_in1    = rbdc.1    
#bit step_motor_in2    = rbdc.2
#bit step_motor_in3    = rbdc.3
#bit step_motor_in4    = rbdc.4
#bit dc_enable         = rbdc.5    
#bit pwrkey            = rbdc.6    

#bit buzzer            = rbdc.8    //1=on,0=off
#bit triac_1           = rbdc.9    //1=on,0=off
#bit triac_2           = rbdc.10   //1=on,0=off
#bit relay_1           = rbdc.11   //0=on,1=off
#bit relay_2           = rbdc.12   //0=on,1=off      

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//Khai bao mang chua 16 ma 7 doan tu 0 den F
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
const unsigned char ma7doan[16]= {
   0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,        
   0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
#define     maso0    0xc0

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham 102: xuat 1 byte ra thanh ghi dich
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void xuat_1byte(unsigned int8 x)
{
   unsigned int8   sb;   
   #bit msb  = x.7;  
   for (sb=0;sb<8;sb++)
   {                                                 
      output_bit(ssdo,msb);    
      output_low(ssck); output_high(ssck);
      x= x<<1;         
   }
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//ham 103: xuat 1 word ra thanh ghi dich
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void xuat_1word(unsigned int16 w)
{  
   unsigned int8 b1,b0;
   b1 = w>>8; b0 = w;
   xuat_1byte(b1);    
   xuat_1byte(b0);
}   
                               
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
//ham 104: xoa cac module 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void xoa_tat_6module()                          
{                                                                                              
   xuat_1word(0);                             
   xuat_1word(0); 
   xuat_1word(0);                             
   xuat_1word(0);                                    
   
   output_high(rck_rlb);   
   output_low(rck_rlb);
   
   output_high(rck_32led);
   output_low(rck_32led); 
   
   output_high(rck_8l7dq);   
   output_low(rck_8l7dq);   
                                 
   output_high(rck_mtl);          
   output_low(rck_mtl);   
                           
   output_high(rck_lcd);   
   output_low(rck_lcd);      
                                                                          
   xuat_1word(0xffff); 
   xuat_1word(0xffff); 
   output_high(rck_4l7d);       
   output_low(rck_4l7d);                                                                      
}             

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//ham 101: ham khoi tao cac port va ic chot
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void set_up_port()                                  
{                            
   set_tris_a(0xff);      set_tris_b(0x3c);                                                  
   set_tris_c(0xf1);    set_tris_e(0x00);                                               
   set_tris_d(0x00);    
   output_d(0x00); 
   xoa_tat_6module();
   port_b_pullups(0xff);          
   rbdc=0;               
            
   setup_adc(adc_clock_div_32);        
   setup_adc_ports(an0_to_an2|vss_vdd); 
   output_low(g_all);        
}
 //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
//xuat 1 bit roi tra lai ket qua sau khi dich di 1 bit
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
unsigned  int8 xuat_1bit(usi8 bx)
{  
   #bit lsb = bx.0                                           
   output_bit(ssdo,lsb);    
   output_low(ssck); output_high(ssck);
   bx = bx>>1;   
   return(bx);  
}   

                                
