/**
 * @file   interrupt.c
 * @brief  define interrupt callback functions.
 * @author mokhwasomssi
 * @date   2021-09-10
 */


#include "interrupt.h"


us imu_sampling_time;
us telemetry_time;
bool imu_ready;


/**
 * @brief ibus receive complete interrupt
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == IBUS_UART)
		ibus_lost_flag_clear();
}

/**
 * @brief rf transmitter data sent interrupt
 *        and imu data ready interrupt
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == NRF24L01P_IRQ_PIN_NUMBER)
	{
		led_blue_on(); //telemetry indicator
		nrf24l01p_tx_irq(); // clear interrupt flag
	}

	if(GPIO_Pin == ICM20948_IRQ_PIN_NUMBER)
	{
		imu_ready = true;
		imu_sampling_time = timer2_end();
		tiemr2_start();
	}
}