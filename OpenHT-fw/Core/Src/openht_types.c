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

#include "openht_types.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct mode_datum openht_mode_data[] =
{
    {M17, "M17"},
    {FreeDV, "FreeDV"},
    {NFM,  "NFM"},
    {SSB,  "SSB"},
};

uint32_t openht_mode_count = sizeof(openht_mode_data)/sizeof(openht_mode_data[0]);

const char * openht_get_mode_str(openht_mode_t mode)
{
	for (int i = 0; i < openht_mode_count; i++) {
		if (openht_mode_data[i].mode == mode) {
			return openht_mode_data[i].mode_name;
		}
	}
}