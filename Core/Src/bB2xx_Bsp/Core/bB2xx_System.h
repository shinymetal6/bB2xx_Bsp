/*
 * bB2xx_System.h
 *
 *  Created on: Oct 18, 2021
 *      Author: fil
 */

#ifndef SRC_BB2XX_BSP_CORE_BB2XX_SYSTEM_H_
#define SRC_BB2XX_BSP_CORE_BB2XX_SYSTEM_H_

#include	"Components/ili9341.h"
#include	"Hmi/menus.h"

/*
Regions
	DTCMRAM   (xrw)    : ORIGIN = 0x20000000,    LENGTH = 128K	Cacheable
	ITCMRAM   (xrw)    : ORIGIN = 0x00000000,    LENGTH = 64K	Cacheable
	RAM_D1    (xrw)    : ORIGIN = 0x24000000,    LENGTH = 512K	Cacheable
	RAM_D2    (xrw)    : ORIGIN = 0x30000000,    LENGTH = 288K	Cacheable
	RAM_D3    (xrw)    : ORIGIN = 0x38000000,    LENGTH = 64K	NON cacheable
*/
#define	DTCM_RAM_AREA				__attribute__((section(".dtcm_ram_area" )))
#define	ITCM_RAM_AREA				__attribute__((section(".itcm_ram_area" )))
#define	RAMD3_RAM_AREA				__attribute__((section(".ram_D3" )))
#define	RAMD2_RAM_AREA				__attribute__((section(".ram_D2" )))
#define	FLASH_AREA					__attribute__((section(".table" )))

extern	TIM_HandleTypeDef 			htim17;
#define	SYSTICK_100MSEC				htim17
extern	TIM_HandleTypeDef 			htim2;
#define	BACKLIGHT_TIMER				htim2
#define	BACKLIGHT_TIMER_CHANNEL		TIM_CHANNEL_4
#define	BACKLIGHT_TIMER_REGISTER	BACKLIGHT_TIMER.Instance->CCR4
extern	TIM_HandleTypeDef 			htim4;
#define	ENCODER_TIMER				htim4
extern	TIM_HandleTypeDef 			htim7;
#define	SAMPLE_TIMER				htim7
extern	TIM_HandleTypeDef 			htim15;
#define	CONTROL_TIMER				htim15
extern	ADC_HandleTypeDef 			hadc1;
#define	CONTROL_DMA					hadc1
extern	DAC_HandleTypeDef 			hdac1;
#define	DAC_DMA						hdac1
extern	SAI_HandleTypeDef 			hsai_BlockA1;
#define	SPDIF_OUT					hsai_BlockA1
extern	DMA_HandleTypeDef 			hdma_sai1_a;
#define	SPDIF_OUT_DMA				hdma_sai1_a
extern	I2S_HandleTypeDef 			hi2s2;
#define	I2S_OUT_DMA					hi2s2
extern	MDMA_HandleTypeDef 			hmdma_mdma_channel40_sw_0;
#define	DAC_TO_I2S_DMA				hmdma_mdma_channel40_sw_0

#define	DAC_SIGNAL_LEN		256
#define	SPDIF_SIGNAL_LEN	512
#define	I2S_SIGNAL_LEN		512

typedef struct {
	uint8_t			timers_flag;
	uint8_t			tim100msec_counter;
	uint8_t			tim1Sec_counter;
	uint8_t			microsd_flags;
	uint8_t			flash_flags;
	uint8_t			lcd_flags;
	uint8_t 		touch_flags;
	uint8_t 		touch_disable_window;
	uint8_t			encoder_flags;
	int16_t 		last_encval;
	int16_t 		encval;
	uint8_t			buttons_flags;
	uint8_t			sw1_counter;
	uint8_t			sw2_counter;
	uint8_t			current_brightness;
	uint8_t			audio_flags;
	int16_t			rvar[4];
	uint8_t			menu_state;
	uint8_t			next_menu_item;
	uint8_t			selected_menu_item;
	Menu_TypeDef 	*current_menu;
}SystemVar_TypeDef;

/* timers_flag */
#define	TIMER_100MS_FLAG			0x01
#define	TIMER_1SEC_FLAG				0x02
/* microsd_flags */
#define	MICROSD_NOT_PRESENT_FLAG	0x80
/* flash_flags */
#define	FLASH_DMARUNNING_FLAG		0x80
/* lcd_flags */
#define	LCD_DMA_BUSY_FLAG			0x80
/* touch_flags */
#define	TOUCH_PENDOWN_FLAG			0x80
#define	TOUCH_CALIBRATED_FLAG		0x40
#define	TOUCH_PENDING_FLAG			0x01
/* encoder_flags */
#define	ENCODER_ROTATION_FLAG		0x80
#define	ENCODER_INCREMENT_FLAG		0x40
#define	ENCODER_DECREMENT_FLAG		0x20
#define	ENCODER_SW_FLAG				0x01

#define	ENCODER_PLUS				0x01
#define	ENCODER_MINUS				0x02
#define	ENCODER_NONE				0x00

/* buttons_flags */
#define	SW1_PRESSED					0x01
#define	SW2_PRESSED					0x02

/* audio_flags */
#define	AUDIO_DAC_HALF_FLAG			0x01
#define	AUDIO_DAC_READY_FLAG		0x02
#define	AUDIO_SPDIF_HALF_FLAG		0x04
#define	AUDIO_SPDIF_READY_FLAG		0x08
#define	AUDIO_I2S_HALF_FLAG			0x10
#define	AUDIO_I2S_READY_FLAG		0x20

/* mdma_flags */
#define	MDMA_COMPLETE_FLAG		0x80
#define	MDMA_RUNNING_FLAG		0x01



#define		TOUCH_DISABLE_WINDOW	2	// 500 mSec delay after touch released the touch is considered not active
#define		LED_ON					0
#define		LED_OFF					1

typedef struct {
	uint8_t			id[8];
	uint8_t			flash_capacity;
	uint16_t 		touch_x_minimum;
	uint16_t 		touch_x_correction;
	uint16_t 		touch_y_minimum;
	uint16_t 		touch_y_correction;
}SystemParameters_TypeDef;

extern	SystemVar_TypeDef			SystemVar;
extern	SystemParameters_TypeDef	SystemParameters;

extern	void bB2xx_Init(void);
extern	void bB2xx_Loop(void);
extern	void SysTimer100msecCallback(void);
extern	void bB2xx_Set_NO_MicroSD_Flag(void);
extern	void MDMA_Callback(void);

#endif /* SRC_BB2XX_BSP_CORE_BB2XX_SYSTEM_H_ */
