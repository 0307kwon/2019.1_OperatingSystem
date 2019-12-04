#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#define MILLION 1000000

int A[2][4] = {{1,2,3,4},{5,6,7,8}};
int B[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
int ans[2][3];

void thread1(){
	int k;
	int sum = 0;
	int i = 0;
	int j = 0;
	for(k=0;k<4;k++){
		sum += A[i][k]*B[k][j];
	}
	ans[i][j] = sum;
	return;
}
void thread2(){
        int k;
        int sum = 0;
        int i = 0;
        int j = 1;
        for(k=0;k<4;k++){
                sum += A[i][k]*B[k][j];
        }
        ans[i][j] = sum;
        return;
}
void thread3(){
        int k;
        int sum = 0;
        int i = 0;
        int j = 2;
        for(k=0;k<4;k++){
                sum += A[i][k]*B[k][j];
        }
        ans[i][j] = sum;
        return;
}
void thread4(){
        int k;
        int sum = 0;
        int i = 1;
        int j = 0;
        for(k=0;k<4;k++){
                sum += A[i][k]*B[k][j];
        }
        ans[i][j] = sum;
        return;
}
void thread5(){
        int k;
        int sum = 0;
        int i = 1;
        int j = 1;
        for(k=0;k<4;k++){
                sum += A[i][k]*B[k][j];
        }
        ans[i][j] = sum;
        return;
}
void thread6(){
        int k;
        int sum = 0;
        int i = 1;
        int j = 2;
        for(k=0;k<4;k++){
                sum += A[i][k]*B[k][j];
        }
        ans[i][j] = sum;
        return;
}


void multiply(){
	pthread_t id[6];
	void* ft[6];
	ft[0] = thread1;
	ft[1] = thread2;
	ft[2] = thread3;
	ft[3] = thread4;
	ft[4] = thread5;
	ft[5] = thread6;	
	int i,j,k;
	k = 0;
	for(i = 0; i<2; i++){
		for(j = 0; j<3; j++){
			pthread_create(&id[k],NULL,ft[k],NULL);
			k++;
		}
	}
	for(i=0; i<k; i++){
		pthread_join(id[i],NULL);
	}
	for(i=0; i<2; i++){
		for(j = 0; j<3; j++){
			printf("%d\t",ans[i][j]);
		}
		printf("\n");
	}
}; 
void main(){
        struct timeval tpstart, tpend;
        long timediff;
        int i;
        gettimeofday(&tpstart, NULL);
        multiply();
        gettimeofday(&tpend, NULL);
        timediff = MILLION*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
        printf("It took %ld msec \n", timediff);
}

