/** @defgroup mpu_defines MPU Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * Memory Protection Unit </b>
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

#ifndef LIBOPENCM3_MPU_H
#define LIBOPENCM3_MPU_H

#include <libopencm3/nrf51/memorymap.h>
#include <libopencm3/cm3/common.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
#define MPU_PERR0				MMIO32(MPU_BASE + 0x528)
#define MPU_RLENR0				MMIO32(MPU_BASE + 0x52C)
#define MPU_PROTENSET0				MMIO32(MPU_BASE + 0x600)
#define MPU_PROTENSET1				MMIO32(MPU_BASE + 0x604)
#define MPU_DISABLEINDEBUG			MMIO32(MPU_BASE + 0x608)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define MPU_PERR0_PPI				(1 << 31)
#define MPU_PERR0_NVMC				(1 << 30)
#define MPU_PERR0_WUCOMP_COMP			(1 << 19)
#define MPU_PERR0_QDEC				(1 << 18)
#define MPU_PERR0_RTC1				(1 << 17)
#define MPU_PERR0_WDT				(1 << 16)
#define MPU_PERR0_CCM_AAR			(1 << 15)
#define MPU_PERR0_ECB				(1 << 14)
#define MPU_PERR0_RNG				(1 << 13)
#define MPU_PERR0_TEMP				(1 << 12)
#define MPU_PERR0_RTC0				(1 << 11)
#define MPU_PERR0_TIMER2			(1 << 10)
#define MPU_PERR0_TIMER1			(1 << 9)
#define MPU_PERR0_TIMER0			(1 << 8)
#define MPU_PERR0_ADC				(1 << 7)
#define MPU_PERR0_GPIOTE			(1 << 6)
#define MPU_PERR0_SPI1_TWI1			(1 << 4)
#define MPU_PERR0_SPI0_TWI0			(1 << 3)
#define MPU_PERR0_UART0				(1 << 2)
#define MPU_PERR0_RADIO				(1 << 1)
#define MPU_PERR0_POWER_CLOCK			(1 << 0)

#define MPU_DISABLEINDEBUG_DISABLE		(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif

