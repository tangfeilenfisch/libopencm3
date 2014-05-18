/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Johann Fischer <j.fischer_at_fh-bingen_de>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- NRF51822 specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define FLASH_BASE			((uint32_t)0x00000000)
#define FICR_BASE			((uint32_t)0x10000000)
#define UICR_BASE			((uint32_t)0x10001000)
#define PERIPH_BASE_APB			((uint32_t)0x40000000)
#define PERIPH_BASE_AHB			((uint32_t)0x50000000)

/* Register boundary addresses */

/* APB */
#define POWER_BASE			(PERIPH_BASE_APB + 0x00000)
#define CLOCK_BASE			(PERIPH_BASE_APB + 0x00000)
#define MPU_BASE			(PERIPH_BASE_APB + 0x00000)
#define RADIO_BASE			(PERIPH_BASE_APB + 0x01000)
#define UART_BASE			(PERIPH_BASE_APB + 0x02000)
#define SPI0_BASE			(PERIPH_BASE_APB + 0x03000)
#define TWI0_BASE			(PERIPH_BASE_APB + 0x03000)
#define SPI1_BASE			(PERIPH_BASE_APB + 0x04000)
#define TWI1_BASE			(PERIPH_BASE_APB + 0x04000)
#define SPIS1_BASE			(PERIPH_BASE_APB + 0x04000)
#define GPIOTE_BASE			(PERIPH_BASE_APB + 0x06000)
#define ADC_BASE			(PERIPH_BASE_APB + 0x07000)
#define TIMER0_BASE			(PERIPH_BASE_APB + 0x08000)
#define TIMER1_BASE			(PERIPH_BASE_APB + 0x09000)
#define TIMER2_BASE			(PERIPH_BASE_APB + 0x0A000)
#define RTC0_BASE			(PERIPH_BASE_APB + 0x0B000)
#define TEMP_BASE			(PERIPH_BASE_APB + 0x0C000)
#define RNG_BASE			(PERIPH_BASE_APB + 0x0D000)
#define ECB_BASE			(PERIPH_BASE_APB + 0x0E000)
#define CCM_BASE			(PERIPH_BASE_APB + 0x0F000)
#define AAR_BASE			(PERIPH_BASE_APB + 0x0F000)
#define WDT_BASE			(PERIPH_BASE_APB + 0x10000)
#define RTC1_BASE			(PERIPH_BASE_APB + 0x11000)
#define QDEC_BASE			(PERIPH_BASE_APB + 0x12000)
#define LPCOMP_BASE			(PERIPH_BASE_APB + 0x13000)
#define NVMC_BASE			(PERIPH_BASE_APB + 0x1E000)
#define PPI_BASE			(PERIPH_BASE_APB + 0x1F000)

/* AHB */
#define GPIO_P0_BASE			(PERIPH_BASE_AHB + 0x00000)

/* register group pattern */
#define RGP_TASKS_BASE			0x000
#define RGP_EVENTS_BASE			0x100
#define RGP_REG_SHORTS			0x200
#define RGP_INTENSET			0x304
#define RGP_INTENCLR			0x308
#define RGP_REG_GEN			0x400

#endif
