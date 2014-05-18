/** @defgroup aar_defines AAR Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822
 * Accelerated Address Resolver </b>
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

#ifndef LIBOPENCM3_ARR_H
#define LIBOPENCM3_ARR_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define AAR_START			MMIO32(AAR_BASE + 0x000)
#define AAR_STOP			MMIO32(AAR_BASE + 0x008)
/* EVENTS */
#define AAR_END				MMIO32(AAR_BASE + 0x100)
#define AAR_RESOLVED			MMIO32(AAR_BASE + 0x104)
#define AAR_NOTRESOLVED			MMIO32(AAR_BASE + 0x108)
/* REGISTERS */
#define AAR_INTENSET			MMIO32(AAR_BASE + 0x304)
#define AAR_INTENCLR			MMIO32(AAR_BASE + 0x308)
#define AAR_STATUS			MMIO32(AAR_BASE + 0x400)
#define AAR_ENABLE			MMIO32(AAR_BASE + 0x500)
#define AAR_NIRK			MMIO32(AAR_BASE + 0x504)
#define AAR_IRKPTR			MMIO32(AAR_BASE + 0x508)
#define AAR_ADDPTR			MMIO32(AAR_BASE + 0x510)
#define AAR_SCRATCHPTR			MMIO32(AAR_BASE + 0x514)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define AAR_INTENSET_NOTRESOLVED		(1 << 2)
#define AAR_INTENSET_RESOLVED			(1 << 1)
#define AAR_INTENSET_END			(1 << 0)
#define AAR_INTENCLR_NOTRESOLVED		(1 << 2)
#define AAR_INTENCLR_RESOLVED			(1 << 1)
#define AAR_INTENCLR_END			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

