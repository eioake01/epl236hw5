#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void recursiveLIS(int *A,int *Opt,int n){
	int i;
	if(n==0){
		Opt[0]=0;
	}
	for(i=0;i<n;i++){
		if(Opt[i]==0)
		recursiveLIS(A,Opt,i);
		if(A[n]>A[i] && Opt[n]<Opt[i]+1){
			Opt[n] = Opt[i]+1;
		}
	}
}

int main(int argc,char* argv[]){


int n;

scanf("%d\n",&n);

int *A,*Opt;
A = (int*) malloc((n+1)*sizeof(int));
Opt = (int*) malloc((n+1)*sizeof(int));

int i = 0,j=0;
for(i=1;i<n+1;i++){
	scanf("%d",&A[i]);
}

A[0] = INT_MIN;

recursiveLIS(A,Opt,n);

int max = -1;
for(i=0;i<n+1;i++){
	if(Opt[i]>max)
		max = Opt[i];
}
printf("%d\n",max);

free(A);
free(Opt);
}