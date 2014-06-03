/** @defgroup CM3_cortex_defines Cortex Core Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the Cortex Core </b>
 *
 * @ingroup CM3_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Ben Gamari <bgamari@gmail.com>
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
 * Copyright (C) 2014 Johann Fischer <j.fischer@fh-bingen.de>
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

#ifndef LIBOPENCM3_CORTEX_H
#define LIBOPENCM3_CORTEX_H

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Enable interrupts
 *
 * Disable the interrupt mask and enable interrupts globally
 */
static inline void cm_enable_interrupts(void)
{
	__asm__("CPSIE I\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Disable interrupts
 *
 * Mask all interrupts globally
 */
static inline void cm_disable_interrupts(void)
{
	__asm__("CPSID I\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Enable faults
 *
 * Disable the HardFault mask and enable fault interrupt globally
 */
static inline void cm_enable_faults(void)
{
	__asm__("CPSIE F\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Disable faults
 *
 * Mask the HardFault interrupt globally
 */
static inline void cm_disable_faults(void)
{
	__asm__("CPSID F\n");
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Check if interrupts are masked
 *
 * Checks, if interrupts are masked (disabled).
 *
 * @returns true, if interrupts are disabled.
 */
__attribute__((always_inline))
static inline bool cm_is_masked_interrupts(void)
{
	register uint32_t result;
	__asm__ ("MRS %0, PRIMASK"  : "=r" (result));
	return result;
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Check if Fault interrupt is masked
 *
 * Checks, if HardFault interrupt is masked (disabled).
 *
 * @returns bool true, if HardFault interrupt is disabled.
 */
__attribute__((always_inline))
static inline bool cm_is_masked_faults(void)
{
	register uint32_t result;
	__asm__ ("MRS %0, FAULTMASK"  : "=r" (result));
	return result;
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Mask interrupts
 *
 * This function switches the mask of the interrupts. If mask is true, the
 * interrupts will be disabled. The result of this function can be used for
 * restoring previous state of the mask.
 *
 * @param[in] mask bool New state of the interrupt mask
 * @returns bool old state of the interrupt mask
 */
__attribute__((always_inline))
static inline bool cm_mask_interrupts(bool mask)
{
	register bool old;
	__asm__ __volatile__("MRS %0, PRIMASK"  : "=r" (old));
	__asm__ __volatile__(""  : : : "memory");
	__asm__ __volatile__("MSR PRIMASK, %0" : : "r" (mask));
	return old;
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Mask HardFault interrupt
 *
 * This function switches the mask of the HardFault interrupt. If mask is true,
 * the HardFault interrupt will be disabled. The result of this function can be
 * used for restoring previous state of the mask.
 *
 * @param[in] mask bool New state of the HardFault interrupt mask
 * @returns bool old state of the HardFault interrupt mask
 */
__attribute__((always_inline))
static inline bool cm_mask_faults(bool mask)
{
	register bool old;
	__asm__ __volatile__ ("MRS %0, FAULTMASK"  : "=r" (old));
	__asm__ __volatile__ (""  : : : "memory");
	__asm__ __volatile__ ("MSR FAULTMASK, %0" : : "r" (mask));
	return old;
}

/*---------------------------------------------------------------------------*/
/** @brief Cortex M check if in interrupt
 *
 * Return value of interrupt program status register.
 *
 */

__attribute__((always_inline))
static inline uint32_t cm_is_in_interrupt(void)
{
	register uint32_t result;
	__asm__ ("MRS %0, IPSR"  : "=r" (result));
	return result;
}

/**@}*/

/*===========================================================================*/
/** @defgroup CM3_cortex_atomic_defines Cortex Core Atomic support Defines
 *
 * @brief Atomic operation support
 *
 * @ingroup CM3_cortex_defines
 */
/**@{*/

#if !defined(__DOXYGEN__)
/* Do not populate this definition outside */
static inline bool __cm_atomic_set(bool *val)
{
	return cm_mask_interrupts(*val);
}

#define __CM_SAVER(state)					\
do {								\
	__val = state,						\
	__save __attribute__((__cleanup__(__cm_atomic_set))) =	\
	__cm_atomic_set(&__val);				\
} while (0)

#endif /* !defined(__DOXYGEN) */


/*---------------------------------------------------------------------------*/
/** @brief Cortex M Atomic Declare block
 *
 * This macro disables interrupts for the next command or block of code. The
 * interrupt mask is automatically restored after exit of the boundary of the
 * code block. Therefore restore of interrupt is done automatically after call
 * of return or goto control sentence jumping outside of the block.
 *
 * @warning The usage of sentences break or continue is prohibited in the block
 * due to implementation of this macro!
 *
 * @note It is safe to use this block inside normal code and in interrupt
 * routine.
 *
 * @example 1: Basic usage of atomic block
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * CM_ATOMIC_BLOCK() {			// interrupts are masked in this block
 *     value = value * 1024 + 651;	// access value as atomic
 * }					// interrupts is restored automatically
 * @endcode
 *
 * @example 2: Use of return inside block:
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * uint64_t allocval(void)
 * {
 *     CM_ATOMIC_BLOCK() {		// interrupts are masked in this block
 *         value = value * 1024 + 651;	// do long atomic operation
 *         return value;		// interrupts is restored automatically
 *     }
 * }
 * @endcode
 */
#if defined(__DOXYGEN__)
#define CM_ATOMIC_BLOCK()
#else /* defined(__DOXYGEN__) */
#define CM_ATOMIC_BLOCK()						\
do {									\
	for (bool ___CM_SAVER(true), __my = true; __my; __my = false);	\
} while (0)
#endif /* defined(__DOXYGEN__) */

/*---------------------------------------------------------------------------*/
/** @brief Cortex M Atomic Declare context
 *
 * This macro disables interrupts in the current block of code from the place
 * where it is defined to the end of the block. The interrupt mask is
 * automatically restored after exit of the boundary of the code block.
 * Therefore restore of interrupt is done automatically after call of return,
 * continue, break, or goto control sentence jumping outside of the block.
 *
 * @note This function is intended for use in for- cycles to enable the use of
 * break and contine sentences inside the block, and for securing the atomic
 * reader-like functions.
 *
 * @note It is safe to use this block inside normal code and in interrupt
 * routine.
 *
 * @example 1: Basic usage of atomic context
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * for (int i=0;i < 100; i++) {
 *     CM_ATOMIC_CONTEXT();		// interrupts are masked in this block
 *     value += 100;			// access value as atomic
 *     if ((value % 16) == 0) {
 *         break;			// restore interrupts and break cycle
 *     }
 * }					// interrupts is restored automatically
 * @endcode
 *
 * @example 2: Usage of atomic context inside atomic reader fcn.
 *
 * @code
 * uint64_t value;		// This value is used somewhere in interrupt
 *
 * ...
 *
 * uint64_t getnextval(void)
 * {
 *     CM_ATOMIC_CONTEXT();	// interrupts are masked in this block
 *     value = value + 3;	// do long atomic operation
 *     return value;		// interrupts is restored automatically
 * }
 * @endcode
 */
#if defined(__DOXYGEN__)
#define CM_ATOMIC_CONTEXT()
#else /* defined(__DOXYGEN__) */
#define CM_ATOMIC_CONTEXT()	bool __CM_SAVER(true)
#endif /* defined(__DOXYGEN__) */

/**@}*/

/*===========================================================================*/
/** @defgroup CM0_thread_support Cortex-M0 context switch support defines
 *
 * @brief context switch operation support
 *
 * @ingroup CM3_cortex_defines
 */
/**@{*/
#define CM0_EXC_RET_HM_MSP		0xfffffff1
#define CM0_EXC_RET_TM_MSP		0xfffffff9
#define CM0_EXC_RET_TM_PSP		0xfffffffd
static uint32_t cm0_cswitch_retval = CM0_EXC_RET_TM_PSP;
static uint32_t cm0_psp_default = 0xfffffffc;

__attribute__((always_inline))
static inline void cm0_switch_context_psp_use(void)
{
	register uint32_t saved_msp asm ("r12");
	register uint32_t tmp asm ("r3");
	register uint32_t ptr asm ("r0");

	asm volatile(	
		"ldr %[o_ptr], [%[i_def_psp_value]]\n\t"
		"mrs %[o_tmp], psp\n\t"
		"cmp %[i_tmp], %[i_ptr]\n\t"
		"beq sv_call_handler_context_exit\n\t"
		/* outputs */
		: [o_tmp] "=r" (tmp), [o_ptr] "=r" (ptr)
		/* inputs */
		: [i_tmp] "r" (tmp), [i_ptr] "r" (ptr) 
		, [i_def_psp_value] "r" (&cm0_psp_default)
		/* clobbers */
		: "memory","r7","r6","r5","r4"
	);
	asm volatile(	
  		".extern  sched_active_thread\n\t"
		/* save main stack pointer, load msp with psp value */
		"mrs %[o_saved_msp], msp\n\t"
		"mrs %[o_tmp], psp\n\t"
		"msr msp, %[i_tmp]\n\t"
		"isb\n\t"

		/* save registers r4 .. r7 */
		"push {r4-r7}\n\t"

		/* save process stack pointer */
		"mrs %[o_tmp], msp\n\t" 
		"ldr %[o_ptr], =sched_active_thread\n\t"
		"ldr %[o_ptr], [%[i_ptr]]\n\t"
		"str %[i_tmp], [%[i_ptr]]\n\t" 

		/* restore main stack pointer */
		"msr msp, %[i_saved_msp]\n\t"
		"isb\n\t"
		/* outputs */
		: [o_tmp] "=r" (tmp), [o_ptr] "=r" (ptr), [o_saved_msp] "=r" (saved_msp)
		/* inputs */
		: [i_tmp] "r" (tmp), [i_ptr] "r" (ptr), [i_saved_msp] "r" (saved_msp)
		/* clobbers */
		: "memory","r7","r6","r5","r4"
	);
	asm volatile(	
		"sv_call_handler_context_exit:\n\t"
		//"push {r0-r3}\n\t"
		"bl sched_run\n\t"
		//"pop {r0-r3}\n\t"
		/* outputs */
		:
		/* inputs */
		:
		/* clobbers */
		: "memory","r7","r6","r5","r4"
	);
	asm volatile(	
  		".extern  sched_active_thread\n\t"
		/* save main stack pointer */
		"mrs %[o_saved_msp], msp\n\t" 
		/* load msp with threads psp value */
		"ldr %[o_ptr], =sched_active_thread\n\t"
		"ldr %[o_ptr], [%[i_ptr]]\n\t"
		"ldr %[o_tmp], [%[i_ptr]]\n\t"
		"msr msp, %[i_tmp]\n\t"
		"isb\n\t"

		/* restore registers r4 .. r7 */
		"pop {r4-r7}\n\t"
		/* copy msp to psp */
		"mrs %[o_tmp], msp\n\t"
		"msr psp, %[i_tmp]\n\t"
		
		/* restore main stack pointer */
		"msr msp, %[i_saved_msp]\n\t"
		"isb\n\t"

		/* return */
		"ldr %[o_tmp], [%[i_ret_tm_psp]]\n\t"
		"bx %[i_tmp]\n\t"

		/* outputs */
		: [o_tmp] "=r" (tmp), [o_ptr] "=r" (ptr), [o_saved_msp] "=r" (saved_msp)
		/* inputs */
		: [i_tmp] "r" (tmp), [i_ptr] "r" (ptr), [i_saved_msp] "r" (saved_msp)
		, [i_ret_tm_psp] "r" (&cm0_cswitch_retval)
		/* clobbers */
		: "memory","r7","r6","r5","r4","cc"
	);
}

__attribute__((always_inline))
static inline void cm0_switch_to_msp(void)
{
	asm("movs r0, #0");
	asm("msr control, r0");
	asm("isb");
}

__attribute__((always_inline))
static inline void cm0_sign_psp(void)
{
	asm volatile("ldr r0, [%0]" : : "r"(&cm0_psp_default));
	asm("msr psp, r0");
}

/**@}*/

#endif
