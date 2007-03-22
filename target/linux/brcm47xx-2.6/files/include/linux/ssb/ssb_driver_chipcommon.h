#ifndef LINUX_SSB_CHIPCO_H_
#define LINUX_SSB_CHIPCO_H_

/* SonicsSiliconBackplane CHIPCOMMON core hardware definitions
 *
 * The chipcommon core provides chip identification, SB control,
 * jtag, 0/1/2 uarts, clock frequency control, a watchdog interrupt timer,
 * gpio interface, extbus, and support for serial and parallel flashes.
 *
 * Copyright 2005, Broadcom Corporation
 * Copyright 2006, Michael Buesch <mb@bu3sch.de>
 *
 * Licensed under the GPL version 2. See COPYING for details.
 */
#ifdef __KERNEL__

/** ChipCommon core registers. **/

#define SSB_CHIPCO_CHIPID		0x0000
#define  SSB_CHIPCO_IDMASK		0x0000FFFF
#define  SSB_CHIPCO_REVMASK		0x000F0000
#define  SSB_CHIPCO_REVSHIFT		16
#define  SSB_CHIPCO_PACKMASK		0x00F00000
#define  SSB_CHIPCO_PACKSHIFT		20
#define  SSB_CHIPCO_NRCORESMASK		0x0F000000
#define  SSB_CHIPCO_NRCORESSHIFT	24
#define SSB_CHIPCO_CAP	 		0x0004		/* Capabilities */
#define  SSB_CHIPCO_CAP_NRUART		0x00000003	/* # of UARTs */
#define  SSB_CHIPCO_CAP_MIPSEB		0x00000004	/* MIPS in BigEndian Mode */
#define  SSB_CHIPCO_CAP_UARTCLK		0x00000018	/* UART clock select */
#define   SSB_CHIPCO_CAP_UARTCLK_INT	0x00000008	/* UARTs are driven by internal divided clock */
#define  SSB_CHIPCO_CAP_UARTGPIO	0x00000020	/* UARTs on GPIO 15-12 */
#define  SSB_CHIPCO_CAP_EXTBUS		0x000000C0	/* External buses present */
#define  SSB_CHIPCO_CAP_FLASHT		0x00000700	/* Flash Type */
#define   SSB_CHIPCO_FLASHT_NONE	0x00000000	/* No flash */
#define   SSB_CHIPCO_FLASHT_STSER	0x00000100	/* ST serial flash */
#define   SSB_CHIPCO_FLASHT_ATSER	0x00000200	/* Atmel serial flash */
#define	  SSB_CHIPCO_FLASHT_PARA	0x00000700	/* Parallel flash */
#define  SSB_CHIPCO_CAP_PLLT		0x00038000	/* PLL Type */
#define   SSB_PLLTYPE_NONE		0x00000000
#define   SSB_PLLTYPE_1			0x00010000	/* 48Mhz base, 3 dividers */
#define   SSB_PLLTYPE_2			0x00020000	/* 48Mhz, 4 dividers */
#define   SSB_PLLTYPE_3			0x00030000	/* 25Mhz, 2 dividers */
#define   SSB_PLLTYPE_4			0x00008000	/* 48Mhz, 4 dividers */
#define   SSB_PLLTYPE_5			0x00018000	/* 25Mhz, 4 dividers */
#define   SSB_PLLTYPE_6			0x00028000	/* 100/200 or 120/240 only */
#define   SSB_PLLTYPE_7			0x00038000	/* 25Mhz, 4 dividers */
#define  SSB_CHIPCO_CAP_PCTL		0x00040000	/* Power Control */
#define  SSB_CHIPCO_CAP_OTPS		0x00380000	/* OTP size */
#define  SSB_CHIPCO_CAP_OTPS_SHIFT	19
#define  SSB_CHIPCO_CAP_OTPS_BASE	5
#define  SSB_CHIPCO_CAP_JTAGM		0x00400000	/* JTAG master present */
#define  SSB_CHIPCO_CAP_BROM		0x00800000	/* Internal boot ROM active */
#define  SSB_CHIPCO_CAP_64BIT		0x08000000	/* 64-bit Backplane */
#define SSB_CHIPCO_CORECTL		0x0008
#define  SSB_CHIPCO_CORECTL_UARTCLK0	0x00000001	/* Drive UART with internal clock */
#define	 SSB_CHIPCO_CORECTL_SE		0x00000002	/* sync clk out enable (corerev >= 3) */
#define SSB_CHIPCO_BIST			0x000C
#define SSB_CHIPCO_OTPS			0x0010		/* OTP status */
#define	 SSB_CHIPCO_OTPS_PROGFAIL	0x80000000
#define	 SSB_CHIPCO_OTPS_PROTECT	0x00000007
#define	 SSB_CHIPCO_OTPS_HW_PROTECT	0x00000001
#define	 SSB_CHIPCO_OTPS_SW_PROTECT	0x00000002
#define	 SSB_CHIPCO_OTPS_CID_PROTECT	0x00000004
#define SSB_CHIPCO_OTPC			0x0014		/* OTP control */
#define	 SSB_CHIPCO_OTPC_RECWAIT	0xFF000000
#define	 SSB_CHIPCO_OTPC_PROGWAIT	0x00FFFF00
#define	 SSB_CHIPCO_OTPC_PRW_SHIFT	8
#define	 SSB_CHIPCO_OTPC_MAXFAIL	0x00000038
#define	 SSB_CHIPCO_OTPC_VSEL		0x00000006
#define	 SSB_CHIPCO_OTPC_SELVL		0x00000001
#define SSB_CHIPCO_OTPP			0x0018		/* OTP prog */
#define	 SSB_CHIPCO_OTPP_COL		0x000000FF
#define	 SSB_CHIPCO_OTPP_ROW		0x0000FF00
#define	 SSB_CHIPCO_OTPP_ROW_SHIFT	8
#define	 SSB_CHIPCO_OTPP_READERR	0x10000000
#define	 SSB_CHIPCO_OTPP_VALUE		0x20000000
#define	 SSB_CHIPCO_OTPP_READ		0x40000000
#define	 SSB_CHIPCO_OTPP_START		0x80000000
#define	 SSB_CHIPCO_OTPP_BUSY		0x80000000
#define SSB_CHIPCO_IRQSTAT		0x0020
#define SSB_CHIPCO_IRQMASK		0x0024
#define	 SSB_CHIPCO_IRQ_GPIO		0x00000001	/* gpio intr */
#define	 SSB_CHIPCO_IRQ_EXT		0x00000002	/* ro: ext intr pin (corerev >= 3) */
#define	 SSB_CHIPCO_IRQ_WDRESET		0x80000000	/* watchdog reset occurred */
#define SSB_CHIPCO_CHIPCTL		0x0028		/* Rev >= 11 only */
#define SSB_CHIPCO_CHIPSTAT		0x002C		/* Rev >= 11 only */
#define SSB_CHIPCO_JCMD			0x0030		/* Rev >= 10 only */
#define  SSB_CHIPCO_JCMD_START		0x80000000
#define  SSB_CHIPCO_JCMD_BUSY		0x80000000
#define  SSB_CHIPCO_JCMD_PAUSE		0x40000000
#define  SSB_CHIPCO_JCMD0_ACC_MASK	0x0000F000
#define  SSB_CHIPCO_JCMD0_ACC_IRDR	0x00000000
#define  SSB_CHIPCO_JCMD0_ACC_DR	0x00001000
#define  SSB_CHIPCO_JCMD0_ACC_IR	0x00002000
#define  SSB_CHIPCO_JCMD0_ACC_RESET	0x00003000
#define  SSB_CHIPCO_JCMD0_ACC_IRPDR	0x00004000
#define  SSB_CHIPCO_JCMD0_ACC_PDR	0x00005000
#define  SSB_CHIPCO_JCMD0_IRW_MASK	0x00000F00
#define  SSB_CHIPCO_JCMD_ACC_MASK	0x000F0000	/* Changes for corerev 11 */
#define  SSB_CHIPCO_JCMD_ACC_IRDR	0x00000000
#define  SSB_CHIPCO_JCMD_ACC_DR		0x00010000
#define  SSB_CHIPCO_JCMD_ACC_IR		0x00020000
#define  SSB_CHIPCO_JCMD_ACC_RESET	0x00030000
#define  SSB_CHIPCO_JCMD_ACC_IRPDR	0x00040000
#define  SSB_CHIPCO_JCMD_ACC_PDR	0x00050000
#define  SSB_CHIPCO_JCMD_IRW_MASK	0x00001F00
#define  SSB_CHIPCO_JCMD_IRW_SHIFT	8
#define  SSB_CHIPCO_JCMD_DRW_MASK	0x0000003F
#define SSB_CHIPCO_JIR			0x0034		/* Rev >= 10 only */
#define SSB_CHIPCO_JDR			0x0038		/* Rev >= 10 only */
#define SSB_CHIPCO_JCTL			0x003C		/* Rev >= 10 only */
#define  SSB_CHIPCO_JCTL_FORCE_CLK	4		/* Force clock */
#define  SSB_CHIPCO_JCTL_EXT_EN		2		/* Enable external targets */
#define  SSB_CHIPCO_JCTL_EN		1		/* Enable Jtag master */
#define SSB_CHIPCO_FLASHCTL		0x0040
#define  SSB_CHIPCO_FLASHCTL_START	0x80000000
#define  SSB_CHIPCO_FLASHCTL_BUSY	SSB_CHIPCO_FLASHCTL_START
#define SSB_CHIPCO_FLASHADDR		0x0044
#define SSB_CHIPCO_FLASHDATA		0x0048
#define SSB_CHIPCO_BCAST_ADDR		0x0050
#define SSB_CHIPCO_BCAST_DATA		0x0054
#define SSB_CHIPCO_GPIOIN		0x0060
#define SSB_CHIPCO_GPIOOUT		0x0064
#define SSB_CHIPCO_GPIOOUTEN		0x0068
#define SSB_CHIPCO_GPIOCTL		0x006C
#define SSB_CHIPCO_GPIOINTPOL		0x0070
#define SSB_CHIPCO_GPIOINTMASK		0x0074
#define SSB_CHIPCO_WATCHDOG		0x0080
#define SSB_CHIPCO_GPIOTIMER		0x0088		/* LED powersave (corerev >= 16) */
#define  SSB_CHIPCO_GPIOTIMER_ONTIME_SHIFT	16
#define SSB_CHIPCO_GPIOTOUTM		0x008C		/* LED powersave (corerev >= 16) */
#define SSB_CHIPCO_CLOCK_N		0x0090
#define SSB_CHIPCO_CLOCK_SB		0x0094
#define SSB_CHIPCO_CLOCK_PCI		0x0098
#define SSB_CHIPCO_CLOCK_M2		0x009C
#define SSB_CHIPCO_CLOCK_MIPS		0x00A0
#define SSB_CHIPCO_CLKDIV		0x00A4		/* Rev >= 3 only */
#define	 SSB_CHIPCO_CLKDIV_SFLASH	0x0F000000
#define	 SSB_CHIPCO_CLKDIV_SFLASH_SHIFT	24
#define	 SSB_CHIPCO_CLKDIV_OTP		0x000F0000
#define	 SSB_CHIPCO_CLKDIV_OTP_SHIFT	16
#define	 SSB_CHIPCO_CLKDIV_JTAG		0x00000F00
#define	 SSB_CHIPCO_CLKDIV_JTAG_SHIFT	8
#define	 SSB_CHIPCO_CLKDIV_UART		0x000000FF
#define SSB_CHIPCO_PLLONDELAY		0x00B0		/* Rev >= 4 only */
#define SSB_CHIPCO_FREFSELDELAY		0x00B4		/* Rev >= 4 only */
#define SSB_CHIPCO_SLOWCLKCTL		0x00B8		/* 6 <= Rev <= 9 only */
#define  SSB_CHIPCO_SLOWCLKCTL_SRC	0x00000007	/* slow clock source mask */
#define	  SSB_CHIPCO_SLOWCLKCTL_SRC_LPO		0x00000000	/* source of slow clock is LPO */
#define   SSB_CHIPCO_SLOWCLKCTL_SRC_XTAL	0x00000001	/* source of slow clock is crystal */
#define	  SSB_CHIPCO_SLOECLKCTL_SRC_PCI		0x00000002	/* source of slow clock is PCI */
#define  SSB_CHIPCO_SLOWCLKCTL_LPOFREQ	0x00000200	/* LPOFreqSel, 1: 160Khz, 0: 32KHz */
#define  SSB_CHIPCO_SLOWCLKCTL_LPOPD	0x00000400	/* LPOPowerDown, 1: LPO is disabled, 0: LPO is enabled */
#define  SSB_CHIPCO_SLOWCLKCTL_FSLOW	0x00000800	/* ForceSlowClk, 1: sb/cores running on slow clock, 0: power logic control */
#define  SSB_CHIPCO_SLOWCLKCTL_IPLL	0x00001000	/* IgnorePllOffReq, 1/0: power logic ignores/honors PLL clock disable requests from core */
#define  SSB_CHIPCO_SLOWCLKCTL_ENXTAL	0x00002000	/* XtalControlEn, 1/0: power logic does/doesn't disable crystal when appropriate */
#define  SSB_CHIPCO_SLOWCLKCTL_XTALPU	0x00004000	/* XtalPU (RO), 1/0: crystal running/disabled */
#define  SSB_CHIPCO_SLOWCLKCTL_CLKDIV	0xFFFF0000	/* ClockDivider (SlowClk = 1/(4+divisor)) */
#define  SSB_CHIPCO_SLOWCLKCTL_CLKDIV_SHIFT	16
#define SSB_CHIPCO_SYSCLKCTL		0x00C0		/* Rev >= 3 only */
#define	 SSB_CHIPCO_SYSCLKCTL_IDLPEN	0x00000001	/* ILPen: Enable Idle Low Power */
#define	 SSB_CHIPCO_SYSCLKCTL_ALPEN	0x00000002	/* ALPen: Enable Active Low Power */
#define	 SSB_CHIPCO_SYSCLKCTL_PLLEN	0x00000004	/* ForcePLLOn */
#define	 SSB_CHIPCO_SYSCLKCTL_FORCEALP	0x00000008	/* Force ALP (or HT if ALPen is not set */
#define	 SSB_CHIPCO_SYSCLKCTL_FORCEHT	0x00000010	/* Force HT */
#define  SSB_CHIPCO_SYSCLKCTL_CLKDIV	0xFFFF0000	/* ClkDiv  (ILP = 1/(4+divisor)) */
#define  SSB_CHIPCO_SYSCLKCTL_CLKDIV_SHIFT	16
#define SSB_CHIPCO_CLKSTSTR		0x00C4		/* Rev >= 3 only */
#define SSB_CHIPCO_PCMCIA_CFG		0x0100
#define SSB_CHIPCO_PCMCIA_MEMWAIT	0x0104
#define SSB_CHIPCO_PCMCIA_ATTRWAIT	0x0108
#define SSB_CHIPCO_PCMCIA_IOWAIT	0x010C
#define SSB_CHIPCO_IDE_CFG		0x0110
#define SSB_CHIPCO_IDE_MEMWAIT		0x0114
#define SSB_CHIPCO_IDE_ATTRWAIT		0x0118
#define SSB_CHIPCO_IDE_IOWAIT		0x011C
#define SSB_CHIPCO_PROG_CFG		0x0120
#define SSB_CHIPCO_PROG_WAITCNT		0x0124
#define SSB_CHIPCO_FLASH_CFG		0x0128
#define SSB_CHIPCO_FLASH_WAITCNT	0x012C
#define SSB_CHIPCO_UART0_DATA		0x0300
#define SSB_CHIPCO_UART0_IMR		0x0304
#define SSB_CHIPCO_UART0_FCR		0x0308
#define SSB_CHIPCO_UART0_LCR		0x030C
#define SSB_CHIPCO_UART0_MCR		0x0310
#define SSB_CHIPCO_UART0_LSR		0x0314
#define SSB_CHIPCO_UART0_MSR		0x0318
#define SSB_CHIPCO_UART0_SCRATCH	0x031C
#define SSB_CHIPCO_UART1_DATA		0x0400
#define SSB_CHIPCO_UART1_IMR		0x0404
#define SSB_CHIPCO_UART1_FCR		0x0408
#define SSB_CHIPCO_UART1_LCR		0x040C
#define SSB_CHIPCO_UART1_MCR		0x0410
#define SSB_CHIPCO_UART1_LSR		0x0414
#define SSB_CHIPCO_UART1_MSR		0x0418
#define SSB_CHIPCO_UART1_SCRATCH	0x041C



/** Clockcontrol masks and values **/

/* SSB_CHIPCO_CLOCK_N */
#define	SSB_CHIPCO_CLK_N1		0x0000003F	/* n1 control */
#define	SSB_CHIPCO_CLK_N2		0x00003F00	/* n2 control */
#define	SSB_CHIPCO_CLK_N2_SHIFT		8
#define	SSB_CHIPCO_CLK_PLLC		0x000F0000	/* pll control */
#define	SSB_CHIPCO_CLK_PLLC_SHIFT	16

/* SSB_CHIPCO_CLOCK_SB/PCI/UART */
#define	SSB_CHIPCO_CLK_M1		0x0000003F	/* m1 control */
#define	SSB_CHIPCO_CLK_M2		0x00003F00	/* m2 control */
#define	SSB_CHIPCO_CLK_M2_SHIFT		8
#define	SSB_CHIPCO_CLK_M3		0x003F0000	/* m3 control */
#define	SSB_CHIPCO_CLK_M3_SHIFT		16
#define	SSB_CHIPCO_CLK_MC		0x1F000000	/* mux control */
#define	SSB_CHIPCO_CLK_MC_SHIFT		24

/* N3M Clock control magic field values */
#define	SSB_CHIPCO_CLK_F6_2		0x02		/* A factor of 2 in */
#define	SSB_CHIPCO_CLK_F6_3		0x03		/* 6-bit fields like */
#define	SSB_CHIPCO_CLK_F6_4		0x05		/* N1, M1 or M3 */
#define	SSB_CHIPCO_CLK_F6_5		0x09
#define	SSB_CHIPCO_CLK_F6_6		0x11
#define	SSB_CHIPCO_CLK_F6_7		0x21

#define	SSB_CHIPCO_CLK_F5_BIAS		5		/* 5-bit fields get this added */

#define	SSB_CHIPCO_CLK_MC_BYPASS	0x08
#define	SSB_CHIPCO_CLK_MC_M1		0x04
#define	SSB_CHIPCO_CLK_MC_M1M2		0x02
#define	SSB_CHIPCO_CLK_MC_M1M2M3	0x01
#define	SSB_CHIPCO_CLK_MC_M1M3		0x11

/* Type 2 Clock control magic field values */
#define	SSB_CHIPCO_CLK_T2_BIAS		2		/* n1, n2, m1 & m3 bias */
#define	SSB_CHIPCO_CLK_T2M2_BIAS	3		/* m2 bias */

#define	SSB_CHIPCO_CLK_T2MC_M1BYP	1
#define	SSB_CHIPCO_CLK_T2MC_M2BYP	2
#define	SSB_CHIPCO_CLK_T2MC_M3BYP	4

/* Type 6 Clock control magic field values */
#define	SSB_CHIPCO_CLK_T6_MMASK		1		/* bits of interest in m */
#define	SSB_CHIPCO_CLK_T6_M0		120000000	/* sb clock for m = 0 */
#define	SSB_CHIPCO_CLK_T6_M1		100000000	/* sb clock for m = 1 */
#define	SSB_CHIPCO_CLK_SB2MIPS_T6(sb)	(2 * (sb))

/* Common clock base */
#define	SSB_CHIPCO_CLK_BASE1		24000000	/* Half the clock freq */
#define SSB_CHIPCO_CLK_BASE2		12500000	/* Alternate crystal on some PLL's */

/* Clock control values for 200Mhz in 5350 */
#define	SSB_CHIPCO_CLK_5350_N		0x0311
#define	SSB_CHIPCO_CLK_5350_M		0x04020009


/** Bits in the config registers **/

#define	SSB_CHIPCO_CFG_EN		0x0001		/* Enable */
#define	SSB_CHIPCO_CFG_EXTM		0x000E		/* Extif Mode */
#define	 SSB_CHIPCO_CFG_EXTM_ASYNC	0x0002		/* Async/Parallel flash */
#define	 SSB_CHIPCO_CFG_EXTM_SYNC	0x0004		/* Synchronous */
#define	 SSB_CHIPCO_CFG_EXTM_PCMCIA	0x0008		/* PCMCIA */
#define	 SSB_CHIPCO_CFG_EXTM_IDE	0x000A		/* IDE */
#define	SSB_CHIPCO_CFG_DS16		0x0010		/* Data size, 0=8bit, 1=16bit */
#define	SSB_CHIPCO_CFG_CLKDIV		0x0060		/* Sync: Clock divisor */
#define	SSB_CHIPCO_CFG_CLKEN		0x0080		/* Sync: Clock enable */
#define	SSB_CHIPCO_CFG_BSTRO		0x0100		/* Sync: Size/Bytestrobe */


/** Flash-specific control/status values */

/* flashcontrol opcodes for ST flashes */
#define SSB_CHIPCO_FLASHCTL_ST_WREN	0x0006		/* Write Enable */
#define SSB_CHIPCO_FLASHCTL_ST_WRDIS	0x0004		/* Write Disable */
#define SSB_CHIPCO_FLASHCTL_ST_RDSR	0x0105		/* Read Status Register */
#define SSB_CHIPCO_FLASHCTL_ST_WRSR	0x0101		/* Write Status Register */
#define SSB_CHIPCO_FLASHCTL_ST_READ	0x0303		/* Read Data Bytes */
#define SSB_CHIPCO_FLASHCTL_ST_PP	0x0302		/* Page Program */
#define SSB_CHIPCO_FLASHCTL_ST_SE	0x02D8		/* Sector Erase */
#define SSB_CHIPCO_FLASHCTL_ST_BE	0x00C7		/* Bulk Erase */
#define SSB_CHIPCO_FLASHCTL_ST_DP	0x00B9		/* Deep Power-down */
#define SSB_CHIPCO_FLASHCTL_ST_RSIG	0x03AB		/* Read Electronic Signature */

/* Status register bits for ST flashes */
#define SSB_CHIPCO_FLASHSTA_ST_WIP	0x01		/* Write In Progress */
#define SSB_CHIPCO_FLASHSTA_ST_WEL	0x02		/* Write Enable Latch */
#define SSB_CHIPCO_FLASHSTA_ST_BP	0x1C		/* Block Protect */
#define SSB_CHIPCO_FLASHSTA_ST_BP_SHIFT	2
#define SSB_CHIPCO_FLASHSTA_ST_SRWD	0x80		/* Status Register Write Disable */

/* flashcontrol opcodes for Atmel flashes */
#define SSB_CHIPCO_FLASHCTL_AT_READ		0x07E8
#define SSB_CHIPCO_FLASHCTL_AT_PAGE_READ	0x07D2
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_READ	/* FIXME */
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_READ	/* FIXME */
#define SSB_CHIPCO_FLASHCTL_AT_STATUS		0x01D7
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_WRITE	0x0384
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_WRITE	0x0387
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_ERASE_PRGM	0x0283	/* Erase program */
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_ERASE_PRGM	0x0286	/* Erase program */
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_PROGRAM	0x0288
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_PROGRAM	0x0289
#define SSB_CHIPCO_FLASHCTL_AT_PAGE_ERASE	0x0281
#define SSB_CHIPCO_FLASHCTL_AT_BLOCK_ERASE	0x0250
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_WRER_PRGM	0x0382	/* Write erase program */
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_WRER_PRGM	0x0385	/* Write erase program */
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_LOAD	0x0253
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_LOAD	0x0255
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_COMPARE	0x0260
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_COMPARE	0x0261
#define SSB_CHIPCO_FLASHCTL_AT_BUF1_REPROGRAM	0x0258
#define SSB_CHIPCO_FLASHCTL_AT_BUF2_REPROGRAM	0x0259

/* Status register bits for Atmel flashes */
#define SSB_CHIPCO_FLASHSTA_AT_READY	0x80
#define SSB_CHIPCO_FLASHSTA_AT_MISMATCH	0x40
#define SSB_CHIPCO_FLASHSTA_AT_ID	0x38
#define SSB_CHIPCO_FLASHSTA_AT_ID_SHIFT	3


/** OTP **/

/* OTP regions */
#define	SSB_CHIPCO_OTP_HW_REGION	SSB_CHIPCO_OTPS_HW_PROTECT
#define	SSB_CHIPCO_OTP_SW_REGION	SSB_CHIPCO_OTPS_SW_PROTECT
#define	SSB_CHIPCO_OTP_CID_REGION	SSB_CHIPCO_OTPS_CID_PROTECT

/* OTP regions (Byte offsets from otp size) */
#define	SSB_CHIPCO_OTP_SWLIM_OFF	(-8)
#define	SSB_CHIPCO_OTP_CIDBASE_OFF	0
#define	SSB_CHIPCO_OTP_CIDLIM_OFF	8

/* Predefined OTP words (Word offset from otp size) */
#define	SSB_CHIPCO_OTP_BOUNDARY_OFF	(-4)
#define	SSB_CHIPCO_OTP_HWSIGN_OFF	(-3)
#define	SSB_CHIPCO_OTP_SWSIGN_OFF	(-2)
#define	SSB_CHIPCO_OTP_CIDSIGN_OFF	(-1)

#define	SSB_CHIPCO_OTP_CID_OFF		0
#define	SSB_CHIPCO_OTP_PKG_OFF		1
#define	SSB_CHIPCO_OTP_FID_OFF		2
#define	SSB_CHIPCO_OTP_RSV_OFF		3
#define	SSB_CHIPCO_OTP_LIM_OFF		4

#define	SSB_CHIPCO_OTP_SIGNATURE	0x578A
#define	SSB_CHIPCO_OTP_MAGIC		0x4E56


struct ssb_device;
struct ssb_serial_port;

struct ssb_chipcommon {
	struct ssb_device *dev;
	u32 capabilities;
	/* Fast Powerup Delay constant */
	u16 fast_pwrup_delay;
};

extern void ssb_chipcommon_init(struct ssb_chipcommon *cc);

#include <linux/pm.h>
extern void ssb_chipco_suspend(struct ssb_chipcommon *cc, pm_message_t state);
extern void ssb_chipco_resume(struct ssb_chipcommon *cc);

extern void ssb_chipco_get_clockcpu(struct ssb_chipcommon *cc, u32 chip_id,
	u32 *rate, u32 *plltype, u32 *n, u32 *m);
extern void ssb_chipco_get_clockcontrol(struct ssb_chipcommon *cc,
					u32 *plltype, u32 *n, u32 *m);
extern void ssb_chipco_timing_init(struct ssb_chipcommon *cc,
				   unsigned long ns_per_cycle);

enum ssb_clkmode {
	SSB_CLKMODE_SLOW,
	SSB_CLKMODE_FAST,
	SSB_CLKMODE_DYNAMIC,
};

extern void ssb_chipco_set_clockmode(struct ssb_chipcommon *cc,
				     enum ssb_clkmode mode);


/* GPIO functions */
static inline u32 ssb_chipco_gpio_in(struct ssb_chipcommon *cc,
				     u32 mask)
{
	return ssb_read32(cc->dev, SSB_CHIPCO_GPIOIN) & mask;
}

static inline u32 ssb_chipco_gpio_out(struct ssb_chipcommon *cc,
				     u32 mask, u32 value)
{
	return ssb_write32_masked(cc->dev, SSB_CHIPCO_GPIOOUT, mask, value);
}

static inline u32 ssb_chipco_gpio_outen(struct ssb_chipcommon *cc,
				     u32 mask, u32 value)
{
	return ssb_write32_masked(cc->dev, SSB_CHIPCO_GPIOOUTEN, mask, value);
}

static inline u32 ssb_chipco_gpio_control(struct ssb_chipcommon *cc,
				     u32 mask, u32 value)
{
	return ssb_write32_masked(cc->dev, SSB_CHIPCO_GPIOCTL, mask, value);
}

static inline u32 ssb_chipco_gpio_intmask(struct ssb_chipcommon *cc,
				     u32 mask, u32 value)
{
	return ssb_write32_masked(cc->dev, SSB_CHIPCO_GPIOINTMASK, mask, value);
}

static inline u32 ssb_chipco_gpio_polarity(struct ssb_chipcommon *cc,
				     u32 mask, u32 value)
{
	return ssb_write32_masked(cc->dev, SSB_CHIPCO_GPIOINTPOL, mask, value);
}
/* TODO: GPIO reservation */

extern int ssb_chipco_watchdog(struct ssb_chipcommon *cc, uint ticks);

#ifdef CONFIG_SSB_SERIAL
extern int ssb_chipco_serial_init(struct ssb_chipcommon *cc,
				  struct ssb_serial_port *ports);
#endif /* CONFIG_SSB_SERIAL */

#endif /* __KERNEL__ */
#endif /* LINUX_SSB_CHIPCO_H_ */
