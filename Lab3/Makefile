CC=gcc
CFLAGS=-c -I. -Wall
LDFLAGS=
SOURCES=create.c merge.c print.c writefile.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exec

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *exe *~ exec *.gch

