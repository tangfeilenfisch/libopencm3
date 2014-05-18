/** @defgroup qdec_defines QDEC Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * Quadrature Decoder</b>
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

#ifndef LIBOPENCM3_QDEC_H
#define LIBOPENCM3_QDEC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define QDEC_START			MMIO32(QDEC_BASE + 0x000)
#define QDEC_STOP			MMIO32(QDEC_BASE + 0x004)
#define QDEC_READCLRACC			MMIO32(QDEC_BASE + 0x008)
/* EVENTS */
#define QDEC_SAMPLERDY			MMIO32(QDEC_BASE + 0x100)
#define QDEC_REPORTRDY			MMIO32(QDEC_BASE + 0x104)
#define QDEC_ACCOF			MMIO32(QDEC_BASE + 0x108)
/* REGISTERS */
#define QDEC_SHORTS			MMIO32(QDEC_BASE + 0x200)
#define QDEC_INTENSET			MMIO32(QDEC_BASE + 0x304)
#define QDEC_INTENCLR			MMIO32(QDEC_BASE + 0x308)
#define QDEC_ENABLE			MMIO32(QDEC_BASE + 0x500)
#define QDEC_LEDPOL			MMIO32(QDEC_BASE + 0x504)
#define QDEC_SAMPLEPER			MMIO32(QDEC_BASE + 0x508)
#define QDEC_SAMPLE			MMIO32(QDEC_BASE + 0x50C)
#define QDEC_REPORTPER			MMIO32(QDEC_BASE + 0x510)
#define QDEC_ACC			MMIO32(QDEC_BASE + 0x514)
#define QDEC_ACCREAD			MMIO32(QDEC_BASE + 0x518)
#define QDEC_PSELLED			MMIO32(QDEC_BASE + 0x51C)
#define QDEC_PSELA			MMIO32(QDEC_BASE + 0x520)
#define QDEC_PSELB			MMIO32(QDEC_BASE + 0x524)
#define QDEC_DBFEN			MMIO32(QDEC_BASE + 0x528)
#define QDEC_LEDPRE			MMIO32(QDEC_BASE + 0x540)
#define QDEC_ACCDBL			MMIO32(QDEC_BASE + 0x544)
#define QDEC_ACCDBLREAD			MMIO32(QDEC_BASE + 0x548)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define QDEC_SHORTS_SAMPLERDY_STOP			(1 << 1)
#define QDEC_SHORTS_REPORTRDY_READCLRACC		(1 << 0)
#define QDEC_INTENSET_ACCOF				(1 << 2)
#define QDEC_INTENSET_REPORTRDY				(1 << 1)
#define QDEC_INTENSET_SAMPLERDY				(1 << 0)
#define QDEC_INTENCLR_ACCOF				(1 << 2)
#define QDEC_INTENCLR_REPORTRDY				(1 << 1)
#define QDEC_INTENCLR_SAMPLERDY				(1 << 0)
#define QDEC_ENABLE_ENABLE				(1 << 0)
#define QDEC_LEDPOL_ACTIVEHIGH				(1 << 0)
#define QDEC_SAMPLE_SAMPLE				(1 << 0)
#define QDEC_DBFEN_ENABLE				(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

