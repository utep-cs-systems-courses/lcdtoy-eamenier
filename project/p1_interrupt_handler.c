#include <msp430.h>
#include "switches.h"
#include "led.h"

void __interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & switch_mask) {
    P1IFG &= ~switch_mask;
    switch_interrupt_handler();
  }
}
