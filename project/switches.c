#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "lcddraw.h"
#include "lcdutils.h"
#include "shapemotion.h"
#include <libTimer.h>

void marioTheme();

static unsigned char switches_current, switch_state_changed, switch_mask, switches_last_reported;

int state = 0;

static void switch_update_interrupt_sense() {
  switches_current = P2IN & switch_mask;
  P2IES |= (switches_current);
  P2IES &= (switches_current | ~switch_mask);
}

void switch_init(unsigned char mask) {
  switch_mask = mask;
  P2REN |= mask;
  P2IE = mask;
  P2OUT |= mask;
  P2DIR &= ~mask;
  switch_update_interrupt_sense();
}

unsigned int p2sw_read() {
  unsigned int sw_changed = switches_current ^ switches_last_reported;
  switches_last_reported = switches_current;
  return switches_current | (sw_changed << 8);
}

void switch_interrupt_handler() {
  if (switch_state_changed) {
    unsigned int switches = p2sw_read(), i;
    char str[5];
    for (i=0; i < 4; i++) {
      str[i] = (switches & (1 << i)) ? '-' : '0' + i;
    }
    str[4] = 0;

    if(str[0] != '-') {
      state = 01;
      switch_state_machine(state);
    }
    else if (str[1] != '-') {
      state = 02;
      switch_state_machine(state);
    }
    else if (str[2] != '-') {
      state = 03;
      switch_state_machine(state);
    }
    else if (str[3] != '-') {
      state = 04;
      switch_state_machine(state);
    }
    switch_state_changed = 0;
  }
}

void switch_state_machine(int state) {
  switch(state) {
  case 01:
    switch_state_changed = 1;
    marioTheme();
    break;
  case 02:
    switch_state_changed = 1;
    movScreen();
    break;
  case 03:
    switch_state_changed = 1;
    //drawChar5x7(20,20, "Got Interrupt?",COLOR_YELLOW, COLOR_BLACK);
    break;
  case 04:
    switch_state_changed = 1;
    movScreen();
    break;
  default:

    break;
  }      
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if(P2IFG & switch_mask) {
    P2IFG &= ~switch_mask;
    switch_state_changed = 1;
    switch_update_interrupt_sense();
    switch_interrupt_handler();
  }
}
