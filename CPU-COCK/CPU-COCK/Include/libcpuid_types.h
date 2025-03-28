/*
 * Copyright 2008  Veselin Georgiev,
 * anrieffNOSPAM @ mgail_DOT.com (convert to gmail)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * @File     libcpuid_types.h
 * @Author   Veselin Georgiev
 * @Brief    Type specifications for libcpuid.
 */

#ifndef __LIBCPUID_TYPES_H__
#define __LIBCPUID_TYPES_H__

#if !defined(_MSC_VER) || _MSC_VER >= 1600
#  include <stdint.h>
#else
/* we have to provide our own: */
#  if !defined(__int32_t_defined)
typedef int int32_t;
#  endif

#  if !defined(__uint32_t_defined)
typedef unsigned uint32_t;
#  endif

typedef signed char		int8_t;
typedef unsigned char		uint8_t;
typedef signed short		int16_t;
typedef unsigned short		uint16_t;
#if (defined _MSC_VER) && (_MSC_VER <= 1300)
	/* MSVC 6.0: no long longs ... */
	typedef signed __int64		int64_t;
	typedef unsigned __int64	uint64_t;
#else
	/* all other sane compilers: */
	typedef signed long long   int64_t;
	typedef unsigned long long uint64_t;
#endif

#endif

typedef uint16_t logical_cpu_t;
#define __MASK_NCPUBITS 8
#define __MASK_SETSIZE  (1ULL << (sizeof(logical_cpu_t) * __MASK_NCPUBITS)) / __MASK_NCPUBITS
/**
 * @brief Internal structure, used in affinity_mask_str_r and affinity_mask_str
 */
typedef struct {
	uint8_t __bits[__MASK_SETSIZE]; /*!< affinity mask */
} cpu_affinity_mask_t;

#endif /* __LIBCPUID_TYPES_H__ */
