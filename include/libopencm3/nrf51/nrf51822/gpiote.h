/** @defgroup gpiote_defines GPIOTE Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * GPIO Tasks and Events </b>
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

#ifndef LIBOPENCM3_GPIOTE_H
#define LIBOPENCM3_GPIOTE_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define GPIOTE_OUT_0				MMIO32(GPIOTE_BASE + 0x000)
#define GPIOTE_OUT_1				MMIO32(GPIOTE_BASE + 0x004)
#define GPIOTE_OUT_2				MMIO32(GPIOTE_BASE + 0x008)
#define GPIOTE_OUT_3				MMIO32(GPIOTE_BASE + 0x00C)
/* EVENTS */
#define GPIOTE_IN_0				MMIO32(GPIOTE_BASE + 0x100)
#define GPIOTE_IN_1				MMIO32(GPIOTE_BASE + 0x104)
#define GPIOTE_IN_2				MMIO32(GPIOTE_BASE + 0x108)
#define GPIOTE_IN_3				MMIO32(GPIOTE_BASE + 0x10C)
#define GPIOTE_PORT				MMIO32(GPIOTE_BASE + 0x17C)
/* REGISTERS */
#define GPIOTE_INTENSET				MMIO32(GPIOTE_BASE + 0x304)
#define GPIOTE_INTENCLR				MMIO32(GPIOTE_BASE + 0x308)
#define GPIOTE_CONFIG_0				MMIO32(GPIOTE_BASE + 0x510)
#define GPIOTE_CONFIG_1				MMIO32(GPIOTE_BASE + 0x514)
#define GPIOTE_CONFIG_2				MMIO32(GPIOTE_BASE + 0x518)
#define GPIOTE_CONFIG_3				MMIO32(GPIOTE_BASE + 0x51C)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define GPIOTE_INTENSET_PORT			(1 << 31)
#define GPIOTE_INTENSET_IN3			(1 << 3)
#define GPIOTE_INTENSET_IN2			(1 << 2)
#define GPIOTE_INTENSET_IN1			(1 << 1)
#define GPIOTE_INTENSET_IN0			(1 << 0)
#define GPIOTE_INTENCLR_PORT			(1 << 31)
#define GPIOTE_INTENCLR_IN3			(1 << 3)
#define GPIOTE_INTENCLR_IN2			(1 << 2)
#define GPIOTE_INTENCLR_IN1			(1 << 1)
#define GPIOTE_INTENCLR_IN0			(1 << 0)
#define GPIOTE_CONFIG_OUTINIT			(1 << 20)
#define GPIOTE_CONFIG_POLARITY			(1 << 16)
#define GPIOTE_CONFIG_PSEL			(1 << 8)
#define GPIOTE_CONFIG_MODE			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

