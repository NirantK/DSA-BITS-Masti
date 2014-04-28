CC=gcc
CFLAGS=-c -g
LDFLAGS=
SOURCES=treeOps.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exec

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -vf *o *exe *~ exec *.gch

