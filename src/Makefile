CC = gcc
LD = gcc
RM = rm -f
CLR = clear
PRMMSG = echo "Program removed successfully:"
PIMSG = echo "Prgram installed successfully:"
LS = ls -la
PROGRAM = challengeBin
OBJECTS = *.o

all: utils.o logic.o cmds.o main.o make clean clear ls

utils.o:
	$(CC) -c utils/info.c -o utils.o

cmds.o:
	$(CC) -c cmds/gen_log.c -o cmds.o

logic.o:
	$(CC) -c logic/logger.c -o logic.o

main.o:
	$(CC) -c challenge.c -o main.o

make:
	$(LD) $(OBJECTS) -o $(PROGRAM)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(PROGRAM); $(CLR); $(LS)

ls:
	$(LS)

clear:
	$(CLR)