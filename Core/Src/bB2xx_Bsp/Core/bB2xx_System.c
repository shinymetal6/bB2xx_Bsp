/*
 * bB2xx_System.c
 *
 *  Created on: Oct 18, 2021
 *      Author: fil
 */

#include "main.h"
#include "bB2xx_System.h"
#include <strings.h>

RAMD3_RAM_AREA	__attribute__ ((aligned (16)))	SystemVar_TypeDef			SystemVar;
RAMD3_RAM_AREA	__attribute__ ((aligned (16)))	SystemParameters_TypeDef	SystemParameters;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if ( GPIO_Pin == ENCODER_BTN_Pin)
		encoder_switch_callback();
	if ( GPIO_Pin == TOUCH_IRQ_Pin)
		ILI9341_TouchCallback();
}

void SysLedActivities(uint8_t val)
{
	  HAL_GPIO_WritePin(SYSTEM_LED_GPIO_Port, SYSTEM_LED_Pin, val);
}

void SysTimer100msecCallback(void)
{
	SystemVar.timers_flag |= TIMER_100MS_FLAG;
	SystemVar.tim100msec_counter++;
	if ( SystemVar.tim100msec_counter >= 9 )
	{
		SystemVar.timers_flag |= TIMER_1SEC_FLAG;
		SysLedActivities(GPIO_PIN_RESET);
		SystemVar.tim100msec_counter = 0;
	}
	else
		SysLedActivities(GPIO_PIN_SET);
	check_buttons();
}

void InitSystemTimers(void)
{
	HAL_TIM_Base_Start_IT(&SYSTICK_100MSEC);
	HAL_TIM_PWM_Start(&BACKLIGHT_TIMER, BACKLIGHT_TIMER_CHANNEL);
	ILI9341_SetBrightness(0);
	HAL_TIM_Encoder_Start_IT(&ENCODER_TIMER, TIM_CHANNEL_ALL);
	HAL_TIM_Base_Start_IT(&CONTROL_TIMER);
}

void InitSystemVars(void)
{
	bzero((uint8_t *)&SystemVar,sizeof(SystemVar));
}

void bB2xx_Init(void)
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CYCCNT = 0;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

	bB2xx_flash_init();
	bB2xx_flash_get_sysparams();
	//bB2xx_flash_store_bluedigits();

	InitSystemVars();
	InitSystemTimers();
	LD1_OnOff(LED_ON);
	LD7_OnOff(LED_ON);
	LD8_OnOff(LED_ON);

	ILI9341_Init();
	ILI9341_FillScreen(ILI9341_BLACK);
	ILI9341_WriteString(0,0,"bB2xx BSP",Font_11x18,ILI9341_RED,ILI9341_BLACK);
	ILI9341_DrawBitmap(16,128,(uint8_t *)&ram_blue_digits[2]);
	ILI9341_SetBrightness(50);

	InitDac();
	InitSPDIF();
	InitI2S();
	InitControls();

	/*
	bB2xx_flash_store_sysparams();
	*/
	LD1_OnOff(LED_OFF);
	LD7_OnOff(LED_OFF);
	LD8_OnOff(LED_OFF);
}

void bB2xx_Set_NO_MicroSD_Flag(void)
{
	SystemVar.microsd_flags |= MICROSD_NOT_PRESENT_FLAG;
}

uint8_t	ld1=0,ld7=0;
extern	MDMA_HandleTypeDef hmdma_mdma_channel40_sw_0;

void bB2xx_Loop(void)
{
	HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON,PWR_SLEEPENTRY_WFI);
	if (( SystemVar.buttons_flags & SW1_PRESSED ) == SW1_PRESSED)
	{
		SystemVar.buttons_flags &= ~SW1_PRESSED;
		ld1++;
		ld1 &=1;
		LD1_OnOff(ld1);
	}
	if (( SystemVar.buttons_flags & SW2_PRESSED ) == SW2_PRESSED)
	{
		SystemVar.buttons_flags &= ~SW2_PRESSED;
		ld7++;
		ld7 &=1;
		LD7_OnOff(ld7);
	}
	if (( SystemVar.timers_flag & TIMER_100MS_FLAG ) == TIMER_100MS_FLAG)
	{
		HAL_GPIO_WritePin(FLAG_GPIO_Port, FLAG_Pin, GPIO_PIN_SET);
		SystemVar.timers_flag &= ~TIMER_100MS_FLAG;
		I2S_GetAudioBuf();
		HAL_GPIO_WritePin(FLAG_GPIO_Port, FLAG_Pin, GPIO_PIN_RESET);
	}

}

