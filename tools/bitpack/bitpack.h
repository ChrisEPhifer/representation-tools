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
 */

#include <stdbool.h>
#include <stdint.h>

#define WORD_SIZE 64

/*
 *    Purpose: Check if a value n fits into the specified number of bits.
 * Parameters: A 64 bit unsigned value n, and an unsigned width (in bits).
 *    Returns: A boolean (true if n fits into width, false otherwise)
 *   Contract: It is a checked runtime error to pass a width greater than the
 *             maximum word size (64).
 */
bool bitpack_fitsu(uint64_t n, unsigned width);

/*
 *    Purpose: Check if a value n fits into the specified number of bits.
 * Parameters: A 64 bit signed value n, and an unsigned width (in bits).
 *    Returns: A boolean (true if n fits into width, false otherwise)
 *   Contract: It is a checked runtime error to pass a width greater than the
 *             maximum word size (64).
 */
bool bitpack_fitss(int64_t n, unsigned width);

/*
 *    Purpose: Unpack a value of given width and offset from a bit vector.
 * Parameters: A bit vector (packed data), the least significant bit position,
 *             and the number of bits (the width).
 *    Returns: The data contained at the location specified by the parameters.
 */
uint64_t bitpack_getu(uint64_t vec, unsigned lsb, unsigned width);

/*
 *    Purpose: Unpack a value of given width and offset from a bit vector.
 * Parameters: A bit vector (packed data), the least significant bit position,
 *             and the number of bits (the width).
 *    Returns: The data contained at the location specified by the parameters.
 */
int64_t bitpack_gets(uint64_t vec, unsigned lsb, unsigned width);

/*
 *    Purpose: Pack an unsigned value into the bit vector, and return the new
 *             bit vector.
 * Parameters: A bit vector, the least significant bit position, the number of
 *             bits, and the data itself.
 *    Returns: The resultant bit vector after packing the data.
 */
uint64_t bitpack_setu(uint64_t vec, unsigned lsb, unsigned width, uint64_t val);

/*
 *    Purpose: Pack an unsigned value into the bit vector, and return the new
 *             bit vector.
 * Parameters: A bit vector, the least significant bit position, the number of
 *             bits, and the data itself.
 *    Returns: The resultant bit vector after packing the data.
 */
uint64_t bitpack_sets(uint64_t vec, unsigned lsb, unsigned width, int64_t val);








