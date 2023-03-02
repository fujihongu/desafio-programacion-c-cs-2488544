CC = gcc
CFLAGS = -Wall -Wextra -Werror
LD = gcc
RM = rm -f
CLR = clear
PRMMSG = echo "Program removed successfully:"
PIMSG = echo "Prgram installed successfully:"
LS = ls -la
PROGRAM_NAME = challengeBin
SRCS = challenge.c */*.c
OBJECTS = *.o

default: .c.o make clean
	$(CLR); $(LS)

.c.o:
	$(CC) $(CFLAGS) -c $(SRCS)

make:
	$(LD) $(OBJECTS) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(PROGRAM_NAME); $(CLR); $(LS)