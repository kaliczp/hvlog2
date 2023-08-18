ARMGNU = arm-none-eabi

AOPS = --warn --fatal-warnings -mcpu=cortex-m0plus
COPS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0plus -march=armv6-m

all : hvlog2.bin

clean:
	rm -f *.bin
	rm -f *.o
	rm -f *.elf
	rm -f *.list

flash.o : flash.s
	$(ARMGNU)-as $(AOPS) flash.s -o flash.o

hvlog2.o : hvlog2.c
	$(ARMGNU)-gcc $(COPS) -mthumb -c hvlog2.c -o hvlog2.o

hvlog2.bin : flash.ld flash.o hvlog2.o
	$(ARMGNU)-ld -o hvlog2.elf -T flash.ld flash.o hvlog2.o
	$(ARMGNU)-objdump -D hvlog2.elf > hvlog2.list
	$(ARMGNU)-objcopy hvlog2.elf hvlog2.bin -O binary
