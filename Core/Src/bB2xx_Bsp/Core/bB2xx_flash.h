/*
 * bB2xx_flash.h
 *
 *  Created on: Oct 29, 2021
 *      Author: fil
 */

#ifndef SRC_BB2XX_BSP_CORE_BB2XX_FLASH_H_
#define SRC_BB2XX_BSP_CORE_BB2XX_FLASH_H_

typedef struct {
	uint32_t		sample_pointer;
}FlashStruct_TypeDef;

typedef struct {
	uint32_t					params_pointer;
	uint32_t					sample_pointer;
	uint32_t					digitblue_pointer;
	uint32_t					digitred_pointer;
	uint32_t					digitgreen_pointer;
	uint32_t					digityellow_pointer;
	uint32_t					splashimage_pointer;
	SystemParameters_TypeDef	SystemParameters;
}FlashConfig_TypeDef;

typedef struct {
	uint8_t					sample_name[14];
	uint8_t					sample_index;
	uint8_t					sample_flags;
}SamplesConfig_TypeDef;



/*
 * memory structure for 128mBit case , 16 mBytes total
 * 0xf00000 - 0xfff000 : parameters , 4096 bytes ( 1 sector )
 * 0xf00000 - 0xffefff : images , 255 sectors
 * 						0xf00000 - 0xf09fff : blue digits
 * 						0xf14000 - 0xf1dfff : red digits
 * 						0xf1e000 - 0xf27fff : green digits
 * 						0xf28000 - 0xf31fff : yellow digits
 * 						0xf3c000 -          : logo
 * 0x000000 - 0xefffff : samples , 3584 sectors
 */
#define		PARAM_NUMSECTORS	1
#define		IMAGE_NUMSECTORS	255
#define		SAMPLES_NUMSECTORS	3584
#define		PARAMS_PTR_F128		(F128_SIZE - (PARAM_NUMSECTORS*SECTOR_SIZE))
#define		IMAGE_PTR_F128		(F128_SIZE - (PARAM_NUMSECTORS*SECTOR_SIZE) - (IMAGE_NUMSECTORS*SECTOR_SIZE))
#define		BLUE_DIGIT_FPTR		IMAGE_PTR_F128
#define		RED_DIGIT_FPTR		(BLUE_DIGIT_FPTR+SECTOR_SIZE*10)
#define		GREEN_DIGIT_FPTR	(RED_DIGIT_FPTR+SECTOR_SIZE*10)
#define		YELLOW_DIGIT_FPTR	(GREEN_DIGIT_FPTR+SECTOR_SIZE*10)
#define		LOGO_FPTR			(YELLOW_DIGIT_FPTR+SECTOR_SIZE*10)

#define		SAMPLE_PTR_F128		0

extern	uint8_t bB2xx_flash_init(void);
extern	void bB2xx_flash_get_sysparams(void);
extern	void bB2xx_flash_store_sysparams(void);

#endif /* SRC_BB2XX_BSP_CORE_BB2XX_FLASH_H_ */
