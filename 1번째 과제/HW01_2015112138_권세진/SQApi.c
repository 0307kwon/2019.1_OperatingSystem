#include "SQ.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


S_Head* MakeStack(){
        S_Head* stack = (S_Head*)malloc(sizeof(S_Head));
        if(stack == NULL){
                return NULL;
        }
        stack->dataNumber = 0;
        stack->head = NULL;
        return stack;
}

int PushStack(S_Head* stack,void* data){
        if(stack != NULL){//not strange input value
		char* newData = (char*)malloc(sizeof(char)*10);
		strcpy(newData,data);
		Stack* temp = (Stack*)malloc(sizeof(Stack));
		if(temp  == NULL){
                   return 0; // failed
                }
                temp->data = newData;
                temp->next = NULL;
                if(stack->dataNumber == 0){
                        stack->head = temp;
                }else{
                        temp->next = stack->head;
                        stack->head = temp;
                }
                stack->dataNumber++;
                return 1; // success
        }
        return 0; //failed
}

void* PopStack(S_Head* stack){
        if(stack->dataNumber != 0){
        Stack* temp = stack->head;// temporary save in temp
        //
        stack->head = stack->head->next;
        stack->dataNumber--;
        //
        void* pop = temp->data;
        free(temp);
        return pop;
        }else{
                printf("no more data in stack");
                return NULL;
        }
}

Q_Head* MakeQueue(){
	Q_Head* head = (Q_Head*)malloc(sizeof(Q_Head));
	if(head == NULL){
		return NULL;
	}
	head->dataNumber = 0;
	head->head = NULL;
	head->rear = NULL;
	return head;
}

int Enqueue(Q_Head* head, void* data){
	 //Queue initialize
         Queue* queue = (Queue*)malloc(sizeof(Queue));
	 if(queue == NULL){
		 return 0;//failed
	 }
	 char* newData = (char*)malloc(sizeof(char)*10);
	 strcpy(newData,data);
	 queue->data = newData;
         queue->next = NULL;
	if(head->dataNumber == 0){
		//Enqueue
		head->head = queue;
		head->rear = queue;
	}else{// >=1	
		head->rear->next = queue;
		head->rear = queue;
	}	
	head->dataNumber++;
	return 1;
}	

void* Dequeue(Q_Head* head){
	if(head->dataNumber == 0){
		printf("no data in Queue");
		return NULL;
	}
	void* temp = head->head->data;
       	if(head->dataNumber==1){
		free(head->head);
		head->head = NULL;
		head->rear = NULL;
		head->dataNumber--;
	}else{
	Queue* queue = head->head;
	head->head = head->head->next;
	free(queue);
	head->dataNumber--;
	}
	return temp; // success
}


