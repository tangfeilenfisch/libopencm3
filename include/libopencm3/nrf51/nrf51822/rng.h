/** @defgroup aes_defines AES Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * Crypto ECB and Random number generator </b>
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

#ifndef LIBOPENCM3_RNG_H
#define LIBOPENCM3_RNG_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/
#define RNG_EVENT_BASE			(RNG_BASE + 0x100)

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define RNG_START			MMIO32(RNG_BASE + 0x000)
#define RNG_STOP			MMIO32(RNG_BASE + 0x004)
/* EVENTS */
#define RNG_VALRDY			MMIO32(RNG_BASE + 0x100)
/* REGISTERS */
#define RNG_SHORTS			MMIO32(RNG_BASE + 0x200)
#define RNG_INTENSET			MMIO32(RNG_BASE + 0x304)
#define RNG_INTENCLR			MMIO32(RNG_BASE + 0x308)
#define RNG_CONFIG			MMIO32(RNG_BASE + 0x504)
#define RNG_VALUE			MMIO32(RNG_BASE + 0x508)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define RNG_SHORTS_VALRDY_STOP			(1 << 0)
#define RNG_INTENSET_VALRDY			(1 << 0)
#define RNG_INTENCLR_VALRDY			(1 << 0)
#define RNG_CONFIG_DERCEN			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
enum rng_interrupt {
	rng_valrdy		= 0,
};

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/
uint8_t rng_get_octet(void);
void rng_get_eight_octets(uint8_t *buf);

BEGIN_DECLS

static inline void rng_start(void)
{
	RNG_START = 1;
}

static inline void rng_stop(void)
{
	RNG_STOP = 1;
}

static inline void rng_wait_valrdy(void)
{
	while(RNG_VALRDY == 0);
}

static inline void rng_shorts_valrdy_stop_enable(void)
{
	RNG_SHORTS = RNG_SHORTS_VALRDY_STOP;
}

static inline void rng_shorts_valrdy_stop_disable(void)
{
	RNG_SHORTS = 0;
}

static inline void rng_dercen_enable(void)
{
	RNG_CONFIG = RNG_CONFIG_DERCEN;
}

static inline void rng_enable_intr(enum rng_interrupt intr)
{
	RNG_INTENSET = (1 << intr);
}

static inline void rng_disable_intr(enum rng_interrupt intr)
{
	RNG_INTENCLR = (1 << intr);
}

static inline uint32_t rng_get_intr_source(enum rng_interrupt intr)
{
	intr &= 31;
	return MMIO32(RNG_EVENT_BASE + (intr << 2));
}


static inline void rng_clear_event(enum rng_interrupt intr)
{
	intr &= 31;
	MMIO32(RNG_EVENT_BASE + (intr << 2)) = 0;
}

END_DECLS

#endif

