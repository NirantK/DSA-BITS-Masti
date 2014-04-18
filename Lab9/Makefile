CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=
SOURCES=AVLTreeOps.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exec

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *exe *~ exec *.gch

