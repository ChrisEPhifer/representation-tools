/*
 * test_bitpack.c
 * Chris Phifer
 *
 * This is a simple testing script for the bitpack library.
 *
 * Note that these tests use the default word size settings, i.e. 64 bits.
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

void test_bitpack_getu(uint64_t vec, unsigned lsb, unsigned width, uint64_t val)
{
        if (bitpack_getu(vec, lsb, width) == val) {
                printf("Got correct value, %" PRIu64 " from vector.\n", val);
        } else {
                printf("Got incorrect value from vector.\n");
        }
}

void test_bitpack_gets(uint64_t vec, unsigned lsb, unsigned width, int64_t val)
{
        if (bitpack_gets(vec, lsb, width) == val) {
                printf("Got correct value, %" PRId64 " from vector.\n", val);
        } else {
                printf("Got incorrect value from vector (%" PRId64 ").\n", bitpack_gets(vec, lsb, width));
        }
}

void test_bitpack_setu(uint64_t vec, unsigned lsb, unsigned width, uint64_t val,
                       uint64_t expected)
{
        if (bitpack_setu(vec, lsb, width, val) == expected) {
                printf("Successfully packed bits.\n");
        } else {
                printf("Error packing bits.\n");
        }
}

void test_bitpack_sets(uint64_t vec, unsigned lsb, unsigned width, int64_t val,
                       uint64_t expected)
{
        if (bitpack_sets(vec, lsb, width, val) == expected) {
                printf("Successfully packed bits.\n");
        } else {
                printf("Error packing bits.\n");
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
        test_bitpack_getu(0xE00ull, 9, 3, 7);
        test_bitpack_gets(0xE00ull, 9, 3, -1);
        test_bitpack_setu(0ull, 9, 3, 7, 0xE00ull);
        test_bitpack_sets(0ull, 9, 3, -1, 0xE00ull);
        return 0;
}
