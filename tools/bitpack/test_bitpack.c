/*
 * test_bitpack.c
 * Chris Phifer
 *
 * This is a simple testing script for the bitpack library.
 */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "bitpack.h"

void test_bitpack_fitsu(uint64_t n, unsigned width)
{
        if (bitpack_fitsu(n, width)) {
                printf("%" PRIu64 " fits in %u bits\n", n, width);
        } else {
                printf("%" PRIu64 " does not fit in %u bits\n", n, width);
        }
}

void test_bitpack_fitss(int64_t n, unsigned width)
{
        if (bitpack_fitss(n, width)) {
                printf("%" PRId64 " fits in %u bits\n", n, width);
        } else {
                printf("%" PRId64 " does not fit in %u bits\n", n, width);
        }
}

int main(void)
{
        test_bitpack_fitsu(0, 1);
        test_bitpack_fitsu(-1, 64);
        test_bitpack_fitsu(20, 5);
        test_bitpack_fitsu(20, 4);
        test_bitpack_fitss(-1, 1);
        test_bitpack_fitss(-2, 2);
        test_bitpack_fitss(-2, 1);
        test_bitpack_fitss(-4, 3);
        test_bitpack_fitss(-4, 2);
        test_bitpack_fitss(10, 64);
        return 0;
}
