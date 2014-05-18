/** @defgroup uart_file UART
 *
 * @ingroup NRF51822
 *
 * @brief <b>libopencm3 NRF51822 radio, ble only</b>
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

#include <libopencm3/nrf51/timer.h>

struct nrf51_timer {
	uint32_t  start;
	uint32_t  stop;
	uint32_t  count;
	uint32_t  clear;
	uint32_t  gap0[12];
	uint32_t  capture[4];
	uint32_t  gap1[60];
	uint32_t  compare[4];
	uint32_t  gap2[44];
	uint32_t  shorts;
	uint32_t  gap3[64];
	uint32_t  intenset;
	uint32_t  intenclr;
	uint32_t  gap4[126];
	uint32_t  mode;
	uint32_t  bitmode;
	uint32_t  gap5;
	uint32_t  prescaler;
	uint32_t  gap6[11];
	uint32_t  cc[4];
};

static struct nrf51_timer *timer0_reg = (struct nrf51_timer*)(TIMER0_BASE);
static struct nrf51_timer *timer1_reg = (struct nrf51_timer*)(TIMER1_BASE);
static struct nrf51_timer *timer2_reg = (struct nrf51_timer*)(TIMER2_BASE);

void timer0_set_cc_reg(uint8_t reg, uint32_t value, bool short_clear)
{
	reg &= 3;
	timer0_reg->cc[reg] = value;
	if (short_clear) {
		TIMER0_SHORTS = (1 << reg);
	}

}

inline uint32_t timer0_get_cc_reg(uint8_t reg)
{
	reg &= 3;
	return timer0_reg->cc[reg];
}

void timer1_set_cc_reg(uint8_t reg, uint32_t value, bool short_clear)
{
	reg &= 3;
	timer1_reg->cc[reg] = value;
	if (short_clear) {
		TIMER1_SHORTS = (1 << reg);
	}

}

inline uint32_t timer1_get_cc_reg(uint8_t reg)
{
	reg &= 3;
	return timer1_reg->cc[reg];
}

void timer2_set_cc_reg(uint8_t reg, uint32_t value, bool short_clear)
{
	reg &= 3;
	timer2_reg->cc[reg] = value;
	if (short_clear) {
		TIMER1_SHORTS = (1 << reg);
	}

}

inline uint32_t timer2_get_cc_reg(uint8_t reg)
{
	reg &= 3;
	return timer2_reg->cc[reg];
}

/*---------------------------------------------------------------------------*/
/** @brief ...
*
* nRF51822-PAN v2.2:
* timer0 can only be used as a 24 bit timer
*/
void timer0_init_1us(void)
{
	timer0_stop();
	timer0_disable_all_intrs();
	timer0_clear();
	timer0_timer_mode();
	timer0_clear_all_events();

	timer0_set_prescaler(4);
	timer0_set_bitmode(timer_24bit);
}

void timer0_init_count_mode(void)
{
	timer0_stop();
	timer0_disable_all_intrs();
	timer0_clear();
	timer0_counter_mode();
	timer0_clear_all_events();

	timer0_set_bitmode(timer_24bit);
}

void timer1_init_1us(void)
{
	timer1_stop();
	timer1_disable_all_intrs();
	timer1_clear();
	timer1_timer_mode();
	timer1_clear_all_events();

	timer1_set_prescaler(4);
	timer1_set_bitmode(timer_16bit);
}
/**@}*/
