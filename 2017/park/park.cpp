#include <stdio.h>
#include <string.h>
#include <vector>
//#include <utility>
#define N 1001
int n,m,k,p,T,dist[N],q[4*N],head,tail;
int way[N][100*N];
//std::map <int,int> way[N];
bool inq[N];
struct Edge{
	int t,l;
	Edge(int x,int y){
		t=x,l=y;
	}
};
std::vector <Edge> e[N],rev[N];
int dfs(int p,int l){
	if (l<0) return 0;
	if (way[p][l]) return way[p][l];
	int ret=0;
	if (p==1&&l>=0)
		ret++;
	for (unsigned int i=0;i<rev[p].size();i++)
		ret=(ret+dfs(rev[p][i].t,l-rev[p][i].l))%p;
	//printf("%d %d %d\n",p,l,ret);
	return way[p][l]=ret;
}
void work(){
	int u,v,l;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for (int i=0;i<=n;i++)
		e[i].clear();
	memset(inq,0,sizeof(inq));
	memset(way,0,sizeof(way));
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&l);
		e[u].push_back(Edge(v,l));
		rev[v].push_back(Edge(u,l));
	}
	for (int i=2;i<=n;i++)
		dist[i]=0x3f3f3f;
	//for (int i=0;i<n;i++)
		//printf("%d ",dist[i]);
	dist[1]=0;q[0]=1;
	for (head=tail=0;head<=tail;head++){
		int cur=q[head];
		for (unsigned int i=0;i<e[cur].size();i++){
			if (dist[e[cur][i].t]>dist[cur]+e[cur][i].l){
				dist[e[cur][i].t]=dist[cur]+e[cur][i].l;
				if (!inq[e[cur][i].t]){
					q[++tail]=e[cur][i].t;
					inq[e[cur][i].t]=true;
				}
			}
		}
		inq[cur]=false;
	}
	int d=dist[n];
	//printf("%d\n",d);
	printf("%d\n",dfs(n,d+k));
}
int main(){
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
	scanf("%d",&T);
	for (;T;T--)
		work();
	return 0;
}
