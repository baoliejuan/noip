#include <stdio.h>
#include <string.h>
#include <vector>
#define M 500000
#define N 10001
#define INF 0x7fffffff
int n,m,s,v,u,l;
struct Edge{
	int d,l;
};
int q[N],head=0,tail=1;
long long dist[N];
bool inqueue[N];
std::vector <Edge> e[M<<1];
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&s);
	//memset(dist,INF,sizeof(dist));
	for (int i=0;i<=n;i++)
		dist[i]=INF;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&l);
		e[u].push_back({v,l});
		//e[v].push_back({u,l});
	}
	dist[s]=0,q[head]=s,inqueue[s]=true;
	for (;head!=tail;inqueue[q[head]]=false,head=(head+1)%N)
		for (unsigned int i=0,cur=q[head];i<e[cur].size();i++)
			if (dist[e[cur][i].d]>e[cur][i].l+dist[cur]){
				dist[e[cur][i].d]=e[cur][i].l+dist[cur];
				if (!inqueue[e[cur][i].d]){
					q[tail]=e[cur][i].d;
					inqueue[e[cur][i].d]=true;
					tail=(tail+1)%N;
				}
			}
	for (int i=1;i<=n;i++)
		printf("%lld ",dist[i]);
}
