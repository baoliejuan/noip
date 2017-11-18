#include <stdio.h>
#include <stdlib.h>
#define N 100000000
long long a,b;
bool aford[N];
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	//a=rand()%10000,b=rand()%10000;
	//printf("%lld %lld %lld\n",a,b,a*b);
	aford[a]=aford[b]=1;
	for (int i=0;i<N;i++)
		if (aford[i]){
			if (i+a<N)
				aford[i+a]=1;
			if (i+b<N)
				aford[i+b]=1;
		}
	for (int i=N-1;i;i--)
		if (!aford[i]){
			printf("%d\n",i);
			return 0;
		}
	return 0;
}
