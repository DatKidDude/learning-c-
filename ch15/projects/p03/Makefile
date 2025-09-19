CC = gcc

qsort.exe: quicksort.o qsort.o
	$(CC) -o qsort.exe qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	$(CC) -c qsort.c

quicksort.o: quicksort.c quicksort.h
	$(CC) -c quicksort.c

clean:
	del *.o

