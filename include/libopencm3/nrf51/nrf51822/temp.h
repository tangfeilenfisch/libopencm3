/** @defgroup temp_defines TEMPERATURE Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 TEMPERATURE</b>
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

#ifndef LIBOPENCM3_TEMPERATURE_H
#define LIBOPENCM3_TEMPERATURE_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define TEMP_START			MMIO32(TEMP_BASE + 0x000)
#define TEMP_STOP			MMIO32(TEMP_BASE + 0x004)
/* EVENTS */
#define TEMP_DATARDY			MMIO32(TEMP_BASE + 0x100)
/* REGISTERS */
#define TEMP_INTENSET			MMIO32(TEMP_BASE + 0x304)
#define TEMP_INTENCLR			MMIO32(TEMP_BASE + 0x308)
#define TEMP_RESULT			MMIO32(TEMP_BASE + 0x508)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS


END_DECLS


#endif
