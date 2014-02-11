CC=gcc
CFLAGS=-c -w -I -Wall
LDFLAGS=
SOURCES=main.c mergesort.c print.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ms

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *exe *~

