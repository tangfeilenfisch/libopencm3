/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Johann Fischer j.fischer_at_fh-bingen_de
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

#include <libopencm3/nrf51/pwr.h>

static void prelaunch(void)
{
	/* NRF51822 Product Anomaly Notice */

	/* PAN ID 16 */
	/* POWER: RAMON reset value causes problems under certain conditions.*/
	PWR_RAMON = PWR_RAMON_ONALL;

	/* PAN ID 42 */
	/* Do not access RAM for 0.5 us after a reset or enabling a RAM block.*/

	/* PAN ID 26 */
	/* System: Manual setup is required to enable use of peripherals.*/
	if ((((*(uint32_t *)0xF0000FE8) >> 4) & 0x0000000F) == 1)
	{
		*(uint32_t *)0x40000504 = 0xC007FFDF; 
		*(uint32_t *)0x40006C18 = 0x00008000;
	}
}
