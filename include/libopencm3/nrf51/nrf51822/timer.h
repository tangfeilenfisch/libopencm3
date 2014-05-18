/** @defgroup timer_defines Timers Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 Timers</b>
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

#ifndef LIBOPENCM3_TIMER_H
#define LIBOPENCM3_TIMER_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/
#define TIMER0_EVENT_BASE			(TIMER0_BASE + 0x100)
#define TIMER1_EVENT_BASE			(TIMER1_BASE + 0x100)
#define TIMER2_EVENT_BASE			(TIMER2_BASE + 0x100)

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define TIMER0_START			MMIO32(TIMER0_BASE + 0x000)
#define TIMER0_STOP			MMIO32(TIMER0_BASE + 0x004)
#define TIMER0_COUNT			MMIO32(TIMER0_BASE + 0x008)
#define TIMER0_CLEAR			MMIO32(TIMER0_BASE + 0x00C)
#define TIMER0_CAPTURE_0		MMIO32(TIMER0_BASE + 0x040)
#define TIMER0_CAPTURE_1		MMIO32(TIMER0_BASE + 0x044)
#define TIMER0_CAPTURE_2		MMIO32(TIMER0_BASE + 0x048)
#define TIMER0_CAPTURE_3		MMIO32(TIMER0_BASE + 0x04C)
#define TIMER1_START			MMIO32(TIMER1_BASE + 0x000)
#define TIMER1_STOP			MMIO32(TIMER1_BASE + 0x004)
#define TIMER1_COUNT			MMIO32(TIMER1_BASE + 0x008)
#define TIMER1_CLEAR			MMIO32(TIMER1_BASE + 0x00C)
#define TIMER1_CAPTURE_0		MMIO32(TIMER1_BASE + 0x040)
#define TIMER1_CAPTURE_1		MMIO32(TIMER1_BASE + 0x044)
#define TIMER1_CAPTURE_2		MMIO32(TIMER1_BASE + 0x048)
#define TIMER1_CAPTURE_3		MMIO32(TIMER1_BASE + 0x04C)
#define TIMER2_START			MMIO32(TIMER2_BASE + 0x000)
#define TIMER2_STOP			MMIO32(TIMER2_BASE + 0x004)
#define TIMER2_COUNT			MMIO32(TIMER2_BASE + 0x008)
#define TIMER2_CLEAR			MMIO32(TIMER2_BASE + 0x00C)
#define TIMER2_CAPTURE_0		MMIO32(TIMER2_BASE + 0x040)
#define TIMER2_CAPTURE_1		MMIO32(TIMER2_BASE + 0x044)
#define TIMER2_CAPTURE_2		MMIO32(TIMER2_BASE + 0x048)
#define TIMER2_CAPTURE_3		MMIO32(TIMER2_BASE + 0x04C)
/* EVENTS */
#define TIMER0_COMPARE_0		MMIO32(TIMER0_BASE + 0x140)
#define TIMER0_COMPARE_1		MMIO32(TIMER0_BASE + 0x144)
#define TIMER0_COMPARE_2		MMIO32(TIMER0_BASE + 0x148)
#define TIMER0_COMPARE_3		MMIO32(TIMER0_BASE + 0x14C)
#define TIMER1_COMPARE_0		MMIO32(TIMER1_BASE + 0x140)
#define TIMER1_COMPARE_1		MMIO32(TIMER1_BASE + 0x144)
#define TIMER1_COMPARE_2		MMIO32(TIMER1_BASE + 0x148)
#define TIMER1_COMPARE_3		MMIO32(TIMER1_BASE + 0x14C)
#define TIMER2_COMPARE_0		MMIO32(TIMER2_BASE + 0x140)
#define TIMER2_COMPARE_1		MMIO32(TIMER2_BASE + 0x144)
#define TIMER2_COMPARE_2		MMIO32(TIMER2_BASE + 0x148)
#define TIMER2_COMPARE_3		MMIO32(TIMER2_BASE + 0x14C)
/* REGISTERS */
#define TIMER0_SHORTS			MMIO32(TIMER0_BASE + 0x200)
#define TIMER0_INTENSET			MMIO32(TIMER0_BASE + 0x304)
#define TIMER0_INTENCLR			MMIO32(TIMER0_BASE + 0x308)
#define TIMER0_MODE			MMIO32(TIMER0_BASE + 0x504)
#define TIMER0_BITMODE			MMIO32(TIMER0_BASE + 0x508)
#define TIMER0_PRESCALER		MMIO32(TIMER0_BASE + 0x510)
#define TIMER0_CC_0			MMIO32(TIMER0_BASE + 0x540)
#define TIMER0_CC_1			MMIO32(TIMER0_BASE + 0x544)
#define TIMER0_CC_2			MMIO32(TIMER0_BASE + 0x548)
#define TIMER0_CC_3			MMIO32(TIMER0_BASE + 0x54C)
#define TIMER1_SHORTS			MMIO32(TIMER1_BASE + 0x200)
#define TIMER1_INTENSET			MMIO32(TIMER1_BASE + 0x304)
#define TIMER1_INTENCLR			MMIO32(TIMER1_BASE + 0x308)
#define TIMER1_MODE			MMIO32(TIMER1_BASE + 0x504)
#define TIMER1_BITMODE			MMIO32(TIMER1_BASE + 0x508)
#define TIMER1_PRESCALER		MMIO32(TIMER1_BASE + 0x510)
#define TIMER1_CC_0			MMIO32(TIMER1_BASE + 0x540)
#define TIMER1_CC_1			MMIO32(TIMER1_BASE + 0x544)
#define TIMER1_CC_2			MMIO32(TIMER1_BASE + 0x548)
#define TIMER1_CC_3			MMIO32(TIMER1_BASE + 0x54C)
#define TIMER2_SHORTS			MMIO32(TIMER2_BASE + 0x200)
#define TIMER2_INTENSET			MMIO32(TIMER2_BASE + 0x304)
#define TIMER2_INTENCLR			MMIO32(TIMER2_BASE + 0x308)
#define TIMER2_MODE			MMIO32(TIMER2_BASE + 0x504)
#define TIMER2_BITMODE			MMIO32(TIMER2_BASE + 0x508)
#define TIMER2_PRESCALER		MMIO32(TIMER2_BASE + 0x510)
#define TIMER2_CC_0			MMIO32(TIMER2_BASE + 0x540)
#define TIMER2_CC_1			MMIO32(TIMER2_BASE + 0x544)
#define TIMER2_CC_2			MMIO32(TIMER2_BASE + 0x548)
#define TIMER2_CC_3			MMIO32(TIMER2_BASE + 0x54C)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define TIMER_SHORTS_COMPARE3_STOP		(1 << 11)
#define TIMER_SHORTS_COMPARE2_STOP		(1 << 10)
#define TIMER_SHORTS_COMPARE1_STOP		(1 << 9)
#define TIMER_SHORTS_COMPARE0_STOP		(1 << 8)
#define TIMER_SHORTS_COMPARE3_CLEAR		(1 << 3)
#define TIMER_SHORTS_COMPARE2_CLEAR		(1 << 2)
#define TIMER_SHORTS_COMPARE1_CLEAR		(1 << 1)
#define TIMER_SHORTS_COMPARE0_CLEAR		(1 << 0)
#define TIMER_INTENSET_COMPARE3			(1 << 19)
#define TIMER_INTENSET_COMPARE2			(1 << 18)
#define TIMER_INTENSET_COMPARE1			(1 << 17)
#define TIMER_INTENSET_COMPARE0			(1 << 16)
#define TIMER_INTENCLR_COMPARE3			(1 << 19)
#define TIMER_INTENCLR_COMPARE2			(1 << 18)
#define TIMER_INTENCLR_COMPARE1			(1 << 17)
#define TIMER_INTENCLR_COMPARE0			(1 << 16)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
enum timer_interrupt {
	timer_compare3		= 19,
	timer_compare2		= 18,
	timer_compare1		= 17,
	timer_compare0		= 16,
};

enum timer_bitmode {
	timer_16bit		= 0,
	timer_8bit		= 1,
	timer_24bit		= 2,
	//timer_32bit		= 3,
};

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/
void timer0_init_1us(void);
void timer0_init_count_mode(void);
void timer0_set_cc_reg(uint8_t reg, uint32_t value, bool short_clear);
uint32_t timer0_get_cc_reg(uint8_t reg);

void timer1_init_1us(void);
void timer1_set_cc_reg(uint8_t reg, uint32_t value, bool short_clear);
uint32_t timer1_get_cc_reg(uint8_t reg);

void timer2_set_cc_reg(uint8_t reg, uint32_t value, bool short_clear);
uint32_t timer2_get_cc_reg(uint8_t reg);

BEGIN_DECLS

/* timer0 */
static inline void timer0_start(void)
{
	TIMER0_START = 1;
}

static inline void timer0_stop(void)
{
	TIMER0_STOP = 1;
}

/* timer0_count has no effect in timer mode */
static inline void timer0_count(void)
{
	TIMER0_COUNT = 1;
}

static inline void timer0_clear(void)
{
	TIMER0_CLEAR = 1;
}

static inline uint32_t timer0_capture_cc0(void)
{
	TIMER0_CAPTURE_0 = 1;
	return TIMER0_CC_0;
}

static inline uint32_t timer0_capture_cc1(void)
{
	TIMER0_CC_1 = 1;
	return TIMER0_CC_1;
}

static inline uint32_t timer0_capture_cc2(void)
{
	TIMER0_CC_2 = 1;
	return TIMER0_CC_2;
}

static inline uint32_t timer0_capture_cc3(void)
{
	TIMER0_CC_3 = 1;
	return TIMER0_CC_3;
}

static inline void timer0_timer_mode(void)
{
	TIMER0_MODE = 0;
}

static inline void timer0_counter_mode(void)
{
	TIMER0_MODE = 1;
}

static inline void timer0_set_prescaler(uint32_t value)
{
	TIMER0_PRESCALER = value;
}

static inline void timer0_set_bitmode(enum timer_bitmode mode)
{
	TIMER0_BITMODE = mode;
}

/* timer0 interrupts */
static inline void timer0_enable_intr(enum timer_interrupt intr)
{
	TIMER0_INTENSET = (1 << intr);
}

static inline void timer0_disable_intr(enum timer_interrupt intr)
{
	TIMER0_INTENCLR = (1 << intr);
}

static inline void timer0_disable_all_intrs(void)
{
	TIMER0_INTENCLR = 0;
}

static inline uint32_t timer0_get_intr_source(enum timer_interrupt intr)
{
	intr &= 31;
	return MMIO32(TIMER0_EVENT_BASE + (intr << 2));
}


static inline void timer0_clear_event(enum timer_interrupt intr)
{
	intr &= 31;
	MMIO32(TIMER0_EVENT_BASE + (intr << 2)) = 0;
}

static inline void timer0_clear_all_events(void)
{
	TIMER0_COMPARE_0 = 0;
	TIMER0_COMPARE_1 = 0;
	TIMER0_COMPARE_2 = 0;
	TIMER0_COMPARE_3 = 0;
}

/* timer1 */
static inline void timer1_start(void)
{
	TIMER1_START = 1;
}

static inline void timer1_stop(void)
{
	TIMER1_STOP = 1;
}

/* timer1_count has no effect in timer mode */
static inline void timer1_count(void)
{
	TIMER1_COUNT = 1;
}

static inline void timer1_clear(void)
{
	TIMER1_CLEAR = 1;
}

static inline uint32_t timer1_capture_cc0(void)
{
	TIMER1_CC_0 = 1;
	return TIMER1_CC_0;
}

static inline uint32_t timer1_capture_cc1(void)
{
	TIMER1_CC_1 = 1;
	return TIMER1_CC_1;
}

static inline uint32_t timer1_capture_cc2(void)
{
	TIMER1_CC_2 = 1;
	return TIMER1_CC_2;
}

static inline uint32_t timer1_capture_cc3(void)
{
	TIMER1_CC_3 = 1;
	return TIMER1_CC_3;
}

static inline void timer1_timer_mode(void)
{
	TIMER1_MODE = 0;
}

static inline void timer1_counter_mode(void)
{
	TIMER1_MODE = 1;
}

static inline void timer1_set_prescaler(uint32_t value)
{
	TIMER1_PRESCALER = value;
}

static inline void timer1_set_bitmode(enum timer_bitmode mode)
{
	TIMER1_BITMODE = mode;
}

/* timer1 interrupts */
static inline void timer1_enable_intr(enum timer_interrupt intr)
{
	TIMER1_INTENSET = (1 << intr);
}

static inline void timer1_disable_intr(enum timer_interrupt intr)
{
	TIMER1_INTENCLR = (1 << intr);
}

static inline void timer1_disable_all_intrs(void)
{
	TIMER1_INTENCLR = 0;
}

static inline uint32_t timer1_get_intr_source(enum timer_interrupt intr)
{
	intr &= 31;
	return MMIO32(TIMER1_EVENT_BASE + (intr << 2));
}


static inline void timer1_clear_event(enum timer_interrupt intr)
{
	intr &= 31;
	MMIO32(TIMER1_EVENT_BASE + (intr << 2)) = 0;
}

static inline void timer1_clear_all_events(void)
{
	TIMER1_COMPARE_0 = 0;
	TIMER1_COMPARE_1 = 0;
	TIMER1_COMPARE_2 = 0;
	TIMER1_COMPARE_3 = 0;
}

END_DECLS

#endif

