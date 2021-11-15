/*
 * digits_memory.c
 *
 *  Created on: Nov 12, 2021
 *      Author: fil
 */

#include "main.h"
#include "digits_memory.h"

RAMD2_RAM_AREA	__attribute__ ((aligned (16)))	uint8_t ram_blue_digits[10][2938];
