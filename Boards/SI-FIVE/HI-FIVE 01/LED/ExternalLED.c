/*
External LED Blinking
The external LED is connected to the Digital pin 5
and Ground
 */
#include <stdio.h>
#include <metal/led.h>
int main(void) {
	     int a=5;
	     struct metal_led *B;
		 B= metal_led_get_rgb("LD0","blue");
		 metal_led_enable(B);
		 while(a>0){
		 printf("a=%d\n",a);
		 metal_led_on(B);
		 delay(1);
		 metal_led_off(B);
		 delay(1);
		 a--;
		 }
		 metal_led_off(B);
	return 0;
}
#define RTC_FREQ 32768
#define CLINT_MTIME 0x200bff8
void delay(int sec){
uint64_t ticks = sec * RTC_FREQ;
mtime_wait(ticks);
}
void mtime_wait( uint64_t ticks)
{
volatile uint64_t * mtime  = (uint64_t*) (CLINT_MTIME);
uint64_t now = *mtime;
uint64_t then = now + ticks;
  while(*mtime<then) {
  }
}


