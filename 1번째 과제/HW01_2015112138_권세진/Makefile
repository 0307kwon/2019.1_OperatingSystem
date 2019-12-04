SQexe.exe : SQApi.o SQmain.o
	gcc -o SQexe SQApi.o SQmain.o
SQApi.o : SQApi.c
	gcc -c -o SQApi.o SQApi.c
SQmain.o : SQmain.c
	gcc -c -o SQmain.o SQmain.c
clean :
	rm *.o SQ SQexe SQApi SQexe.exe
