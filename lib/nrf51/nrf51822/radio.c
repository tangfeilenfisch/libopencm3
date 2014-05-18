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

#include <libopencm3/nrf51/radio.h>
#include <libopencm3/nrf51/ficr.h>

static uint32_t le_channel_tab[40] = {
	BLE_RFCH1,
	BLE_RFCH2,
	BLE_RFCH3,
	BLE_RFCH4,
	BLE_RFCH5,
	BLE_RFCH6,
	BLE_RFCH7,
	BLE_RFCH8,
	BLE_RFCH9,
	BLE_RFCH10,
	BLE_RFCH11,
	BLE_RFCH13,
	BLE_RFCH14,
	BLE_RFCH15,
	BLE_RFCH16,
	BLE_RFCH17,
	BLE_RFCH18,
	BLE_RFCH19,
	BLE_RFCH20,
	BLE_RFCH21,
	BLE_RFCH22,
	BLE_RFCH23,
	BLE_RFCH24,
	BLE_RFCH25,
	BLE_RFCH26,
	BLE_RFCH27,
	BLE_RFCH28,
	BLE_RFCH29,
	BLE_RFCH30,
	BLE_RFCH31,
	BLE_RFCH32,
	BLE_RFCH33,
	BLE_RFCH34,
	BLE_RFCH35,
	BLE_RFCH36,
	BLE_RFCH37,
	BLE_RFCH38,
	BLE_RFCH0,
	BLE_RFCH12,
	BLE_RFCH39,
};

struct radio_debug {
	uint32_t txen;
	uint32_t rxen;
	uint32_t start;
	uint32_t stop;
	uint32_t disable;
	uint32_t rssistart;
	uint32_t rssistop;
	uint32_t bcstart;
	uint32_t bcstop;
	uint32_t fill_gap0[0x37];
	uint32_t ready;
	uint32_t address;
	uint32_t payload;
	uint32_t end;
	uint32_t disabled;
	uint32_t devmatch;
	uint32_t devmiss;
	uint32_t rssiend;
	uint32_t fill_gap1[0x2];
	uint32_t bcmatch;
	uint32_t fill_gap2[0x35];
	uint32_t shorts;
	uint32_t fill_gap3[0x40];
	uint32_t intenset;
	uint32_t intenclr;
	uint32_t fill_gap4[0x3d];
	uint32_t crcstatus;
	uint32_t fill_gap5;
	uint32_t rxmatch;
	uint32_t rxcrc;
	uint32_t dai;
	uint32_t fill_gap6[0x3c];
	uint32_t packetptr;
	uint32_t frequency;
	uint32_t txpower;
	uint32_t mode;
	uint32_t pcnf0;
	uint32_t pcnf1;
	uint32_t base0;
	uint32_t base1;
	uint32_t prefix0;
	uint32_t prefix1;
	uint32_t txaddress;
	uint32_t rxaddresses;
	uint32_t crccnf;
	uint32_t crcpoly;
	uint32_t crcinit;
	uint32_t test;
	uint32_t tifs;
	uint32_t rssisample;
	uint32_t fill_gap7;
	uint32_t state;
	uint32_t datawhiteiv;
	uint32_t fill_gap8[0x2];
	uint32_t bcc;
	uint32_t fill_gap9[0x27];
	uint32_t dab_0[8];
	uint32_t dap_0[8];
	uint32_t dacnf;
	uint32_t fill_gap10[0x38];
	uint32_t override_0;
	uint32_t override_1;
	uint32_t override_2;
	uint32_t override_3;
	uint32_t override_4;
	uint32_t fill_gap11[0x231];
	uint32_t power;
};

struct radio_setup {
	/* RADIO_BASE + 0x508 */
	uint32_t frequency;
	uint32_t txpower;
	uint32_t mode;
	uint32_t pcnf0;
	uint32_t pcnf1;
	uint32_t base0;
	uint32_t base1;
	uint32_t prefix0;
	uint32_t prefix1;
	uint32_t txaddress;
	uint32_t rxaddress;
};

struct crc_setup {
	/* RADIO_BASE + 0x534 */
	uint32_t crccnf;
	uint32_t crcpoly;
	uint32_t crcinit;
};

struct dab_setup {
	/* RADIO_BASE + 0x600 */
	uint32_t dab[8];
	uint32_t dap[8];
	uint32_t dacnf;
};

static struct radio_debug *rf_debug = (struct radio_debug*)(RADIO_BASE);
static struct radio_setup *ble_rf = (struct radio_setup*)(RADIO_BASE + 0x508);
static struct crc_setup *ble_crc = (struct crc_setup*)(RADIO_BASE + 0x534);
static struct dab_setup *ble_dab = (struct dab_setup*)(RADIO_BASE + 0x600);

/*---------------------------------------------------------------------------*/
/*
 * Device address match, dab = base register (32 LSB), 
 * dap = prefix register(16 MSB).
 * TxAdd = 1 indicates randmo device address type
*/
int ble_dab_add(uint32_t b, uint16_t p, uint8_t random)
{
	int i;
	for (i = 0; i < RADIO_DAB_SIZE; i++) {
		if (!(ble_dab->dab[i] || ble_dab->dap[i])) {
			ble_dab->dab[i] = b;
			ble_dab->dap[i] = p;
			if (random) {
				ble_dab->dacnf |= ((1 << i) << 8) | (1 << i);
			}
			else {
				ble_dab->dacnf |= (1 << i);
			}
			return 0;
		}
	}
	return -1;
}

int ble_dab_del(uint32_t b, uint16_t p)
{
	int i;
	for (i = 0; i < RADIO_DAB_SIZE; i++) {
		if ((ble_dab->dab[i] == b) && (ble_dab->dap[i] == p)) {
			ble_dab->dab[i] = 0;
			ble_dab->dap[i] = 0;
			ble_dab->dacnf &= ~((1 << i) << 8) | (1 << i);
			return 0;
		}
	}
	return -1;
}

void ble_dab_clear(void)
{
	int i;
	//memset(ble_dab, sizeof(struct dab_setup), 0);
	for (i = 0; i < RADIO_DAB_SIZE; i++) {
		ble_dab->dab[i] = 0;
		ble_dab->dap[i] = 0;
	}
	ble_dab->dacnf = 0;
}

/*---------------------------------------------------------------------------*/
/*
 * The CRC shall be calculated on the PDU field only (configurable in CRCCNF).
 * p(x) =  x^24 + x^10 + x^9 + x^6 + x^4 + x^3 + x^1 + x^0
 *
*/
void ble_crc_init(uint32_t init_value)
{
	ble_crc->crccnf 	= RADIO_CRCCNF_SKIP_ADDR | 3;
	ble_crc->crcpoly 	= (1 << 24 | 1 << 10 | 1 << 9 | 1 << 6 |
					1 << 4 | 1 << 3 | 1 << 1 | 1 << 0);
	ble_crc->crcinit 	= init_value;
}

#define ACH_ACCESS_ADDR		0x8E89BED6

/*---------------------------------------------------------------------------*/
/*
 * Bluetooth LE radio configuration, PHY initialisation
 *
 * There are 7+1 selectable logical addresses, at the moment we support 
 * only 1+1 (advertising channel access addresse + 1) addresses.
 *
*/

void ble_radio_init(enum nrf51_rf_txpower p)
{
	RADIO_POWER		= 1;
	RADIO_TIFS		= 150;
	ble_rf->txpower		= p;
	ble_rf->mode		= ble_1mbit;

	ble_rf->pcnf0		= RADIO_PCNF0_S0_EN | 8;
	ble_rf->pcnf1		= BLE_PAYLOAD_MAX
				| (3 << RADIO_PCNF1_BALEN_POS)
				| RADIO_PCNF1_WHITEEN;

	ble_dab->dacnf 		= 0;
	ble_crc_init(0x555555);

	ble_rf->frequency	= le_channel_tab[37];
	ble_rf->base0		= ACH_ACCESS_ADDR << 8;
	ble_rf->base1		= 0;
	ble_rf->prefix0		= ACH_ACCESS_ADDR >> 24;
	ble_rf->prefix1		= 0;
	ble_rf->txaddress	= 0;
	ble_rf->rxaddress	= RADIO_RXADDRESSES_ADDR0;
}

inline void ble_set_ch(uint8_t ch_idx)
{
	rf_set_datawhiteiv(ch_idx);
	ble_rf->frequency = le_channel_tab[ch_idx];
}

inline void ble_adv_access_addr_en(void)
{
	ble_rf->txaddress	= 0;
	ble_rf->rxaddress	= RADIO_RXADDRESSES_ADDR0;
}

inline void ble_access_addr_en(uint32_t addr)
{
	ble_rf->base1		= addr << 8;
	ble_rf->prefix1		= addr >> 24;
	ble_rf->txaddress	= 4;
	ble_rf->rxaddress	= RADIO_RXADDRESSES_ADDR4;
}

/**@}*/
