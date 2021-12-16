#ifndef __W25QXX_H
#define __W25QXX_H

#include "fsl_dspi.h"
#include "fsl_port.h"
#include "fsl_gpio.h"

#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */

#define SPI0_CS_High   GPIO_PinWrite(GPIOD,0U,1);
#define SPI0_CS_Low    GPIO_PinWrite(GPIOD,0U,0);

#define EXAMPLE_DSPI_MASTER_BASEADDR SPI0
#define DSPI_MASTER_CLK_SRC DSPI0_CLK_SRC
#define DSPI_MASTER_CLK_FREQ CLOCK_GetFreq(DSPI0_CLK_SRC)
#define EXAMPLE_DSPI_MASTER_PCS_FOR_INIT kDSPI_Pcs0

#define EXAMPLE_DSPI_MASTER_PCS1_FOR_INIT kDSPI_Pcs1

#define EXAMPLE_DSPI_MASTER_PCS_FOR_TRANSFER kDSPI_MasterPcs0
#define EXAMPLE_DSPI_DEALY_COUNT 0xfffffU

#define TRANSFER_SIZE 64U         /*! Transfer dataSize */
#define TRANSFER_BAUDRATE 500000U /*! Transfer baudrate - 500k */

#define W25Q80         0X1451         
#define W25Q16         0XEF14
#define W25Q32         0XEF15
#define W25Q64         0XEF16
#define W25Q128        0XEF17

#define W25QXX_CS_Low  SPI0_CS_Low
#define W25QXX_CS_High SPI0_CS_High
extern uint16_t W25QXX_TYPE;                                                   
      
                                 
#define W25X_WriteEnable                0x06
#define W25X_WriteDisable                0x04
#define W25X_ReadStatusReg                0x05
#define W25X_WriteStatusReg                0x01
#define W25X_ReadData                        0x03
#define W25X_FastReadData                0x0B
#define W25X_FastReadDual                0x3B
#define W25X_PageProgram                0x02
#define W25X_BlockErase                        0xD8
#define W25X_SectorErase                0x20
#define W25X_ChipErase                        0xC7
#define W25X_PowerDown                        0xB9
#define W25X_ReleasePowerDown        0xAB
#define W25X_DeviceID                        0xAB
#define W25X_ManufactDeviceID        0x90
#define W25X_JedecDeviceID                0x9F

void SPI_Config(void);
uint16_t  W25QXX_ReadID(void);                           
uint8_t W25QXX_ReadByte(uint32_t ReadAdress);
void W25QXX_Read(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead);
uint8_t W25QXX_ReadSR(void) ;
void W25QXX_Write_SR(uint8_t sr);
void W25QXX_Write_Enable(void);
void W25QXX_Write_Disable(void);
void W25QXX_Write_Page(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite);
void W25QXX_Write_NoCheck(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite);
void W25QXX_Write(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite);
void W25QXX_Erase_Sector(uint32_t Dst_Addr);

#endif
