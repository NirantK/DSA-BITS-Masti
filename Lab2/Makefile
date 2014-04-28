CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=
SOURCES=evaluate.c method1.c method2.c method3.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=evaluate

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -vf *o *exe *~ exec *.gch ../*~

