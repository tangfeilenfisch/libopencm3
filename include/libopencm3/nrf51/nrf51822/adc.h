/** @defgroup adc_defines ADC Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 Analog to Digital
 * Converter</b>
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

#ifndef LIBOPENCM3_ADC_H
#define LIBOPENCM3_ADC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define ADC_START			MMIO32(ADC_BASE + 0x000)
#define ADC_STOP			MMIO32(ADC_BASE + 0x004)
/* EVENTS */
#define ADC_END				MMIO32(ADC_BASE + 0x100)
/* REGISTERS */
#define ADC_INTENSET			MMIO32(ADC_BASE + 0x304)
#define ADC_INTENCLR			MMIO32(ADC_BASE + 0x308)
#define ADC_BUSY			MMIO32(ADC_BASE + 0x400)
#define ADC_ENABLE			MMIO32(ADC_BASE + 0x500)
#define ADC_CONFIG			MMIO32(ADC_BASE + 0x504)
#define ADC_RESULT			MMIO32(ADC_BASE + 0x508)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define ADC_INTENSET_END			(1 << 0)
#define ADC_INTENCLR_END			(1 << 0)
#define ADC_BUSY_BUSY				(1 << 0)
#define ADC_ENABLE_ENABLE			(1 << 0)
#define ADC_CONFIG_EXTREFSEL			(1 << 16)
#define ADC_CONFIG_PSEL				(1 << 8)
#define ADC_CONFIG_REFSEL			(1 << 5)
#define ADC_CONFIG_INPSEL			(1 << 2)
#define ADC_CONFIG_RES				(1 << 0)

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS


END_DECLS

#endif

