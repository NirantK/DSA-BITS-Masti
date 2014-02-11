
.c.o:
	gcc -c -o $@ $<

#orderedND: driver.c *.h OrderedSearch.o orderND.o 
#	gcc -o OrderedSearch driver.c OrderedSearch.o orderND.o
#intorderedND: driver.c *.h OrderedSearch.o intorderND.o 
#	gcc -o OrderedSearch driver.c OrderedSearch.o orderND.o
#orderedNI: driver.c *.h OrderedSearch.o orderNI.o 
#	gcc -o OrderedSearch driver.c OrderedSearch.o orderNI.o

insert: insort.o driver.c *.h
	gcc -o sortdata driver.c insort.o

ordinsert: orderinsort.o compare.o driver.c *.h
	gcc -o orderinsert.exe driver.c orderinsort.o compare.o

merge1: mergesort1.o compare.o driver.c *.h
	gcc -o mergesort1.exe driver.c mergesort1.o compare.o

merge2: mergesort2.o compare.o driver.c *.h
	gcc -o mergesort2.exe driver.c mergesort2.o compare.o

merge3: mergesort3.o compare.o driver.c *.h
	gcc -o mergesort3.exe driver.c mergesort3.o compare.o -lm


all: insort

clean:
	rm -vf *.o *.exe OrderedSearch *~ 
