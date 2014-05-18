/** @defgroup uart_file UART
 *
 * @ingroup NRF51822
 *
 * @brief <b>libopencm3 NRF51822 UART</b>
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

#include <libopencm3/nrf51/uart.h>
#include <libopencm3/nrf51/gpio.h>

void uart_pmux(uint32_t rts_pin, uint32_t txd_pin,
		uint32_t cts_pin, uint32_t rxd_pin)
{
	uint8_t i;
	UART_PSELRTS = UART_PSEL_OFF;
	UART_PSELCTS = UART_PSEL_OFF;

	for (i = 0; i < 32; i++) {
		if ((1 << i) & txd_pin) {
			GPIO_PIN_CNF_N(i) = (GPIO_MODE_OUTPUT & CNF_MODE_MSK);
			UART_PSELTXD = i;
		}
		else if ((1 << i) & rxd_pin) {
			GPIO_PIN_CNF_N(i) = (GPIO_MODE_INPUT & CNF_MODE_MSK);
			UART_PSELRXD = i;
		}
		else if ((1 << i) & rts_pin) {
			GPIO_PIN_CNF_N(i) = (GPIO_MODE_OUTPUT & CNF_MODE_MSK);
			UART_PSELRTS = i;
		}
		else if ((1 << i) & cts_pin) {
			GPIO_PIN_CNF_N(i) = (GPIO_MODE_INPUT & CNF_MODE_MSK);
			UART_PSELCTS = i;
		}
	}
}

void uart_config(enum uart_baudrate baudrate, enum uart_config config)
{
	UART_INTENCLR = 0xFFFFFFFF;
	UART_BAUDRATE = baudrate;
	UART_CONFIG = config;
	uart_enable();
}

void uart_send_blocking(uint8_t data)
{
	uart_wait_send_ready();
	uart_send(data);
}

uint8_t uart_recv_blocking(void)
{
	uart_wait_recv_ready();
	return uart_recv();
}

bool uart_get_error(uint32_t error)
{
	if (UART_ERRORSRC & error) {
		return true;
	}
	return false;
}

/**@}*/
