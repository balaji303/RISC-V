#include <stdio.h>
//#include <stdint.h>
//#include "stdatomic.h"
//#include <unistd.h>

//#include "platform.h"
//#include "encoding.h"
//#include "plic/plic_driver.h"

//#define CLINT_CTRL_ADDR CLIC_CTRL_ADDR

//#include <stdio.h>
//#include <metal/cpu.h>
#include <metal/led.h>
#define RTC_FREQ 32768
//#define CLINT_CTRL_ADDR 35
//#define CLINT_MTIME 35
#define CLINT_MTIME 0x200bff8
void mtime_wait( uint64_t ticks);
void delay(int sec);
int main(void){
	 int a=5;
	 printf("Hello....ON.\n");
	 struct metal_led *led0_red, *led0_green, *led0_blue;
	 led0_red = metal_led_get_rgb("LD0", "red");
	 led0_green = metal_led_get_rgb("LD0", "green");
	 metal_led_enable(led0_red);
	 metal_led_enable(led0_green);
	 delay(1);

	 metal_led_off(led0_green); //LED HIGH
	 metal_led_on(led0_red);    //LED LOW

//	 metal_led_off(led0_green);
//	 metal_led_off(led0_red);
/*
	 while(a>0){
	 metal_led_enable(led0_red);
     printf("Red\n");
	 metal_led_on(led0_green);
     delay(1);
	 metal_led_on(led0_red);
	 metal_led_enable(led0_red);
     printf("Green\n");
	 a--;
     }
*/
     printf("Over\n");
	return 0;
}

void delay(int sec){

uint64_t ticks = sec * RTC_FREQ;
mtime_wait(ticks);
}
void mtime_wait( uint64_t ticks)
{
//volatile uint64_t * mtime  = (uint64_t*) (CLINT_CTRL_ADDR +CLINT_MTIME);
volatile uint64_t * mtime  = (uint64_t*) (CLINT_MTIME);
uint64_t now = *mtime;
uint64_t then = now + ticks;
  while(*mtime<then) {
  }
}

