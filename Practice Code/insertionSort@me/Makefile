CC=gcc
CFLAGS=-c -w -I -Wall
LDFLAGS=
SOURCES=main.c insertSort.c print.c read.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ins

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *exe *~

