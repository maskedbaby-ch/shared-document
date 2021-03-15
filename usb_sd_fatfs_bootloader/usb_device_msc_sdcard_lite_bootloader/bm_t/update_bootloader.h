#ifndef UPDATE_BOOTLOAADER
#define UPDATE_BOOTLOAADER

#include "fsl_sd.h"
#include "ff.h"
#include "fsl_flash.h"

#define BUFFER_SIZE (100U)
#define BL_APP_VECTOR_TABLE_ADDRESS 0xa000
#define APP_VECTOR_TABLE ((uint32_t *)BL_APP_VECTOR_TABLE_ADDRESS)

void deinit(void);
void jumptoApp(void);
int  update_bootloader(FIL *g_fileObject);
void error_trap(void);
void app_final(void);
void checkStatus(status_t result);
static void InitAndErase(   flash_config_t        *my_flash_config,
                     ftfx_cache_config_t   *my_flash_cache,
                     uint32_t               destAdrss,
                     uint32_t               size);
static void programFlash(   flash_config_t        *my_flash_config,
                     ftfx_cache_config_t   *my_flash_cache,
                     uint32_t               destAdrss,
                     uint8_t               *data,
                     uint32_t               dataSize);

#endif
