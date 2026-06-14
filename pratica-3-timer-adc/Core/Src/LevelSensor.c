/*
 * LevelSensor.c
 *
 *  Created on: 14 de jun. de 2026
 *      Author: Dhiego da Costa
 */

#include "Bsp.h"
#include "LevelSensor.h"

static levelSensor_t ls_inst;

/** @brief Inicializar estado interno. */
void LevelSensor_Init(void)
{
	ls_inst.acc = 0;
	ls_inst.sampleCount = 0;
	ls_inst.lastMean = 0;
	ls_inst.ready = dFALSE;
}

int LevelSensor_rawToPercentage(int raw)
{
	int level = (raw * 100) / dLEVEL_SENSOR_ADC_MAX;
	return level;
}

/** @brief Acumula uma nova amostra para a média. */
void LevelSensor_AddSample(int raw)
{
	ls_inst.acc += raw;
	ls_inst.sampleCount++;
	if (ls_inst.sampleCount >= dLEVEL_SENSOR_SAMPLE_NUM) {
		int rawMean = ls_inst.acc / ls_inst.sampleCount;
		ls_inst.lastMean = LevelSensor_rawToPercentage(rawMean);
		ls_inst.ready = dTRUE;
		ls_inst.acc = 0;
		ls_inst.sampleCount = 0;
	}
}

/** @brief Retorne a última média calculada. */
int LevelSensor_GetLastMean(void)
{
	return ls_inst.lastMean;
}

/** @brief Retorne true se existe uma nova média desde o último ClearReady. */
bool LevelSensor_IsReady(void)
{
	return ls_inst.ready;
}

/** @brief Marca a última média como lida, reseta IsReady. */
void LevelSensor_ClearReady(void)
{
	ls_inst.ready = dFALSE;
}
