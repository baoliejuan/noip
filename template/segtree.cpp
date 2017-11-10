#include <stdio.h>
void put(int x,int p){
	for (;p;p<N;p+=p&-p)
		tree[p]+=x;
}
int get(int p,int ans=0){
	for (;p;p-=p&-p)
		ans+=tree[p];
	return ans;
}
