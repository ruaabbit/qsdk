/*
 * Copyright (c) 2018-2019, The Linux Foundation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __QTISECLIB_DEFS_H__
#define __QTISECLIB_DEFS_H__

#include <stdint.h>

#ifndef u_register_t
typedef uintptr_t u_register_t;
#endif

#define QTISECLIB_PLAT_CLUSTER_COUNT	1
#define QTISECLIB_PLAT_CORE_COUNT	4

/* Different Log Level supported in qtiseclib.
   TODO: Currently no filtering done on QTISECLIB logs. */
#define QTISECLIB_LOG_LEVEL_NONE	0
#define QTISECLIB_LOG_LEVEL_ERROR	10
#define QTISECLIB_LOG_LEVEL_NOTICE	20
#define QTISECLIB_LOG_LEVEL_WARNING	30
#define QTISECLIB_LOG_LEVEL_INFO	40
#define QTISECLIB_LOG_LEVEL_VERBOSE	50

#define QTI_GICV3_IRM_PE		0
#define QTI_GICV3_IRM_ANY		1

/* Interrupt number/ID defs. TODO: Chipset specific.
   Need to be feature gurded with Chipset Macro. */
#define QTISECLIB_INT_ID_SEC_WDOG_BARK                  (0xD5)
#define QTISECLIB_INT_ID_NON_SEC_WDOG_BITE              (0x24)
#define QTISECLIB_INT_ID_RESET_SGI                      (0xf)
#define QTISECLIB_INT_ID_CPU_WAKEUP_SGI                 (0x8)

#define QTISECLIB_INT_ID_VMIDMT_ERR_CLT_SEC             (0xE6)
#define QTISECLIB_INT_ID_VMIDMT_ERR_CLT_NONSEC          (0xE7)
#define QTISECLIB_INT_ID_VMIDMT_ERR_CFG_SEC             (0xE8)
#define QTISECLIB_INT_ID_VMIDMT_ERR_CFG_NONSEC          (0xE9)

#define QTISECLIB_INT_ID_XPU_SEC                        (0xE3)
#define QTISECLIB_INT_ID_XPU_NON_SEC                    (0xE4)

#define QTISECLIB_INT_ID_MEM_NOC_ERROR                  (0x71)
#define QTISECLIB_INT_ID_SYSTEM_NOC_ERROR               (0xE1)
#define QTISECLIB_INT_ID_PC_NOC_ERROR                   (0xE2)
#define QTISECLIB_INT_ID_AGGNOC_NOC_ERROR               (0x8E)
#define QTISECLIB_INT_ID_AHB_TIMEOUT                    (0xE5)
#define QTISECLIB_INT_ID_TME_IPC                        (0x021E)
#define QTISECLIB_INT_INVALID_INT_NUM                   (0xFFFFFFFFU)

/*
 * Put BL31 at DDR as per memory map. BL31_BASE is calculated using the
 * current BL31 debug size plus a little space for growth.
 */
#define BL31_BASE						0x4A600000
#define BL31_SIZE						0x300000
#define QTI_TRUSTED_MAILBOX_SIZE				0x1000
#define BL31_LIMIT						(BL31_BASE + BL31_SIZE - QTI_TRUSTED_MAILBOX_SIZE)

/* External CPU Dump Structure - 64 bit EL */
typedef struct
{
	uint64_t x0;
	uint64_t x1;
	uint64_t x2;
	uint64_t x3;
	uint64_t x4;
	uint64_t x5;
	uint64_t x6;
	uint64_t x7;
	uint64_t x8;
	uint64_t x9;
	uint64_t x10;
	uint64_t x11;
	uint64_t x12;
	uint64_t x13;
	uint64_t x14;
	uint64_t x15;
	uint64_t x16;
	uint64_t x17;
	uint64_t x18;
	uint64_t x19;
	uint64_t x20;
	uint64_t x21;
	uint64_t x22;
	uint64_t x23;
	uint64_t x24;
	uint64_t x25;
	uint64_t x26;
	uint64_t x27;
	uint64_t x28;
	uint64_t x29;
	uint64_t x30;
	uint64_t pc;
	uint64_t currentEL;
	uint64_t sp_el3;
	uint64_t elr_el3;
	uint64_t spsr_el3;
	uint64_t sp_el2;
	uint64_t elr_el2;
	uint64_t spsr_el2;
	uint64_t sp_el1;
	uint64_t elr_el1;
	uint64_t spsr_el1;
	uint64_t sp_el0;
	uint64_t __reserved1;
	uint64_t __reserved2;
	uint64_t __reserved3;
	uint64_t __reserved4;
	uint64_t __reserved5;
	uint64_t __reserved6;
	uint64_t __reserved7;
	uint64_t __reserved8;
}qtiseclib_dbg_a64_ctxt_regs_type;

typedef struct qtiseclib_cb_spinlock {
	volatile uint32_t lock;
} qtiseclib_cb_spinlock_t;

typedef enum qtiseclib_mmap_attr_s {
	QTISECLIB_MAP_NS_RO_XN_DATA = 1,
	QTISECLIB_MAP_RW_XN_NC_DATA = 2,
	QTISECLIB_MAP_RW_XN_DATA = 3,
} qtiseclib_mmap_attr_t;

/*------------------------------------------------------------------------------
 * Syscalls marked with RSP flag will be passed a ptr to
 * this struct.
 *
 * A syscall cannot send more than three 4-byte values back to HLOS via registers.
 * A syscall cannot return with more than 6 4-byte values back to TEE via registers.
 * -------------------------------------------------------------------------*/
typedef struct qti_smc_rsp_s {
  uintptr_t rsp[6];              //Values to return to HLOS or TEE
  uintptr_t return_to_tee;       //Indication to post an smc after the current smc has been handled and return to tee
} qti_smc_rsp_t;

typedef struct hlos_boot_params_s
{
  uintptr_t el1_x0;
  uintptr_t el1_x1;
  uintptr_t el1_x2;
  uintptr_t el1_x3;
  uintptr_t el1_x4;
  uintptr_t el1_x5;
  uintptr_t el1_x6;
  uintptr_t el1_x7;
  uintptr_t el1_x8;
  uintptr_t el1_elr;
} hlos_boot_params_t;


#endif /* __QTISECLIB_DEFS_H__ */
