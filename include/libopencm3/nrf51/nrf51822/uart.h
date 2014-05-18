/** @defgroup uart_defines UART Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 UART</b>
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

#ifndef LIBOPENCM3_UART_H
#define LIBOPENCM3_UART_H

#include <libopencm3/nrf51/memorymap.h>
#include <libopencm3/cm3/common.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/
#define UART_EVENT_BASE			(UART_BASE + 0x100)

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define UART_STARTRX			MMIO32(UART_BASE + 0x000)
#define UART_STOPRX			MMIO32(UART_BASE + 0x004)
#define UART_STARTTX			MMIO32(UART_BASE + 0x008)
#define UART_STOPTX			MMIO32(UART_BASE + 0x00C)
/* EVENTS */
#define UART_RXDRDY			MMIO32(UART_BASE + 0x108)
#define UART_TXDRDY			MMIO32(UART_BASE + 0x11C)
#define UART_ERROR			MMIO32(UART_BASE + 0x124)
#define UART_RXTO			MMIO32(UART_BASE + 0x144)
/* REGISTERS */
#define UART_INTENSET			MMIO32(UART_BASE + 0x304)
#define UART_INTENCLR			MMIO32(UART_BASE + 0x308)
#define UART_ERRORSRC			MMIO32(UART_BASE + 0x480)
#define UART_ENABLE			MMIO32(UART_BASE + 0x500)
#define UART_PSELRTS			MMIO32(UART_BASE + 0x508)
#define UART_PSELTXD			MMIO32(UART_BASE + 0x50C)
#define UART_PSELCTS			MMIO32(UART_BASE + 0x510)
#define UART_PSELRXD			MMIO32(UART_BASE + 0x514)
#define UART_RXD			MMIO32(UART_BASE + 0x518)
#define UART_TXD			MMIO32(UART_BASE + 0x51C)
#define UART_BAUDRATE			MMIO32(UART_BASE + 0x524)
#define UART_CONFIG			MMIO32(UART_BASE + 0x56C)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define UART_INTENSET_RXTO			(1 << 17)
#define UART_INTENSET_ERROR			(1 << 9)
#define UART_INTENSET_TXDRDY			(1 << 7)
#define UART_INTENSET_RXDRDY			(1 << 2)
#define UART_INTENCLR_RXTO			(1 << 17)
#define UART_INTENCLR_ERROR			(1 << 9)
#define UART_INTENCLR_TXDRDY			(1 << 7)
#define UART_INTENCLR_RXDRDY			(1 << 2)

#define UART_ERRORSRC_BREAK			(1 << 3)
#define UART_ERRORSRC_FRAMING			(1 << 2)
#define UART_ERRORSRC_PARITY			(1 << 1)
#define UART_ERRORSRC_OVERRUN			(1 << 0)
#define UART_ERRORSRC_ALL			0xF

#define UART_ENABLE_ENABLE			0x4

#define UART_BAUDRATE_1200			(0x0004F000)
#define UART_BAUDRATE_2400			(0x0009D000)
#define UART_BAUDRATE_4800			(0x0013B000)
#define UART_BAUDRATE_9600			(0x00275000)
#define UART_BAUDRATE_14400			(0x003B0000)
#define UART_BAUDRATE_19200			(0x004EA000)
#define UART_BAUDRATE_28800			(0x0075F000)
#define UART_BAUDRATE_38400			(0x009D5000)
#define UART_BAUDRATE_57600			(0x00EBF000)
#define UART_BAUDRATE_76800			(0x013A9000)
#define UART_BAUDRATE_115200			(0x01D7E000)
#define UART_BAUDRATE_230400			(0x03AFB000)
#define UART_BAUDRATE_250000			(0x04000000)
#define UART_BAUDRATE_460800			(0x075F7000)
#define UART_BAUDRATE_921600			(0x0EBEDFA4)
#define UART_BAUDRATE_1M			(0x10000000)

#define UART_CONFIG_PARITY_POS			(1 << 1)
#define UART_CONFIG_PARITY_INCLUDE		(0)
#define UART_CONFIG_PARITY_EXCLUDE		(7)
#define UART_CONFIG_HWFC			(1 << 0)

#define UART_PSEL_OFF				(0xFFFFFFFF)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
enum uart_baudrate {
	baudrate_1200			= 0x0004f000,
	baudrate_2400			= 0x0009d000,
	baudrate_4800			= 0x0013b000,
	baudrate_9600			= 0x00275000,
	baudrate_14400			= 0x003b0000,
	baudrate_19200			= 0x004ea000,
	baudrate_28800			= 0x0075f000,
	baudrate_38400			= 0x009d5000,
	baudrate_57600			= 0x00ebf000,
	baudrate_76800			= 0x013a9000,
	baudrate_115200			= 0x01d7e000,
	baudrate_230400			= 0x03afb000,
	baudrate_250000			= 0x04000000,
	baudrate_460800			= 0x075f7000,
	baudrate_921600			= 0x0ebedfa4,
	baudrate_1m			= 0x10000000,
};

enum uart_config {
	pbit_off_hwflow_off		= 0x0,
	pbit_off_hwflow_on		= 0x1,
	pbit_on_hwflow_off		= 0xe,
	pbit_on_hwflow_on		= 0xf,
};

enum uart_interrupt {
	uart_intr_rxdrdy		= 2,
	uart_intr_txdrdy		= 7,
	uart_intr_error			= 9,
	uart_intr_rxto			= 17,
};


/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void uart_pmux(uint32_t rts_pin, uint32_t txd_pin,
		uint32_t cts_pin, uint32_t rxd_pin);
void uart_config(enum uart_baudrate baudrate, enum uart_config config);
void uart_send_blocking(uint8_t data);
uint8_t uart_recv_blocking(void);
bool uart_get_error(uint32_t error);
bool uart_get_interrupt_source(uint32_t flag);

static inline void uart_enable(void)
{
	UART_ENABLE = UART_ENABLE_ENABLE;
	UART_STARTTX = 1;
	UART_STARTRX = 1;
}

static inline void uart_disable(void)
{
	UART_ENABLE = 0;
	UART_STOPTX = 1;
	UART_STOPRX = 1;
}

static inline void uart_send(uint8_t data)
{
	UART_TXD = (uint32_t)data;
}

static inline uint8_t uart_recv(void)
{
	return (uint8_t)UART_RXD;
}

static inline void uart_wait_send_ready(void)
{
	while (UART_TXDRDY == 0);
}

static inline void uart_wait_recv_ready(void)
{
	while (UART_RXDRDY == 0);
}

static inline void uart_enable_intr(enum uart_interrupt intr)
{
	UART_INTENSET = (1 << intr);
}

static inline void uart_disable_intr(enum uart_interrupt intr)
{
	UART_INTENCLR = (1 << intr);
}

static inline uint32_t uart_get_intr_source(enum uart_interrupt intr)
{
	intr &= 31;
	return MMIO32(UART_EVENT_BASE + (intr << 2));
}

static inline void uart_clear_event(enum uart_interrupt intr)
{
	intr &= 31;
	MMIO32(UART_EVENT_BASE + (intr << 2)) = 0;
}

static inline void uart_clear_error(uint32_t error)
{
	UART_ERRORSRC = error;
}

END_DECLS

#endif

