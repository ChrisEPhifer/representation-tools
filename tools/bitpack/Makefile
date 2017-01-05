CC = gcc
# Add any additional linker variables up here and edit things appropriately
CFLAGS = -g -std=gnu99 -Wall -Wextra -Werror -pedantic -O2

# Add the names of your executable files here:
EXECS = test

all: $(EXECS)

test: test_bitpack.o bitpack.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECS) *.o *~
