/*
 * bB2xx_flash.c
 *
 *  Created on: Oct 29, 2021
 *      Author: fil
 */

#include "main.h"
#include <string.h>
#include <stdio.h>

FlashConfig_TypeDef		FlashConfig,ReadFlashConfig;
//SamplesConfig_TypeDef	SamplesConfig[NUMSAMPLES_F256];
uint32_t	flash_id;

uint8_t bB2xx_flash_identify(void)
{
	flash_id = w25qxx_ReadID();
	flash_id = w25qxx_ReadID();
	flash_id = w25qxx_ReadID();
	SystemParameters.flash_capacity = (uint8_t )(flash_id & 0xff);
	if ( SystemParameters.flash_capacity != F128 )
		return 1;

	FlashConfig.params_pointer = PARAMS_PTR_F128;
	FlashConfig.sample_pointer = SAMPLE_PTR_F128;
	FlashConfig.digitblue_pointer = BLUE_DIGIT_FPTR;
	FlashConfig.digitred_pointer = RED_DIGIT_FPTR;
	FlashConfig.digitgreen_pointer = GREEN_DIGIT_FPTR;
	FlashConfig.digityellow_pointer = YELLOW_DIGIT_FPTR;
	FlashConfig.splashimage_pointer = LOGO_FPTR;

	return 0;
	/*
	memcpy((uint8_t *)&RamFlashConfig.SystemParameters , (uint8_t *)&SystemParameters, sizeof(SystemParameters));
	w25qxx_EraseSector(RamFlashConfig.config_pointer);
	w25qxx_EraseSector(RamFlashConfig.sample_pointer);
	w25qxx_WriteBytes((uint8_t *)&RamFlashConfig, RamFlashConfig.config_pointer, sizeof(RamFlashConfig));
	HAL_Delay(10);
	w25qxx_ReadBytes((uint8_t *)&ReadRamFlashConfig, RamFlashConfig.config_pointer, sizeof(ReadRamFlashConfig));
	for(i=0;i<flash_samples_num;i++)
	{
		SamplesConfig[i].sample_index = i;
		sprintf((char *)SamplesConfig[i].sample_name,"Empty");
		SamplesConfig[i].sample_flags = 0;
		size_to_write += sizeof(SamplesConfig_TypeDef);
	}
	w25qxx_WriteBytes((uint8_t *)&SamplesConfig[0], RamFlashConfig.sample_pointer, size_to_write);
	HAL_Delay(10);
	w25qxx_ReadBytes((uint8_t *)&SamplesConfig[0], RamFlashConfig.sample_pointer, size_to_write);
	*/
}

uint8_t bB2xx_flash_init(void)
{
	return bB2xx_flash_identify();
}

void bB2xx_flash_store_sysparams(void)
{
	w25qxx_EraseSector(w25qxx_AddressToSector(FlashConfig.params_pointer));
	w25qxx_WriteBytes((uint8_t *)&SystemParameters, FlashConfig.params_pointer, sizeof(SystemParameters));
}

void bB2xx_flash_get_sysparams(void)
{
uint32_t	digit_address,i;
	w25qxx_ReadBytes((uint8_t *)&SystemParameters, FlashConfig.params_pointer, sizeof(SystemParameters));
	if (( SystemParameters.id[0] == 'b') && ( SystemParameters.id[1] == 'B') && ( SystemParameters.id[2] == '2')&& ( SystemParameters.flash_capacity == F128))
	{
		digit_address = FlashConfig.digitblue_pointer;
		for(i=0;i<10;i++,digit_address += SECTOR_SIZE)
		{
			w25qxx_ReadBytes((uint8_t *)&ram_blue_digits[i], digit_address, sizeof(blue_digits[i]));
			HAL_Delay(2);
		}
		return;
	}
	else
	{
		SystemParameters.id[0] = 'b';
		SystemParameters.id[1] = 'B';
		SystemParameters.id[2] = '2';
		SystemParameters.id[3] = 'x';
		SystemParameters.touch_x_minimum = 0;
		SystemParameters.touch_y_minimum = 0;
		SystemParameters.flash_capacity = F128;
		bB2xx_flash_store_sysparams();
		w25qxx_ReadBytes((uint8_t *)&SystemParameters, FlashConfig.params_pointer, sizeof(SystemParameters));
	}
}

void bB2xx_flash_store_bluedigits(void)
{
uint32_t	bluedigits_sector,digit_address,i;
	bluedigits_sector = w25qxx_AddressToSector(FlashConfig.digitblue_pointer);
	for(i=0;i<10;i++,bluedigits_sector++)
	{
		w25qxx_EraseSector(bluedigits_sector);
		HAL_Delay(2);
	}
	digit_address = FlashConfig.digitblue_pointer;
	for(i=0;i<10;i++,digit_address += SECTOR_SIZE)
	{
		w25qxx_WriteBytes((uint8_t *)&blue_digits[i], digit_address, sizeof(blue_digits[i]));
		HAL_Delay(2);
	}

}

