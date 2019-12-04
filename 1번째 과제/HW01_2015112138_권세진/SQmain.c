#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SQ.h"

void S_InputFunction(S_Head* stack){
	char input[20];
	char* temp;
	printf("please input\n");
	fgets(input,sizeof(input),stdin);
	temp = strtok(input," \n");
	while(temp != NULL){
		PushStack(stack,temp);
		temp = strtok(NULL," \n");
	}
}

void S_OutputFunction(S_Head* stack){
	while(stack->dataNumber !=0){
                void* temp = PopStack(stack);
                printf((char*)temp);
                free(temp);
                printf("----- data\n");
        }
}

void Q_InputFunction(Q_Head* queue){
       	char input[20];
        char* temp;
        printf("please input\n");
        fgets(input,sizeof(input),stdin);
        temp = strtok(input," \n");
        while(temp != NULL){
                Enqueue(queue,temp);
                temp = strtok(NULL," \n");
        }
}

void Q_OutputFunction(Q_Head* queue){
	while(queue->dataNumber !=0){
		void* temp = Dequeue(queue);
		printf((char*)temp);
		free(temp);
		printf("----- data\n");
	}
}


int main(){
	printf("1 : use a stack\n2 : use a queue\nany number except 1,2 : exit \n");
	char ch = getchar();getchar();
	if(ch == '1'){ // stack
		S_Head* stack = MakeStack();
		S_InputFunction(stack);
		printf("the number of stack : %d \n",stack->dataNumber);
		S_OutputFunction(stack);
	}else if(ch == '2'){ // queue
		Q_Head* queue = MakeQueue();
		Q_InputFunction(queue);
		printf("the number of queue : %d \n",queue->dataNumber);
		Q_OutputFunction(queue);
	}
}
