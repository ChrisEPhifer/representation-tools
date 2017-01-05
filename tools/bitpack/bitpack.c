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

bool bitpack_fitsu(uint64_t n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        return (n >> width) == 0;
}

bool bitpack_fitss(int64_t n, unsigned width)
{
        assert(width <= WORD_SIZE);
        assert(width > 0);

        return (n >> width) == -1; /* Depends on arithmetic shift! */
}

uint64_t bitpack_getu(uint64_t vec, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        return vec << (WORD_SIZE - (lsb + width)) >> (WORD_SIZE - width);
}

int64_t bitpack_gets(uint64_t, unsigned lsb, unsigned width)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(width + lsb <= WORD_SIZE);

        /* Depends on arithmetic shift! */
        return ((int64_t) vec << (WORD_SIZE - (lsb + width)))
                              >> (WORD_SIZE - width);
}

uint64_t bitpack_setu(uint64_t vec, unsigned lsb, unsigned width, uint64_t val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitsu(val, width));

        uint64_t mask = ~0ull >> (WORD_SIZE - width) << lsb;

        return (word & ~mask) | (val << lsb);
}

uint64_t bitpack_sets(uint64_t vec, unsigned lsb, unsigned width, int64_t val)
{
        assert(lsb < WORD_SIZE);
        assert(width <= WORD_SIZE);
        assert(lsb + width <= WORD_SIZE);
        assert(bitpack_fitsu(val, width));

        uint64_t mask = ~0ull >> (WORD_SIZE - width) << lsb;

        /* 'And'-ing with the mask gets rid of excess leading 1s */
        return (word & ~mask) | (mask & (val << lsb));
}




