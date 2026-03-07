#ifndef LPC2129_REGACC_H

#define LPC2129_REGACC_H

#include <stdint.h>

#define U0RBR (*((volatile unsigned char *) 0xE000C000))
#define U0THR (*((volatile unsigned char *) 0xE000C000))
#define U0DLL (*((volatile unsigned char *) 0xE000C000))
#define U0DLM (*((volatile unsigned char *) 0xE000C004))
#define U0LCR (*((volatile unsigned char *) 0xE000C00C))
#define U0LSR (*((volatile unsigned char *) 0xE000C014))

/* Register field MASK macros */
#define U0LSR_THRE_MASK 0x20
#define U0LSR_BI_MASK 0x10
#define U0LSR_FE_MASK 0x8
#define U0LSR_PE_MASK 0x4
#define U0LSR_OE_MASK 0x2
#define U0LSR_RDR_MASK 0x1
#define U0LCR_DLAB_MASK 0x80
#define U0LCR_PARITY_MASK 0x38
#define U0LCR_STOP_BIT_MASK 0x4
#define U0LCR_DATA_LEN_MASK 0x3


/* Register field LPOS macros */
#define U0LSR_THRE_LPOS 5
#define U0LSR_BI_LPOS 4
#define U0LSR_FE_LPOS 3
#define U0LSR_PE_LPOS 2
#define U0LSR_OE_LPOS 1
#define U0LSR_RDR_LPOS 0
#define U0LCR_DLAB_LPOS 7
#define U0LCR_PARITY_LPOS 3
#define U0LCR_STOP_BIT_LPOS 2
#define U0LCR_DATA_LEN_LPOS 0

/**********************************************************
 * Macros to read from the different bits (fields) in LSR 
 *********************************************************/

#define LSR_THRE_RD(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LSR));\
  val = (tval & U0LSR_THRE_MASK) >> U0LSR_THRE_LPOS;\
} while(0)

#define LSR_BI_RD(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LSR));\
  val = (tval & U0LSR_BI_MASK) >> U0LSR_BI_LPOS;\
} while(0)

#define LSR_FE_RD(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LSR));\
  val = (tval & U0LSR_FE_MASK) >> U0LSR_FE_LPOS;\
} while(0)

#define LSR_PE_RD(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LSR));\
  val = (tval & U0LSR_PE_MASK) >> U0LSR_PE_LPOS;\
} while(0)

#define LSR_OE_RD(val) do {\
  uint8_t tval = (unit8_t)(*(volatile uint8_t *)(U0LSR));\
  val = (tval & U0LSR_OE_MASK) >> U0LSR_OE_LPOS;\
} while(0)

#define LSR_RDR_RD(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LSR));\
  val = (tval & U0LSR_RDR_MASK) >> U0LSR_RDR_LPOS;\
} while(0)

/**********************************************************
 * Macros to write to the different bits (fields) in LCR 
 *********************************************************/

#define LCR_DLAB_WR(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LCR));\
  tval = (tval & ~U0LCR_DLAB_MASK) | (val << U0LCR_DLAB_LPOS);\
  *(uint8_t *)(U0LCR) = tval;\
} while(0)

#define LCR_PARITY_WR(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LCR));\
  tval = (tval & ~U0LCR_PARITY_MASK) | (val << U0LCR_PARITY_LPOS);\
  *(uint8_t *)(U0LCR) = tval;\
} while(0)

#define LCR_STOP_BIT_WR(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LCR));\
  tval = (tval & ~U0LCR_STOP_BIT_MASK) | (val << U0LCR_STOP_BIT_LPOS);\
  *(uint8_t *)(U0LCR) = tval;\
} while(0)

#define LCR_DATA_LEN_WR(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LCR));\
  tval = (tval & ~U0LCR_DATA_LEN_MASK) | (val << U0LCR_DATA_LEN_LPOS);\
  *(uint8_t *)(U0LCR) = tval;\
} while(0)

/**********************************************************
 * Macros to read from the different bits (fields) in LCR 
 *********************************************************/
#define LCR_DATA_LEN_RD(val) do {\
  uint8_t tval = (uint8_t)(*(volatile uint8_t *)(U0LCR));\
  tval = (tval & U0LCR_DATA_LEN_MASK) >> U0LCR_DATA_LEN_LPOS;\
  val = tval;\
} while(0)

#endif
