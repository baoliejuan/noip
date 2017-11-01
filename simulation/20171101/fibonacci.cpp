#include <stdio.h>
long long m,a,b,fi[60]={0,1};
long long low(long long x,int ans=0){
	for (;fi[ans+1]<x;ans++);
	return fi[ans];
}
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	for (int i=2;i<60;i++)
		fi[i]=fi[i-1]+fi[i-2];
	scanf("%lld",&m);
	for (;m>0;m--){
		scanf("%lld%lld",&a,&b);
		for (;a^b^0;){
			if (a<b)
				b-=low(b);
			else if (b<a)
				a-=low(a);
			//printf("%lld %lld\n",a,b);
		}
		printf("%lld\n",a);
	}
}
