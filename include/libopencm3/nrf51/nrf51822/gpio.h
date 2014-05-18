/** @defgroup gpio_defines GPIO Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 GPIO </b>
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
 * based on LM4Fxx gpio defines:
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

#ifndef LIBOPENCM3_GPIO_H
#define LIBOPENCM3_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
#define GPIO_OUT			MMIO32(GPIO_P0_BASE + 0x504)
#define GPIO_OUTSET			MMIO32(GPIO_P0_BASE + 0x508)
#define GPIO_OUTCLR			MMIO32(GPIO_P0_BASE + 0x50C)
#define GPIO_IN				MMIO32(GPIO_P0_BASE + 0x510)
#define GPIO_DIR			MMIO32(GPIO_P0_BASE + 0x514)
#define GPIO_DIRSET			MMIO32(GPIO_P0_BASE + 0x518)
#define GPIO_DIRCLR			MMIO32(GPIO_P0_BASE + 0x51C)
//#define GPIO_PIN_CNF_0		MMIO32(GPIO_P0_BASE + 0x700)
#define GPIO_PIN_CNF_N(n)		MMIO32(GPIO_P0_BASE + 0x700 + (n << 2))
//#define GPIO_PIN_CNF_31		MMIO32(GPIO_P0_BASE + 0x77C)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
/** @defgroup gpio_pin_id GPIO pin identifiers
 * @{*/
#define GPIO31				(1 << 31)
#define GPIO30				(1 << 30)
#define GPIO29				(1 << 29)
#define GPIO28				(1 << 28)
#define GPIO27				(1 << 27)
#define GPIO26				(1 << 26)
#define GPIO25				(1 << 25)
#define GPIO24				(1 << 24)
#define GPIO23				(1 << 23)
#define GPIO22				(1 << 22)
#define GPIO21				(1 << 21)
#define GPIO20				(1 << 20)
#define GPIO19				(1 << 19)
#define GPIO18				(1 << 18)
#define GPIO17				(1 << 17)
#define GPIO16				(1 << 16)
#define GPIO15				(1 << 15)
#define GPIO14				(1 << 14)
#define GPIO13				(1 << 13)
#define GPIO12				(1 << 12)
#define GPIO11				(1 << 11)
#define GPIO10				(1 << 10)
#define GPIO9				(1 << 9)
#define GPIO8				(1 << 8)
#define GPIO7				(1 << 7)
#define GPIO6				(1 << 6)
#define GPIO5				(1 << 5)
#define GPIO4				(1 << 4)
#define GPIO3				(1 << 3)
#define GPIO2				(1 << 2)
#define GPIO1				(1 << 1)
#define GPIO0				(1 << 0)
#define GPIO_ALL			0xFFFFFFFF
/** @} */

#define GPIO_PIN_CNF_SENSE		16
#define CNF_SENSE_MSK			3
#define GPIO_PIN_CNF_DRIVE		8
#define CNF_DRIVE_MSK			7
#define GPIO_PIN_CNF_PULL		2
#define CNF_PULL_MSK			3
#define GPIO_PIN_CNF_INPUT		1
#define GPIO_PIN_CNF_DIR		0
#define CNF_MODE_MSK			3

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
enum gpio_mode {
	GPIO_MODE_INPUT,		/**< Configure pin as input */
	GPIO_MODE_OUTPUT,		/**< Configure pin as output */
	GPIO_MODE_DISCONNECT,		/**< Disconnect input buffer */
	GPIO_MODE_OUTPUT_DISCONNECT,	/**< output, disconnect input buffer*/
};

enum gpio_pull {
	GPIO_PUPD_NONE,			/**< Do not pull the pin high or low */
	GPIO_PUPD_PULLDOWN,		/**< Pull the pin low */
	GPIO_PUPD_UNDEFINED,
	GPIO_PUPD_PULLUP,		/**< Pull the pin high */
};

enum gpio_drive {
	S0S1,				/**< Standard 0, standard 1 */
	H0S1,				/**< High drive 0, standard 1 */
	S0H1,				/**< Standard 0, high drive 1 */
	H0H1,				/**< High drive 0, high drive 1 */
	D0S1,				/**< Disconnect 0, standard 1 */
	D0H1,				/**< Disconnect 0, high drive 1 */
	S0D1,				/**< Standard 0, disconnect 1 */
	H0D1,				/**< High drive 0, disconnect 1 */
};

enum gpio_sense {
	GPIO_SENSE_DISABLED,
	GPIO_SENSE_UNDEFINED,
	GPIO_SENSE_HIGH,	/**< Sensing for high level */
	GPIO_SENSE_LOW,		/**< Sensing for low level */
};

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void gpio_mode_setup(uint32_t gpiopin, enum gpio_mode mode,
		enum gpio_pull pull, enum gpio_drive drive,
		enum gpio_sense sense);

/** @ingroup gpio_control
 * @{ */

/*---------------------------------------------------------------------------*/
/** @brief Read level of all pins from GPIO port (atomic)

@return The level of all 32 pins on the GPIO port.
*/
static inline uint32_t gpio_port_read(void)
{
	return GPIO_IN;
}

/*---------------------------------------------------------------------------*/
/** @brief Read a Group of Pins.

@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
If multiple pins are to be read, use logical OR '|' to separate them.

@return uint32_t value of the pin values. The bit position of the pin
value returned corresponds to the pin number.
*/
static inline uint32_t gpio_get(uint32_t gpios)
{
	return GPIO_IN & gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Write to GPIO Port (atomic)

Write a value to the given GPIO port.

@param[in] data uint32_t. The value to be written to the GPIO port.
*/
static inline void gpio_port_write(uint32_t data)
{
	GPIO_OUT = data;
}

/*---------------------------------------------------------------------------*/
/** @brief Toggle a Group of Pins

Toggle one or more pins of the given GPIO port. This is not an atomic operation.

@param[in] gpios uint32_t. Pin identifiers @ref gpio_pin_id
If multiple pins are to be changed, use logical OR '|' to separate them.
*/
static inline void gpio_toggle(uint32_t gpios)
{
	GPIO_OUT ^= gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Set a Group of Pins (atomic)

Set one or more pins of the given GPIO port to 1 in an atomic operation.

@param[in] gpios uint32_t. Pin identifiers @ref gpio_pin_id
If multiple pins are to be changed, use logical OR '|' to separate them.
*/
static inline void gpio_set(uint32_t gpios)
{
	GPIO_OUTSET = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear a Group of Pins (atomic)

Clear one or more pins of the given GPIO port to 0 in an atomic operation.

@param[in] gpios uint32_t. Pin identifiers @ref gpio_pin_id
If multiple pins are to be changed, use logical OR '|' to separate them.
*/
static inline void  gpio_clear(uint32_t gpios)
{
	GPIO_OUTCLR = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Direction of Pins (atomic)

Set the direction of all pins in the given GPIO port in an atomic operation.

@param[in] gpios uint32_t. Pin identifiers @ref gpio_pin_id
A '1' will configure the corresponding pin as output, '0' as input.
If multiple pins are to be set as output, use logical OR '|' to group them.
*/
static inline void gpio_direction(uint32_t gpios)
{
	GPIO_DIR = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Set a Direction of Pins (atomic)

Set the direction of one or more pins in the given GPIO port in an atomic operation.

@param[in] gpios uint32_t. Pin identifiers @ref gpio_pin_id
If multiple pins are to be changed, use logical OR '|' to separate them.
*/
static inline void gpio_dirset(uint32_t gpios)
{
	GPIO_DIRSET = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear a Direction of Pins (atomic)

Clear the direction of one or more pins in the given GPIO port in an atomic operation.

@param[in] gpios uint32_t. Pin identifiers @ref gpio_pin_id
If multiple pins are to be changed, use logical OR '|' to separate them.
*/
static inline void  gpio_dirclear(uint32_t gpios)
{
	GPIO_DIRCLR = gpios;
}

/** @} */
END_DECLS

#endif
