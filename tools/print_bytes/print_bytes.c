/* 
 * print_bytes.c
 * Chris Phifer
 * 
 * This is the implementation of the print_bytes library. For detailed usage
 * info, see print_bytes.h
 */

#include <stdio.h>

#include "print_bytes.h"

void show_bytes(byte_ptr addr, size_t size)
{
        unsigned i;
        for (i = 0; i < size; ++i) {
                /* Print two hex digits */
                printf(" %.2x", addr[i]);
        }
        printf("\n");
}

void show_char(char c)
{
        show_bytes((byte_ptr) &c, sizeof(char));
}

void show_short(short s)
{
        show_bytes((byte_ptr) &s, sizeof(short));
}

void show_int(int i)
{
        show_bytes((byte_ptr) &i, sizeof(int));
}

void show_long(long l)
{
        show_bytes((byte_ptr) &l, sizeof(long));
}

void show_float(float f)
{
        show_bytes((byte_ptr) &f, sizeof(float));
}

void show_double(double d)
{
        show_bytes((byte_ptr) &d, sizeof(double));
}

void show_pointer(void *p)
{
        show_bytes((byte_ptr) &p, sizeof(void *));
}





