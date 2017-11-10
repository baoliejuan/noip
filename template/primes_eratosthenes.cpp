#include <stdio.h>
#define N 10000000
int n,m,primes[N];
bool notprime[N]={1,1,0};
int main(){
	for (int i=2;i<N;i++)
		if (!notprime[i]){
			//printf("%d\n",i);
			for (int j=i+i;j<N;j+=i)
				notprime[j]=true;
		}
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%d",&n);
		printf("%s\n",notprime[n]?"No":"Yes");
	}
}
