COMMON_OBJECTS	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h -L/opti/ti/msp430_gcc/include
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as
AR		= msp430-elf-ar

all: buzzBlink.elf

buzzBlink.elf:${COMMON_OBJECTS} main.o shapemotion.o p1_interrupt_handler.o switches.o buzzer.o  ../project/lib/libTimer.a
	${CC} $(CFLAGS) $(LDFLAGS) -o $@ $^ -lTimer -lLcd -lShape -lCircle

load: buzzBlink.elf
	msp430loader.sh buzzBlink.elf

clean:
	rm -f *.o *.elf

