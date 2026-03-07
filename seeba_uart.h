/*
 * This is the header file containing the driver function declarations for
 * LPC2129's UART written by Seeba Doddmani
 */
 
#ifndef SEEBA_UART_H
#define SEEBA_UART_H

/**
 * @brief Configures the baud rate of the UART
 *
 * @param baud : the baud rate of the UART data to be transmitted
 * valid values: 50 ...128000
 * @param clock: the input clock frequency in MHz is from the crystal clock. 
 * valid values: 1.8432MHz, 3.072MHz, 18.432MHz
 *
 * @return none
 */
 
void configure_baudrate (unsigned int baud, float clock);

/**
 * @brief Configures the width (number of data bits) per UART frame
 *
 * @param data_bits : The number of data bits in the UART frame
 * valid values: 5, 6, 7, 8
 *
 * @return none
 */
void configure_data_width (unsigned int data_bits);

/**
 * @brief Configures the number of stop bits in UART 
 *
 * @param stop_bits : the number of stop bits to be transmitted
 * valid values: 1, 1.5, 2
 *
 * @return none
 */
void configure_stop_bit (float stop_bits);

/**
 * @brief Configures the parity mode of UART 
 *
 * @param parity : the parity type to be used
 * valid values: 0 = None, 1 = Odd, 2 = Even
 *
 * @return none
 */
void configure_parity(unsigned int parity);

/**
 * @brief Transmits a single byte of data over UART
 *
 * @param data : the byte to be transmitted
 * valid values: 0x00 to 0xFF
 *
 * @return : 0 for success
 *	    1 for failure
 */
 
int transmit_data(unsigned char data);

/**
* @brief receive data of the UART
* @param data : one byte of data to be received
* @return : 0 for success
*	    1 for failure
*
*/
int receive_data(unsigned char *data);

#endif
