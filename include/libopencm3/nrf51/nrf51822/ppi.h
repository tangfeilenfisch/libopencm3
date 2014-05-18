/** @defgroup ppi_defines PPI Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 
 * Programmable Peripheral Interconnect</b>
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

#ifndef LIBOPENCM3_PPI_H
#define LIBOPENCM3_PPI_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

#include <libopencm3/nrf51/timer.h>
#include <libopencm3/nrf51/radio.h>
/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define PPI_CHG0_EN			MMIO32(PPI_BASE + 0x000)
#define PPI_CHG0_DIS			MMIO32(PPI_BASE + 0x004)
#define PPI_CHG1_EN			MMIO32(PPI_BASE + 0x008)
#define PPI_CHG1_DIS			MMIO32(PPI_BASE + 0x00C)
#define PPI_CHG2_EN			MMIO32(PPI_BASE + 0x010)
#define PPI_CHG2_DIS			MMIO32(PPI_BASE + 0x014)
#define PPI_CHG3_EN			MMIO32(PPI_BASE + 0x018)
#define PPI_CHG3_DIS			MMIO32(PPI_BASE + 0x01C)
/* REGISTERS */
#define PPI_CHEN			MMIO32(PPI_BASE + 0x500)
#define PPI_CHENSET			MMIO32(PPI_BASE + 0x504)
#define PPI_CHENCLR			MMIO32(PPI_BASE + 0x508)
#define PPI_CH0_EEP			MMIO32(PPI_BASE + 0x510)
#define PPI_CH0_TEP			MMIO32(PPI_BASE + 0x514)
#define PPI_CH1_EEP			MMIO32(PPI_BASE + 0x518)
#define PPI_CH1_TEP			MMIO32(PPI_BASE + 0x51C)
#define PPI_CH2_EEP			MMIO32(PPI_BASE + 0x520)
#define PPI_CH2_TEP			MMIO32(PPI_BASE + 0x524)
#define PPI_CH3_EEP			MMIO32(PPI_BASE + 0x528)
#define PPI_CH3_TEP			MMIO32(PPI_BASE + 0x52C)
#define PPI_CH4_EEP			MMIO32(PPI_BASE + 0x530)
#define PPI_CH4_TEP			MMIO32(PPI_BASE + 0x534)
#define PPI_CH5_EEP			MMIO32(PPI_BASE + 0x538)
#define PPI_CH5_TEP			MMIO32(PPI_BASE + 0x53C)
#define PPI_CH6_EEP			MMIO32(PPI_BASE + 0x540)
#define PPI_CH6_TEP			MMIO32(PPI_BASE + 0x544)
#define PPI_CH7_EEP			MMIO32(PPI_BASE + 0x548)
#define PPI_CH7_TEP			MMIO32(PPI_BASE + 0x54C)
#define PPI_CH8_EEP			MMIO32(PPI_BASE + 0x550)
#define PPI_CH8_TEP			MMIO32(PPI_BASE + 0x554)
#define PPI_CH9_EEP			MMIO32(PPI_BASE + 0x558)
#define PPI_CH9_TEP			MMIO32(PPI_BASE + 0x55C)
#define PPI_CH10_EEP			MMIO32(PPI_BASE + 0x560)
#define PPI_CH10_TEP			MMIO32(PPI_BASE + 0x564)
#define PPI_CH11_EEP			MMIO32(PPI_BASE + 0x568)
#define PPI_CH11_TEP			MMIO32(PPI_BASE + 0x56C)
#define PPI_CH12_EEP			MMIO32(PPI_BASE + 0x570)
#define PPI_CH12_TEP			MMIO32(PPI_BASE + 0x574)
#define PPI_CH13_EEP			MMIO32(PPI_BASE + 0x578)
#define PPI_CH13_TEP			MMIO32(PPI_BASE + 0x57C)
#define PPI_CH14_EEP			MMIO32(PPI_BASE + 0x580)
#define PPI_CH14_TEP			MMIO32(PPI_BASE + 0x584)
#define PPI_CH15_EEP			MMIO32(PPI_BASE + 0x588)
#define PPI_CH15_TEP			MMIO32(PPI_BASE + 0x58C)
#define PPI_CHG_0			MMIO32(PPI_BASE + 0x800)
#define PPI_CHG_1			MMIO32(PPI_BASE + 0x804)
#define PPI_CHG_2			MMIO32(PPI_BASE + 0x808)
#define PPI_CHG_3			MMIO32(PPI_BASE + 0x80C)
/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define PPI_CH31			(1 << 31)
#define PPI_CH30			(1 << 30)
#define PPI_CH29			(1 << 29)
#define PPI_CH28			(1 << 28)
#define PPI_CH27			(1 << 27)
#define PPI_CH26			(1 << 26)
#define PPI_CH25			(1 << 25)
#define PPI_CH24			(1 << 24)
#define PPI_CH23			(1 << 23)
#define PPI_CH22			(1 << 22)
#define PPI_CH21			(1 << 21)
#define PPI_CH20			(1 << 20)
#define PPI_CH15			(1 << 15)
#define PPI_CH14			(1 << 14)
#define PPI_CH13			(1 << 13)
#define PPI_CH12			(1 << 12)
#define PPI_CH11			(1 << 11)
#define PPI_CH10			(1 << 10)
#define PPI_CH9				(1 << 9)
#define PPI_CH8				(1 << 8)
#define PPI_CH7				(1 << 7)
#define PPI_CH6				(1 << 6)
#define PPI_CH5				(1 << 5)
#define PPI_CH4				(1 << 4)
#define PPI_CH3				(1 << 3)
#define PPI_CH2				(1 << 2)
#define PPI_CH1				(1 << 1)
#define PPI_CH0				(1 << 0)

#define PPI_TIMER0_CMP0_RF_TXEN		PPI_CH20
#define PPI_TIMER0_CMP0_RF_RXEN		PPI_CH21
#define PPI_TIMER0_CMP1_RF_DIS		PPI_CH22
#define PPI_RF_BCMATCH_AAR_START	PPI_CH23
#define PPI_RF_READY_CCM_KSGEN		PPI_CH24
#define PPI_RF_ADR_CCM_CRYPT		PPI_CH25
#define PPI_RF_ADR_TIMER0_CAP1		PPI_CH26
#define PPI_RF_END_TIMER0_CAP2		PPI_CH27
#define PPI_RTC0_CMP0_RF_TXEN		PPI_CH28
#define PPI_RTC0_CMP0_RF_RXEN		PPI_CH29
#define PPI_RTC0_CMP0_RF_CLEAR		PPI_CH30
#define PPI_RTC0_CMP0_RF_START		PPI_CH31

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
struct task_channel_group {
	uint32_t enable;
	uint32_t disable;
};

struct channel_endpoints {
	uint32_t event;
	uint32_t task;
};

struct ppi_system {
	struct task_channel_group task_chg[4];
	uint32_t  gap0[312];
	uint32_t  chen;
	uint32_t  chenset;
	uint32_t  chenclr;
	uint32_t  gap1;
	struct channel_endpoints che[16];
	uint32_t  gap2[156];
	uint32_t  chg[4];
};

static struct ppi_system *ppi = (struct ppi_system*)(PPI_BASE);

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

/* ch0 - ch8 reserved for ble phy*/

static inline void ppi_setup_for_ble(void)
{
        ppi->che[0].event = (uint32_t)&RADIO_END;
        ppi->che[0].task = (uint32_t)&TIMER0_CAPTURE_2;

        ppi->che[1].event = (uint32_t)&TIMER0_COMPARE_0;
        ppi->che[1].task = (uint32_t)&RADIO_RXEN;

        ppi->che[2].event = (uint32_t)&TIMER0_COMPARE_1;
        ppi->che[2].task = (uint32_t)&RADIO_DISABLE;

        ppi->che[3].event = (uint32_t)&TIMER0_COMPARE_0;
        ppi->che[3].task = (uint32_t)&RADIO_TXEN;
}

static inline void ppi_enable_ch(uint32_t ch)
{
        ppi->chenset = ch;
}

static inline void ppi_disable_ch(uint32_t ch)
{
        ppi->chenclr = ch;
}

END_DECLS

#endif

