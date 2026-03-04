all: collection

collection: main.o collection.o
	gcc -o collection main.o collection.o

main.o: main.c collection.h
	gcc -c main.c

collection.o: collection.c collection.h
	gcc -c collection.c

clean:
	rm -f *.o collection