/*
 * bitpack.h
 * Chris Phifer
 * 
 * This library is a bitpacking API useful for applications that make use of
 * flags, binary packed data (networking, emulation, etc), and for the study of
 * bitwise operations and compressed data.
 *
 * The API provides methods for packing both signed and unsigned data. Packing
 * and unpacking is safe, in that the behavior for edge cases is well-defined.
 * There are methods for packing in both 32 and 64-bit integers, using the
 * standard library stdint.h, with types uint32_t, uint64_t, int32_t, and
 * int64_t.
 */

#include <stdbool.h>
#include <stdint.h>

bool bitpack_fitsu32();
bool bitpack_fitsu64();
bool bitpack_fitss32();
bool bitpack_fitss64();



