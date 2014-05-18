/** @defgroup comp_defines LPCOMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the NRF51822
 * Low Power Comparator module</b>
 *
 * @ingroup NRF51822_defines
 *
 * @version 1.0.0
 *
 * @date 1 February 2014
 *
 *LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_COMP_H
#define LIBOPENCM3_COMP_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define LPCOMP_START			MMIO32(LPCOMP_BASE + 0x000)
#define LPCOMP_STOP			MMIO32(LPCOMP_BASE + 0x004)
#define LPCOMP_SAMPLE			MMIO32(LPCOMP_BASE + 0x008)
/* EVENTS */
#define LPCOMP_READY			MMIO32(LPCOMP_BASE + 0x100)
#define LPCOMP_DOWN			MMIO32(LPCOMP_BASE + 0x104)
#define LPCOMP_UP			MMIO32(LPCOMP_BASE + 0x108)
#define LPCOMP_CROSS			MMIO32(LPCOMP_BASE + 0x10C)
/* REGISTERS */
#define LPCOMP_SHORTS			MMIO32(LPCOMP_BASE + 0x200)
#define LPCOMP_INTENSET			MMIO32(LPCOMP_BASE + 0x304)
#define LPCOMP_INTENCLR			MMIO32(LPCOMP_BASE + 0x308)
#define LPCOMP_RESULT			MMIO32(LPCOMP_BASE + 0x400)
#define LPCOMP_ENABLE			MMIO32(LPCOMP_BASE + 0x500)
#define LPCOMP_PSEL			MMIO32(LPCOMP_BASE + 0x504)
#define LPCOMP_REFSEL			MMIO32(LPCOMP_BASE + 0x508)
#define LPCOMP_EXTREFSEL		MMIO32(LPCOMP_BASE + 0x50C)
#define LPCOMP_ANADETECT		MMIO32(LPCOMP_BASE + 0x520)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define COMP_SHORTS_CROSS_STOP			(1 << 4)
#define COMP_SHORTS_UP_STOP			(1 << 3)
#define COMP_SHORTS_DOWN_STOP			(1 << 2)
#define COMP_SHORTS_READY_STOP			(1 << 1)
#define COMP_SHORTS_READY_SAMPLE		(1 << 0)
#define COMP_INTENSET_CROSS			(1 << 3)
#define COMP_INTENSET_UP			(1 << 2)
#define COMP_INTENSET_DOWN			(1 << 1)
#define COMP_INTENSET_READY			(1 << 0)
#define COMP_INTENCLR_CROSS			(1 << 3)
#define COMP_INTENCLR_UP			(1 << 2)
#define COMP_INTENCLR_DOWN			(1 << 1)
#define COMP_INTENCLR_READY			(1 << 0)
#define COMP_RESULT_ABOVE			(1 << 0)
#define COMP_ENABLE_ENABLE			(1 << 0)
#define COMP_EXTREFSEL_AREF1			(1 << 0)
#define COMP_ANADETECT_UP			(1 << 0)
#define COMP_ANADETECT_DOWN			(1 << 1)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

