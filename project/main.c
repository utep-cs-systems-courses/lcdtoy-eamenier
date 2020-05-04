#include <msp430.h>
#include "timerLib/libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <shape.h>
#include <abCircle.h>
#include "shapemotion.h"
#include <stdio.h>
#include <stdlib.h>

void main(void){
  configureClocks();
  switch_init(15);
  lcd_init();
  setScreen();
   
  or_sr(0x8);
}
