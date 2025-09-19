CC = gcc

remind.exe: remind.o readline.o
	$(CC) -o remind.exe remind.o readline.o

remind.o: remind.c readline.h
	$(CC) -c remind.c

readline.o: readline.c readline.h
	$(CC) -c $< 

clean:
	del *.o