#include <stdio.h>
#define N 10000000
int n,m,primes[N],cnt=0;
bool notprime[N]={1,1};
int main(){
	for (int i=2;i<N;i++){
		if (!notprime[i])
			primes[cnt++]=i;
		for (int j=0;j<cnt&&i*primes[j]<N;j++){
			notprime[i*primes[j]]=true;
			if (i%primes[j]==0)
				break;
		}
	}
}
