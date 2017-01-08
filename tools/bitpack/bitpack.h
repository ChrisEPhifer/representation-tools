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

/* 
 * Edit these three lines if you wish to pack with smaller data types!
 * Make sure to use stdint fixed-width types, however, or else you risk making
 * the code machine dependent.
 */
#define WORD_SIZE 64

typedef uint64_t uword;
typedef int64_t  sword;

/*
 *    Purpose: Check if a value n fits into the specified number of bits.
 * Parameters: A 64 bit unsigned value n, and an unsigned width (in bits).
 *    Returns: A boolean (true if n fits into width, false otherwise)
 *   Contract: It is a checked runtime error to pass a width greater than the
 *             maximum word size (64). It is also checked that width be
 *             positive.
 */
bool bitpack_fitsu(uword n, unsigned width);

/*
 *    Purpose: Check if a value n fits into the specified number of bits.
 * Parameters: A 64 bit signed value n, and an unsigned width (in bits).
 *    Returns: A boolean (true if n fits into width, false otherwise)
 *   Contract: It is a checked runtime error to pass a width greater than the
 *             maximum word size (64).
 */
bool bitpack_fitss(sword n, unsigned width);

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
uword bitpack_getu(uword vec, unsigned lsb, unsigned width);

/*
 *    Purpose: Unpack a value of given width and offset from a bit vector.
 * Parameters: A bit vector (packed data), the least significant bit position,
 *             and the number of bits (the width).
 *    Returns: The data contained at the location specified by the parameters.
 *   Contract: Same as the above function.
 */
sword bitpack_gets(uword vec, unsigned lsb, unsigned width);

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
uword bitpack_setu(uword vec, unsigned lsb, unsigned width, uword val);

/*
 *    Purpose: Pack an unsigned value into the bit vector, and return the new
 *             bit vector.
 * Parameters: A bit vector, the least significant bit position, the number of
 *             bits, and the data itself.
 *    Returns: The resultant bit vector after packing the data.
 *   Contract: Same as the above function.
 */
uword bitpack_sets(uword vec, unsigned lsb, unsigned width, sword val);
