/*
 * Bsp.c
 *
 *  Created on: 14 de jun. de 2026
 *      Author: Dhiego da Costa
 */

#include "Bsp.h"
#include "LevelSensor.h"

int timerElapsedFlag = 0;

/** @brief Inicializar a placa e periféricos. */
void Bsp_Init(void)
{
	LevelSensor_Init();
	Bsp_StartTimerInterrupt();

}

/** @brief Ativar interrupção no período definido. */
void Bsp_StartTimerInterrupt(void)
{
}

bool Bsp_GetTimerOverflowFlag(void)
{
	return timerElapsedFlag;
}

void Bsp_ClearTimerFlag(void)
{
	timerElapsedFlag = 0;
}

int Bsp_ReadAdcPolling(ADC_HandleTypeDef* h)
{
	HAL_ADC_Start(h);
	HAL_ADC_PollForConversion(h, HAL_MAX_DELAY);
	int val = HAL_ADC_GetValue(h);
	HAL_ADC_Stop(h);
	return val;
}

