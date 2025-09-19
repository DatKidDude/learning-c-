CFLAGS = -g -Wall

inventory.exe: inventory.o readline.o quicksort.o
	gcc $(CFLAGS) -o inventory.exe inventory.o readline.o quicksort.o

inventory.o: inventory.c parts.h readline.h quicksort.h 
	gcc $(CFLAGS) -c inventory.c

readline.o: readline.c readline.h
	gcc $(CFLAGS) -c readline.c

quicksort.o: quicksort.c quicksort.h parts.h
	gcc $(CFLAGS) -c quicksort.c

clean:
	del *.o