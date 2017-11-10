#include <stdio.h>
#define N 200001
int n,m,opt,u,v,father[N];
int find(int x){
	return x==father[x]?x:father[x]=find(father[x]);
}
void merge(int x,int y){
	if (find(x)==find(y)) return;
	father[find(x)]=find(y);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		father[i]=i;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&opt,&u,&v);
		if (opt==1) merge(u,v);
		if (opt==2) printf("%c\n",find(u)==find(v)?'Y':'N');
	}
}
