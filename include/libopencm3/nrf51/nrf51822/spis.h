/** @defgroup spis_defines SPIS Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 SPI Slave</b>
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

#ifndef LIBOPENCM3_SPIS_H
#define LIBOPENCM3_SPIS_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define SPIS_ACQUIRE			MMIO32(SPIS_BASE + 0x024)
#define SPIS_RELEASE			MMIO32(SPIS_BASE + 0x028)
/* EVENTS */
#define SPIS_END			MMIO32(SPIS_BASE + 0x104)
#define SPIS_ACQUIRED			MMIO32(SPIS_BASE + 0x128)
/* REGISTERS */
#define SPIS_SHORTS			MMIO32(SPIS_BASE + 0x200)
#define SPIS_INTENSET			MMIO32(SPIS_BASE + 0x304)
#define SPIS_INTENCLR			MMIO32(SPIS_BASE + 0x308)
#define SPIS_SEMSTAT			MMIO32(SPIS_BASE + 0x400)
#define SPIS_STATUS			MMIO32(SPIS_BASE + 0x440)
#define SPIS_ENABLE			MMIO32(SPIS_BASE + 0x500)
#define SPIS_PSELSCK			MMIO32(SPIS_BASE + 0x508)
#define SPIS_PSELMISO			MMIO32(SPIS_BASE + 0x50C)
#define SPIS_PSELMOSI			MMIO32(SPIS_BASE + 0x510)
#define SPIS_PSELCSN			MMIO32(SPIS_BASE + 0x514)
#define SPIS_RXDPTR			MMIO32(SPIS_BASE + 0x534)
#define SPIS_MAXRX			MMIO32(SPIS_BASE + 0x538)
#define SPIS_AMOUNTRX			MMIO32(SPIS_BASE + 0x53C)
#define SPIS_TXDPTR			MMIO32(SPIS_BASE + 0x544)
#define SPIS_MAXTX			MMIO32(SPIS_BASE + 0x548)
#define SPIS_AMOUNTTX			MMIO32(SPIS_BASE + 0x54C)
#define SPIS_CONFIG			MMIO32(SPIS_BASE + 0x554)
#define SPIS_DEF			MMIO32(SPIS_BASE + 0x55C)
#define SPIS_ORC			MMIO32(SPIS_BASE + 0x5C0)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define SPIS_SHORTS_END_ACQUIRE			(1 << 2)
#define SPIS_INTENSET_ACQUIRED			(1 << 10)
#define SPIS_INTENSET_END			(1 << 1)
#define SPIS_INTENCLR_ACQUIRED			(1 << 10)
#define SPIS_INTENCLR_END			(1 << 1)
#define SPIS_STATUS_OVERFLOW			(1 << 1)
#define SPIS_STATUS_OVERREAD			(1 << 0)
#define SPIS_ENABLE_ENABLE			(1 << 1)
#define SPIS_CONFIG_ACTIVELOW			(1 << 2)
#define SPIS_CONFIG_TRAILING			(1 << 1)
#define SPIS_CONFIG_LSBFIRST			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

