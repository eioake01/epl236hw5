#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define BILLION 1000000000L

void recursivemLIS(int *A,int *Opt,int n){
	int i;
	if(n==0){
		Opt[0]=0;
	}
	for(i=0;i<n;i++){
		if(Opt[i]==0)
		recursivemLIS(A,Opt,i);
		if(A[n]>A[i] && Opt[n]<Opt[i]+1){
			Opt[n] = Opt[i]+1;
		}
	}
}

int main(int argc,char* argv[]){

struct timespec requestStart, requestEnd;


FILE *fp = NULL;
FILE *fo = NULL;
fp = fopen("n50000.txt","r");
fo = fopen("recursiveMemoTime50000.txt","w");

int length = 50000;
int n = 0;

int *A,*Opt;
A = (int*) malloc((length+1)*sizeof(int));
Opt = (int*) malloc((length+1)*sizeof(int));

for(n=0;n<20;n++){

int i = 0,j=0;

for(i=1;i<length+1;i++){
	fscanf(fp,"%d",&A[i]);
	Opt[i]=0;
}

clock_gettime(CLOCK_REALTIME, &requestStart);

A[0] = INT_MIN;

recursivemLIS(A,Opt,length);

int max = 0;
for(i=0;i<length+1;i++){
	if(Opt[i]>max)
		max = Opt[i];
}

clock_gettime(CLOCK_REALTIME, &requestEnd);

time_t diff = BILLION * (requestEnd.tv_sec - requestStart.tv_sec) + requestEnd.tv_nsec - requestStart.tv_nsec;
fprintf(fo,"%llu\n",diff);

}

free(A);
free(Opt);
}
