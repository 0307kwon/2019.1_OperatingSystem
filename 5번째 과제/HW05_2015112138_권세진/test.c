#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_SIZE 20

int main(void){
	int fd;

	char* in = (char*)malloc(sizeof(char)*MAX_SIZE);
	char* out = (char*)malloc(sizeof(char)*MAX_SIZE);

	if( (fd=open("/dev/mydevicefile",O_RDWR))<0){
		perror("open error");
		return -1;
	}
	printf("if you type \"end\", this program will be closed\n");
	while(printf("please input data :")){
		gets(out);
		if(!strcmp(out,"end")){
			break;
		}
		write(fd,out,MAX_SIZE);

		read(fd,in,MAX_SIZE);
		printf("%s\n",in);
	}

	free(in);
	free(out);

	close(fd);
	return 0;
}
