/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MKW36Z512xxx4
package_id: MKW36Z512VHT4
mcu_data: ksdk2_0
processor_version: 0.0.4
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "board.h"

/*FUNCTION**********************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 *END**************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */
#define PIN17_IDX                       17u   /*!< Pin number for pin 17 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define SOPT5_LPUART0RXSRC_LPUART_RX  0x00u   /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX  0x00u   /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '42', peripheral: LPUART0, signal: RX, pin_signal: PTC6/LLWU_P14/RF_RFOSC_EN/I2C1_SCL/LPUART0_RX/TPM2_CH0/BSM_FRAME}
  - {pin_num: '43', peripheral: LPUART0, signal: TX, pin_signal: PTC7/LLWU_P15/SPI0_PCS2/I2C1_SDA/LPUART0_TX/TPM2_CH1/BSM_DATA, direction: OUTPUT}
  - {pin_num: '16', peripheral: I2C0, signal: CLK, pin_signal: PTB0/LLWU_P8/RF_RFOSC_EN/RF_RESET/I2C0_SCL/CMP0_OUT/TPM0_CH1/CLKOUT/CAN0_TX, slew_rate: fast, drive_strength: low,
    pull_select: up, pull_enable: enable}
  - {pin_num: '17', peripheral: I2C0, signal: SDA, pin_signal: ADC0_SE1/CMP0_IN5/PTB1/RF_PRIORITY/DTM_RX/I2C0_SDA/LPTMR0_ALT1/TPM0_CH2/CMT_IRO/CAN0_RX, slew_rate: fast,
    drive_strength: low, pull_select: up, pull_enable: enable}
  - {pin_num: '46', peripheral: I2C1, signal: CLK, pin_signal: PTC17/LLWU_P1/RF_EXT_OSC_EN/SPI0_SOUT/I2C1_SCL/LPUART0_RX/BSM_FRAME/DTM_RX/LPUART1_RX, slew_rate: fast,
    drive_strength: low, pull_select: up, pull_enable: enable}
  - {pin_num: '47', peripheral: I2C1, signal: SDA, pin_signal: PTC18/LLWU_P2/SPI0_SIN/I2C1_SDA/LPUART0_TX/BSM_DATA/DTM_TX/LPUART1_TX, slew_rate: fast, drive_strength: low,
    pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  const port_pin_config_t portb0_pin16_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt3,                                           /* Pin is configured as I2C0_SCL */
  };
  PORT_SetPinConfig(PORTB, PIN0_IDX, &portb0_pin16_config);  /* PORTB0 (pin 16) is configured as I2C0_SCL */
  const port_pin_config_t portb1_pin17_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt3,                                           /* Pin is configured as I2C0_SDA */
  };
  PORT_SetPinConfig(PORTB, PIN1_IDX, &portb1_pin17_config);  /* PORTB1 (pin 17) is configured as I2C0_SDA */
//  const port_pin_config_t portc17_pin46_config = {
//    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
//    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
//    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
//    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
//    kPORT_MuxAlt3,                                           /* Pin is configured as I2C1_SCL */
//  };
//  PORT_SetPinConfig(PORTC, PIN17_IDX, &portc17_pin46_config); /* PORTC17 (pin 46) is configured as I2C1_SCL */
//  const port_pin_config_t portc18_pin47_config = {
//    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
//    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
//    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
//    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
//    kPORT_MuxAlt3,                                           /* Pin is configured as I2C1_SDA */
//  };
//  PORT_SetPinConfig(PORTC, PIN18_IDX, &portc18_pin47_config); /* PORTC18 (pin 47) is configured as I2C1_SDA */
  PORT_SetPinMux(PORTC, PIN6_IDX, kPORT_MuxAlt4);            /* PORTC6 (pin 42) is configured as LPUART0_RX */
  PORT_SetPinMux(PORTC, PIN7_IDX, kPORT_MuxAlt4);            /* PORTC7 (pin 43) is configured as LPUART0_TX */


  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK))) /* Mask bits to zero which are setting */
      | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
      | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
    );

//  PORT_SetPinMux(PORTC, 1, kPORT_MuxAsGpio);
//  gpio_pin_config_t vBat = {kGPIO_DigitalOutput, 1};
//  GPIO_PinInit(GPIOC, 1, &vBat);


  /* Initialize NXPNCI GPIO pins below */
  /* IRQ and VEN PIN_MUX Configuration */
  PORT_SetPinMux(BOARD_NXPNCI_IRQ_PORT, BOARD_NXPNCI_IRQ_PIN, kPORT_MuxAsGpio);
  PORT_SetPinMux(BOARD_NXPNCI_VEN_PORT, NXPNCI_VEN_PIN, kPORT_MuxAsGpio);
  /* IRQ interrupt Configuration */
  NVIC_SetPriority(BOARD_NXPNCI_IRQ_PORTIRQn, 6);
  EnableIRQ(BOARD_NXPNCI_IRQ_PORTIRQn);
  PORT_SetPinInterruptConfig(BOARD_NXPNCI_IRQ_PORT, BOARD_NXPNCI_IRQ_PIN, kPORT_InterruptRisingEdge);
}

/*******************************************************************************
 * EOF
 ******************************************************************************/