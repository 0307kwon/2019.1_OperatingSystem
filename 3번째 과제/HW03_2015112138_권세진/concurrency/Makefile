cc = gcc

create.exe : create.c mutex.exe
	gcc create.c -o create.exe -pthread

mutex.exe : mutex.c
	gcc mutex.c -o mutex.exe -pthread

clean :
	rm *.exe

