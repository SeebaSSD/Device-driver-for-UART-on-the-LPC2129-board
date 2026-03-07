
#include "seeba_uart.h"
// #include "lpc2129_regacc.h"
#include "mock_lpc2129_regacc.h"

/**
 * @brief Configures the baud rate of the UART
 */
void configure_baudrate(unsigned int baud, float clock)
{
    unsigned int divisor;
    unsigned char dll_val;
    unsigned char dlm_val;
    float clk_hz;

    /* convert MHz to Hz */
    clk_hz = clock * 1000000;

    /* calculate divisor */
    divisor = (unsigned int)(clk_hz / (baud * 16));

    dll_val = divisor & 0xFF;
    dlm_val = (divisor >> 8) & 0xFF;

    /* enable DLAB */
    U0LCR |= (1 << 7);

    /* write divisor registers */
    U0DLL = dll_val;
    U0DLM = dlm_val;

    /* disable DLAB */
    U0LCR &= ~(1 << 7);
}

/**
 * @brief Configures UART data width
 */
void configure_data_width(unsigned int data_bits)
{
    unsigned char val = 0;

    /* clear bits 0 and 1 */
    U0LCR &= ~(0x03);

    switch(data_bits)
    {
        case 5:
            val = 0x00;
            break;

        case 6:
            val = 0x01;
            break;

        case 7:
            val = 0x02;
            break;

        case 8:
            val = 0x03;
            break;

        default:
            val = 0x03;
            break;
    }

    U0LCR |= val;
}

/**
 * @brief Configures stop bits
 */
void configure_stop_bit(float stop_bits)
{
    if(stop_bits == 2)
    {
        U0LCR |= (1 << 2);
    }
    else
    {
        /* default = 1 stop bit */
        U0LCR &= ~(1 << 2);
    }
}

/**
 * @brief Configures parity
 */
void configure_parity(unsigned int parity)
{
    /* clear parity bits (3 and 4) */
    U0LCR &= ~(0x18);

    switch(parity)
    {
        case 1: /* odd parity */
            U0LCR |= (1 << 3);
            break;

        case 2: /* even parity */
            U0LCR |= (1 << 3);
            U0LCR |= (1 << 4);
            break;

        case 0: /* no parity */
        default:
            break;
    }
}

/**
 * @brief Transmits a single byte of data
 */
int transmit_data(unsigned char data)
{
    int timeout = 100000;

    /* wait until THR empty (LSR bit 5) */
    while(!(U0LSR & (1 << 5)))
    {
        timeout--;

        if(timeout == 0)
        {
            return 1;
        }
    }

    /* write data to THR */
    U0THR = data;

    return 0;
}

/**
 * @brief Receives a single byte of data
 */
int receive_data(unsigned char *data)
{
    int timeout = 100000;

    /* wait until data ready (LSR bit 0) */
    while(!(U0LSR & (1 << 0)))
    {
        timeout--;

        if(timeout == 0)
        {
            return 1;
        }
    }

    /* read received byte */
    *data = U0RBR;

    return 0;
}

