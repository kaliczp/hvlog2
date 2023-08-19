void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void dummy ( unsigned int );

#define GPIOABASE 0x50000000
#define RCCBASE   0x40021000

int notmain ( void ) {
    unsigned int ra;

    ra=GET32(RCCBASE+0x2C);
    ra|=1<<0; //enable port A
    PUT32(RCCBASE+0x2C,ra);
    ra=GET32(RCCBASE+0x3C);
    ra|=1<<0; //enable port A during sleep
    PUT32(RCCBASE+0x3C,ra);
    //moder
    ra=GET32(GPIOABASE+0x00);
    ra&=~(3<<0); //PA0
    ra|=1<<0; //PA0 output 01
    PUT32(GPIOABASE+0x00,ra);
    //OTYPER
    ra=GET32(GPIOABASE+0x04);
    ra&=~(1<<0); //PA0 push-pull
    PUT32(GPIOABASE+0x04,ra);
    while(1) {
        PUT32(GPIOABASE+0x18,1<<(0+0));
        for(ra=0;ra<200000;ra++) dummy(ra);
        PUT32(GPIOABASE+0x18,1<<(0+16));
        for(ra=0;ra<200000;ra++) dummy(ra);
    }
    return(0);
}
