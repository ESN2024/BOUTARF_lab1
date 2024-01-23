#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include <io.h>
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include <unistd.h>
#include <sys/alt_irq.h>

static void init_interrupt_pio();
static void led_chaser(int v);
static void irqhandler_bs(void *context, alt_u32 id);

volatile int edge_capture;
int v = 100000;

static void init_interrupt_pio()
{
    void *edge_capture_ptr = (void *)&edge_capture;
    // autoriser l interruption de 2bp et 4 swicths
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BS_BASE, 0x80F);

    // Reset le registre edge capture
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BS_BASE, 0x80F);
}

static void led_chaser(int t)
{
    int data = 0x01;
    IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, 0x01);
    usleep(v);

    while (data != 0x200)
    {
        data = data << 1;
        IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, data);
        usleep(v);
    }

    while (data != 0x01)
    {
        data = data >> 1;
        IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, data);
        usleep(v);
    }
}

static void irqhandler_bs(void *context, alt_u32 id)
{
    alt_u32 val = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BS_BASE);
    switch (val)
    {
    case 0x01:
        // Vitesse +
        v = 50000;
        break;
    case 0x02:
        // Vitesse ++
        v = 70000;
        break;
    case 0x04:
        // Vitesse +++
        v = 100000;
        break;
    case 0x08:
        // Vitesse ++++
        v = 17500;
        break;
    }
    if (val == 0x800)
    {
        led_chaser(v);
    
    }

    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BS_BASE, 0x3F);
}

int main()
{
    init_interrupt_pio();
    alt_ic_isr_register(BS_IRQ_INTERRUPT_CONTROLLER_ID, BS_IRQ, irqhandler_bs, NULL, NULL);

    while (1)
    {
    }
    return 0;
}
