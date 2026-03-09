#include <stdio.h>
#include "seeba_uart.h"
#define PINSEL0 (*((volatile unsigned int *)0xE002C000))
int main()
{
    unsigned char tx_data = 'B';
    unsigned char rx_data;
	  PINSEL0 |= 0x05;
   
    // UART Configuration
    configure_baudrate(9600, 1.843);
    configure_data_width(7);
    configure_stop_bit(1);
    configure_parity(2);
		transmit_data(tx_data);

	
	 while(1){
        int status=receive_data(&rx_data); // 1 = error & 0 = success.
        if(status==1){
            // Error in data
            break;
        }else if(status==0){
            // Data received succefully
            transmit_data(rx_data);
        }
    }

    return 0;
}
