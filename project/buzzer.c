#include <msp430.h>
#include "timerLib/libTimer.h"
#include "buzzer.h"
#include <stdio.h>
#include <stdlib.h>

#define E7 2637
#define C7 2093
#define G7 4049
#define G6 1568
#define E6 1319
#define A6 1760
#define B6 1976
#define AS6 1865
#define D7 2349
#define F7 2794
#define A7 3520

void buzzer_init() {
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles) {
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void marioTheme(){
  timerAUpmode();
  //turn buzzers off and on
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;
  //song notes
  int super_mario[] =
    {E7, E7, 0, E7, 0, C7, E7, 0, G7, 0, 0, 0, G6, 0, 0, 0, C7, 0, 0, G6, 0, 0, E6, 0, 0, A6, 0,
     B6, 0, AS6, A6, 0, G6, E7, G7, A7, 0, F7, G7, 0, E7, 0, C7, D7, B6, 0, 0, C7, 0, 0, G6, 0, 0,
     E6, 0, 0, A6, 0, B6, 0, AS6, A6, 0, G6, E7, G7, A7, 0, F7, G7, 0, E7, 0, C7, D7, B6, 0, 0};
  int keys = 0;
  for (int i = 0; i < 80; i++) {
    keys = super_mario[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    //turn buzzer off
    P2SEL &= ~BIT7;
  }
  //turn buzzer off
  P2DIR &= ~BIT6;
}
