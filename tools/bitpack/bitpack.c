/*
 * bitpack.c
 * Chris Phifer
 *
 * This is the implementation of the bitpack library. For interface and usage
 * details, see bitpack.h.
 */

#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "bitpack.h"

uint64_t shl(uint64_t n, unsigned amt)
{
        if (amt == WORD_SIZE) {
                return 0;
        }
        
        return n << amt;
}

uint64_t shr_arith(uint64_t n, unsigned amt)
{
        uint64_t result = n >> amt;
        uint64_t sign_bits;

        if (amt == WORD_SIZE) {
                return 0;
        }

        /* If the sign bit is on, put in sign bits */
        if (n & 0x8000000000000000) {
                sign_bits = ~(shl(1, WORD_SIZE - amt) - 1);
                result = result | sign_bits;
        }

        return result;
}

uint64_t shr_logic(uint64_t n, unsigned amt)
{
        if (amt == WORD_SIZE) {
                return 0;
        }
        
        return n >> amt;       
}

bool bitpack_fitsu(uint64_t n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        return shr_logic(n, width) == 0;
}

bool bitpack_fitss(int64_t n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        /* Shift one less than the width to account for sign bit */
        if (n < 0) {
                return ((int64_t) shr_arith(n, width - 1)) == -1;
        } else {
                return shr_logic(n, width - 1) == 0;
        }
}

uint64_t bitpack_getu(uint64_t vec, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        return shr_logic(shl(vec, WORD_SIZE - (lsb + width)),
                         WORD_SIZE - width);
}

int64_t bitpack_gets(uint64_t vec, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        return (int64_t) shr_arith(shl(vec, WORD_SIZE - (lsb + width)),
                                   WORD_SIZE - width);
}

uint64_t bitpack_setu(uint64_t vec, unsigned lsb, unsigned width, uint64_t val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitsu(val, width));

        uint64_t mask = ~0ull >> (WORD_SIZE - width) << lsb;

        return (vec & ~mask) | (val << lsb);
}

uint64_t bitpack_sets(uint64_t vec, unsigned lsb, unsigned width, int64_t val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitss(val, width));

        uint64_t mask = ~0ull >> (WORD_SIZE - width) << lsb;

        /* 'And'-ing with the mask gets rid of excess leading 1s */
        return (vec & ~mask) | (mask & (val << lsb));
}




