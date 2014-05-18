/** @defgroup ficr_defines FICF Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * Factory and User Information Configuration Registers</b>
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

#ifndef LIBOPENCM3_FICR_H
#define LIBOPENCM3_FICR_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
#define FICR_CODEPAGESIZE			MMIO32(FICR_BASE + 0x010)
#define FICR_CODESIZE				MMIO32(FICR_BASE + 0x014)
#define FICR_CLENR0				MMIO32(FICR_BASE + 0x028)
#define FICR_PPFC				MMIO32(FICR_BASE + 0x02C)
#define FICR_NUMRAMBLOCK			MMIO32(FICR_BASE + 0x034)
#define FICR_SIZERAMBLOCK_0			MMIO32(FICR_BASE + 0x038)
#define FICR_SIZERAMBLOCK_1			MMIO32(FICR_BASE + 0x03C)
#define FICR_SIZERAMBLOCK_2			MMIO32(FICR_BASE + 0x040)
#define FICR_SIZERAMBLOCK_3			MMIO32(FICR_BASE + 0x044)
#define FICR_CONFIGID				MMIO32(FICR_BASE + 0x05C)
#define FICR_DEVICEID_0				MMIO32(FICR_BASE + 0x060)
#define FICR_DEVICEID_1				MMIO32(FICR_BASE + 0x064)
#define FICR_ER_0				MMIO32(FICR_BASE + 0x080)
#define FICR_ER_1				MMIO32(FICR_BASE + 0x084)
#define FICR_ER_2				MMIO32(FICR_BASE + 0x088)
#define FICR_ER_3				MMIO32(FICR_BASE + 0x08C)
#define FICR_IR_0				MMIO32(FICR_BASE + 0x090)
#define FICR_IR_1				MMIO32(FICR_BASE + 0x094)
#define FICR_IR_2				MMIO32(FICR_BASE + 0x098)
#define FICR_IR_3				MMIO32(FICR_BASE + 0x09c)
#define FICR_DEVICEADDRTYPE			MMIO32(FICR_BASE + 0x0A0)
#define FICR_DEVICEADDR_0			MMIO32(FICR_BASE + 0x0A4)
#define FICR_DEVICEADDR_1			MMIO32(FICR_BASE + 0x0A8)
#define FICR_OVERRIDDEN				MMIO32(FICR_BASE + 0x0AC)
#define FICR_NRF_1MBIT_0			MMIO32(FICR_BASE + 0x0B0)
#define FICR_NRF_1MBIT_1			MMIO32(FICR_BASE + 0x0B4)
#define FICR_NRF_1MBIT_2			MMIO32(FICR_BASE + 0x0B8)
#define FICR_NRF_1MBIT_3			MMIO32(FICR_BASE + 0x0BC)
#define FICR_NRF_1MBIT_4			MMIO32(FICR_BASE + 0x0C0)
#define FICR_BLE_1MBIT_0			MMIO32(FICR_BASE + 0x0EC)
#define FICR_BLE_1MBIT_1			MMIO32(FICR_BASE + 0x0F0)
#define FICR_BLE_1MBIT_2			MMIO32(FICR_BASE + 0x0F4)
#define FICR_BLE_1MBIT_3			MMIO32(FICR_BASE + 0x0F8)
#define FICR_BLE_1MBIT_4			MMIO32(FICR_BASE + 0x0FC)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define FICR_PPFC_PPFC_PRESENT			0x00
#define FICR_CONFIGID_FWID			(1 << 16)
#define FICR_CONFIGID_HWID			(1 << 0)
#define FICR_DEVICEADDRTYPE_PUBLIC		0
#define FICR_DEVICEADDRTYPE_RANDOM		1

#define UICR_RBPCONF_PALL			(1 << 8)
#define UICR_RBPCONF_PR0			(1 << 0)
#define UICR_XTALFREQ_XTALFREQ_16MHz		0xFF
#define UICR_XTALFREQ_XTALFREQ_32MHz		0x00
#define UICR_FWID_FWID				(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

static inline uint32_t ficr_deviceaddr_random(void)
{
	return FICR_DEVICEADDRTYPE;
}

static inline uint32_t ficr_get_daddr_base(void)
{
	return FICR_DEVICEADDR_0;
}

static inline uint16_t ficr_get_daddr_prefix(void)
{
	return (uint16_t)FICR_DEVICEADDR_1;
}

END_DECLS

#endif
