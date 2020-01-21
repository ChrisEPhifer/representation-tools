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

WORD_UNSIGNED_TYPE shl(WORD_UNSIGNED_TYPE n, unsigned amt)
{
        if (amt == WORD_SIZE) {
                return 0;
        }

        return n << amt;
}

WORD_UNSIGNED_TYPE shr_arith(WORD_UNSIGNED_TYPE n, unsigned amt)
{
        WORD_UNSIGNED_TYPE result = n >> amt;
        WORD_UNSIGNED_TYPE sign_bits;

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

WORD_UNSIGNED_TYPE shr_logic(WORD_UNSIGNED_TYPE n, unsigned amt)
{
        if (amt == WORD_SIZE) {
                return 0;
        }

        return n >> amt;
}

bool bitpack_fitsu(WORD_UNSIGNED_TYPE n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        return shr_logic(n, width) == 0;
}

bool bitpack_fitss(WORD_SIGNED_TYPE n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        /* Shift one less than the width to account for sign bit */
        if (n < 0) {
                return ((WORD_SIGNED_TYPE) shr_arith(n, width - 1)) == -1;
        } else {
                return shr_logic(n, width - 1) == 0;
        }
}

WORD_UNSIGNED_TYPE bitpack_getu(WORD_UNSIGNED_TYPE vec, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        return shr_logic(shl(vec, WORD_SIZE - (lsb + width)),
                         WORD_SIZE - width);
}

WORD_SIGNED_TYPE bitpack_gets(WORD_UNSIGNED_TYPE vec, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        return (WORD_SIGNED_TYPE) shr_arith(shl(vec, WORD_SIZE - (lsb + width)),
                                   WORD_SIZE - width);
}

WORD_UNSIGNED_TYPE bitpack_setu(WORD_UNSIGNED_TYPE vec, unsigned lsb, unsigned width, WORD_UNSIGNED_TYPE val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitsu(val, width));

        WORD_UNSIGNED_TYPE mask = ~0ull >> (WORD_SIZE - width) << lsb;

        return (vec & ~mask) | (val << lsb);
}

WORD_UNSIGNED_TYPE bitpack_sets(WORD_UNSIGNED_TYPE vec, unsigned lsb, unsigned width, WORD_SIGNED_TYPE val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitss(val, width));

        WORD_UNSIGNED_TYPE mask = ~0ull >> (WORD_SIZE - width) << lsb;

        /* 'And'-ing with the mask gets rid of excess leading 1s */
        return (vec & ~mask) | (mask & (val << lsb));
}




