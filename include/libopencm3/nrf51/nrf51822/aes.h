/** @defgroup aes_defines AES Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * Crypto ECB </b>
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

#ifndef LIBOPENCM3_AES_H
#define LIBOPENCM3_AES_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* ECB */
/* TASKS */
#define ECB_STARTECB			MMIO32(ECB_BASE + 0x000)
#define ECB_STOPECB			MMIO32(ECB_BASE + 0x004)
/* EVENTS */
#define ECB_ENDECB			MMIO32(ECB_BASE + 0x100)
#define ECB_ERRORECB			MMIO32(ECB_BASE + 0x104)
/* REGISTERS */
#define ECB_INTENSET			MMIO32(ECB_BASE + 0x304)
#define ECB_INTENCLR			MMIO32(ECB_BASE + 0x308)
#define ECB_DATAPTR			MMIO32(ECB_BASE + 0x504)

/* CCM */
/* TASKS */
#define CCM_KSGEN			MMIO32(CCM_BASE + 0x000)
#define CCM_CRYPT			MMIO32(CCM_BASE + 0x004)
#define CCM_STOP			MMIO32(CCM_BASE + 0x008)
/* EVENTS */
#define CCM_ENDKSGEN			MMIO32(CCM_BASE + 0x100)
#define CCM_ENDCRYPT			MMIO32(CCM_BASE + 0x104)
#define CCM_ERROR			MMIO32(CCM_BASE + 0x108)
/* REGISTERS */
#define CCM_SHORTS			MMIO32(CCM_BASE + 0x200)
#define CCM_INTENSET			MMIO32(CCM_BASE + 0x304)
#define CCM_INTENCLR			MMIO32(CCM_BASE + 0x308)
#define CCM_MICSTATUS			MMIO32(CCM_BASE + 0x400)
#define CCM_ENABLE			MMIO32(CCM_BASE + 0x500)
#define CCM_MODE			MMIO32(CCM_BASE + 0x504)
#define CCM_CNFPTR			MMIO32(CCM_BASE + 0x508)
#define CCM_INPTR			MMIO32(CCM_BASE + 0x50C)
#define CCM_OUTPTR			MMIO32(CCM_BASE + 0x510)
#define CCM_SCRATCHPTR			MMIO32(CCM_BASE + 0x521)
/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define CCM_SHORTS_ENDKSGEN_CRYPT		(1 << 0)
#define CCM_INTENSET_ERROR			(1 << 2)
#define CCM_INTENSET_ENDCRYPT			(1 << 1)
#define CCM_INTENSET_ENDKSGEN			(1 << 0)
#define CCM_INTENCLR_ERROR			(1 << 2)
#define CCM_INTENCLR_ENDCRYPT			(1 << 1)
#define CCM_INTENCLR_ENDKSGEN			(1 << 0)
#define CCM_MICSTATUS_MICSTATUS			(1 << 0)
#define CCM_ENABLE_ENABLE			(1 << 1)
#define CCM_MODE_MODE				(1 << 0)

#define ECB_INTENSET_ERRORECB			(1 << 1)
#define ECB_INTENSET_ENDECB			(1 << 0)
#define ECB_INTENCLR_ERRORECB			(1 << 1)
#define ECB_INTENCLR_ENDECB			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

