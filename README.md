# Representation Tools
## January 4, 2017

### Introduction
This is a basic set of C programs for studying the representation of data at the
machine level. The tools are platform-independent, and should compile and run on
any machine using a standard, ANSI C-compliant compiler.

### Included Tools
#### Print Bytes
This is an incredibly small and portable library for printing out hexadecimal
byte representations of all the basic C types. The general purpose function
show_bytes can be used for any data structure, in fact, and it is simple to
extend this library to support your needs. For implementation and use details,
see the header file. A small test script is included.

#### Bitpack
This is a platform-independent library for performing bitpacking operations.
This is intended to be used in applications that use compression techniques
and other bit-level manipulations without having to worry about writing hard to
read or contrived shifting code. The implementation file contains three small
shifting functions to perform the three most commonly needed shifts:
         - Left shift
         - Logical Right Shift
         - Arithmetic Right Shift
These are not included as functions available through the header, but can easily
be copied where needed. One important detail of note is the defined behavior for
shifts equal to the word size (64 bits): These, in the defined functions
described above, will return 0 (rather than performing modular arithmetic before
executing the shift). For additional details about implementation and use, see
the header file. A small test script is included.

### Support
For help, contact me at christopher.phifer@tufts.edu. 