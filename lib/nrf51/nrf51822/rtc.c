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

#include <libopencm3/nrf51/rtc.h>


inline void rtc0_set_prescaler(uint32_t prescaler)
{
	/* stop RTC -> set prescaler -> start RTC */
	rtc0_stop();
	rtc0_clear();
	RTC0_PRESCALER = prescaler;
	rtc0_start();
}

inline void rtc1_set_prescaler(uint32_t prescaler)
{
	/* stop RTC -> set prescaler -> start RTC */
	rtc1_stop();
	rtc1_clear();
	RTC1_PRESCALER = prescaler;
	rtc1_start();
}

/**@}*/
