 #makefile#

CC = gcc

CFLAGS = -Wall\
	 -Werror

all: mem_util unit_test

source := main.c exit.c help.c allocate_memory.c free_memory.c Allocated_memory_display.c Write_memory_words.c Display_particular_address.c Write_particular_offset.c Invert_memory_block.c Write_pattern.c Verify_pattern.c
src := unit_test.c allocate_memory.c Write_memory_words.c free_memory.c Display_particular_address.c Invert_memory_block.c Write_pattern.c Verify_pattern.c Write_particular_offset.c Allocated_memory_display.c

vpath %.h ../includes/

OBJ1 := $(source:.c=.o)
OBJ2 := $(src:.c=.o)

mem_util: $(OBJ1)
	$(CC) -o mem_util $(OBJ1) $(CFLAGS)

unit_test: $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o unit_test -lcunit

test: mem_util testfile
	./mem_util < testfile


clean:
	rm -f *.o mem_util
	rm -f *.o unit_test
	
