/** @defgroup radio_defines RADIO Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51822 2.4 GHz Radio</b>
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

#ifndef LIBOPENCM3_RADIO_H
#define LIBOPENCM3_RADIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf51/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/
#define RADIO_EVENT_BASE			(RADIO_BASE + 0x100)

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/
/* TASKS */
#define RADIO_TXEN			MMIO32(RADIO_BASE + 0x000)
#define RADIO_RXEN			MMIO32(RADIO_BASE + 0x004)
#define RADIO_START			MMIO32(RADIO_BASE + 0x008)
#define RADIO_STOP			MMIO32(RADIO_BASE + 0x00C)
#define RADIO_DISABLE			MMIO32(RADIO_BASE + 0x010)
#define RADIO_RSSISTART			MMIO32(RADIO_BASE + 0x014)
#define RADIO_RSSISTOP			MMIO32(RADIO_BASE + 0x018)
#define RADIO_BCSTART			MMIO32(RADIO_BASE + 0x01C)
#define RADIO_BCSTOP			MMIO32(RADIO_BASE + 0x020)
/* EVENTS */
#define RADIO_READY			MMIO32(RADIO_BASE + 0x100)
#define RADIO_ADDRESS			MMIO32(RADIO_BASE + 0x104)
#define RADIO_PAYLOAD			MMIO32(RADIO_BASE + 0x108)
#define RADIO_END			MMIO32(RADIO_BASE + 0x10C)
#define RADIO_DISABLED			MMIO32(RADIO_BASE + 0x110)
#define RADIO_DEVMATCH			MMIO32(RADIO_BASE + 0x114)
#define RADIO_DEVMISS			MMIO32(RADIO_BASE + 0x118)
#define RADIO_RSSIEND			MMIO32(RADIO_BASE + 0x11C)
#define RADIO_BCMATCH			MMIO32(RADIO_BASE + 0x128)
/* REGISTERS */
#define RADIO_SHORTS			MMIO32(RADIO_BASE + 0x200)
#define RADIO_INTENSET			MMIO32(RADIO_BASE + 0x304)
#define RADIO_INTENCLR			MMIO32(RADIO_BASE + 0x308)
#define RADIO_CRCSTATUS			MMIO32(RADIO_BASE + 0x400)
#define RADIO_RXMATCH			MMIO32(RADIO_BASE + 0x408)
#define RADIO_RXCRC			MMIO32(RADIO_BASE + 0x40C)
#define RADIO_DAI			MMIO32(RADIO_BASE + 0x410)
#define RADIO_PACKETPTR			MMIO32(RADIO_BASE + 0x504)
#define RADIO_FREQUENCY			MMIO32(RADIO_BASE + 0x508)
#define RADIO_TXPOWER			MMIO32(RADIO_BASE + 0x50C)
#define RADIO_MODE			MMIO32(RADIO_BASE + 0x510)
#define RADIO_PCNF0			MMIO32(RADIO_BASE + 0x514)
#define RADIO_PCNF1			MMIO32(RADIO_BASE + 0x518)
#define RADIO_BASE0			MMIO32(RADIO_BASE + 0x51C)
#define RADIO_BASE1			MMIO32(RADIO_BASE + 0x520)
#define RADIO_PREFIX0			MMIO32(RADIO_BASE + 0x524)
#define RADIO_PEFIX1			MMIO32(RADIO_BASE + 0x528)
#define RADIO_TXADDRESS			MMIO32(RADIO_BASE + 0x52C)
#define RADIO_RXADDRESSES		MMIO32(RADIO_BASE + 0x530)
#define RADIO_CRCCNF			MMIO32(RADIO_BASE + 0x534)
#define RADIO_CRCPOLY			MMIO32(RADIO_BASE + 0x538)
#define RADIO_CRCINIT			MMIO32(RADIO_BASE + 0x53C)
#define RADIO_TEST			MMIO32(RADIO_BASE + 0x540)
#define RADIO_TIFS			MMIO32(RADIO_BASE + 0x544)
#define RADIO_RSSISAMPLE		MMIO32(RADIO_BASE + 0x548)
#define RADIO_STATE			MMIO32(RADIO_BASE + 0x550)
#define RADIO_DATAWHITEIV		MMIO32(RADIO_BASE + 0x554)
#define RADIO_BCC			MMIO32(RADIO_BASE + 0x560)
#define RADIO_DAB_0			MMIO32(RADIO_BASE + 0x600)
#define RADIO_DAB_7			MMIO32(RADIO_BASE + 0x61C)
#define RADIO_DAP_0			MMIO32(RADIO_BASE + 0x620)
#define RADIO_DAP_7			MMIO32(RADIO_BASE + 0x63C)
#define RADIO_DACNF			MMIO32(RADIO_BASE + 0x640)
#define RADIO_OVERRIDE_0		MMIO32(RADIO_BASE + 0x724)
#define RADIO_OVERRIDE_1		MMIO32(RADIO_BASE + 0x728)
#define RADIO_OVERRIDE_2		MMIO32(RADIO_BASE + 0x72C)
#define RADIO_OVERRIDE_3		MMIO32(RADIO_BASE + 0x730)
#define RADIO_OVERRIDE_4		MMIO32(RADIO_BASE + 0x734)
#define RADIO_POWER			MMIO32(RADIO_BASE + 0xFFC)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/
#define RADIO_SHORTS_DISABLED_RSSISTOP		(1 << 8)
#define RADIO_SHORTS_ADDRESS_BCSTART		(1 << 6)
#define RADIO_SHORTS_END_START			(1 << 5)
#define RADIO_SHORTS_ADDRESS_RSSISTART		(1 << 4)
#define RADIO_SHORTS_DISABLED_RXEN		(1 << 3)
#define RADIO_SHORTS_DISABLED_TXEN		(1 << 2)
#define RADIO_SHORTS_END_DISABLE		(1 << 1)
#define RADIO_SHORTS_READY_START		(1 << 0)
#define RADIO_INTENSET_BCMATCH			(1 << 10)
#define RADIO_INTENSET_RSSIEND			(1 << 7)
#define RADIO_INTENSET_DEVMISS			(1 << 6)
#define RADIO_INTENSET_DEVMATCH			(1 << 5)
#define RADIO_INTENSET_DISABLED			(1 << 4)
#define RADIO_INTENSET_END			(1 << 3)
#define RADIO_INTENSET_PAYLOAD			(1 << 2)
#define RADIO_INTENSET_ADDRESS			(1 << 1)
#define RADIO_INTENSET_READY			(1 << 0)
#define RADIO_INTENCLR_BCMATCH			(1 << 10)
#define RADIO_INTENCLR_RSSIEND			(1 << 7)
#define RADIO_INTENCLR_DEVMISS			(1 << 6)
#define RADIO_INTENCLR_DEVMATCH			(1 << 5)
#define RADIO_INTENCLR_DISABLED			(1 << 4)
#define RADIO_INTENCLR_END			(1 << 3)
#define RADIO_INTENCLR_PAYLOAD			(1 << 2)
#define RADIO_INTENCLR_ADDRESS			(1 << 1)
#define RADIO_INTENCLR_READY			(1 << 0)
#define RADIO_PCNF0_S1LEN_POS			16
#define RADIO_PCNF0_S0_EN			(1 << 8)
#define RADIO_PCNF0_LFLEN_POS			0
#define RADIO_PCNF1_WHITEEN			(1 << 25)
#define RADIO_PCNF1_ENDIAN			(1 << 24)
#define RADIO_PCNF1_BALEN_POS			16
#define RADIO_PCNF1_STATLEN_POS			8
#define RADIO_PCNF1_MAXLEN_POS			0
#define RADIO_PREFIX0_AP3			(1 << 24)
#define RADIO_PREFIX0_AP2			(1 << 16)
#define RADIO_PREFIX0_AP1			(1 << 8)
#define RADIO_PREFIX0_AP0			(1 << 0)
#define RADIO_PREFIX1_AP7			(1 << 24)
#define RADIO_PREFIX1_AP6			(1 << 16)
#define RADIO_PREFIX1_AP5			(1 << 8)
#define RADIO_PREFIX1_AP4			(1 << 0)
#define RADIO_RXADDRESSES_ADDR7			(1 << 7)
#define RADIO_RXADDRESSES_ADDR6			(1 << 6)
#define RADIO_RXADDRESSES_ADDR5			(1 << 5)
#define RADIO_RXADDRESSES_ADDR4			(1 << 4)
#define RADIO_RXADDRESSES_ADDR3			(1 << 3)
#define RADIO_RXADDRESSES_ADDR2			(1 << 2)
#define RADIO_RXADDRESSES_ADDR1			(1 << 1)
#define RADIO_RXADDRESSES_ADDR0			(1 << 0)
#define RADIO_CRCCNF_SKIP_ADDR			(1 << 8)
#define RADIO_CRCCNF_LEN_POS			0
#define RADIO_CRCPOLY_CRCPOLY			(1 << 1)
#define RADIO_TEST_PLL_LOCK			(1 << 1)
#define RADIO_TEST_CONST_CARRIER		(1 << 0)
#define RADIO_DAB_SIZE				8
#define RADIO_DACNF_TXADD7			(1 << 15)
#define RADIO_DACNF_TXADD6			(1 << 14)
#define RADIO_DACNF_TXADD5			(1 << 13)
#define RADIO_DACNF_TXADD4			(1 << 12)
#define RADIO_DACNF_TXADD3			(1 << 11)
#define RADIO_DACNF_TXADD2			(1 << 10)
#define RADIO_DACNF_TXADD1			(1 << 9)
#define RADIO_DACNF_TXADD0			(1 << 8)
#define RADIO_DACNF_ENA7			(1 << 7)
#define RADIO_DACNF_ENA6			(1 << 6)
#define RADIO_DACNF_ENA5			(1 << 5)
#define RADIO_DACNF_ENA4			(1 << 4)
#define RADIO_DACNF_ENA3			(1 << 3)
#define RADIO_DACNF_ENA2			(1 << 2)
#define RADIO_DACNF_ENA1			(1 << 1)
#define RADIO_DACNF_ENA0			(1 << 0)

#define RADIO_PAYLOAD_MAXLEN			255

/* bluetooth le rf channels */
#define BLE_RFCH0				2	/* 2402 MHz */
#define BLE_RFCH1				4	/* 2404 MHz */
#define BLE_RFCH2				6	/* 2406 MHz */
#define BLE_RFCH3				8	/* 2408 MHz */
#define BLE_RFCH4				10	/* 2410 MHz */
#define BLE_RFCH5				12	/* 2412 MHz */
#define BLE_RFCH6				14	/* 2414 MHz */
#define BLE_RFCH7				16	/* 2416 MHz */
#define BLE_RFCH8				18	/* 2418 MHz */
#define BLE_RFCH9				20	/* 2420 MHz */
#define BLE_RFCH10				22	/* 2422 MHz */
#define BLE_RFCH11				24	/* 2424 MHz */
#define BLE_RFCH12				26	/* 2426 MHz */
#define BLE_RFCH13				28	/* 2428 MHz */
#define BLE_RFCH14				30	/* 2430 MHz */
#define BLE_RFCH15				32	/* 2432 MHz */
#define BLE_RFCH16				34	/* 2434 MHz */
#define BLE_RFCH17				36	/* 2436 MHz */
#define BLE_RFCH18				38	/* 2438 MHz */
#define BLE_RFCH19				40	/* 2440 MHz */
#define BLE_RFCH20				42	/* 2442 MHz */
#define BLE_RFCH21				44	/* 2444 MHz */
#define BLE_RFCH22				46	/* 2446 MHz */
#define BLE_RFCH23				48	/* 2448 MHz */
#define BLE_RFCH24				50	/* 2450 MHz */
#define BLE_RFCH25				52	/* 2452 MHz */
#define BLE_RFCH26				54	/* 2454 MHz */
#define BLE_RFCH27				56	/* 2456 MHz */
#define BLE_RFCH28				58	/* 2458 MHz */
#define BLE_RFCH29				60	/* 2460 MHz */
#define BLE_RFCH30				62	/* 2462 MHz */
#define BLE_RFCH31				64	/* 2464 MHz */
#define BLE_RFCH32				66	/* 2466 MHz */
#define BLE_RFCH33				68	/* 2468 MHz */
#define BLE_RFCH34				70	/* 2470 MHz */
#define BLE_RFCH35				72	/* 2472 MHz */
#define BLE_RFCH36				74	/* 2474 MHz */
#define BLE_RFCH37				76	/* 2476 MHz */
#define BLE_RFCH38				78	/* 2478 MHz */
#define BLE_RFCH39				80	/* 2480 MHz */

#define BLE_PAYLOAD_MAX				37
#define BLE_OWN_SCA				250
#define BLE_T_TXEN				300
#define BLE_T_RXEN				300

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/
enum nrf51_rf_txpower {
	nrf51_txpower_4dbm	= 0x04,
	nrf51_txpower_0dbm	= 0x00,
	nrf51_txpower_neg4dbm	= 0xfc,
	nrf51_txpower_neg8dbm	= 0xf8,
	nrf51_txpower_neg12dbm	= 0xf4,
	nrf51_txpower_neg16dbm	= 0xf0,
	nrf51_txpower_neg20dbm	= 0xec,
	nrf51_txpower_neg30dbm	= 0xd8,
};

enum nrf51_rf_mode {
	nrf_1mbit		= 0x00,
	nrf_2mbit		= 0x01,
	nrf_250kbit		= 0x02,
	ble_1mbit		= 0x03,
};

enum nrf51_rf_state {
	nrf51_state_disabled	= 0x00,
	nrf51_state_rxru	= 0x01,
	nrf51_state_rxidle	= 0x02,
	nrf51_state_rx		= 0x03,
	nrf51_state_rxdisable	= 0x04,
	nrf51_state_txru	= 0x09,
	nrf51_state_txidle	= 0x0a,
	nrf51_state_tx		= 0x0b,
	nrf51_state_txdisable	= 0x0c,
};

enum nrf51_rf_interrupt {
	nrf51_rf_bcmatch	= 10,
	nrf51_rf_rssiend	= 7,
	nrf51_rf_devmiss	= 6,
	nrf51_rf_devmatch	= 5,
	nrf51_rf_disabled	= 4,
	nrf51_rf_end		= 3,
	nrf51_rf_payload	= 2,
	nrf51_rf_address	= 1,
	nrf51_rf_ready		= 0,
};

enum nrf51_dacnf_addr {
	nrf51_daddr0		= 0,
	nrf51_daddr1		= 1,
	nrf51_daddr2		= 2,
	nrf51_daddr3		= 3,
	nrf51_daddr4		= 4,
	nrf51_daddr5		= 5,
	nrf51_daddr6		= 6,
	nrf51_daddr7		= 7,
};


/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/
void ble_radio_init(enum nrf51_rf_txpower p);
void ble_adv_access_addr_en(void);
void ble_access_addr_en(uint32_t addr);
int ble_dab_add(uint32_t b, uint16_t p, uint8_t random);
int ble_dab_del(uint32_t b, uint16_t p);
void ble_dab_clear(void);
void ble_crc_init(uint32_t init_value);
void ble_set_ch(uint8_t ch_idx);

BEGIN_DECLS

/* shortcuts setup: enable shortcut between x event and y task */
static inline void rf_shorts_end_disable(void)
{
	RADIO_SHORTS		= RADIO_SHORTS_END_DISABLE;
}

static inline void rf_shorts_ready_start(void)
{
	RADIO_SHORTS 		= RADIO_SHORTS_READY_START;
}

static inline void rf_shorts_ready_start_disable(void)
{
	RADIO_SHORTS 		= RADIO_SHORTS_READY_START
				| RADIO_SHORTS_END_DISABLE;
}

static inline void rf_shorts_end_disable_txen(void)
{
	RADIO_SHORTS 		= RADIO_SHORTS_END_DISABLE
				| RADIO_SHORTS_DISABLED_TXEN;
}

static inline void rf_shorts_end_disable_rxen(void)
{
	RADIO_SHORTS 		= RADIO_SHORTS_END_DISABLE
				| RADIO_SHORTS_DISABLED_RXEN;
}
static inline void rf_shorts_disable_txen_start(void)
{
	RADIO_SHORTS 		= RADIO_SHORTS_DISABLED_TXEN
				| RADIO_SHORTS_READY_START;
}

static inline void rf_shorts_disable_rxen_start(void)
{
	RADIO_SHORTS 		= RADIO_SHORTS_DISABLED_RXEN
				| RADIO_SHORTS_READY_START;
}

/* tasks */
static inline void rf_txen(void)
{
	RADIO_TXEN = 1;
}

static inline void rf_rxen(void)
{
	RADIO_RXEN = 1;
}

static inline void rf_start(void)
{
	RADIO_START = 1;
}

static inline void rf_stop(void)
{
	RADIO_STOP = 1;
}

static inline void rf_disable(void)
{
	RADIO_SHORTS = 0;
	RADIO_DISABLED = 0;
	RADIO_DISABLE = 1;
	while(RADIO_DISABLED == 0);
	RADIO_DISABLED = 0;
	RADIO_RXEN = 0;
	RADIO_TXEN = 0;
}

/* register */
/*
 * rf_get_crcstat returns zero if packet received with crc error.
 */
static inline uint32_t rf_get_crcstat(void)
{
	return RADIO_CRCSTATUS;
}

/*
 * logical address on which previous packet was received.
 */
static inline uint32_t rf_get_rxmatch(void)
{
	return RADIO_RXMATCH;
}

/*
 * crc field of previously recieved packet.
 */
static inline uint32_t rf_get_rxcrc(void)
{
	return RADIO_RXCRC;
}

static inline uint32_t rf_get_dai(void)
{
	return RADIO_DAI;
}

/*
 * packet address for next transmission or reception.
 */
static inline void rf_set_packetptr(void *ptr)
{
	RADIO_PACKETPTR = (uint32_t)ptr;
}

static inline int8_t rf_get_txpower(void)
{
	return (int8_t)RADIO_TXPOWER;
}

/* state register may be not functional, see nrf51 PAN */
static inline uint32_t rf_get_state(void)
{
	return RADIO_STATE;
}

static inline void rf_set_datawhiteiv(uint32_t value)
{
	RADIO_DATAWHITEIV = value;
}

static inline void rf_set_bcc(uint32_t value)
{
	RADIO_BCC = value;
}

static inline void rf_power(uint32_t value)
{
	RADIO_POWER = value;
}

static inline void rf_enable_intr(enum nrf51_rf_interrupt intr)
{
	RADIO_INTENSET = (1 << intr);
}

static inline void rf_disable_intr(enum nrf51_rf_interrupt intr)
{
	RADIO_INTENCLR = (1 << intr);
}

static inline uint32_t rf_get_intr_source(enum nrf51_rf_interrupt intr)
{
	intr &= 31;
	return MMIO32(RADIO_EVENT_BASE + (intr << 2));
}

static inline void rf_clear_event(enum nrf51_rf_interrupt intr)
{
	intr &= 31;
	MMIO32(RADIO_EVENT_BASE + (intr << 2)) = 0;
}

static inline uint32_t rf_get_event_ready(void)
{
	return RADIO_READY;
}

static inline uint32_t rf_get_event_address(void)
{
	return RADIO_ADDRESS;
}

static inline uint32_t rf_get_event_devmatch(void)
{
	return RADIO_DEVMATCH;
}

static inline uint32_t rf_get_event_devmiss(void)
{
	return RADIO_DEVMISS;
}

static inline uint32_t rf_get_event_end(void)
{
	return RADIO_END;
}

static inline uint32_t rf_get_event_disabled(void)
{
	return RADIO_DISABLED;
}

static inline void rf_clear_event_ready(void)
{
	RADIO_READY = 0;
}

static inline void rf_clear_event_address(void)
{
	RADIO_ADDRESS = 0;
}

static inline void rf_clear_event_payload(void)
{
	RADIO_PAYLOAD = 0;
}

static inline void rf_clear_event_devmatch(void)
{
	RADIO_DEVMATCH = 0;
}

static inline void rf_clear_event_devmiss(void)
{
	RADIO_DEVMISS = 0;
}

static inline void rf_clear_event_end(void)
{
	RADIO_END = 0;
}

static inline void rf_clear_event_disabled(void)
{
	RADIO_DISABLED = 0;
}

END_DECLS

#endif

