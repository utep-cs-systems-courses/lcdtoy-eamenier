#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_changed;

void switch_state_machine(int state) {
  switch(state) {
  case 01:
    switch_state_changed = 1;
    blinkLEDS();
    marioTheme();

    break;
  case 02:
    switch_state_changed = 1;
    blinkLEDS();

    break;
  case 03:
    switch_state_changed = 1;
    blinkLEDS();

    break;
  case 04:
    switch_state_changed = 1;
    blinkLEDS();
    marioTheme();

    break;
  default:
    break;
  }
}
