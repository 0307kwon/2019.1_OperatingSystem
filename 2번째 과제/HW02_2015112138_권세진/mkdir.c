#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "command.h"

int mkdir(char* factor){
	int stat,pid;
	char* argv[4];
	argv[0] = strtok(factor," ");
	argv[1] = strtok(NULL," ");
	argv[2] = strtok(NULL," ");
	argv[3] = strtok(NULL," ");

	pid = fork();

        switch(pid) {
                case -1: // error
                        printf("fork error\n");
                        exit(1);
                case 0: // child
                        execv("/bin/mkdir",argv);
                        printf("exec error \n");
                        exit(1);
                default:// parents
                        wait(&stat);
        }
        return 0;
}
