#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"

static void irqhandler (void * context, alt_u32 id)
{

}


int main()
{
	int data = 0x01;
    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE,0x01);
	usleep(60000);

	while(1)
	{		
		while(data != 0x200) 
		{
			data = data<<1;
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE,data);
			usleep(60000);	
		}
		
		while(data != 0x01) 
		{
			data = data>>1;
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE,data);
			usleep(60000);	
		}
	}
	return 0;
}