void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void dummy ( unsigned int );

#define GPIOABASE 0x50000000
#define RCCBASE   0x40021000

int notmain ( void )
{
    unsigned int ra;

    ra=GET32(RCCBASE+0x2C);
    ra|=1<<2; //enable port c
    PUT32(RCCBASE+0x18,ra);
    //moder
    ra=GET32(GPIOABASE+0x00);
    ra&=~(3<<16); //PA8
    ra|=1<<16; //PA8 output
    PUT32(GPIOABASE+0x00,ra);
    //OTYPER
    ra=GET32(GPIOABASE+0x04);
    ra&=~(1<<8); //PA8
    PUT32(GPIOABASE+0x04,ra);
    while(1)
    {
        PUT32(GPIOABASE+0x18,1<<(8+0));
        for(ra=0;ra<200000;ra++) dummy(ra);
        PUT32(GPIOABASE+0x18,1<<(8+16));
        for(ra=0;ra<200000;ra++) dummy(ra);
    }
    return(0);
}
