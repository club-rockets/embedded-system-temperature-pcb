#include "battery.h"
#include "main.h"
#include "spi.h"

static float current_samples[N_MEAN] = { 0 };
static uint8_t current_sample_index = 0;

static float voltage_samples[N_MEAN] = { 0 };
static uint8_t voltage_sample_index = 0;

/* moyenne
 * Calculates the mean of all non-null floats in an array
 *
 * param:
 *		-list		a float array
 *		-length		number of values in provided array
 *
 * return: the mean of non-null floats
 */
static float moyenne(float* list, uint8_t length)
{
	uint8_t count = 0;
	float total = 0;

	for (length--; length != 0xFF; length--) {
		if (list[length] != 0) {
			total += list[length];
			count++;
		}
	}

	return (total / (count ? count : 1));
}

float read_voltage()
{
	uint32_t data = 0;
	float voltage = 0;

	// Rx/Tx buffer
	uint8_t rx_buffer[2] = { 0 };
	uint8_t tx_buffer[2] = { 0 };

	// Sélectopm du channel 0
	tx_buffer[0] = 0b11000010;
	tx_buffer[1] = 0b00000000;

	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, tx_buffer, 2, 100);
	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_SET);

	// Délai de conversion
	HAL_Delay(5);

	// Lecture du channel 0
	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_RESET);
	HAL_SPI_Receive(&hspi2, rx_buffer, 2, 100);
	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_RESET);

	// Traitement
	data = (rx_buffer[0] << 8) | (rx_buffer[1]);
	data = (data & 0xfff0) >> 4;
	voltage = ((float)data) / 2048.0;

	// Condition pour enlever les valeurs erronées
	if (voltage > 0.5 && voltage < 3.0)
		voltage_samples[voltage_sample_index++] = voltage;

	// Circularité du buffer
	if (voltage_sample_index >= N_MEAN)
		voltage_sample_index = 0;

	return moyenne(voltage_samples, N_MEAN) * 10 + 0.2; // voltage * gain + offset
}

float read_current()
{
	uint32_t data = 0;
	float current = 0;

	// Rx/Tx buffer
	uint8_t rx_buffer[2] = { 0 };
	uint8_t tx_buffer[2] = { 0 };

	// Sélection du channel 1 de l'ADC
	tx_buffer[0] = 0b11001010;
	tx_buffer[1] = 0b00000000;

	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, tx_buffer, 2, 100);
	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_SET);

	// Délai de conversion
	HAL_Delay(5);

	// Lecture du channel 1
	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_RESET);
	HAL_SPI_Receive(&hspi2, rx_buffer, 2, 100);
	HAL_GPIO_WritePin(SPI2_ADC_SELECT_GPIO_Port, SPI2_ADC_SELECT_Pin, GPIO_PIN_RESET);

	// Traitement
	data = (rx_buffer[0] << 8) | (rx_buffer[1]);
	data = (data & 0xfff0) >> 4;
	current = (float)data;
	current = current / 2048 * 3.271;

	// Condition pour enlever les valeurs erronées
	if (current > 1.5 && current < 3.0)
		current_samples[current_sample_index] = current; //offset

	// Circularité du buffer
	if (current_sample_index >= N_MEAN)
		current_sample_index = 0;

	return (moyenne(current_samples, N_MEAN) - 1.65) / 0.11; // (moyenne - ?) / ?
}
