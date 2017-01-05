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
 *
 * IMPORTANT NOTE: We assume that you are working on a reasonable machine and
 * with a reasonable compiler that implements right bit shifts as arithmetic
 * rather than logical (i.e. the most significant bit is that which is copied
 * into the newly opened positions, rather than zero). Failure to do so will
 * result in unexpected behavior!
 */

#include <stdbool.h>
#include <stdint.h>

#define WORD_SIZE 64

/*
 *    Purpose: Check if a value n fits into the specified number of bits.
 * Parameters: A 64 bit unsigned value n, and an unsigned width (in bits).
 *    Returns: A boolean (true if n fits into width, false otherwise)
 *   Contract: It is a checked runtime error to pass a width greater than the
 *             maximum word size (64). It is also checked that width be
 *             positive.
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
 *             and the number of bits (the width). Note that bit positions are
 *             zero indexed.
 *    Returns: The data contained at the location specified by the parameters.
 *   Contract: It is a checked runtime error to pass in an invalid least
 *             significant bit value, it is checked to pass in an invalid
 *             width, and it is checked to pass an invalid combination of the
 *             two.
 */
uint64_t bitpack_getu(uint64_t vec, unsigned lsb, unsigned width);

/*
 *    Purpose: Unpack a value of given width and offset from a bit vector.
 * Parameters: A bit vector (packed data), the least significant bit position,
 *             and the number of bits (the width).
 *    Returns: The data contained at the location specified by the parameters.
 *   Contract: Same as the above function.
 */
int64_t bitpack_gets(uint64_t vec, unsigned lsb, unsigned width);

/*
 *    Purpose: Pack an unsigned value into the bit vector, and return the new
 *             bit vector.
 * Parameters: A bit vector, the least significant bit position, the number of
 *             bits, and the data itself.
 *    Returns: The resultant bit vector after packing the data.
 *   Contract: It is a checked runtime error to pass in an invalid least
 *             significant bit value, an invalid width, combination of the two,
 *             or to try and pack in a width the value does not fit into.
 */
uint64_t bitpack_setu(uint64_t vec, unsigned lsb, unsigned width, uint64_t val);

/*
 *    Purpose: Pack an unsigned value into the bit vector, and return the new
 *             bit vector.
 * Parameters: A bit vector, the least significant bit position, the number of
 *             bits, and the data itself.
 *    Returns: The resultant bit vector after packing the data.
 *   Contract: Same as the above function.
 */
uint64_t bitpack_sets(uint64_t vec, unsigned lsb, unsigned width, int64_t val);








