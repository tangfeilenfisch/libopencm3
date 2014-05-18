/** @defgroup spi_defines SPI Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * Serial Peripheral Interface</b>
 *
 * @ingroup NRF51822_defines
 *
 * @version 1.0.0
 *
 * @date 1 February 2014
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Johann Fischer <j.fischer_at_fh-bingen_de>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 *			(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_SPI_H
#define LIBOPENCM3_SPI_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* EVENTS */
#define SPI0_READY			MMIO32(SPI0_BASE + 0x108)
#define SPI1_READY			MMIO32(SPI1_BASE + 0x108)
/* REGISTERS */
#define SPI0_INTENSET			MMIO32(SPI0_BASE + 0x304)
#define SPI0_INTENCLR			MMIO32(SPI0_BASE + 0x308)
#define SPI0_ENABLE			MMIO32(SPI0_BASE + 0x500)
#define SPI0_PSELSCK			MMIO32(SPI0_BASE + 0x508)
#define SPI0_PSELMOSI			MMIO32(SPI0_BASE + 0x50C)
#define SPI0_PSELMISO			MMIO32(SPI0_BASE + 0x510)
#define SPI0_RXD			MMIO32(SPI0_BASE + 0x518)
#define SPI0_TXD			MMIO32(SPI0_BASE + 0x51C)
#define SPI0_FREQUENCY			MMIO32(SPI0_BASE + 0x524)
#define SPI0_CONFIG			MMIO32(SPI0_BASE + 0x554)
#define SPI1_INTENSET			MMIO32(SPI1_BASE + 0x304)
#define SPI1_INTENCLR			MMIO32(SPI1_BASE + 0x308)
#define SPI1_ENABLE			MMIO32(SPI1_BASE + 0x500)
#define SPI1_PSELSCK			MMIO32(SPI1_BASE + 0x508)
#define SPI1_PSELMOSI			MMIO32(SPI1_BASE + 0x50C)
#define SPI1_PSELMISO			MMIO32(SPI1_BASE + 0x510)
#define SPI1_RXD			MMIO32(SPI1_BASE + 0x518)
#define SPI1_TXD			MMIO32(SPI1_BASE + 0x51C)
#define SPI1_FREQUENCY			MMIO32(SPI1_BASE + 0x524)
#define SPI1_CONFIG			MMIO32(SPI1_BASE + 0x554)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define SPI_INTENSET_READY			(1 << 2)
#define SPI_INTENCLR_READY			(1 << 2)
#define SPI_ENABLE_ENABLE			(1 << 0)
#define SPI_FREQUENCY_K125			(0x02000000)
#define SPI_FREQUENCY_K250			(0x04000000)
#define SPI_FREQUENCY_K500			(0x08000000)
#define SPI_FREQUENCY_M1			(0x10000000)
#define SPI_FREQUENCY_M2			(0x20000000)
#define SPI_FREQUENCY_M4			(0x40000000)
#define SPI_FREQUENCY_M8			(0x80000000)
#define SPI_CONFIG_CPOL_ACTIVELOW		(1 << 2)
#define SPI_CONFIG_CPHA_TRAILING		(1 << 1)
#define SPI_CONFIG_ORDER_LSBFIRST		(1 << 0)

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS


END_DECLS

#endif

