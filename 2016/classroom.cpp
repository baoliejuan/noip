#include <cstdio>
#define min(x,y) ((x)<(y)?(x):(y))
const int N=2002,V=301;
int a,b,w,n,m,v,e,room[2][N]={0};
int map[V][V]={0},dist[V][V]={0};
float chs[N],hope[N][2][N],ans=1e16;
//float min(float x,float y){
//return x<y?x:y;
//}
int main(){
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for (int i=0;i<2;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&room[i][j]);
	for (int i=1;i<=n;i++)
		scanf("%f",&chs[i]);
	for (int i=1;i<=v;i++)
		for (int j=1;j<=v;j++)
			if (i!=j)
				map[i][j]=0x3f3f3f;
	for (int i=0;i<e;i++){
		scanf("%d%d%d",&a,&b,&w);
		map[a][b]=map[b][a]=w;
	}
	for (int i=1;i<=v;i++)
		for (int j=i+1;j<=v;j++)
			for (int k=1;k<=v;k++)
				if (k!=i&&k!=j&&map[i][k]+map[k][j]<map[i][j])
					map[j][i]=map[i][j]=map[i][k]+map[k][j];
	//for (int i=1;i<=n;i++)
	//map[0][i]=map[i][0]=map[n+1][i]=map[i][n+1]=0;
#ifdef DEBUG
	for (int i=1;i<=v;i++)
		for (int j=i+1;j<=v;j++)
			printf("m[%d][%d]=%d\n",i,j,map[i][j]);
#endif
	//float x,y;
	for (int i=1;i<=m;i++)
		hope[0][i][1]=10e8;
	for (int i=2;i<=n;i++){
		for (int j=0;j<(i-1<m?i-1:m);j++){
			//for (int k=0;k<2;k++){
			//float ret=1e8;
			//for (int l=0;l<2;l++){
			//ret=min(ret,
			//x=	hope[l][i-2]+map[room[l][i-2]][room[0][i-1]]+
			//map[room[0][i-1]][room[k][i]];
			//y=	hope[l][i-2]+map[room[l][i-2]][room[0][i-1]]+
			//map[room[0][i-1]][room[k][i]];

			//x=hope[0][i-1]+map[room[0][i-1]][room[k][i]];
			//y=chs[i-1]*(

			//y=hope[1][i-1]+map[room[1][i-1]][room[k][i]];
			//hope[k][i]=min(x,chs[i-1]*y+(1-chs[i-1])*x);
			//hope[k][i]=min(x,y);
			//#ifdef DEBUG
			//printf("%f %f %f\n",x,y,chs[n-1]*y+(1-chs[n-1]));
			//#endif
			//}
			//}

			hope[j][0][i]=min(
				hope[j][0][i-1]+map[room[0][i-1]][room[0][i]],
				hope[j-1][1][i-1]+map[room[1][i-1]][room[0][i]]*chs[i-1]+
					map[room[0][i-1]][room[0][i]]*(1-chs[i-1])
				);
			hope[j][1][i]=min(
				hope[j][0][i-1]+
					map[room[0][i-1]][room[1][i]]*chs[i]+
					map[room[0][i-1]][room[0][i]]*(1-chs[i]),
				hope[j-1][1][i-1]+
					map[room[1][i-1]][room[1][i]]*chs[i-1]*chs[i]+
					map[room[1][i-1]][room[0][i]]*chs[i-1]*(1-chs[i])+
					map[room[0][i-1]][room[1][i]]*(1-chs[i-1])*chs[i]+
					map[room[0][i-1]][room[0][i]]*(1-chs[i-1])*(1-chs[i])
				);
		}
	}
#ifdef DEBUG
	//for (int j=1;j<=n;j++)
	//printf("%f ",chs[j]);
	//printf("\n");
	for (int j=1;j<=n;j++)
		for (int i=0;i<2;i++)
			for (int k=0;k<=m;k++)
			printf("h[%d][%d][%d]=%f\n",k,i,j,hope[k][i][j]);
#endif
	for (int i=0;i<2;i++)
		for (int j=0;j<=m;j++)
			if (hope[j][i][n]<ans)
				ans=hope[j][i][n];
	printf("%.2f\n",ans+0.005);
}
