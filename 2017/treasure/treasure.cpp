#include <stdio.h>
#include <string.h>
#define N 13
#define INF 0x3f3f3f
int n,m,u,v,l,root,min=INF,ans;
int map[N][N],room[N],q[N<<2],head,tail;
bool inq[N];
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&m);
	//memset(map,INF,sizeof(map));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			map[i][j]=INF;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&l);
		if (map[u][v]>l)
			map[u][v]=l;
		if (map[v][u]>l)
			map[v][u]=l;
	}
	for (int i=1;i<=n;i++){
		ans=0;
		memset(room,INF,sizeof(room));
		memset(inq,0,sizeof(inq));
		room[i]=0,q[0]=i,inq[i]=true;
		for (head=tail=0;head<=tail;inq[head]=false,head++)
			for (int j=1;j<=n;j++)
				if (map[q[head]][j]!=INF){
					//printf("%d %d %d",q[head],j,map[q[head]][j]);
					if (room[j]>room[q[head]]+1){
						room[j]=room[q[head]]+1;
						if (!inq[j]){
							q[++tail]=j;
							inq[j]=true;
						}
					}
				}
		for (int j=1;j<=n;j++)
			if (j!=i)
				ans+=room[j];
		if (min>ans)
			min=ans;
		//printf("%d %d\n",i,ans);
		//for (int i=1;i<=n;i++)
			//printf("%d ",room[i]);
		//printf("\n");
	}
	printf("%d\n",min*l);
	return 0;
}
