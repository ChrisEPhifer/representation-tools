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

uword shl(uword n, unsigned amt)
{
        if (amt == WORD_SIZE) {
                return 0;
        }
        
        return n << amt;
}

uword shr_arith(uword n, unsigned amt)
{
        uword result = n >> amt;
        uword sign_bits;

        if (amt == WORD_SIZE) {
                return 0;
        }

        /* If the sign bit is on, put in sign bits */
        if (n & 0x8000000000000) {
                sign_bits = ~(shl(1, WORD_SIZE - amt) - 1);
                result = result | sign_bits;
        }

        return result;
}

uword shr_logic(uword n, unsigned amt)
{
        if (amt == WORD_SIZE) {
                return 0;
        }
        
        return n >> amt;       
}

bool bitpack_fitsu(uword n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        return shr_logic(n, width) == 0;
}

bool bitpack_fitss(sword n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        /* Shift one less than the width to account for sign bit */
        if (n < 0) {
                return ((sword) shr_arith(n, width - 1)) == -1;
        } else {
                return shr_logic(n, width - 1) == 0;
        }
}

uword bitpack_getu(uword vec, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        return shr_logic(shl(vec, WORD_SIZE - (lsb + width)),
                         WORD_SIZE - width);
}

sword bitpack_gets(uword vec, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        return shr_arith(shl(vec, WORD_SIZE - (lsb + width)),
                         WORD_SIZE - width);
}

uword bitpack_setu(uword vec, unsigned lsb, unsigned width, uword val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitsu(val, width));

        uword mask = ~0ull >> (WORD_SIZE - width) << lsb;

        return (vec & ~mask) | (val << lsb);
}

uword bitpack_sets(uword vec, unsigned lsb, unsigned width, sword val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitsu(val, width));

        uword mask = ~0ull >> (WORD_SIZE - width) << lsb;

        /* 'And'-ing with the mask gets rid of excess leading 1s */
        return (vec & ~mask) | (mask & (val << lsb));
}




