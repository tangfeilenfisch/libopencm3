/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENCM3_CM3_COMMON_H
#define LIBOPENCM3_CM3_COMMON_H

#include <stdint.h>
#include <stdbool.h>

/* This must be placed around external function declaration for C++
 * support. */
#ifdef __cplusplus
# define BEGIN_DECLS extern "C" {
# define END_DECLS }
#else
# define BEGIN_DECLS
# define END_DECLS
#endif

/* Full-featured deprecation attribute with fallback for older compilers. */

#ifdef __GNUC__
#	if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ > 4)
#		define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated(x)))
#	else
#		define LIBOPENCM3_DEPRECATED(x) __attribute__((deprecated))
#	endif
#else
#	define LIBOPENCM3_DEPRECATED(x)
#endif


/* Generic memory-mapped I/O accessor functions */
#define MMIO8(addr)		(*(volatile uint8_t *)(addr))
#define MMIO16(addr)		(*(volatile uint16_t *)(addr))
#define MMIO32(addr)		(*(volatile uint32_t *)(addr))
#define MMIO64(addr)		(*(volatile uint64_t *)(addr))

/* Generic bit-band I/O accessor functions */
#define BBIO_SRAM(addr, bit) \
	MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x22000000 + (bit) * 4)

#define BBIO_PERIPH(addr, bit) \
	MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x42000000 + (bit) * 4)

/* Generic bit definition */
#ifndef BIT0 
#define BIT0  (1<<0)
#endif

#ifndef BIT1 
#define BIT1  (1<<1)
#endif

#ifndef BIT2 
#define BIT2  (1<<2)
#endif

#ifndef BIT3 
#define BIT3  (1<<3)
#endif

#ifndef BIT4 
#define BIT4  (1<<4)
#endif

#ifndef BIT5 
#define BIT5  (1<<5)
#endif

#ifndef BIT6 
#define BIT6  (1<<6)
#endif

#ifndef BIT7 
#define BIT7  (1<<7)
#endif

#ifndef BIT8 
#define BIT8  (1<<8)
#endif

#ifndef BIT9 
#define BIT9  (1<<9)
#endif

#ifndef BIT10
#define BIT10 (1<<10)
#endif

#ifndef BIT11
#define BIT11 (1<<11)
#endif

#ifndef BIT12
#define BIT12 (1<<12)
#endif

#ifndef BIT13
#define BIT13 (1<<13)
#endif

#ifndef BIT14
#define BIT14 (1<<14)
#endif

#ifndef BIT15
#define BIT15 (1<<15)
#endif

#ifndef BIT16
#define BIT16 (1<<16)
#endif

#ifndef BIT17
#define BIT17 (1<<17)
#endif

#ifndef BIT18
#define BIT18 (1<<18)
#endif

#ifndef BIT19
#define BIT19 (1<<19)
#endif

#ifndef BIT20
#define BIT20 (1<<20)
#endif

#ifndef BIT21
#define BIT21 (1<<21)
#endif

#ifndef BIT22
#define BIT22 (1<<22)
#endif

#ifndef BIT23
#define BIT23 (1<<23)
#endif

#ifndef BIT24
#define BIT24 (1<<24)
#endif

#ifndef BIT25
#define BIT25 (1<<25)
#endif

#ifndef BIT26
#define BIT26 (1<<26)
#endif

#ifndef BIT27
#define BIT27 (1<<27)
#endif

#ifndef BIT28
#define BIT28 (1<<28)
#endif

#ifndef BIT29
#define BIT29 (1<<29)
#endif

#ifndef BIT30
#define BIT30 (1<<30)
#endif

#ifndef BIT31
#define BIT31 (1<<31)
#endif

/* might be provided by os specific init */
void __attribute__((weak)) libopencm3_os_spec_init(void);

#endif
