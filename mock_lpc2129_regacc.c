#include "mock_lpc2129_regacc.h"

/* Define variables to simulate hardware registers */
volatile uint8_t U0RBR = 0;
volatile uint8_t U0THR = 0;
volatile uint8_t U0DLL = 0;
volatile uint8_t U0DLM = 0;
volatile uint8_t U0LCR = 0;
volatile uint8_t U0LSR = 0x20; // THR empty initially