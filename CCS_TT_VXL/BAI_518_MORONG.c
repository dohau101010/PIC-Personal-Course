#include <tv_pickit2_shift_1.c>
signed int8 sp, sec, bdn;
int1 tt_timer, tt_counter, dir_timer, dir_counter;
#int_timer1
void interrupt_timer1()
{
   bdn++;
   set_timer1(3036);
}
void  phim_onoff_counter()
{
   if(!input(bt0))
   {
      delay_ms(20);
      if(!input(bt0))
      {
         tt_counter=!tt_counter;
         if(!tt_counter) 
         {
            setup_timer_0(t0_ext_l_to_h|t0_div_1);
            xuat_32led_don_1dw(0xffffffff);
         }
         else          
         {
            setup_timer_0(t0_off);
            xuat_32led_don_1dw(0);
         }
         while(!input(bt0));
      }
   }
}
void chieudem()
{
   if(tt_chieu==0)
   {
      sp=get_timer0();
      if(sp>100)
      {
         set_timer0(1);
         sp=1;
      }
   }
   else
   {
      sp=99-get_timer0();
      if(sp<0)
      {
         set_timer0(0);
         sp=0;
      }
   }
}
void phim_chieu_counter()
{
   if(!input(bt1))
   {
      delay_ms(20);
      if(!input(bt1))
      {
         dir_counter=!dir_counter;
         set_timer0(99-get_timer0());
         while(!input(bt1));
      }
   }
}
void  phim_onoff_timer()
{
   if(!input(bt3))
   {
      delay_ms(20);
      if(!input(bt3))
      {
         tt_timer=!tt_timer;
         if(!tt_timer)   setup_timer_1(t1_internal|t1_div_by_8);
         else            setup_timer_1(t1_disabled); 
         while(!input(bt3));
      }
   }
}
void giaima_7doan()
{
   led_7dq[7]=ma7doan[sp/10];
   led_7dq[6]=ma7doan[sp%10];
}

void main()
{
   set_up_port_ic_chot();
   setup_timer_0(t0_off);
   set_timer0(0);
   setup_timer_1 (t1_internal|t1_div_by_8);
   set_timer1(3036);
   enable_interrupts(global) ;
   enable_interrupts(int_timer1);
   tt_onoff=1;
   sp=0;
   while(true)
   {
      phim_start_stop();
      phim_chieu_counter();
      giaima_7doan();
      chieudem();
      hien_thi_8led_7doan_quet_all ();
   }
}

