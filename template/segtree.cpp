#include <stdio.h>
#include <iostream>
#define N 500001
int tree[N];
int read(int ret=0,char c='\0'){
	for (c=getchar();!isdigit(c);c=getchar());
	for (;isdigit(c);c=getchar())
		ret=ret*10+int(c)-int('0');
	return ret;
}
void put(int p,int x){
	for (;p<N;p+=p&-p)
		tree[p]+=x;
}
int get(int p,int ret=0){
	for (;p;p-=p&-p)
		ret+=tree[p];
	return ret;
}
