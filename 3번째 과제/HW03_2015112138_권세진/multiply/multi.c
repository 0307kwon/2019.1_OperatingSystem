#include <stdio.h>
#include <sys/time.h>
#define MILLION 1000000

int A[2][4] = {{1,2,3,4},{5,6,7,8}};
int B[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
int ans[2][3];

void multiply(){
	int i,j,k;
	int sum;
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			sum = 0;
			for(k=0; k<4; k++){
				sum += A[i][k]*B[k][j];
			}
			ans[i][j] = sum;
			printf("%d\t",ans[i][j]);
		}
		printf("\n");
	}
}
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
