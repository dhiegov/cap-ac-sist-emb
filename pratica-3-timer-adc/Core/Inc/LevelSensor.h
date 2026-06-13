#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

#include "Bsp.h"

#define dLEVEL_SENSOR_SAMPLE_NUM 20
#define dLEVEL_SENSOR_ADC_MAX 4095

typedef struct levelSensor {
    int lastMean;
    int acc;
    int sampleCount;
    bool ready;
} levelSensor_t;

/** @brief Inicializar estado interno. */
void LevelSensor_Init(void);

/** @brief Acumula uma nova amostra para a média. */
void LevelSensor_AddSample(int raw);

/** @brief Retorne a última média calculada. */
int LevelSensor_GetLastMean(void);

/** @brief Retorne true se existe uma nova média desde o último ClearReady. */
bool LevelSensor_IsReady(void);

/** @brief Marca a última média como lida, reseta IsReady. */
void LevelSensor_ClearReady(void);

#endif
