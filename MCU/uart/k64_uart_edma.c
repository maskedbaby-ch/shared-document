/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "fsl_uart_edma.h"
#include "fsl_dmamux.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* UART instance and clock */

#define UART_TX_DMA_CHANNEL 0U
#define UART_RX_DMA_CHANNEL 1U
#define UART_TX_DMA_REQUEST kDmaRequestMux0UART0Tx
#define UART_RX_DMA_REQUEST kDmaRequestMux0UART0Rx
#define ECHO_BUFFER_LENGTH 1024
#define BUFFER_TX_LENGTH 10
#define BUFFER_RX_LENGTH 31
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
 typedef struct {   
    uint32_t uart;
    volatile uint8_t buffer[ECHO_BUFFER_LENGTH];
    volatile bool txDone;
	volatile bool rxDone;
    bool initialized;
    uart_edma_handle_t handle;
    edma_handle_t txHandle;
    edma_handle_t rxHandle;  

    uart_transfer_t rx;
    uart_transfer_t tx;
} uart_cfg_t;
 
typedef struct {
    UART_Type *base;
    uint32_t muxChan;
    uint32_t rxChan;
    uint32_t txChan;    
    uint32_t rxSrc;
    uint32_t txSrc;    
} uart_edma_cfg_t;
 
static const uart_edma_cfg_t uartParams[] = {
    {UART0, 0, UART_RX_DMA_CHANNEL, UART_TX_DMA_CHANNEL, kDmaRequestMux0UART0Rx, kDmaRequestMux0UART0Tx},
};

/* UART user callback */
void UART_UserCallback(UART_Type *base, uart_edma_handle_t *handle, status_t status, void *userData);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static uart_cfg_t uarts[1]; 

/*******************************************************************************
 * Code
 ******************************************************************************/
static void uart_rx_start (uint8_t uart, bool clear);
static void uart_cb (UART_Type *base, uart_edma_handle_t *handle, status_t status, void *userData);
void uart_write (uint8_t uart, const uint8_t *str, size_t len);
static void uart_cb (UART_Type *base, uart_edma_handle_t *handle, status_t status, void *userData);
uint8_t *uart_read (uint8_t uart, size_t *len);

void uart_open (uint8_t uart, uint32_t baudrateBps)
{  
    uart_config_t uart_cfg;
    edma_config_t edma_cfg;
    static bool initDmaMux = true;
    static bool initEdma = true;

    if (uarts[uart].initialized)
        return;
    uarts[uart].initialized = true;

    /* Initialize uart */
    UART_GetDefaultConfig(&uart_cfg);
    uart_cfg.baudRate_Bps = baudrateBps;
    uart_cfg.enableTx = true;
    uart_cfg.enableRx = true;
    UART_Init (uartParams[uart].base, &uart_cfg, CLOCK_GetFreq(UART0_CLK_SRC));    

    /* Initialize dmamux/edma */
    if (initDmaMux)
    {
        DMAMUX_Init (DMAMUX0);
        initDmaMux = false;
    }

    /* Ensure that DMAMUX default values are set */
    DMAMUX->CHCFG[uartParams[uart].muxChan] = 0;

    /* Configure channels */
    DMAMUX_SetSource(DMAMUX0, uartParams[uart].txChan, uartParams[uart].txSrc);
    DMAMUX_SetSource(DMAMUX0, uartParams[uart].rxChan, uartParams[uart].rxSrc);
    DMAMUX_EnableChannel(DMAMUX0, uartParams[uart].txChan);
    DMAMUX_EnableChannel(DMAMUX0, uartParams[uart].rxChan);    


    /* Initialize Edma */
    if (initEdma)
    {
        EDMA_GetDefaultConfig(&edma_cfg);
        EDMA_Init(DMA0, &edma_cfg);        
        initEdma = false;
    }
    EDMA_CreateHandle(&uarts[uart].txHandle, DMA0, uartParams[uart].txChan);
    EDMA_CreateHandle(&uarts[uart].rxHandle, DMA0, uartParams[uart].rxChan);

    /* Create dma handle */
    UART_TransferCreateHandleEDMA(uartParams[uart].base, &uarts[uart].handle, uart_cb, 
                                    (void*)uart, &uarts[uart].txHandle, &uarts[uart].rxHandle);

    /* Start free-running rx dma */
    uart_rx_start (uart, true);
}



/*!
 * @brief Main function
 */
int main(void)
{
	uint8_t* ptr;
	
	size_t length;
    BOARD_InitPins();
    BOARD_BootClockRUN();
	
	uart_open(0,115200);
	uint8_t tbuffer[] = {'A','B','\r','\n'};
	while(1)
	{
		uart_write(0,tbuffer,sizeof(tbuffer));
		SDK_DelayAtLeastUs(200000);
		ptr = uart_read (0,&length);
		
		uart_write(0,tbuffer,sizeof(tbuffer));
		SDK_DelayAtLeastUs(200000);
		ptr = uart_read (0,&length);
	}
}

static void uart_rx_start (uint8_t uart, bool clear)
{
    UART_TransferAbortReceiveEDMA(uartParams[uart].base, &uarts[uart].handle);
    if (clear)
        memset ((uint8_t*)&uarts[uart].buffer[0], 0, ECHO_BUFFER_LENGTH);
//    uarts[uart].rxDone = false;   
    uarts[uart].rx.data = &uarts[uart].buffer[0];
    uarts[uart].rx.dataSize = BUFFER_RX_LENGTH;
    UART_ReceiveEDMA(uartParams[uart].base, &uarts[uart].handle, &uarts[uart].rx);    
//	while (!uarts[uart].rxDone);
}

void uart_write (uint8_t uart, const uint8_t *str, size_t len)
{
    uart_rx_start (uart, false);

    if (len > 0)
    {
        uarts[uart].txDone = false;
        uarts[uart].tx.data = (uint8_t*)str;
        uarts[uart].tx.dataSize = len;

        UART_SendEDMA(uartParams[uart].base, &uarts[uart].handle, &uarts[uart].tx);        
        while (!uarts[uart].txDone);
    }
}

static void uart_cb (UART_Type *base, uart_edma_handle_t *handle, status_t status, void *userData)
{
    uint8_t uart = (uint8_t)(uintptr_t)userData;

    if (kStatus_UART_TxIdle == status)
    {
        /* Tx buffer transmitted */
        uarts[uart].txDone = true;
    }

    if (kStatus_UART_RxIdle == status)
    {
        uart_rx_start (uart, false);
    }
}

uint8_t *uart_read (uint8_t uart, size_t *len)
{
    uint8_t *head = (uint8_t*)&uarts[uart].buffer[0];
    uint8_t *tail = (uint8_t*)(uintptr_t)DMA0->TCD[uartParams[uart].rxChan].DADDR;
    *len = (size_t)(tail - head);

    //uint32_t count = 0;
    //status_t status = UART_TransferGetReceiveCountEDMA(uartParams[uart].base, &uarts[uart].handle, &count);

    return (uint8_t*)&uarts[uart].buffer[0];
}
