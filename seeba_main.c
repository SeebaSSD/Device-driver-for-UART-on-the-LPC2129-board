#include <stdio.h>
#include "seeba_uart.h"

int main()
{
    unsigned char tx_data;
    unsigned char rx_data;
    int mode;
    int timeout;

    // UART Configuration
    configure_baudrate(9600, 1.843);
    configure_data_width(7);
    configure_stop_bit(1);
    configure_parity(2);

    printf("Select UART Mode\n");
    printf("1 -> Transmitter\n");
    printf("2 -> Receiver\n");
    scanf("%d", &mode);

    switch(mode)
    {
        case 1:   // Transmitter
        {
            printf("Enter character to transmit: "); 
            scanf(" %c", &tx_data); 
            timeout = 10;

            while(timeout > 0)
            {
                if(transmit_data(tx_data) == 0)   // success
                {
                    printf("Data transmitted: %c\n", tx_data);
                    break;
                }

                timeout--;
            }

            if(timeout == 0)
            {
                printf("Transmission timeout error\n");
                return 1;
            }

            break;
        }

        case 2:   // Receiver
        {
            timeout = 10;

            while(timeout > 0)
            {
                if(receive_data(&rx_data) == 0)   // data received
                {
                    printf("Received data: %c\n", rx_data);
                    break;
                }

                timeout--;
            }

            if(timeout == 0)
            {
                printf("Receive timeout error\n");
                return 1;
            }

            break;
        }

        default:
            printf("Invalid Mode\n");
            return 1;
    }

    return 0;
}

