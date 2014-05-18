/** @defgroup wdg_defines WDT Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 Watchdog
 * Timer</b>
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

#ifndef LIBOPENCM3_WDT_H
#define LIBOPENCM3_WDT_H

#include <libopencm3/nrf51/memorymap.h>
#include <libopencm3/cm3/common.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define WDT_START			MMIO32(WDT_BASE + 0x000)
/* EVENTS */
#define WDT_TIMEOUT			MMIO32(WDT_BASE + 0x100)
/* REGISTERS */
#define WDT_INTENSET			MMIO32(WDT_BASE + 0x304)
#define WDT_INTENCLR			MMIO32(WDT_BASE + 0x308)
#define WDT_RUNSTATUS			MMIO32(WDT_BASE + 0x400)
#define WDT_REQSTATUS			MMIO32(WDT_BASE + 0x404)
#define WDT_CRV				MMIO32(WDT_BASE + 0x504)
#define WDT_RREN			MMIO32(WDT_BASE + 0x508)
#define WDT_CONFIG			MMIO32(WDT_BASE + 0x50C)
#define WDT_RR0				MMIO32(WDT_BASE + 0x600)
#define WDT_RR1				MMIO32(WDT_BASE + 0x604)
#define WDT_RR7				MMIO32(WDT_BASE + 0x61C)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define WDT_INTENSET_TIMEOUT			(1 << 0)
#define WDT_INTENCLR_TIMEOUT			(1 << 0)
#define WDT_RUNSTATUS_RUNNING			(1 << 0)
#define WDT_REQ_RR7				(1 << 7)
#define WDT_REQ_RR6				(1 << 6)
#define WDT_REQ_RR5				(1 << 5)
#define WDT_REQ_RR4				(1 << 4)
#define WDT_REQ_RR3				(1 << 3)
#define WDT_REQ_RR2				(1 << 2)
#define WDT_REQ_RR1				(1 << 1)
#define WDT_REQ_RR0				(1 << 0)
#define WDT_CONFIG_HALT_RUN			(1 << 3)
#define WDT_CONFIG_SLEEP_RUN			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

