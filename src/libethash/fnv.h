/* ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
 * Copyright 2018 Pawel Bylica.
 * Licensed under the Apache License, Version 2.0. See the LICENSE file.
 */

/*
  (C)TAO.Foundation for TETHASHV1 modification. GPL V3 License term.
  https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1_hash

  FNV_hash0 is depricated
  use FNV1 hash

use hash offset
FNV-1a hash
The FNV-1a hash differs from the FNV-1 hash by only the order in which the multiply and XOR is
performed:[8][10]

   hash = FNV_offset_basis
   for each byte_of_data to be hashed
    hash = hash XOR byte_of_data
    hash = hash × FNV_prime
   return hash

Size in bits
{\displaystyle n=2^{s}} {\displaystyle n=2^{s}}

FNV prime	FNV offset basis
32	224 + 28 + 0x93 = 16777619

2166136261 = 0x811c9dc5
*/

/*
  This file is part of cpp-ethereum.

  cpp-ethereum is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  cpp-ethereum is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file fnv.h
* @author Matthew Wampler-Doty <negacthulhu@gmail.com>
* @date 2015
*/

#pragma once
#include <stdint.h>
#include "compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __TETHASHV1__
#undef __ETHASH__

#define FNV_PRIME 0x01000193
#define FNV_OFFSET_BASIS 0x811c9dc5

/*
#ifdef __ETHASH__
#define fnv(x, y) ((x)*FNV_PRIME ^ (y))
#define fnv_reduce(v) fnv(fnv(fnv(v.x, v.y), v.z), v.w)
#else // default __TETHASHV1__
#define fnv1a_(x, y) ((((FNV_OFFSET_BASIS ^ (x)) * FNV_PRIME) ^ (y)) * FNV_PRIME)
#define fnv1a_reduce(v) fnv1a(fnv1a(fnv1a(v.x, v.y), v.z), v.w)
#endif
*/

/* The FNV-1 spec multiplies the prime with the input one byte (octet) in turn.
   We instead multiply it with the full 32-bit input.
   This gives a different result compared to a canonical FNV-1 implementation.
*/
  static inline uint32_t fnv_hash(uint32_t const x, uint32_t const y)
  {
    return x * FNV_PRIME ^ y;
  }

  /**
 * The implementation of FNV-1a hash.
 *
 * See https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash.
 */
  static inline uint32_t fnv1a_hash(uint32_t u, uint32_t v)
  {
    return (u ^ v) * FNV_PRIME;
  }

#ifdef __cplusplus
}
#endif
