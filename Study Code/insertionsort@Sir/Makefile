
.c.o:
	gcc -c -o $@ $<

#orderedND: driver.c *.h OrderedSearch.o orderND.o 
#	gcc -o OrderedSearch driver.c OrderedSearch.o orderND.o
#intorderedND: driver.c *.h OrderedSearch.o intorderND.o 
#	gcc -o OrderedSearch driver.c OrderedSearch.o orderND.o
#orderedNI: driver.c *.h OrderedSearch.o orderNI.o 
#	gcc -o OrderedSearch driver.c OrderedSearch.o orderNI.o

insert: insort.o driver.c *.h
	gcc -o sort.exe driver.c insort.o

ordinsert: orderinsort.o compare.o driver.c *.h
	gcc -o orderinsert.exe driver.c orderinsort.o compare.o


all: insort

clean:
	rm -vf *.o *.exe OrderedSearch *~ 
