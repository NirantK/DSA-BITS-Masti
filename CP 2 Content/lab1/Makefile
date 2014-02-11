CC=gcc
CFLAGS=

.c.o:
	${CC} ${CFLAGS}  -c -o $@ $<

OBJ=BaseOps.o NumberOps.o calc.o

all: calc

calc: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o calc

clean:
	rm -vf *.o *~ calc 
