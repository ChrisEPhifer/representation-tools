/*
 * test_print_bytes.c
 * Chris Phifer
 *
 * A simple testing script for the print_bytes library.
 */

#include <stdio.h>

#include "print_bytes.h"

void test_show_bytes(int val)
{
        int i = val;
        int f = (float) val;
        int *p = &val;

        printf("Bytes of an integer:\n");
        show_int(i);

        printf("Bytes of a float:\n");
        show_float(f);

        printf("Bytes of a pointer:\n");
        show_pointer(p);
}

int main(void)
{
        test_show_bytes(12345);
        return 0;
}
