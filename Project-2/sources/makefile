 #makefile#

CC = gcc

CFLAGS = -Wall\
	 -Werror

all: c_buff unittest

source := main.c c_buff.c
src := unittest.c c_buff.c

vpath %.h ../includes/

OBJ1 := $(source:.c=.o)
OBJ2 := $(src:.c=.o)

c_buff: $(OBJ1)
	$(CC) -o c_buff $(OBJ1) $(CFLAGS)

unittest: $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o unittest -lcunit

clean:
	rm -f *.o c_buff
	rm -f *.o unittest
	
