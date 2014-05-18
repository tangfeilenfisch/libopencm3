/** @defgroup rng_file rng
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

#include <libopencm3/nrf51/rng.h>


uint8_t rng_get_octet(void)
{
	uint8_t rnd;
	rng_dercen_enable();

	rng_start();
	rng_wait_valrdy();
	/* read gen. random number  before the 
	 * valrdy event is cleared, see nRF51822-PAN */
	rnd = RNG_VALUE;
	rng_clear_event(rng_valrdy);
	rng_stop();

	return rnd;
}

void rng_get_eight_octets(uint8_t *buf)
{
	int i;

	rng_dercen_enable();

	for (i = 0; i < 8; i++){
		rng_start();
		rng_wait_valrdy();
		buf[i] = RNG_VALUE;
		rng_clear_event(rng_valrdy);
		rng_stop();
	}

}

/**@}*/
