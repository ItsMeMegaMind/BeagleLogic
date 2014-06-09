#ifndef PRU_DEFS_H
#define PRU_DEFS_H

volatile register unsigned int __R31;
volatile register unsigned int __R30;
 
__far volatile char C0[0x300] __attribute__((cregister("C0", far)));	/* PINTC */
__far volatile char C4[0x100] __attribute__((cregister("C4", near)));	/* PRUCFG */

#define PRUCFG(_reg) \
	(*(volatile u32 *)((char *)&C4 + (_reg)))

/* fast access to the registers using the constants */
#define PRUCFG_REVID	PRUCFG(0x0000)

#define PRUCFG_SYSCFG	PRUCFG(0x0004)
#define  SYSCFG_IDLE_MODE_S		0
#define  SYSCFG_IDLE_MODE_W		2
#define  SYSCFG_IDLE_MODE_M		((SYSCFG_IDLE_MODE_W - 1) << SYSCFG_IDLE_MODE_S)
#define  SYSCFG_IDLE_MODE_FORCE		(0 << SYSCFG_IDLE_MODE_S)
#define  SYSCFG_IDLE_MODE_NO		(1 << SYSCFG_IDLE_MODE_S)
#define  SYSCFG_IDLE_MODE_SMART		(2 << SYSCFG_IDLE_MODE_S)
#define  SYSCFG_STANDBY_MODE_S		2
#define  SYSCFG_STANDBY_MODE_W		2	
#define  SYSCFG_STANDBY_MODE_M		((SYSCFG_STANDBY_MODE_W - 1) << SYSCFG_STANDBY_MODE_S)
#define  SYSCFG_STANDBY_MODE_FORCE	(0 << SYSCFG_STANDBY_MODE_S)
#define  SYSCFG_STANDBY_MODE_NO		(1 << SYSCFG_STANDBY_MODE_S)
#define  SYSCFG_STANDBY_MODE_SMART	(2 << SYSCFG_STANDBY_MODE_S)
#define  SYSCFG_STANDBY_INIT		(1 << 4)
#define  SYSCFG_SUB_MWAIT		(1 << 5)
#define PRUCFG_SPP	PRUCFG(0x0034)
#define  SPP_PRU1_PAD_HP_EN		(1 << 0)
#define  SPP_XFR_SHIFT_EN		(1 << 1)

#define PRUCFG_GPCFG0	PRUCFG(0x0008)
#define  CPCFG0_PRU0_GPI_MODE_S		0
#define  CPCFG0_PRU0_GPI_MODE_W		2
#define  CPCFG0_PRU0_GPI_MODE_M		((CPCFG0_PRU0_GPI_MODE_W - 1) << CPCFG0_PRU0_GPI_MODE_S)
#define  CPCFG0_PRU0_GPI_MODE_DIRECT	(0 << CPCFG0_PRU0_GPI_MODE_S)
#define  CPCFG0_PRU0_GPI_MODE_PARALLEL	(1 << CPCFG0_PRU0_GPI_MODE_S)
#define  CPCFG0_PRU0_GPI_MODE_SHIFT	(2 << CPCFG0_PRU0_GPI_MODE_S)
#define  CPCFG0_PRU0_GPI_MODE_MII_RT	(3 << CPCFG0_PRU0_GPI_MODE_S)
#define  CPCFG0_PRU0_GPI_CLK_MODE	(1 << 2)
#define  CPCFG0_PRU0_GPI_DIV0_S		3
#define  CPCFG0_PRU0_GPI_DIV0_W		5
#define  CPCFG0_PRU0_GPI_DIV0_M		((CPCFG0_PRU0_GPI_DIV0_W - 1) << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_1		(0 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_1_5	(1 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_2		(2 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_2_5	(3 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_3		(4 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_3_5	(5 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_4		(6 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_4_5	(7 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_5		(8 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_5_5	(9 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_6		(10 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_6_5	(11 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_7		(12 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_7_5	(13 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_8		(14 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_8_5	(15 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_9		(16 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_9_5	(17 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_10	(18 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_10_5	(19 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_11	(20 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_11_5	(21 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_12	(22 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_12_5	(23 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_13	(24 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_13_5	(25 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_14	(26 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_14_5	(27 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_15	(28 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_15_5	(29 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV0_16	(30 << CPCFG0_PRU0_GPI_DIV0_S)
#define  CPCFG0_PRU0_GPI_DIV1_S		8
#define  CPCFG0_PRU0_GPI_DIV1_W		5
#define  CPCFG0_PRU0_GPI_DIV1_M		((CPCFG0_PRU0_GPI_DIV1_W - 1) << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_1		(0 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_1_5	(1 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_2		(2 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_2_5	(3 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_3		(4 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_3_5	(5 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_4		(6 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_4_5	(7 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_5		(8 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_5_5	(9 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_6		(10 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_6_5	(11 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_7		(12 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_7_5	(13 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_8		(14 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_8_5	(15 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_9		(16 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_9_5	(17 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_10	(18 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_10_5	(19 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_11	(20 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_11_5	(21 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_12	(22 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_12_5	(23 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_13	(24 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_13_5	(25 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_14	(26 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_14_5	(27 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_15	(28 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_15_5	(29 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_DIV1_16	(30 << CPCFG0_PRU0_GPI_DIV1_S)
#define  CPCFG0_PRU0_GPI_S8		(1 << 13)
#define  CPCFG0_PRU0_GPO_MODE		(1 << 14)
#define  CPCFG0_PRU0_GPO_DIV0_S		15
#define  CPCFG0_PRU0_GPO_DIV0_W		5
#define  CPCFG0_PRU0_GPO_DIV0_M		((CPCFG0_PRU0_GPO_DIV0_W - 1) << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_1		(0 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_1_5	(1 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_2		(2 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_2_5	(3 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_3		(4 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_3_5	(5 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_4		(6 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_4_5	(7 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_5		(8 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_5_5	(9 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_6		(10 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_6_5	(11 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_7		(12 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_7_5	(13 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_8		(14 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_8_5	(15 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_9		(16 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_9_5	(17 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_10	(18 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_10_5	(19 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_11	(20 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_11_5	(21 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_12	(22 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_12_5	(23 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_13	(24 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_13_5	(25 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_14	(26 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_14_5	(27 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_15	(28 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_15_5	(29 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV0_16	(30 << CPCFG0_PRU0_GPO_DIV0_S)
#define  CPCFG0_PRU0_GPO_DIV1_S		20
#define  CPCFG0_PRU0_GPO_DIV1_W		5
#define  CPCFG0_PRU0_GPO_DIV1_M		((CPCFG0_PRU0_GPO_DIV1_W - 1) << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_1		(0 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_1_5	(1 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_2		(2 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_2_5	(3 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_3		(4 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_3_5	(5 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_4		(6 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_4_5	(7 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_5		(8 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_5_5	(9 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_6		(10 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_6_5	(11 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_7		(12 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_7_5	(13 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_8		(14 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_8_5	(15 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_9		(16 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_9_5	(17 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_10	(18 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_10_5	(19 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_11	(20 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_11_5	(21 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_12	(22 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_12_5	(23 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_13	(24 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_13_5	(25 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_14	(26 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_14_5	(27 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_15	(28 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_15_5	(29 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_DIV1_16	(30 << CPCFG0_PRU0_GPO_DIV1_S)
#define  CPCFG0_PRU0_GPO_SH_SE		(1 << 25)

#define PRUCFG_GPCFG1	PRUCFG(0x000C)
#define  CPCFG0_PRU1_GPI_MODE_S		0
#define  CPCFG0_PRU1_GPI_MODE_W		2
#define  CPCFG0_PRU1_GPI_MODE_M		((CPCFG0_PRU1_GPI_MODE_W - 1) << CPCFG0_PRU1_GPI_MODE_S)
#define  CPCFG0_PRU1_GPI_MODE_DIRECT	(0 << CPCFG0_PRU1_GPI_MODE_S)
#define  CPCFG0_PRU1_GPI_MODE_PARALLEL	(1 << CPCFG0_PRU1_GPI_MODE_S)
#define  CPCFG0_PRU1_GPI_MODE_SHIFT	(2 << CPCFG0_PRU1_GPI_MODE_S)
#define  CPCFG0_PRU1_GPI_MODE_MII_RT	(3 << CPCFG0_PRU1_GPI_MODE_S)
#define  CPCFG0_PRU1_GPI_CLK_MODE	(1 << 2)
#define  CPCFG0_PRU1_GPI_DIV0_S		3
#define  CPCFG0_PRU1_GPI_DIV0_W		5
#define  CPCFG0_PRU1_GPI_DIV0_M		((CPCFG0_PRU1_GPI_DIV0_W - 1) << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_1		(0 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_1_5	(1 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_2		(2 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_2_5	(3 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_3		(4 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_3_5	(5 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_4		(6 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_4_5	(7 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_5		(8 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_5_5	(9 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_6		(10 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_6_5	(11 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_7		(12 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_7_5	(13 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_8		(14 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_8_5	(15 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_9		(16 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_9_5	(17 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_10	(18 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_10_5	(19 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_11	(20 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_11_5	(21 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_12	(22 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_12_5	(23 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_13	(24 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_13_5	(25 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_14	(26 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_14_5	(27 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_15	(28 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_15_5	(29 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV0_16	(30 << CPCFG0_PRU1_GPI_DIV0_S)
#define  CPCFG0_PRU1_GPI_DIV1_S		8
#define  CPCFG0_PRU1_GPI_DIV1_W		5
#define  CPCFG0_PRU1_GPI_DIV1_M		((CPCFG0_PRU1_GPI_DIV1_W - 1) << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_1		(0 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_1_5	(1 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_2		(2 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_2_5	(3 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_3		(4 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_3_5	(5 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_4		(6 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_4_5	(7 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_5		(8 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_5_5	(9 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_6		(10 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_6_5	(11 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_7		(12 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_7_5	(13 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_8		(14 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_8_5	(15 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_9		(16 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_9_5	(17 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_10	(18 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_10_5	(19 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_11	(20 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_11_5	(21 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_12	(22 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_12_5	(23 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_13	(24 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_13_5	(25 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_14	(26 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_14_5	(27 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_15	(28 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_15_5	(29 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_DIV1_16	(30 << CPCFG0_PRU1_GPI_DIV1_S)
#define  CPCFG0_PRU1_GPI_S8		(1 << 13)
#define  CPCFG0_PRU1_GPO_MODE		(1 << 14)
#define  CPCFG0_PRU1_GPO_DIV0_S		15
#define  CPCFG0_PRU1_GPO_DIV0_W		5
#define  CPCFG0_PRU1_GPO_DIV0_M		((CPCFG0_PRU1_GPO_DIV0_W - 1) << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_1		(0 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_1_5	(1 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_2		(2 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_2_5	(3 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_3		(4 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_3_5	(5 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_4		(6 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_4_5	(7 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_5		(8 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_5_5	(9 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_6		(10 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_6_5	(11 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_7		(12 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_7_5	(13 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_8		(14 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_8_5	(15 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_9		(16 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_9_5	(17 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_10	(18 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_10_5	(19 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_11	(20 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_11_5	(21 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_12	(22 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_12_5	(23 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_13	(24 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_13_5	(25 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_14	(26 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_14_5	(27 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_15	(28 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_15_5	(29 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV0_16	(30 << CPCFG0_PRU1_GPO_DIV0_S)
#define  CPCFG0_PRU1_GPO_DIV1_S		20
#define  CPCFG0_PRU1_GPO_DIV1_W		5
#define  CPCFG0_PRU1_GPO_DIV1_M		((CPCFG0_PRU1_GPO_DIV1_W - 1) << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_1		(0 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_1_5	(1 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_2		(2 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_2_5	(3 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_3		(4 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_3_5	(5 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_4		(6 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_4_5	(7 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_5		(8 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_5_5	(9 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_6		(10 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_6_5	(11 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_7		(12 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_7_5	(13 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_8		(14 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_8_5	(15 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_9		(16 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_9_5	(17 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_10	(18 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_10_5	(19 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_11	(20 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_11_5	(21 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_12	(22 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_12_5	(23 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_13	(24 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_13_5	(25 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_14	(26 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_14_5	(27 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_15	(28 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_15_5	(29 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_DIV1_16	(30 << CPCFG0_PRU1_GPO_DIV1_S)
#define  CPCFG0_PRU1_GPO_SH_SE		(1 << 25)

#define PRUCFG_CGR	PRUCFG(0x0010)

#define PRUCFG_ISRP	PRUCFG(0x0014)

#define PRUCFG_ISP	PRUCFG(0x0018)

#define PRUCFG_IESP	PRUCFG(0x001C)

#define PRUCFG_PMAO	PRUCFG(0x0028)
#define  PMAO_PMAO_PRU0		(1 << 0)
#define  PMAO_PMAO_PRU1		(1 << 1)

#define PRUCFG_MII_RT	PRUCFG(0x002C)

#define PRUCFG_IEPCLK	PRUCFG(0x0030)

#define PRUCFG_PINMX	PRUCFG(0x0040)

#define PINTC(_reg) \
	(*(volatile u32 *)((char *)&C0[_reg]))

#define PINTC_REVID		PINTC(0x0000)
#define PINTC_CR		PINTC(0x0004)
#define PINTC_GER		PINTC(0x0010)
#define PINTC_GNLR		PINTC(0x001C)
#define PINTC_SISR		PINTC(0x0020)
#define PINTC_SICR		PINTC(0x0024)
#define PINTC_EISR		PINTC(0x0028)
#define PINTC_EICR		PINTC(0x002C)
#define PINTC_HIEISR		PINTC(0x0034)
#define PINTC_HIDISR		PINTC(0x0038)
#define PINTC_GPIR		PINTC(0x0080)
#define PINTC_SRSR0		PINTC(0x0200)
#define PINTC_SECR0		PINTC(0x0280)
#define PINTC_ESR0		PINTC(0x0300)

#if defined(PRU0) || defined(PRU1)

#ifdef PRU0
#define PCTRL(_reg) \
	(*(volatile u32 *)((char *)0x22000 + (_reg)))
#define PCTRL_OTHER(_reg) \
	(*(volatile u32 *)((char *)0x24000 + (_reg)))
#else
#define PCTRL(_reg) \
	(*(volatile u32 *)((char *)0x24000 + (_reg)))
#define PCTRL_OTHER(_reg) \
	(*(volatile u32 *)((char *)0x22000 + (_reg)))
#endif

#define PCTRL_CONTROL		PCTRL(0x0000)
#define  CONTROL_SOFT_RST_N	(1 << 0)
#define  CONTROL_ENABLE		(1 << 1)
#define  CONTROL_SLEEPING	(1 << 2)
#define  CONTROL_COUNTER_ENABLE	(1 << 3)
#define  CONTROL_SINGLE_STEP	(1 << 8)
#define  CONTROL_RUNSTATE	(1 << 15)
#define PCTRL_STATUS		PCTRL(0x0004)
#define PCTRL_WAKEUP_EN		PCTRL(0x0008)
#define PCTRL_CYCLE		PCTRL(0x000C)
#define PCTRL_STALL		PCTRL(0x0010)
#define PCTRL_CTBIR0		PCTRL(0x0020)
#define PCTRL_CTBIR1		PCTRL(0x0024)
#define PCTRL_CTPPR0		PCTRL(0x0028)
#define PCTRL_CTPPR1		PCTRL(0x002C)

/* we can't access our debug registers (since we have to be stopped) */
#ifdef PRU0
#define PDBG_OTHER(_reg) \
	(*(volatile u32 *)((char *)0x24400 + (_reg)))
#else
#define PDBG_OTHER(_reg) \
	(*(volatile u32 *)((char *)0x22400 + (_reg)))
#endif

#endif

#define SIGNAL_EVENT(x) \
	do { \
		__R31 = (1 << 5) | ((x) - 16); \
	} while(0)


#ifndef PRU_CLK
/* default PRU clock (200MHz) */
#define PRU_CLK	200000000
#endif

/* NOTE: Do no use it for larger than 5 secs */
#define PRU_200MHz_sec(x)	((u32)(((x) * 200000000)))
#define PRU_200MHz_ms(x)	((u32)(((x) * 200000)))
#define PRU_200MHz_ms_err(x)	0
#define PRU_200MHz_us(x)	((u32)(((x) * 200)))
#define PRU_200MHz_us_err(x)	0
#define PRU_200MHz_ns(x)	((u32)(((x) * 2) / 10))
#define PRU_200MHz_ns_err(x)	((u32)(((x) * 2) % 10))

#if PRU_CLK != 200000000 
/* NOTE: Do no use it for larger than 5 secs */
#define PRU_sec(x)	((u32)(((u64)(x) * PRU_CLK)))
#define PRU_ms(x)	((u32)(((u64)(x) * PRU_CLK) / 1000))
#define PRU_ms_err(x)	((u32)(((u64)(x) * PRU_CLK) % 1000))
#define PRU_us(x)	((u32)(((u64)(x) * PRU_CLK) / 1000000))
#define PRU_us_err(x)	((u32)(((u64)(x) * PRU_CLK) % 1000000))
#define PRU_ns(x)	((u32)(((u64)(x) * PRU_CLK) / 1000000000))
#define PRU_ns_err(x)	((u32)(((u64)(x) * PRU_CLK) % 1000000000))
#else
/* NOTE: Do no use it for larger than 5 secs */
#define PRU_sec(x)	PRU_200MHz_sec(x)
#define PRU_ms(x)	PRU_200MHz_ms(x)
#define PRU_ms_err(x)	PRU_200MHz_ms_err(x)
#define PRU_us(x)	PRU_200MHz_us(x)
#define PRU_us_err(x)	PRU_200MHz_us_err(x)
#define PRU_ns(x)	PRU_200MHz_ns(x)
#define PRU_ns_err(x)	PRU_200MHz_ns_err(x)
#endif

#define DPRAM_SHARED	0x00010000

/* event definitions */
#define SYSEV_ARM_TO_PRU0	21
#define SYSEV_ARM_TO_PRU1	22
#define SYSEV_PRU0_TO_ARM	19
#define SYSEV_PRU0_TO_PRU1	17
#define SYSEV_PRU1_TO_ARM	20
#define SYSEV_PRU1_TO_PRU0	19

/* for communication with the host we have another set of events */
#define SYSEV_VR_ARM_TO_PRU0	24
#define SYSEV_VR_PRU0_TO_ARM	25
#define SYSEV_VR_ARM_TO_PRU1	26
#define SYSEV_VR_PRU1_TO_ARM	27

#define pru0_signal() (__R31 & (1U << 30))
#define pru1_signal() (__R31 & (1U << 31))

#ifdef PRU0
#define pru_signal()	pru0_signal()
#define SYSEV_OTHER_PRU_TO_THIS_PRU	SYSEV_PRU1_TO_PRU0
#define SYSEV_ARM_TO_THIS_PRU		SYSEV_ARM_TO_PRU0
#define SYSEV_THIS_PRU_TO_OTHER_PRU	SYSEV_PRU0_TO_PRU1
#define SYSEV_THIS_PRU_TO_ARM		SYSEV_PRU0_TO_ARM
#define SYSEV_VR_ARM_TO_THIS_PRU	SYSEV_VR_ARM_TO_PRU0
#define SYSEV_VR_THIS_PRU_TO_ARM	SYSEV_VR_PRU0_TO_ARM
#endif

#ifdef PRU1
#define pru_signal()	pru1_signal()
#define SYSEV_OTHER_PRU_TO_THIS_PRU	SYSEV_PRU0_TO_PRU1
#define SYSEV_ARM_TO_THIS_PRU		SYSEV_ARM_TO_PRU1
#define SYSEV_THIS_PRU_TO_OTHER_PRU	SYSEV_PRU1_TO_PRU0
#define SYSEV_THIS_PRU_TO_ARM		SYSEV_PRU1_TO_ARM
#define SYSEV_VR_ARM_TO_THIS_PRU	SYSEV_VR_ARM_TO_PRU1
#define SYSEV_VR_THIS_PRU_TO_ARM	SYSEV_VR_PRU1_TO_ARM
#endif

/* all events < 32 */
#define SYSEV_THIS_PRU_INCOMING_MASK	\
	(BIT(SYSEV_ARM_TO_THIS_PRU) | \
	 BIT(SYSEV_OTHER_PRU_TO_THIS_PRU) | \
	 BIT(SYSEV_VR_ARM_TO_THIS_PRU))

#define DELAY_CYCLES(x) \
	do { \
		unsigned int t = (x) >> 1; \
		do { \
			__asm(" "); \
		} while (--t); \
	} while(0)

#ifndef BIT
#define BIT(x) (1U << (x))
#endif

/* access to the resources of the other PRU (halt it and have your way) */
#if defined(PRU0) || defined(PRU1)

static inline void pru_other_halt(void)
{
	PCTRL_OTHER(0x0000) &= ~CONTROL_ENABLE;	/* clear enable */
	/* loop until RUNSTATE clears */
	while ((PCTRL_OTHER(0x0000) & CONTROL_RUNSTATE) != 0)
		;
}

static inline void pru_other_resume(void)
{
	PCTRL_OTHER(0x0000) |= CONTROL_ENABLE;	/* set enable */
}

static inline u32 pru_other_read_reg(u16 reg)
{
	u32 val;

	reg <<= 2;	/* multiply by 4 */
	pru_other_halt();
	val = PDBG_OTHER(reg);
	pru_other_resume();
	return val;
}

static inline void pru_other_write_reg(u16 reg, u32 val)
{
	reg <<= 2;	/* multiply by 4 */
	pru_other_halt();
	PDBG_OTHER(reg) = val;
	pru_other_resume();
}

static inline void pru_other_and_or_reg(u16 reg, u32 andmsk, u32 ormsk)
{
	reg <<= 2;	/* multiply by 4 */
	pru_other_halt();
	PDBG_OTHER(reg) = (PDBG_OTHER(reg) & andmsk) | ormsk;
	pru_other_resume();
}

#endif

#endif