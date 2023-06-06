/*
 * Copyright (C) 2023 M17 Project and contributors
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/*
 * The NOR flash memory is organized as 256 (64KB) main sectors
 * that are further divided into 16 subsectors each (4096 subsectors
 * in total). The memory can be erased one 4KB subsector at a time,
 * 64KB sectors at a time, or as a whole. Erasing the memory turns
 * bits on ('1'). Writing memory drives them off ('0').
 * Erasing flash causes wear.
 */

#include "user_settings.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "nor_map.h"
#include "eeeprom.h"
#include "eeeprom_hal.h"

#define CALLSIGN1_EEEPROM_ADDR		0x00	// Contains CS letters [1:4]
#define CALLSIGN2_EEEPROM_ADDR		0x01	// Contains CS letters [5:8]
#define CALLSIGN3_EEEPROM_ADDR 		0x02	// Contains CS letters [9:10]
#define TX_FREQ_EEEPROM_ADDR		0x03	// Tx frequency (in Hz)
#define RX_FREQ_EEEPROM_ADDR		0x04	// Rx frequency (in Hz)
#define AV_MODE_EEEPROM_ADDR		0x05	// Contains Audio volume and mode
#define CONFIG_BITS_EEEPROM_ADDR	0x06	// Configuration bool values



EEEPROMHandle_t user_settings_eeeprom = {
		.address_size = EEEPROM_ADDRESS_1BYTE,
		.alignment = 1,
		.data_size = 4,
		.read = EEEPROM_HAL_qspi_read,
		.write = EEEPROM_HAL_qspi_write,
		.erase_page = EEEPROM_HAL_erase_subsector,
		.number_pages = USER_SETTINGS_NB_SECTORS,
		.page_offset = USER_SETTINGS_START_SECTOR,
		.page_size = SUBSECTOR_SIZE,
		.start_address = USER_SETTINGS_START_ADDRESS,
};

bool init_done = false;
settings_t cached_settings;

void user_settings_reset(){
	bool res = EEEPROM_erase(&user_settings_eeeprom);
	if( res != EXIT_SUCCESS){
		printf("Error erasing EEPROM content for user settings.\r\n");
		return;
	}
	printf("Successfully erased user settings. Rebooting\r\n");
	NVIC_SystemReset();
}

void user_settings_init()
{
	if(EEEPROM_init(&user_settings_eeeprom) != EXIT_SUCCESS){
		printf("Error initializing EEEPROM for user settings.\r\n");
	}
	uint32_t buffer;

	// CS letters 1 to 4
	if(EEEPROM_read_data(&user_settings_eeeprom, CALLSIGN1_EEEPROM_ADDR, &buffer) == EXIT_SUCCESS){
		*(uint32_t *)(cached_settings.callsign) = buffer;
	}else{
		cached_settings.callsign[0] = '\0';
	}


	// CS letters 5 to 8
	if(EEEPROM_read_data(&user_settings_eeeprom, CALLSIGN2_EEEPROM_ADDR, &buffer) == EXIT_SUCCESS){
		*(uint32_t *)(cached_settings.callsign+4) = buffer;
	}else{
		cached_settings.callsign[4] = '\0';
	}


	// CS letters 9-10
	if(EEEPROM_read_data(&user_settings_eeeprom, CALLSIGN3_EEEPROM_ADDR, &buffer) == EXIT_SUCCESS){
		*(uint16_t *)(cached_settings.callsign+8) = (uint16_t)buffer;
	}else{
		cached_settings.callsign[8] = '\0';
	}


	// RX freq
	if(EEEPROM_read_data(&user_settings_eeeprom, RX_FREQ_EEEPROM_ADDR, &buffer) == EXIT_SUCCESS){
		cached_settings.rx_freq = buffer;
	}else{
		cached_settings.rx_freq = 0;
	}


	// TX freq
	if(EEEPROM_read_data(&user_settings_eeeprom, TX_FREQ_EEEPROM_ADDR, &buffer) == EXIT_SUCCESS){
		cached_settings.tx_freq = buffer;
	}else{
		cached_settings.tx_freq = 0;
	}


	// Audio volume and mode
	if(EEEPROM_read_data(&user_settings_eeeprom, AV_MODE_EEEPROM_ADDR, &buffer) == EXIT_SUCCESS){
		cached_settings.audio_vol = buffer & 0xFF;
		cached_settings.mode = (buffer>>8) & 0xFF;
	}else{
		cached_settings.audio_vol = 0;
		cached_settings.mode = FM;
	}

	// config bits
	if(EEEPROM_read_data(&user_settings_eeeprom, CONFIG_BITS_EEEPROM_ADDR, &buffer) == EXIT_SUCCESS){
		cached_settings.use_freq_offset = buffer & 0x01;
		cached_settings.split_mode = buffer & 0x02;
	}else{
		cached_settings.use_freq_offset = false;
		cached_settings.split_mode = false;
	}

	init_done = true;
}

void user_settings_save(const settings_t *settings)
{
	uint32_t buffer;
	if(strcmp(settings->callsign, cached_settings.callsign) != 0){
		// Compare first four letters
		if(*(uint32_t *)(settings->callsign) != *(uint32_t *)(cached_settings.callsign)){
			EEEPROM_write_data(&user_settings_eeeprom, CALLSIGN1_EEEPROM_ADDR, (void *)settings->callsign);
		}
		// Compare letters 5 to 8
		if(*(uint32_t *)(settings->callsign+4) != *(uint32_t *)(cached_settings.callsign+4)){
			EEEPROM_write_data(&user_settings_eeeprom, CALLSIGN2_EEEPROM_ADDR, (void *)(settings->callsign+4));
		}
		// Compare letters 9-10
		if(*(uint16_t *)(settings->callsign+8) != *(uint16_t *)(cached_settings.callsign+8)){
			EEEPROM_write_data(&user_settings_eeeprom, CALLSIGN3_EEEPROM_ADDR, (void *)(settings->callsign+8));
		}
		memcpy(cached_settings.callsign, settings->callsign, 10);
	}

	if( (cached_settings.audio_vol != settings->audio_vol)
			|| (cached_settings.mode != settings->mode) ){
		buffer = settings->audio_vol + ( ( (uint16_t)settings->mode ) << 8 );
		EEEPROM_write_data(&user_settings_eeeprom, AV_MODE_EEEPROM_ADDR, (void *)(&buffer));
		cached_settings.audio_vol = settings->audio_vol;
		cached_settings.mode = settings->mode;
	}

	if( (cached_settings.use_freq_offset != settings->use_freq_offset)
			|| (cached_settings.split_mode != settings->split_mode) ){
		buffer = (settings->use_freq_offset << 0) + (settings->split_mode << 1);
		EEEPROM_write_data(&user_settings_eeeprom, CONFIG_BITS_EEEPROM_ADDR, (void *)(&buffer));
		cached_settings.use_freq_offset = settings->use_freq_offset;
		cached_settings.split_mode = settings->split_mode;
	}

	if(cached_settings.rx_freq != settings->rx_freq){
		EEEPROM_write_data(&user_settings_eeeprom, RX_FREQ_EEEPROM_ADDR, &(settings->rx_freq) );
		cached_settings.rx_freq = settings->rx_freq;
	}

	if(cached_settings.tx_freq != settings->tx_freq){
		EEEPROM_write_data(&user_settings_eeeprom, TX_FREQ_EEEPROM_ADDR, (void *)(&(settings->tx_freq)));
		cached_settings.tx_freq = settings->tx_freq;
	}
}

void user_settings_get(settings_t *settings)
{

	BSP_LED_Off(LED_ORANGE);
	BSP_LED_Off(LED_GREEN);

	if(!init_done){
		user_settings_init();
	}

	memcpy(settings, &cached_settings, sizeof(settings_t));
}

