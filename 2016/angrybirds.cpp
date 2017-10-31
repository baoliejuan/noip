#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 18
int T,n,m;
int ln[1<<N];
int e[N][N][N];
int min[1<<N];
struct Pig{
	float x,y;
}p[N];
bool comp(Pig x,Pig y){
	return x.x<y.x||(x.x==y.x&&x.y<y.y);
}
bool co(int p0,int p1,int p2){
	float x0=p[p0].x,x1=p[p1].x,x2=p[p2].x;
	float y0=p[p0].y,y1=p[p1].y,y2=p[p2].y;
	float k0=y0/x0,k1=y1/x1,k2=y2/x2;
	return (x0-x1)/(k0-k1)==(x1-x2)/(k1-k2);
}
void work(){
	memset(e,0,sizeof(e));
	//memset(min,N,sizeof(min));
	scanf("%d%d",&n,&m);
	for (int i=0;i<(1<<n);i++)
		min[i]=N;
	min[0]=0;
	for (int i=0;i<n;i++)
		scanf("%f%f",&p[i].x,&p[i].y);
	std::sort(p,p+n,comp);
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (p[i].y/p[i].x<p[j].y/p[j].x)
				e[i][j][0]=-1;
			else{
				e[i][j][++e[i][j][0]]=j;
				for (int k=j+1;k<n;k++)
					if (co(i,j,k))
						e[i][j][++e[i][j][0]]=k;
			}
	for (int i=0;i<(1<<n);i++){
		if (min[i]+1<min[i|((~i)&-(~i))])
			min[i|((~i)&-(~i))]=min[i]+1;
		for (int c=ln[(~i)&-(~i)],j=c+1;j<n;j++){
			//if (e[c][j][0]>=0){
				int b=i|(1<<c);
				for (int l=1;l<=e[c][j][0];l++)
					b|=(1<<e[c][j][l]);
				//printf("%d\n",b);
				if (min[i]+1<min[b])
					min[b]=min[i]+1;
			}
		}
	printf("%d\n",min[(1<<n)-1]);
}
int main(){
	//freopen("angrybirds.in","r",stdin);
	for (int i=0;i<N;i++)
		ln[1<<i]=i;
	scanf("%d",&T);
	while (T--)
		work();
}
