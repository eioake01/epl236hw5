#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define BILLION 1000000000L


int main(int argc,char* argv[]){

struct timespec requestStart, requestEnd;

FILE *fp = NULL;
FILE *fo = NULL;
fp = fopen("n50000.txt","r");
fo = fopen("dpTime50000.txt","w");

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
Opt[0] = 0;

int max = 0;

for(i=0;i<length+1;i++){
	for(j=0;j<i;j++){
		if(A[i]>A[j] && Opt[i]<Opt[j]+1){
			Opt[i] = Opt[j]+1;
			if(Opt[i]>max)
				max = Opt[i];
		}
	}
}

clock_gettime(CLOCK_REALTIME, &requestEnd);

time_t diff = BILLION * (requestEnd.tv_sec - requestStart.tv_sec) + requestEnd.tv_nsec - requestStart.tv_nsec;
fprintf(fo,"%llu\n",diff);
}

fclose(fp);
fclose(fo);
free(A);
free(Opt);
}
