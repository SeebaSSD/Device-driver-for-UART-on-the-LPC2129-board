#ifndef MOCK_LPC2129_REGACC_H
#define MOCK_LPC2129_REGACC_H

#include <stdint.h>

/* Simulated UART registers as variables (PC memory) */
extern volatile uint8_t U0RBR;  // Receive Buffer Register
extern volatile uint8_t U0THR;  // Transmit Holding Register
extern volatile uint8_t U0DLL;  // Divisor Latch LSB
extern volatile uint8_t U0DLM;  // Divisor Latch MSB
extern volatile uint8_t U0LCR;  // Line Control Register
extern volatile uint8_t U0LSR;  // Line Status Register

/* Masks and bit positions (same as your original file) */
#define U0LSR_THRE_MASK 0x20
#define U0LSR_BI_MASK   0x10
#define U0LSR_FE_MASK   0x08
#define U0LSR_PE_MASK   0x04
#define U0LSR_OE_MASK   0x02
#define U0LSR_RDR_MASK  0x01

#define U0LSR_THRE_LPOS 5
#define U0LSR_BI_LPOS   4
#define U0LSR_FE_LPOS   3
#define U0LSR_PE_LPOS   2
#define U0LSR_OE_LPOS   1
#define U0LSR_RDR_LPOS  0

#define U0LCR_DLAB_MASK       0x80
#define U0LCR_PARITY_MASK     0x38
#define U0LCR_STOP_BIT_MASK   0x04
#define U0LCR_DATA_LEN_MASK   0x03

#define U0LCR_DLAB_LPOS       7
#define U0LCR_PARITY_LPOS     3
#define U0LCR_STOP_BIT_LPOS   2
#define U0LCR_DATA_LEN_LPOS   0

/* Macros for LSR reading */
#define LSR_THRE_RD(val)  (val = (U0LSR & U0LSR_THRE_MASK) >> U0LSR_THRE_LPOS)
#define LSR_BI_RD(val)    (val = (U0LSR & U0LSR_BI_MASK) >> U0LSR_BI_LPOS)
#define LSR_FE_RD(val)    (val = (U0LSR & U0LSR_FE_MASK) >> U0LSR_FE_LPOS)
#define LSR_PE_RD(val)    (val = (U0LSR & U0LSR_PE_MASK) >> U0LSR_PE_LPOS)
#define LSR_OE_RD(val)    (val = (U0LSR & U0LSR_OE_MASK) >> U0LSR_OE_LPOS)
#define LSR_RDR_RD(val)   (val = (U0LSR & U0LSR_RDR_MASK) >> U0LSR_RDR_LPOS)

/* Macros for LCR writing */
#define LCR_DLAB_WR(val)      (U0LCR = (U0LCR & ~U0LCR_DLAB_MASK) | ((val << U0LCR_DLAB_LPOS) & U0LCR_DLAB_MASK))
#define LCR_PARITY_WR(val)    (U0LCR = (U0LCR & ~U0LCR_PARITY_MASK) | ((val << U0LCR_PARITY_LPOS) & U0LCR_PARITY_MASK))
#define LCR_STOP_BIT_WR(val)  (U0LCR = (U0LCR & ~U0LCR_STOP_BIT_MASK) | ((val << U0LCR_STOP_BIT_LPOS) & U0LCR_STOP_BIT_MASK))
#define LCR_DATA_LEN_WR(val)  (U0LCR = (U0LCR & ~U0LCR_DATA_LEN_MASK) | ((val << U0LCR_DATA_LEN_LPOS) & U0LCR_DATA_LEN_MASK))

/* Macros for LCR reading */
#define LCR_DATA_LEN_RD(val)  (val = (U0LCR & U0LCR_DATA_LEN_MASK) >> U0LCR_DATA_LEN_LPOS)

#endif