#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "command.h"
#define SIZE 20

int main(){
	char input[SIZE];
	char token[SIZE];

	while(true){
		printf("please input\n");
		gets(input);
		strcpy(token,input);
		strtok(token," ");
		if(!strcmp("ls",token)){
			ls(input);
		}
		if(!strcmp("mkdir",token)){
			mkdir(input);
		}
		if(!strcmp("exit",token)){
			break;
		}
	}

	return 0;
}
