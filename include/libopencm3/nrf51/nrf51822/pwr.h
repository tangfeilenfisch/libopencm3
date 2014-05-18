/** @defgroup pwr_defines PWR Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 PWR Control</b>
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* tasks */
#define PWR_CONSTLAT			MMIO32(POWER_BASE + 0x078)
#define PWR_LOWPWR			MMIO32(POWER_BASE + 0x07C)
/* events */
#define PWR_POFWARN			MMIO32(POWER_BASE + 0x108)
/* registers */
#define PWR_INTENSET			MMIO32(POWER_BASE + 0x304)
#define PWR_INTENCLR			MMIO32(POWER_BASE + 0x308)
#define PWR_RESETREAS			MMIO32(POWER_BASE + 0x400)
#define PWR_SYSTEMOFF			MMIO32(POWER_BASE + 0x500)
#define PWR_POFCON			MMIO32(POWER_BASE + 0x510)
#define PWR_GPREGRET			MMIO32(POWER_BASE + 0x51C)
#define PWR_RAMON			MMIO32(POWER_BASE + 0x524)
#define PWR_RESET			MMIO32(POWER_BASE + 0x544)
#define PWR_DCDCEN			MMIO32(POWER_BASE + 0x578)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define PWR_INTENSET_POFWARN		(1 << 2) 
#define PWR_INTENCLR_POFWARN		(1 << 2) 

#define PWR_RESETREAS_DIF		(1 << 18) 
#define PWR_RESETREAS_WUCOMP		(1 << 17) 
#define PWR_RESETREAS_OFF		(1 << 16) 
#define PWR_RESETREAS_LOCKUP		(1 << 3) 
#define PWR_RESETREAS_SREQ		(1 << 2) 
#define PWR_RESETREAS_DOG		(1 << 1) 
#define PWR_RESETREAS_RESETPIN		(1 << 0) 

#define PWR_SYSTEMOFF_ENTER		(1 << 0) 

#define PWR_POFCON_DISABLED		0x00
#define PWR_POFCON_THRESHOLD_V21	0x01
#define PWR_POFCON_THRESHOLD_V23	0x03
#define PWR_POFCON_THRESHOLD_V25	0x05
#define PWR_POFCON_THRESHOLD_V27	0x07

#define PWR_RAMON_OFFRAM3		(1 << 19) 
#define PWR_RAMON_OFFRAM2		(1 << 18) 
#define PWR_RAMON_OFFRAM1		(1 << 17) 
#define PWR_RAMON_OFFRAM0		(1 << 16) 
#define PWR_RAMON_ONRAM3		(1 << 3) 
#define PWR_RAMON_ONRAM2		(1 << 2) 
#define PWR_RAMON_ONRAM1		(1 << 1) 
#define PWR_RAMON_ONRAM0		(1 << 0) 
#define PWR_RAMON_ONALL			0x0F

#define PWR_RESET_ENABLE		(1 << 0) 

#define PWR_DCDCEN_ENABLE		(1 << 0) 

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

/** @ingroup power_control
 * @{ */

static inline void pwr_set_constlat_mode(void)
{
	PWR_CONSTLAT = 1;
}

static inline void pwr_set_lowpwr_mode(void)
{
	PWR_LOWPWR = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Enter system off mode (atomic)
*/
static inline void pwr_system_off(void)
{
	PWR_SYSTEMOFF = PWR_SYSTEMOFF_ENTER;
}

/*---------------------------------------------------------------------------*/
/** @brief Setup power failure comparator (atomic)

@param[in] gpios uint32_t. Threshold identifiers @ref threshold_id
*/
static inline void pwr_setup_pofcon(uint32_t threshold)
{
	PWR_POFCON = threshold;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable dc/dc converter (atomic)
*/
static inline void pwr_enable_dcdc(void)
{
	PWR_DCDCEN = PWR_DCDCEN_ENABLE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable dc/dc converter (atomic)
*/
static inline void pwr_disable_dcdc(void)
{
	PWR_DCDCEN = 0;
}

/** @} */

END_DECLS

#endif
