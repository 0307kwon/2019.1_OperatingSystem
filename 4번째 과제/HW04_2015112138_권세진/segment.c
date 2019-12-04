#include <stdio.h>
#include <pthread.h>


#define   ONE_MEG              1048576

long* firstHeap;

void mkHeap(int* heapMax) { // MB
	int heapSize = 0;
	while (*heapMax >= heapSize ||  *heapMax == -1) {
			firstHeap = (long*)malloc(ONE_MEG);
			if (firstHeap == 0) {
				printf("The program is ending because we could allocate no more memory.\n");
				printf("final Heap size : %d\n",heapSize);
				exit(0);
			}
			heapSize++;
			if(heapSize%10000 == 0){
				printf("Heap size : %d MB\n",heapSize);
			}

	}
	pthread_exit(0);
}


unsigned long firstStackLocation;
int recursiveDepth;
#define STACK_ALLOC ONE_MEG
void mkStack(int stackMax) {//MB
	recursiveDepth++;
	char temp[STACK_ALLOC];
	unsigned long size = firstStackLocation-(unsigned long)&(temp[STACK_ALLOC]);
	if(recursiveDepth%10000 == 0){
	printf("%d stack size : %d MB\n",recursiveDepth,size/ONE_MEG);
	}
	if(size/ONE_MEG < stackMax || stackMax == -1){
		mkStack(stackMax);
	}else{
		while(1){
		}
	}
}

void main() {
	int stack;
	recursiveDepth = 0;
	int stackMax;
	int heapMax;

	pthread_t id;

	 printf("please put heap Maxsize in :");
        scanf("%d",&heapMax);
	printf("please put stack Maxsize in :");
	scanf("%d",&stackMax);


	firstStackLocation = &stack;
	pthread_create(&id,NULL,mkHeap,&heapMax);
	mkStack(stackMax);

	pthread_join(id,NULL);

}
