/**
	******************************************************************************
	* File Name          : temperature.c
	* Description        : 
	******************************************************************************
	*
	* COPYRIGHT(c) 2017 
	*
	* Redistribution and use in source and binary forms, with or without modification,
	* are permitted provided that the following conditions are met:
	*   1. Redistributions of source code must retain the above copyright notice,
	*      this list of conditions and the following disclaimer.
	*   2. Redistributions in binary form must reproduce the above copyright notice,
	*      this list of conditions and the following disclaimer in the documentation
	*      and/or other materials provided with the distribution.
	*   3. Neither the name of STMicroelectronics nor the names of its contributors
	*      may be used to endorse or promote products derived from this software
	*      without specific prior written permission.
	*
	* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*
	******************************************************************************
	*/

#include "temperature.h"
#include "main.h"
#include "spi.h"

float read_sensor(uint8_t sensor_id)
{
	uint8_t rxbuffer[4] = { 0 };
	uint8_t data = 0;
	float temperature = 0.0f;

	// Select chip and receive SPI data
	HAL_GPIO_WritePin(SPI2_TEMP1_SELECT_GPIO_Port, SPI2_TEMP1_SELECT_Pin << (sensor_id - 1), GPIO_PIN_RESET);
	HAL_SPI_Receive(&hspi2, rxbuffer, 2, 100);
	HAL_GPIO_WritePin(SPI2_TEMP1_SELECT_GPIO_Port, SPI2_TEMP1_SELECT_Pin << (sensor_id - 1), GPIO_PIN_SET);

	// FIXME : I have no idea how this works, I only copied it straight from last year's code
	// Interesting note : why do I only read 2 bytes for a 4 bytes float?
	data = (rxbuffer[0] << 5) | (rxbuffer[1] >> 3);

	temperature = (float)((data & 0x000007f0) >> 4);

	if (data & 0x00000001)
		temperature += 0.0625;
	if (data & 0x00000002)
		temperature += 0.125;
	if (data & 0x00000004)
		temperature += 0.25;
	if (data & 0x00000008)
		temperature += 0.5;

	//if negative, two's complement
	if (data & 0x00000800)
		temperature -= 128;

	return temperature;
	// </FIXME>
}

float read_thermocouple_sensor(uint8_t sensor_id)
{
	uint8_t rxbuffer[4] = { 0 };
	uint8_t data = 0;
	float temperature = 0.0f;
	//float internal_temperature;

	// Select chip and receive SPI data
	HAL_GPIO_WritePin(SPI2_TC1_SELECT_GPIO_Port, SPI2_TC1_SELECT_Pin << (sensor_id - 1), GPIO_PIN_RESET);
	HAL_SPI_Receive(&hspi2, rxbuffer, 4, 100);
	HAL_GPIO_WritePin(SPI2_TC1_SELECT_GPIO_Port, SPI2_TC1_SELECT_Pin << (sensor_id - 1), GPIO_PIN_SET);

	// FIXME : This code's purpose/function is unclear, it was copied here from last year's code
	data = (rxbuffer[0] << 24) | (rxbuffer[1] << 16) | (rxbuffer[2] << 8) | (rxbuffer[3]);

	// Reconstruct temperature value
	temperature = (float)((data & 0x7ffc0000) >> 20);
	if(data & 0x00040000)
		temperature += 0.25;
	if(data & 0x00080000)
		temperature += 0.5;

	//if negative, two's complement
	if(data & 0x80000000)
		temperature -= 2048;
	
	/* FIXME : The following code was copied from last year's code but 
			it is unclear if it serves a purpose

	// Internal temperature 
	internal_temperature = (float)((data & 0x0000fff0) >> 8);
	if(data & 0x00000010)
		internal_temperature += 0.0625;
	if(data & 0x00000020)
		internal_temperature += 0.125;
	if(data & 0x00000040)
		internal_temperature += 0.25;
	if(data & 0x00000080)
		internal_temperature += 0.5;

	// if negative, two's complement
	if(data & 0x00008000)
		internal_temperature -= 128;
	*/

	// Read error flags and set temperature to fault-signalling value
	if (data & 0x09)
		temperature = -9999;
	else if (data & 0x01)
		temperature = 9999;
	
	return temperature;
	// </FIXME>
}
