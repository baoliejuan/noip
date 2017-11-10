#include <stdio.h>
#include <vector>
#define N 500001
int n,m,s,u,v,q[N],head=0,tail=0,f[20][N],depth[N],ln[N];
std::vector <int> e[N];
int lca(int u,int v){
	if (depth[u]<depth[v])
		std::swap(u,v);
	for (int i=depth[u]-depth[v];i;i-=i&-i)
		u=f[ln[i&-i]][u];
	for (int i=0,t=1;u!=v;i+=t){
		if (i<0) break;
		if (f[i][u]!=f[i][v])
			u=f[i][u],v=f[i][v],t=1;
		else t=-1;
	}
	if (u==v) return u;
	if (f[0][u]==f[0][v]) 
		return f[0][v];
	return u==v?u:f[0][v];
}
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	q[head]=s,f[0][s]=s,depth[s]=0;
	for (;head<=tail;head++)
		for (unsigned int i=0;i<e[q[head]].size();i++)
			if (e[q[head]][i]!=f[0][q[head]]){
				f[0][e[q[head]][i]]=q[head];
				depth[e[q[head]][i]]=depth[q[head]]+1;
				q[++tail]=e[q[head]][i];
			}
	for (int i=1;(1<<i)<n;i++)
		for (int j=1;j<=n;j++)
			if (depth[j]>=(1<<i))
				f[i][j]=f[i-1][f[i-1][j]];
	for (int i=0;(1<<i)<n;i++)
		ln[1<<i]=i;
	for (int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
}
