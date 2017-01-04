/*
 * print_bytes.h
 * Chris Phifer
 *
 * This simple library can be included in any program in which you wish to debug
 * or study by displaying the byte-level representation of data of all basic C
 * types. There are particular functions for every type, and a general-purpose
 * function you can use to study your own data structures.
 *
 * These functions are adapted from Bryant and O'Hallaron "Computer Systems: A
 * Programmer's Perspective"
 */

typedef unsigned char *byte_ptr;

/*
 *    Purpose: This function shows the byte-level representation of the data at
 *             location addr.
 * Parameters: A pointer to an unsigned character (the address), and a size.
 *    Returns: Nothing (Prints to standard output)
 *   Contract: All errors are unchecked. You're responsible for giving this
 *             function (and all described below) reasonable arguments.
 */
void show_bytes(byte_ptr addr, size_t size);

/*
 *    Purpose: This function shows the byte-level representation of a character.
 * Parameters: A single character.
 *    Returns: Nothing (Prints to standard output)
 */
void show_char(char c);

/*
 *    Purpose: This function shows the byte-level representation of a short.
 * Parameters: A single short.
 *    Returns: Nothing (Prints to standard output)
 */
void show_short(short s);

/*
 *    Purpose: This function shows the byte-level representation of an int.
 * Parameters: A single int.
 *    Returns: Nothing (Prints to standard output)
 */
void show_int(int i);

/*
 *    Purpose: This function shows the byte-level representation of a long.
 * Parameters: A single long.
 *    Returns: Nothing (Prints to standard output)
 */
void show_long(long l);

/*
 *    Purpose: This function shows the byte-level representation of a float.
 * Parameters: A single float.
 *    Returns: Nothing (Prints to standard output)
 */
void show_float(float f);

/*
 *    Purpose: This function shows the byte-level representation of a double.
 * Parameters: A single double.
 *    Returns: Nothing (Prints to standard output)
 */
void show_double(double d);

/*
 *    Purpose: This function shows the byte-level representation of a pointer.
 * Parameters: A single pointer.
 *    Returns: Nothing (Prints to standard output)
 */
void show_pointer(void *p);




