/** @defgroup rcc_file RCC
 *
 * @ingroup NRF51822
 *
 * @brief <b>libopencm3 NRF51822 Reset and Clock Control</b>
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

#include <libopencm3/nrf51/rcc.h>

/*---------------------------------------------------------------------------*/
/** @brief Start calibration of LFCLK RC oscillator.
*/
bool rcc_start_lfrc_calibration(void)
{
	if (RCC_HFCLKSTAT & (RCC_HFCLKSTAT_SRC_XTAL)) {
		if (RCC_LFCLKSTAT == RCC_LFCLKSTAT_STATE_RUN) {
			RCC_CAL = 1;
			while (RCC_DONE == 0);
			return true;
		}
	}
	return false;
}

/*---------------------------------------------------------------------------*/
/** @brief Setup and start HF and LF clock oscillators
*/
bool rcc_sysclk_config(enum xtalfreq freq, enum lf_src src, bool lfrc_cal)
{
	rcc_hfclkstart(freq);
	rcc_lfclkstart(src);
	if (lfrc_cal) {
		return rcc_start_lfrc_calibration();
	}
	return true;
}

/**@}*/
