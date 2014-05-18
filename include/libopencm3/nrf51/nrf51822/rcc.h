/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>libopencm3 NRF51822 Reset and Clock Control</b>
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
/**@{*/

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <libopencm3/nrf51/memorymap.h>
#include <libopencm3/cm3/common.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* Tasks */
#define RCC_HFCLKSTART				MMIO32(CLOCK_BASE + 0x000)
#define RCC_HFCLKSTOP				MMIO32(CLOCK_BASE + 0x004)
#define RCC_LFCLKSTART				MMIO32(CLOCK_BASE + 0x008)
#define RCC_LFCLKSTOP				MMIO32(CLOCK_BASE + 0x00C)
#define RCC_CAL					MMIO32(CLOCK_BASE + 0x010)
#define RCC_CTSTART				MMIO32(CLOCK_BASE + 0x014)
#define RCC_CTSTOP				MMIO32(CLOCK_BASE + 0x018)
/* Events */
#define RCC_HFCLKSTARTED			MMIO32(CLOCK_BASE + 0x100)
#define RCC_LFCLKSTARTED			MMIO32(CLOCK_BASE + 0x104)
#define RCC_DONE				MMIO32(CLOCK_BASE + 0x10C)
#define RCC_CTTO				MMIO32(CLOCK_BASE + 0x110)
/* Register */
#define RCC_INTENSET				MMIO32(CLOCK_BASE + 0x304)
#define RCC_INTENCLR				MMIO32(CLOCK_BASE + 0x308)
#define RCC_HFCLKSTAT				MMIO32(CLOCK_BASE + 0x40C)
#define RCC_LFCLKSTAT				MMIO32(CLOCK_BASE + 0x418)
#define RCC_LFCLKSRC				MMIO32(CLOCK_BASE + 0x518)
/* CTIV := calibration timer interval in mult. of 0.25 seconds, 6 bit value */
#define RCC_CTIV				MMIO32(CLOCK_BASE + 0x538)
#define RCC_XTALFREQ				MMIO32(CLOCK_BASE + 0x550)

/* Register values                                                           */
/*****************************************************************************/

#define RCC_HFCLKSTAT_SRC_XTAL			(1 << 0)
#define RCC_HFCLKSTAT_STATE_RUN			(1 << 16)

#define RCC_LFCLKSRC_RC				0
#define RCC_LFCLKSRC_XTAL			1
#define RCC_LFCLKSRC_SYNTH			2

#define RCC_LFCLKSTAT_RC			0
#define RCC_LFCLKSTAT_XTAL			(1 << 1)
#define RCC_LFCLKSTAT_SYNTH			(1 << 2)
#define RCC_LFCLKSTAT_STATE_RUN			(1 << 16)

#define RCC_XTALFREQ_32MHZ			((uint32_t(0x00)
#define RCC_XTALFREQ_16MHZ			((uint32_t(0xFF)

/* Enable interrupt on CLOCK_X event. */
#define RCC_INTENSET_CTTO			(1 << 4)		
#define RCC_INTENSET_DONE			(1 << 3)
#define RCC_INTENSET_LFCLKSTARTED		(1 << 1)
#define RCC_INTENSET_HFCLKSTARTED		(1 << 0)

/* Disable interrupt on CLOCK_X event. */
#define RCC_INTENCLR_CTTO			(1 << 4)		
#define RCC_INTENCLR_DONE			(1 << 3)
#define RCC_INTENCLR_LFCLKSTARTED		(1 << 1)
#define RCC_INTENCLR_HFCLKSTARTED		(1 << 0)

#define RCC_DEFAULT_FREQ			((uint32_t)16000000)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
enum xtalfreq {
	F_32MHZ		= 0x00,
	F_16MHZ		= 0xFF,
};

enum lf_src {
	RC, HFXTAL, SYNTH
};

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

bool rcc_sysclk_config(enum xtalfreq freq, enum lf_src src, bool lfrc_cal);
bool rcc_start_lfrc_calibration(void);

/*---------------------------------------------------------------------------*/
/** @brief Start high frequency crystal oscillator.
 
@param[in] enum xtalfreq. Frequency identifiers @ref xtalfreq
*/
static inline void rcc_hfclkstart(enum xtalfreq freq)
{
	RCC_XTALFREQ = freq;
	RCC_HFCLKSTART = 1;
	while (RCC_HFCLKSTARTED == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Stop high frequency crystal oscillator.
*/
static inline void rcc_hfclkstop(void)
{
	RCC_HFCLKSTOP = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Start low frequency oscillator.
 
@param[in] enum xtalfreq. Frequency identifiers @ref xtalfreq
*/
static inline void rcc_lfclkstart(enum lf_src src)
{
	RCC_LFCLKSRC = src;
	RCC_LFCLKSTART = 1;
	while (RCC_LFCLKSTARTED == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Stop low frequency oscillator.
*/
static inline void rcc_lfclkstop(void)
{
	RCC_LFCLKSTOP = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Return system clock frequency.
*/
static inline uint32_t rcc_get_system_clock_frequency(void)
{
	return RCC_DEFAULT_FREQ;
}

/** @} */
END_DECLS

#endif
/**@}*/

