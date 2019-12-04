fork.exe : main.o ls.o mkdir.o
	gcc -o fork.exe main.o ls.o mkdir.o
ls.o : ls.c
	gcc -o ls.o ls.c -c
main.o : main.c
	gcc -o main.o main.c -c
mkdir.o : mkdir.c
	gcc -o mkdir.o mkdir.c -c
clean :
	rm *.o fork.exe
