#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#define NUM 0 // original number
#define SIZE1 10000 // the number of threads
#define SIZE2 10000 // the number which is subtracted per thread

volatile int num = NUM;
pthread_mutex_t mutex;

void* func1(void* args){
        for(int i=0; i<SIZE2; i++){
		pthread_mutex_lock(&mutex);
                num++;
		pthread_mutex_unlock(&mutex);
        }
        pthread_exit(0);
}



int main(int argc, char **argv){
        int i;
	pthread_mutex_init(&mutex,NULL);
        pthread_t id[SIZE1];
        for(i = 0; i<SIZE1; i++){
                if(pthread_create(&id[i],NULL,func1,&i)){
                        printf("error\n");
                        return 0;
                }
        }
	for(i = 0; i<SIZE1; i++){
		pthread_join(id[i],NULL);
	}
        printf("actual num : %d\n",num);
        printf("ideal num : %d\n",NUM+SIZE1*SIZE2);
	pthread_mutex_destroy(&mutex);
        return 0;
}


