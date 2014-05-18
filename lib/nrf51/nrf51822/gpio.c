/** @defgroup gpio_file GPIO
 *
 * @ingroup NRF51822
 *
 * @brief <b>libopencm3 NRF51822 General Purpose I/O</b>
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

#include <libopencm3/nrf51/gpio.h>

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO Pin Mode

Sets the Pin Direction, Output Pin Pullup or Pulldown, Drive Mode and Sense Mode
for a  GPIO pin.

*/
void gpio_mode_setup(uint32_t gpios, enum gpio_mode mode,
			enum gpio_pull pull, enum gpio_drive drive,
			enum gpio_sense sense)
{
	uint8_t i;

	for (i = 0; i < 32; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		GPIO_PIN_CNF_N(i) = (mode & CNF_MODE_MSK);
		GPIO_PIN_CNF_N(i) |= (pull & CNF_PULL_MSK) << GPIO_PIN_CNF_PULL;
		GPIO_PIN_CNF_N(i) |= (drive & CNF_DRIVE_MSK) << GPIO_PIN_CNF_DRIVE;
		GPIO_PIN_CNF_N(i) |= (sense & CNF_SENSE_MSK) << GPIO_PIN_CNF_SENSE;
	}
}

/**@}*/
