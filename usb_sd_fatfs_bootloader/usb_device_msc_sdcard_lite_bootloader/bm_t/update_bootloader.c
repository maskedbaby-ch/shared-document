/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "fsl_sd.h"
#include "fsl_debug_console.h"
#include "ff.h"
#include "diskio.h"
#include "fsl_sd_disk.h"
#include "board.h"
#include "fsl_flash.h"

#include "fsl_sysmpu.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "update_bootloader.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* buffer size (in byte) for read/write operations */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief wait card insert function.
 */

/*******************************************************************************
 * Variables
 ******************************************************************************/
static flash_config_t s_flashDriver;
static ftfx_cache_config_t s_cacheDriver;

/*******************************************************************************
 * Code
 ******************************************************************************/

void deinit()
{
	__disable_irq();
	// Disable the timer and interrupts from it
    SysTick->CTRL = SysTick->CTRL & ~(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
    // Clear the current value register
    SysTick->VAL = 0;
	SCB->VTOR = 0;
	CLOCK_ExternalModeToFbeModeQuick();
	CLOCK_BootToFeiMode(kMCG_Dmx32Default,kMCG_DrsLow,NULL);
	SIM->SCGC5 = SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTC_MASK|SIM_SCGC5_PORTD_MASK|SIM_SCGC5_PORTE_MASK;
	__enable_irq();
}
void jumptoApp()
{
//	SD_Deinit(&g_sd);
//	DbgConsole_Deinit();
	deinit();
	static void (*farewellBootloader)(void) = 0;
    farewellBootloader = (void (*)(void))(APP_VECTOR_TABLE[1]);
	__set_MSP(APP_VECTOR_TABLE[0]);
    __set_PSP(APP_VECTOR_TABLE[0]);
	SCB->VTOR = (uint32_t)APP_VECTOR_TABLE;

	farewellBootloader();	
}

int update_bootloader(FIL *g_fileObject)
{
	assert(g_fileObject);
//    FRESULT error;
    volatile bool failedFlag           = false;
	uint8_t rBuff[4096] = {0};
	
	memset(&s_flashDriver,0,sizeof(flash_config_t));
	memset(&s_cacheDriver ,0,sizeof(ftfx_cache_config_t));
	SYSMPU_Enable(SYSMPU, false);
//	uint32_t addrValue = 0;
	
//	addrValue = *((uint32_t*)(0xa000)); //if the 0xa000 has the app address
//	if(addrValue != 0xffffffff)
//	{
//		jumptoApp();
//	}

	uint32_t fileSize = g_fileObject->obj.objsize; //get file size
	uint32_t readSize;
	uint32_t regPrimask = DisableGlobalIRQ();
	InitAndErase(&s_flashDriver,&s_cacheDriver,BL_APP_VECTOR_TABLE_ADDRESS,4096*50);//erase 200kb
	EnableGlobalIRQ(regPrimask);
	if(fileSize > 4096U) // file size >4k
	{
		uint32_t remainSize = fileSize;
		uint32_t sectorNum = BL_APP_VECTOR_TABLE_ADDRESS / 4096 ;    //0xa000 sector_10
		while(remainSize > 0U) //the left byte
		{
			if(remainSize >= 4096U) //if the remain size >= 4k,read 4kb ,then program 4kb
			{
				f_read(g_fileObject,rBuff,4096U,&readSize);
				regPrimask = DisableGlobalIRQ();
				programFlash(&s_flashDriver,&s_cacheDriver,sectorNum*4096U,rBuff,readSize);
				EnableGlobalIRQ(regPrimask);
			}
			if(remainSize < 4096U) //remain size <4k ,judge if align with 8 byte
			{
				f_read(g_fileObject,rBuff,remainSize,&readSize);
				while((readSize&((uint8_t)0x07))!=0)
				{
					readSize++;
				}
				regPrimask = DisableGlobalIRQ();
				programFlash(&s_flashDriver,&s_cacheDriver,sectorNum*4096U,rBuff,readSize);
				EnableGlobalIRQ(regPrimask);
				break;
			}
			memset(rBuff,0,4096); // clear the buff
			sectorNum++;         //sector num adds
			remainSize -= 4096U;
		}
	}
	if(fileSize <= 4096U)
	{
		f_read(g_fileObject,rBuff,g_fileObject->obj.objsize,&readSize);
		while((readSize&((uint8_t)0x07))!=0)
		{
			readSize++;
		}
		regPrimask = DisableGlobalIRQ();
		programFlash(&s_flashDriver,&s_cacheDriver,BL_APP_VECTOR_TABLE_ADDRESS,rBuff,readSize);
		EnableGlobalIRQ(regPrimask);
	}
	return 0;
}


void error_trap(void)
{
//  PRINTF("TRAP\r\n");
  while(1);
}
void app_final(void)
{
//  PRINTF("END OF PROGRAM\r\n");
  while(1); 
}
void checkStatus(status_t result)
{
    if(kStatus_FTFx_Success != result)
    {
      error_trap();
    }
}

static void InitAndErase(   flash_config_t        *my_flash_config,
                     ftfx_cache_config_t   *my_flash_cache,
                     uint32_t               destAdrss,
                     uint32_t               size)
{
    assert(size%4096 == 0);
    uint32_t pflashBlockBase  = 0;
    uint32_t pflashTotalSize  = 0;
    uint32_t pflashSectorSize = 0;
	uint32_t sectorNum = 0;
    ftfx_security_state_t my_security_state = kFTFx_SecurityStateNotSecure;
    status_t result;
    /*init flash*/
    result = FLASH_Init(my_flash_config);
    checkStatus(result);
    /*init cache*/
    result = FTFx_CACHE_Init(my_flash_cache);
    checkStatus(result);
    
    /*get flash property*/
    FLASH_GetProperty(my_flash_config, kFLASH_PropertyPflash0BlockBaseAddr,&pflashBlockBase);
    FLASH_GetProperty(my_flash_config, kFLASH_PropertyPflash0TotalSize,    &pflashTotalSize);
    FLASH_GetProperty(my_flash_config, kFLASH_PropertyPflash0SectorSize,   &pflashSectorSize);  
    
    /*get security status*/
    result = FLASH_GetSecurityState(my_flash_config,&my_security_state);
    checkStatus(result);
    
    /*Test flash when flah is unsecure*/
    if(kFTFx_SecurityStateNotSecure == my_security_state)
    {
      FTFx_CACHE_ClearCachePrefetchSpeculation(my_flash_cache,true);
//      PRINTF("\r\n ERASE a sector");
		while(sectorNum < (size/4096))
		{
		  result = FLASH_Erase(my_flash_config,destAdrss+sectorNum*4096,pflashSectorSize,kFTFx_ApiEraseKey);
		  checkStatus(result);
		  
		  /*verify if erase*/
		  result = FLASH_VerifyErase(my_flash_config,destAdrss+sectorNum*4096,pflashSectorSize,kFTFx_MarginValueUser);
		  checkStatus(result);
		  sectorNum++;
		}
     // PRINTF("Erase the sector from 0x%x----0x%x\r\n",destAdrss,destAdrss+pflashSectorSize);
    }
    else
    {
 //     PRINTF("Nothing will happen,as flash is security\r\n");
    } 
}
static void programFlash(   flash_config_t        *my_flash_config,
                     ftfx_cache_config_t   *my_flash_cache,
                     uint32_t               destAdrss,
                     uint8_t               *data,
                     uint32_t               dataSize)
{
	 status_t result;
	 uint32_t failAddr, failDat;
	 /*program*/
      result = FLASH_Program(my_flash_config,destAdrss,data,dataSize);
      checkStatus(result);
      /*verify if program*/
      result = FLASH_VerifyProgram(my_flash_config,destAdrss,dataSize,data,kFTFx_MarginValueUser,&failAddr, &failDat);
      checkStatus(result);
      FTFx_CACHE_ClearCachePrefetchSpeculation(my_flash_cache, false);
}
