#include "seeba_uart.h"
#include "lpc2129_regacc.h"

/**
 * Configure UART baudrate
 */
void configure_baudrate(unsigned int baud, float clock)
{
    unsigned int divisor;
    unsigned char dll_val;
    unsigned char dlm_val;
    float clk_hz;

    clk_hz = clock * 1000000;

    divisor = (unsigned int)(clk_hz / (baud * 16));

    dll_val = divisor & 0xFF;
    dlm_val = (divisor >> 8) & 0xFF;

    /* Enable divisor latch access */
    LCR_DLAB_WR(1);

    U0DLL = dll_val;
    U0DLM = dlm_val;

    /* Disable divisor latch access */
    LCR_DLAB_WR(0);
}


/**
 * Configure UART data width
 */
void configure_data_width(unsigned int data_bits)
{
    switch(data_bits)
    {
        case 5:LCR_DATA_LEN_WR(0); break;
        case 6:LCR_DATA_LEN_WR(1); break;
        case 7:LCR_DATA_LEN_WR(2); break;
        case 8:LCR_DATA_LEN_WR(3); break;
        default: LCR_DATA_LEN_WR(3); break;
    }
}


/**
 * Configure stop bits
 */
void configure_stop_bit(float stop_bits)
{
    if(stop_bits == 2)
    {
        LCR_STOP_BIT_WR(1);
    }
    else
    {
        LCR_STOP_BIT_WR(0);
    }
}


/**
 * Configure parity
 */
void configure_parity(unsigned int parity)
{
    switch(parity)
    {
        case 1: /* odd parity */
            LCR_PARITY_WR(1);
            break;

        case 2: /* even parity */
            LCR_PARITY_WR(3);
            break;

        case 0: /* no parity */
        default:
            LCR_PARITY_WR(0);
            break;
    }
}


/**
 * Transmit one byte
 */
void transmit_data(unsigned char data)
{
    unsigned char thre;
    int timeout = 100000;

    do
    {
        LSR_THRE_RD(thre);

        timeout--;

        if(timeout == 0)
        {
            return ;
        }

    } while(thre == 0);

    U0THR = data;

    return ;
}


/**
 * Receive one byte
 */
int receive_data(unsigned char *data)
{
    unsigned char rdr,bi,fe,pe,oe;
    int timeout = 100000;

    do
    {
        LSR_RDR_RD(rdr);

        timeout--;

        if(timeout <= 0)
        {
            return -1;
        }

    } while(rdr == 0);

    *data = U0RBR;
		LSR_BI_RD(bi);
    LSR_FE_RD(fe);
    LSR_PE_RD(pe);
    LSR_OE_RD(oe);
    if(bi || fe || pe || oe) 
        return 1;
    else
        return 0;

}