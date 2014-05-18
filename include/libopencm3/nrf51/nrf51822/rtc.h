/** @defgroup rtc_defines RTC Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 RTC</b>
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

#ifndef LIBOPENCM3_RTC_H
#define LIBOPENCM3_RTC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/
#define RTC0_EVENT_BASE			(RTC0_BASE + 0x100)
#define RTC1_EVENT_BASE			(RTC1_BASE + 0x100)

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define RTC0_START			MMIO32(RTC0_BASE + 0x000)
#define RTC0_STOP			MMIO32(RTC0_BASE + 0x004)
#define RTC0_CLEAR			MMIO32(RTC0_BASE + 0x008)
#define RTC0_TRIGOVRFLW			MMIO32(RTC0_BASE + 0x00C)
#define RTC1_START			MMIO32(RTC1_BASE + 0x000)
#define RTC1_STOP			MMIO32(RTC1_BASE + 0x004)
#define RTC1_CLEAR			MMIO32(RTC1_BASE + 0x008)
#define RTC1_TRIGOVRFLW			MMIO32(RTC1_BASE + 0x00C)
/* EVENTS */
#define RTC0_TICK			MMIO32(RTC0_BASE + 0x100)
#define RTC0_OVRFLW			MMIO32(RTC0_BASE + 0x104)
#define RTC0_COMPARE0			MMIO32(RTC0_BASE + 0x140)
#define RTC0_COMPARE1			MMIO32(RTC0_BASE + 0x144)
#define RTC0_COMPARE2			MMIO32(RTC0_BASE + 0x148)
#define RTC0_COMPARE3			MMIO32(RTC0_BASE + 0x14C)
#define RTC1_TICK			MMIO32(RTC1_BASE + 0x100)
#define RTC1_OVRFLW			MMIO32(RTC1_BASE + 0x104)
#define RTC1_COMPARE0			MMIO32(RTC1_BASE + 0x140)
#define RTC1_COMPARE1			MMIO32(RTC1_BASE + 0x144)
#define RTC1_COMPARE2			MMIO32(RTC1_BASE + 0x148)
#define RTC1_COMPARE3			MMIO32(RTC1_BASE + 0x14C)
/* REGISTERS */
#define RTC0_INTENSET			MMIO32(RTC0_BASE + 0x304)
#define RTC0_INTENCLR			MMIO32(RTC0_BASE + 0x308)
#define RTC0_EVTEN			MMIO32(RTC0_BASE + 0x340)
#define RTC0_EVTENSET			MMIO32(RTC0_BASE + 0x344)
#define RTC0_EVTENCLR			MMIO32(RTC0_BASE + 0x348)
#define RTC0_COUNTER			MMIO32(RTC0_BASE + 0x504)
#define RTC0_PRESCALER			MMIO32(RTC0_BASE + 0x508)
#define RTC0_CC0			MMIO32(RTC0_BASE + 0x540)
#define RTC0_CC1			MMIO32(RTC0_BASE + 0x544)
#define RTC0_CC2			MMIO32(RTC0_BASE + 0x548)
#define RTC0_CC3			MMIO32(RTC0_BASE + 0x54C)
#define RTC1_INTENSET			MMIO32(RTC1_BASE + 0x304)
#define RTC1_INTENCLR			MMIO32(RTC1_BASE + 0x308)
#define RTC1_EVTEN			MMIO32(RTC1_BASE + 0x340)
#define RTC1_EVTENSET			MMIO32(RTC1_BASE + 0x344)
#define RTC1_EVTENCLR			MMIO32(RTC1_BASE + 0x348)
#define RTC1_COUNTER			MMIO32(RTC1_BASE + 0x504)
#define RTC1_PRESCALER			MMIO32(RTC1_BASE + 0x508)
#define RTC1_CC0			MMIO32(RTC1_BASE + 0x540)
#define RTC1_CC1			MMIO32(RTC1_BASE + 0x544)
#define RTC1_CC2			MMIO32(RTC1_BASE + 0x548)
#define RTC1_CC3			MMIO32(RTC1_BASE + 0x54C)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define RTC_INTENSET_COMPARE3			(1 << 19)
#define RTC_INTENSET_COMPARE2			(1 << 18)
#define RTC_INTENSET_COMPARE1			(1 << 17)
#define RTC_INTENSET_COMPARE0			(1 << 16)
#define RTC_INTENSET_OVRFLW			(1 << 1)
#define RTC_INTENSET_TICK			(1 << 0)
#define RTC_INTENCLR_COMPARE3			(1 << 19)
#define RTC_INTENCLR_COMPARE2			(1 << 18)
#define RTC_INTENCLR_COMPARE1			(1 << 17)
#define RTC_INTENCLR_COMPARE0			(1 << 16)
#define RTC_INTENCLR_OVRFLW			(1 << 1)
#define RTC_INTENCLR_TICK			(1 << 0)
#define RTC_EVTEN_COMPARE3			(1 << 19)
#define RTC_EVTEN_COMPARE2			(1 << 18)
#define RTC_EVTEN_COMPARE1			(1 << 17)
#define RTC_EVTEN_COMPARE0			(1 << 16)
#define RTC_EVTEN_OVRFLW			(1 << 1)
#define RTC_EVTEN_TICK				(1 << 0)
#define RTC_EVTENSET_COMPARE3			(1 << 19)
#define RTC_EVTENSET_COMPARE2			(1 << 18)
#define RTC_EVTENSET_COMPARE1			(1 << 17)
#define RTC_EVTENSET_COMPARE0			(1 << 16)
#define RTC_EVTENSET_OVRFLW			(1 << 1)
#define RTC_EVTENSET_TICK			(1 << 0)
#define RTC_EVTENCLR_COMPARE3			(1 << 19)
#define RTC_EVTENCLR_COMPARE2			(1 << 18)
#define RTC_EVTENCLR_COMPARE1			(1 << 17)
#define RTC_EVTENCLR_COMPARE0			(1 << 16)
#define RTC_EVTENCLR_OVRFLW			(1 << 1)
#define RTC_EVTENCLR_TICK			(1 << 0)
#define RTC_COUNTER_COUNTER			(1 << 0)
#define RTC_COUNTER_COUNTER_MSK			(0xFFFFFFUL << RTC_COUNTER_COUNTER)
#define RTC_PRESCALER_PRESCALER			(1 << 0)
#define RTC_PRESCALER_PRESCALER_MSK		(0xFFFUL << RTC_PRESCALER_PRESCALER)
#define RTC_CC_COMPARE				(1 << 0)
#define RTC_CC_COMPARE_MSK			(0xFFFFFFUL << RTC_CC_COMPARE)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
enum rtc_interrupt {
	rtc_compare3		= 19,
	rtc_compare2		= 18,
	rtc_compare1		= 17,
	rtc_compare0		= 16,
	rtc_ovrflw		= 1,
	rtc_tick		= 0,
};

#define NRF51822_LFCLK			32768

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/
void rtc0_set_prescaler(uint32_t prescaler);
void rtc1_set_prescaler(uint32_t prescaler);

BEGIN_DECLS

/* rtc0 tasks */
static inline void rtc0_start(void)
{
	RTC0_START = 1;
}

static inline void rtc0_stop(void)
{
	RTC0_STOP = 1;
}

static inline void rtc0_clear(void)
{
	RTC0_CLEAR = 1;
}

static inline void rtc0_trigovrfwl(void)
{
	RTC0_TRIGOVRFLW = 1;
}

/* rtc1 tasks */
static inline void rtc1_start(void)
{
	RTC1_START = 1;
}

static inline void rtc1_stop(void)
{
	RTC1_STOP = 1;
}

static inline void rtc1_clear(void)
{
	RTC1_CLEAR = 1;
}

static inline void rtc1_trigovrfwl(void)
{
	RTC1_TRIGOVRFLW = 1;
}

/* rtc0 get/set */
static inline uint32_t rtc0_get_counter(void)
{
	return RTC0_COUNTER;
}

static inline void rtc0_set_cc0(uint32_t value)
{
	RTC0_CC0 = value;
}

static inline void rtc0_set_cc1(uint32_t value)
{
	RTC0_CC1 = value;
}

static inline void rtc0_set_cc2(uint32_t value)
{
	RTC0_CC2 = value;
}

static inline void rtc0_set_cc3(uint32_t value)
{
	RTC0_CC3 = value;
}

/* rtc1 get/set */
static inline uint32_t rtc1_get_counter(void)
{
	return RTC1_COUNTER;
}

static inline void rtc1_set_cc0(uint32_t value)
{
	RTC1_CC0 = value;
}

static inline void rtc1_set_cc1(uint32_t value)
{
	RTC1_CC1 = value;
}

static inline void rtc1_set_cc2(uint32_t value)
{
	RTC1_CC2 = value;
}

static inline void rtc1_set_cc3(uint32_t value)
{
	RTC1_CC3 = value;
}

/* rtc0 interrupts */
static inline void rtc0_enable_intr(enum rtc_interrupt intr)
{
	RTC0_EVTENSET = (1 << intr);
	RTC0_INTENSET = (1 << intr);
}

static inline void rtc0_disable_intr(enum rtc_interrupt intr)
{
	RTC0_EVTENCLR = (1 << intr);
	RTC0_INTENCLR = (1 << intr);
}

static inline uint32_t rtc0_get_intr_source(enum rtc_interrupt intr)
{
	intr &= 31;
	return MMIO32(RTC0_EVENT_BASE + (intr << 2));
}


static inline void rtc0_clear_event(enum rtc_interrupt intr)
{
	intr &= 31;
	MMIO32(RTC0_EVENT_BASE + (intr << 2)) = 0;
}

/* rtc1 interrupts */
static inline void rtc1_enable_intr(enum rtc_interrupt intr)
{
	RTC1_EVTENSET = (1 << intr);
	RTC1_INTENSET = (1 << intr);
}

static inline void rtc1_disable_intr(enum rtc_interrupt intr)
{
	RTC1_EVTENCLR = (1 << intr);
	RTC1_INTENCLR = (1 << intr);
}

static inline uint32_t rtc1_get_intr_source(enum rtc_interrupt intr)
{
	intr &= 31;
	return MMIO32(RTC1_EVENT_BASE + (intr << 2));
}


static inline void rtc1_clear_event(enum rtc_interrupt intr)
{
	intr &= 31;
	MMIO32(RTC1_EVENT_BASE + (intr << 2)) = 0;
}

END_DECLS


#endif
