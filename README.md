# UART Driver for LPC2129

## Overview

This project implements a **UART (Universal Asynchronous Receiver Transmitter) driver** for the **NXP LPC2129 ARM7 microcontroller** in C.  
The driver provides functions to configure UART parameters and perform **data transmission and reception**.

The implementation uses **register-level programming** through macros defined in `lpc2129_regacc.h`.

This project demonstrates:

- Low-level UART peripheral programming
- Memory-mapped register access
- Use of bit-field macros for safe register manipulation
- Simple transmit and receive APIs

---

## Features

- Configure UART baud rate
- Configure data width (5–8 bits)
- Configure stop bits
- Configure parity
- UART single byte transmission
- UART single byte reception
- Timeout protection for transmit and receive operations

---

## Project Structure
UART_ON_LPC2129_Board/

│

├── seeba_main.c # Application code

├── seeba_drv.c # UART driver implementation

├── seeba_uart.h # UART driver function declarations

├── lpc2129_regacc.h # Register access macros

└── README.md # Project documentation


---

## UART Configuration Functions

The driver provides the following configuration functions:

| Function | Description |
|--------|--------|
| `configure_baudrate()` | Sets UART baud rate |
| `configure_data_width()` | Sets number of data bits |
| `configure_stop_bit()` | Configures stop bits |
| `configure_parity()` | Configures parity mode |

---

## Data Transfer Functions

| Function | Description |
|--------|--------|
| `transmit_data()` | Sends one byte via UART |
| `receive_data()` | Receives one byte via UART |

Both functions implement a **timeout mechanism** to prevent infinite blocking.

---

# Running the Project

## Running the Project in Keil µVision Simulator

This project can be executed in the **Keil µVision simulator** for the LPC2129 microcontroller.

### Step 1: Create a new Keil project

Open **Keil µVision** and create a new project.

### Step 2: Select the target device

Select:
NXP → LPC2129


### Step 3: Add source files

Add the following files to the project:

seeba_main.c

seeba_drv.c

seeba_uart.h

lpc2129_regacc.h


### Step 4: Enable simulator

Go to:
Project → Options for Target → Debug


Select:


Use Simulator


### Step 5: Build the project

### Step 6: Start debugging

Go to:


Debug → Start/Stop Debug Session

### Step 7: Run the program


You can step through the code and inspect UART registers during execution.

---

## Example Flow

1. Configure UART settings  
2. Select transmit or receive mode  
3. Send or receive a byte  
4. Display success or timeout message  

---

## Concepts Demonstrated

- UART communication basics  
- Embedded C driver design  
- Register-level peripheral programming  
- Bit masking and shifting  
- Use of register access macros to abstract hardware register operations.
  
---

## Author

**Seeba Doddmani**
