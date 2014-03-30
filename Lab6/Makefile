CC=gcc
CFLAGS=-c -g 
LDFLAGS=
SOURCES=newDriver.c createEmptyBST.c print.c insertBST.c find.c delete.c findMaxMin.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exec

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *exe *~ exec *.gch

