CFLAGS = -g -Wall

justify.exe: justify.o word.o line.o
	gcc $(CFLAGS) -o justify.exe justify.o word.o line.o

justify.o: justify.c word.h line.h
	gcc $(CFLAGS) -c justify.c

word.o: word.c word.h
	gcc $(CFLAGS) -c word.c

line.o: line.c line.h
	gcc $(CFLAGS) -c line.c

clean:
	del *.o 
