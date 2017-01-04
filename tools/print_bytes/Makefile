CC = gcc
# Add any additional linker variables up here and edit things appropriately
CFLAGS = -g -std=gnu99 -Wall -Wextra -Werror -pedantic -O2

# Add the names of your executable files here:
# EXECS =

# Once you have executables, uncomment this.
# all: $(EXECS)

# Make sure to add a rule for any executable you want to build below here!

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *~
