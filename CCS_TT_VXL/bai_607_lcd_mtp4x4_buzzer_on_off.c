#include <tv_kit_vdk_pic_all.c>
unsigned int8 mp,bdn,i;
unsigned int8 tg_cai,tg_dem;
unsigned int8 chuc=1,donvi=0;
int1 tt_ss,tt_cai;

void lcd_hienthi_off()
{
   lcd_goto_xy(1,17);
   lcd_data("OFF");
}
void lcd_hienthi_on()
{
   lcd_goto_xy(1,17);
   lcd_data("ON ");
}

void lcd_hienthi_ena()
{
   lcd_goto_xy(1,12);
   lcd_data("ena");
}

void lcd_hienthi_dis()
{
   lcd_goto_xy(1,12);
   lcd_data("dis");
}

#int_timer3
void interrupt_timer3()
{
   bdn++;   
   set_timer3(3036);
}

void lcd_hienthi_tg_cai()
{
   lcd_goto_xy(2,18);
   tg_cai = chuc*10+donvi;
   lcd_data(tg_cai/10%10+0x30);
   lcd_data(tg_cai%10+0x30);
}

void lcd_hienthi_tg_dem()
{
   lcd_goto_xy(3,18);
   lcd_data(tg_dem/10%10+0x30);
   lcd_data(tg_dem%10+0x30);
}

void tat_het()
{
   disable_interrupts(int_timer3);
   lcd_hienthi_off();
   xuat_32led_don_1dw(0);
   tg_dem=0;
   tt_ss=0;
   lcd_hienthi_tg_dem();
}

void buzz_bip()
{
   for(i=0;i<5;i++)
   {
      buzzer_on_off(500);
      delay_ms(500);
   }
}

void xu_ly_cac_phim()
{
   mp=key_4x4_dw();
   if(!tt_ss)
   {
      if(mp==0x0e)
      {
         tt_cai=enable; //=1 
         lcd_hienthi_ena();
      }
      else if(mp==0x0f)
      {
         tt_cai=disable; //=0
         lcd_hienthi_dis();
      }
      else if((mp<10)&&(tt_cai))
      {
         chuc = donvi;
         donvi = mp;
         lcd_hienthi_tg_cai();
      }
   }
   if((mp==10)&&(tg_cai>0)) //phim a
   {
      tg_dem=tg_cai;
      xuat_32led_don_1dw(0xffffffff);
      enable_interrupts(int_timer3);
      lcd_hienthi_on();
      tt_ss=1;  //trang thai dang dinh thoi
   }
   else if((mp==0x0c)&&(tt_ss==1))
         tat_het();
}

void main()
{
   set_up_port();
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   enable_interrupts(global);
   
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("  LO VI BA HCMUTE ");
   
   lcd_goto_xy(1,0);
   lcd_data("DINH THOI:          ");
   lcd_goto_xy(2,0);
   lcd_data("THOI GIAN CAI:      ");
   lcd_goto_xy(3,0);
   lcd_data("THOI GIAN DEM:      ");
   lcd_hienthi_dis();
   lcd_hienthi_off();
   
   tg_dem=0;
   tt_ss=0; tt_cai=0;
   chuc=1; donvi=0;  //thoi gian cai mac nhien la 10
   
   lcd_hienthi_tg_cai();
   lcd_hienthi_tg_dem();
   
   while(true)
   {
      xu_ly_cac_phim();
      if((tt_ss)&&(bdn>=10))
      {
         bdn=bdn-10;
         //if(tg_dem>0)
         tg_dem--;
         if(tg_dem==0)
         {
            tat_het();
            buzz_bip();
         }
         lcd_hienthi_tg_dem();
      }
      delay_ms(200); //lam cham bot
   }
}
