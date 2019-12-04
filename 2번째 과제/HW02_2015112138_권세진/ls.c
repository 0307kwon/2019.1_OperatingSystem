#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "command.h"

int ls(char* factor){
	int pid, stat;
	char* argv[3];	
	argv[0] = strtok(factor," ");
	argv[1] = strtok(NULL," ");
	argv[2] = 0;
	pid = fork();

	switch(pid) {
		case -1: // error
			printf("fork error\n");
			exit(1);
		case 0: //child
			execv("/bin/ls",argv);
			printf("exec error \n");
			exit(1);
		default:// parents
			wait(&stat);
	}
	return 0;
}

