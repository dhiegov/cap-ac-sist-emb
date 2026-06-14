#ifndef BSP_H
#define BSP_H

typedef int bool;

#define dTRUE 1
#define dFALSE 0

/** @brief Inicializar a placa e periféricos. */
void Bsp_Init(void);

/** @brief Ativar interrupção no período definido. */
void Bsp_StartTimerInterrupt(void);

/** @brief Retorne se passou o tempo definido. */
bool Bsp_GetTimerOverflowFlag(void);

/** @brief Zere a flag que indica que passou o tempo definido. */
void Bsp_ClearTimerFlag(void);

/** @brief Retorne leitura do ADC por polling.
 *
 * Bloqueante. */
int Bsp_ReadAdcPolling(void);

#endif
