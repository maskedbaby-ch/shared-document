#include "w25q.h"


void SPI_Config(void)
{
    dspi_master_config_t masterConfig;
    gpio_pin_config_t cs_config = {kGPIO_DigitalOutput, 1,};
    CLOCK_EnableClock ( kCLOCK_PortD);
	
	PORT_SetPinMux(PORTD, PIN0_IDX, kPORT_MuxAsGpio);            /* PORTD0 (pin 93) CS0 */
	PORT_SetPinMux(PORTD, PIN1_IDX, kPORT_MuxAlt2);            /* PORTD1 (pin 94) is configured as SPI0_SCK */
	PORT_SetPinMux(PORTD, PIN2_IDX, kPORT_MuxAlt2);            /* PORTD2 (pin 95) is configured as SPI0_SOUT */
	PORT_SetPinMux(PORTD, PIN3_IDX, kPORT_MuxAlt2);            /* PORTD3 (pin 96) is configured as SPI0_SIN */

    GPIO_PinInit (GPIOD,PIN0_IDX,&cs_config);
   

    /* Master config */
    masterConfig.whichCtar                                = kDSPI_Ctar0;
    masterConfig.ctarConfig.baudRate                      = TRANSFER_BAUDRATE;
    masterConfig.ctarConfig.bitsPerFrame                  = 8U;
    masterConfig.ctarConfig.cpol                          = kDSPI_ClockPolarityActiveHigh;
    masterConfig.ctarConfig.cpha                          = kDSPI_ClockPhaseFirstEdge;
    masterConfig.ctarConfig.direction                     = kDSPI_MsbFirst;
    masterConfig.ctarConfig.pcsToSckDelayInNanoSec        = 1000000000U / TRANSFER_BAUDRATE;
    masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec    = 1000000000U / TRANSFER_BAUDRATE;
    masterConfig.ctarConfig.betweenTransferDelayInNanoSec = 1000000000U / TRANSFER_BAUDRATE;

    masterConfig.whichPcs           = EXAMPLE_DSPI_MASTER_PCS_FOR_INIT;
    masterConfig.pcsActiveHighOrLow = kDSPI_PcsActiveLow;

    masterConfig.enableContinuousSCK        = false;
    masterConfig.enableRxFifoOverWrite      = false;
    masterConfig.enableModifiedTimingFormat = false;
    masterConfig.samplePoint                = kDSPI_SckToSin0Clock;
    DSPI_MasterInit(EXAMPLE_DSPI_MASTER_BASEADDR, &masterConfig, DSPI_MASTER_CLK_FREQ);
}


void SPI_Transfer(uint8_t *txData,uint8_t *rxData,uint8_t size)
{
    dspi_transfer_t masterXfer;
    masterXfer.txData = txData;
    masterXfer.rxData = rxData;
    masterXfer.dataSize = size;
    masterXfer.configFlags =  kDSPI_MasterPcsContinuous;//kDSPI_MasterCtar0 | kDSPI_MasterPcs0 |
    DSPI_MasterTransferBlocking(EXAMPLE_DSPI_MASTER_BASEADDR, &masterXfer);
}


uint8_t SPI_ReadWriteByte(uint8_t inData)
{
    uint8_t a = inData,b=0x00;
    SPI_Transfer(&a,&b,1);
    return b;
   
}

void W25QXX_Wait_Busy(void)   
{   
	while((W25QXX_ReadSR()&0x01)==0x01);                  
}  


uint16_t W25QXX_ReadID(void)
{
    uint16_t Temp = 0;
    SPI_ReadWriteByte (0x00);//
    W25QXX_CS_Low ;
    SPI_ReadWriteByte (0x90);
    SPI_ReadWriteByte (0x00);
    SPI_ReadWriteByte (0x00);
    SPI_ReadWriteByte (0x00);
    Temp|=SPI_ReadWriteByte(0xFF)<<8;  
    Temp|=SPI_ReadWriteByte(0xFF);
    W25QXX_CS_High;
    return Temp;
}  




uint8_t W25QXX_ReadSR(void)   
{  
	uint8_t byte=0;   
	SPI_ReadWriteByte (0x00);//   
	W25QXX_CS_Low;                            //
	SPI_ReadWriteByte(W25X_ReadStatusReg); // 
	byte=SPI_ReadWriteByte(0Xff);          //
	W25QXX_CS_High;                            //    
	return byte;   
}


void W25QXX_Write_SR(uint8_t sr)   
{   
	SPI_ReadWriteByte (0x00); //   
	W25QXX_CS_Low;                             //
	SPI_ReadWriteByte(W25X_WriteStatusReg);//
	SPI_ReadWriteByte(sr);                       //
	W25QXX_CS_High;                            //               
}   


void W25QXX_Write_Enable(void)   
{
    SPI_ReadWriteByte (0x00);  //  
    W25QXX_CS_Low;                                  //
    SPI_ReadWriteByte(W25X_WriteEnable);         //
    W25QXX_CS_High;                                     //    
}


void W25QXX_Write_Disable(void)   
{  
    SPI_ReadWriteByte (0x00);    
    W25QXX_CS_Low;                            
    SPI_ReadWriteByte(W25X_WriteDisable);    
    W25QXX_CS_High;                                            
}


void W25QXX_Read(uint8_t* pBuffer,uint32_t ReadAddr,uint16_t NumByteToRead)   
{
	uint16_t i;                                                                                       
	SPI_ReadWriteByte (0x00);  
	W25QXX_CS_Low;                                     
    SPI_ReadWriteByte(W25X_ReadData);                
    SPI_ReadWriteByte((uint8_t)((ReadAddr)>>16));           
    SPI_ReadWriteByte((uint8_t)((ReadAddr)>>8));   
    SPI_ReadWriteByte((uint8_t)ReadAddr);   
    for(i=0;i<NumByteToRead;i++)
    {
        *pBuffer++ = SPI_ReadWriteByte(0XFF);           
    }
	W25QXX_CS_High;                                                   
}  


void W25QXX_Write_Page(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)
{
    uint16_t i;  
    W25QXX_Write_Enable();                          
    SPI_ReadWriteByte (0x00);  
    W25QXX_CS_Low;                                    
    SPI_ReadWriteByte(W25X_PageProgram);             
    SPI_ReadWriteByte((uint8_t)((WriteAddr)>>16));         
    SPI_ReadWriteByte((uint8_t)((WriteAddr)>>8));   
    SPI_ReadWriteByte((uint8_t)WriteAddr);   
    for(i=0;i<NumByteToWrite;i++)
	{
		SPI_ReadWriteByte(*pBuffer++); 
	}
    W25QXX_CS_High;                                 
    W25QXX_Wait_Busy();                                                       
}


void W25QXX_Write_NoCheck(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)   
{                                          
	uint16_t pageremain;           
	pageremain=256-WriteAddr%256; //                         
	if(NumByteToWrite<=pageremain)pageremain=NumByteToWrite;//
	while(1)
	{           
		W25QXX_Write_Page(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)break;//
		 else //NumByteToWrite>pageremain
		{
			pBuffer += pageremain;
			WriteAddr += pageremain;        
			NumByteToWrite -= pageremain;                          //
			if(NumByteToWrite>256)
			{
				pageremain=256; //
			}
			else
			{							
				pageremain=NumByteToWrite;           //
			}
		}
	}          
}

uint8_t W25QXX_BUFFER[4096];                 
void W25QXX_Write(uint8_t* pBuffer,uint32_t WriteAddr,uint16_t NumByteToWrite)   
{
        uint32_t secpos;
        uint16_t secoff;
        uint16_t secremain;           
        uint16_t i;   
        uint8_t * W25QXX_BUF;         
        W25QXX_BUF=W25QXX_BUFFER;            
        secpos=WriteAddr/4096;
        secoff=WriteAddr%4096;
        secremain=4096-secoff;  

        if(NumByteToWrite<=secremain)secremain=NumByteToWrite;
        while(1)
        {        
			W25QXX_Read(W25QXX_BUF,secpos*4096,4096);
			for(i=0;i<secremain;i++)
			{
				if(W25QXX_BUF[secoff+i]!=0XFF) break;    
			}
			if(i<secremain)
			{
				W25QXX_Erase_Sector(secpos);                
				for(i=0;i<secremain;i++)                          
				{
						W25QXX_BUF[i+secoff] = *pBuffer++;         
				}
				W25QXX_Write_NoCheck(W25QXX_BUF,secpos*4096,4096);
			}
			else
			{				
				W25QXX_Write_NoCheck(pBuffer,WriteAddr,secremain);       
			}				
			if(NumByteToWrite==secremain)
			{
				break;
			}
			else
			{
				secpos++;
				secoff=0;        
				pBuffer += secremain;                                 
				WriteAddr += secremain;                                       
				NumByteToWrite -= secremain;                        
				if(NumByteToWrite>4096)secremain=4096;
				else
				{					
					secremain=NumByteToWrite;
				}					
			}         
        }       
}


void W25QXX_Erase_Chip(void)   
{                                   
    W25QXX_Write_Enable();                                
    W25QXX_Wait_Busy();   
    SPI_ReadWriteByte (0x00);   
    W25QXX_CS_Low;                                     
    SPI_ReadWriteByte(W25X_ChipErase);               
    W25QXX_CS_High;                                                     
    W25QXX_Wait_Busy();                                                     
}

void W25QXX_Erase_Sector(uint32_t Dst_Addr)   
{  
       
    Dst_Addr*=4096;
    W25QXX_Write_Enable();                           
    W25QXX_Wait_Busy();   
    SPI_ReadWriteByte (0x00);   
    W25QXX_CS_Low;                                     
    SPI_ReadWriteByte(W25X_SectorErase);            
    SPI_ReadWriteByte((uint8_t)((Dst_Addr)>>16));         
    SPI_ReadWriteByte((uint8_t)((Dst_Addr)>>8));   
    SPI_ReadWriteByte((uint8_t)Dst_Addr);  
    W25QXX_CS_High;                                                    
    W25QXX_Wait_Busy();                                                      
}  


void W25QXX_PowerDown(void)   
{
    SPI_ReadWriteByte (0x00); 
    W25QXX_CS_Low;                                           
    SPI_ReadWriteByte(W25X_PowerDown);      
    W25QXX_CS_High;                                                                          
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
}   


void W25QXX_WAKEUP(void)   
{  
	SPI_ReadWriteByte (0x00); 
	W25QXX_CS_Low;                                     
    SPI_ReadWriteByte(W25X_ReleasePowerDown);        //  send W25X_PowerDown command 0xAB   
    W25QXX_CS_High;                                          
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
}  
