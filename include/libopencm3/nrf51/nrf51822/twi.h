/** @defgroup twi_defines TWI Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 TWI</b>
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

#ifndef LIBOPENCM3_TWI_H
#define LIBOPENCM3_TWI_H

#include <libopencm3/cm3/common.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define TWI0_STARTRX			MMIO32(TWI0_BASE + 0x000)
#define TWI0_STARTTX			MMIO32(TWI0_BASE + 0x008)
#define TWI0_STOP			MMIO32(TWI0_BASE + 0x014)
#define TWI0_SUSPEND			MMIO32(TWI0_BASE + 0x01C)
#define TWI0_RESUME			MMIO32(TWI0_BASE + 0x020)
#define TWI1_STARTRX			MMIO32(TWI1_BASE + 0x000)
#define TWI1_STARTTX			MMIO32(TWI1_BASE + 0x008)
#define TWI1_STOP			MMIO32(TWI1_BASE + 0x014)
#define TWI1_SUSPEND			MMIO32(TWI1_BASE + 0x01C)
#define TWI1_RESUME			MMIO32(TWI1_BASE + 0x020)
/* EVENTS */
#define TWI0_STOPPED			MMIO32(TWI0_BASE + 0x104)
#define TWI0_RXDRDY			MMIO32(TWI0_BASE + 0x108)
#define TWI0_TXDSENT			MMIO32(TWI0_BASE + 0x11C)
#define TWI0_ERROR			MMIO32(TWI0_BASE + 0x124)
#define TWI0_BB				MMIO32(TWI0_BASE + 0x138)
#define TWI1_STOPPED			MMIO32(TWI1_BASE + 0x104)
#define TWI1_RXDRDY			MMIO32(TWI1_BASE + 0x108)
#define TWI1_TXDSENT			MMIO32(TWI1_BASE + 0x11C)
#define TWI1_ERROR			MMIO32(TWI1_BASE + 0x124)
#define TWI1_BB				MMIO32(TWI1_BASE + 0x138)
/* REGISTERS */
#define TWI0_SHORTS			MMIO32(TWI0_BASE + 0x200)
#define TWI0_INTENSET			MMIO32(TWI0_BASE + 0x304)
#define TWI0_INTENCLR			MMIO32(TWI0_BASE + 0x308)
#define TWI0_ERRORSRC			MMIO32(TWI0_BASE + 0x4C4)
#define TWI0_ENABLE			MMIO32(TWI0_BASE + 0x500)
#define TWI0_PSELSCL			MMIO32(TWI0_BASE + 0x508)
#define TWI0_PSELSDA			MMIO32(TWI0_BASE + 0x50C)
#define TWI0_RXD			MMIO32(TWI0_BASE + 0x518)
#define TWI0_TXD			MMIO32(TWI0_BASE + 0x51C)
#define TWI0_FREQUENCY			MMIO32(TWI0_BASE + 0x524)
#define TWI0_ADDRESS			MMIO32(TWI0_BASE + 0x588)
#define TWI1_SHORTS			MMIO32(TWI1_BASE + 0x200)
#define TWI1_INTENSET			MMIO32(TWI1_BASE + 0x304)
#define TWI1_INTENCLR			MMIO32(TWI1_BASE + 0x308)
#define TWI1_ERRORSRC			MMIO32(TWI1_BASE + 0x4C4)
#define TWI1_ENABLE			MMIO32(TWI1_BASE + 0x500)
#define TWI1_PSELSCL			MMIO32(TWI1_BASE + 0x508)
#define TWI1_PSELSDA			MMIO32(TWI1_BASE + 0x50C)
#define TWI1_RXD			MMIO32(TWI1_BASE + 0x518)
#define TWI1_TXD			MMIO32(TWI1_BASE + 0x51C)
#define TWI1_FREQUENCY			MMIO32(TWI1_BASE + 0x524)
#define TWI1_ADDRESS			MMIO32(TWI1_BASE + 0x588)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define TWI_SHORTS_BB_STOP			(1 << 1)
#define TWI_SHORTS_BB_SUSPEND			(1 << 0)
#define TWI_INTENSET_BB				(1 << 14)
#define TWI_INTENSET_ERROR			(1 << 9)
#define TWI_INTENSET_TXDSENT			(1 << 7)
#define TWI_INTENSET_RXDREADY			(1 << 2)
#define TWI_INTENSET_STOPPED			(1 << 1)
#define TWI_INTENCLR_BB				(1 << 14)
#define TWI_INTENCLR_ERROR			(1 << 9)
#define TWI_INTENCLR_TXDSENT			(1 << 7)
#define TWI_INTENCLR_RXDREADY			(1 << 2)
#define TWI_INTENCLR_STOPPED			(1 << 1)
#define TWI_ERRORSRC_DNACK			(1 << 2)
#define TWI_ERRORSRC_ANACK			(1 << 1)
#define TWI_ENABLE_ENABLE			0x5
#define TWI_FREQUENCY_K100			(0x01980000)
#define TWI_FREQUENCY_K250			(0x04000000)
#define TWI_FREQUENCY_K400			(0x06680000)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
/* pin configuration, drive strength S0D1 */
#define SCL_DRIVE_STRENGTH			(0x06)
#define SDA_DRIVE_STRENGTH			(0x06)

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

