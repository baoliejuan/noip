#include <stdio.h>
#define N 1001
int matrix[N][N],tree[300002];
int n,m,q,x,y;
int map[50001]={0},qx[500],qy[500],mapedmatrix[501][50001],lastcol[50001];
void put(int p,int a){
	for (;p<300002;p+=p&-p)
		tree[p]+=a;
}
int get(int p,int ret=0){
	for (;p>0;p-=p&-p)
		ret+=tree[p];
	return ret;
}
int main(){
	freopen("phalanx.in","r",stdin);
	freopen("phalanx.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	if (n==1&&m>1000){
		for (int i=1;i<=m;i++)
			put(i,1);
		for (int i=0;i<q;i++){
			scanf("%d%d",&x,&y);
			int out=get(y);
			printf("%d\n",out);
			if (y==m) continue;
			int a=get(y+1)-out;
			int b=get(m-1)+out-2*get(m);
			put(y,a);
			put(m,b);
		}
		return 0;
	}
	if (n>1000&&q<=500){
		int cnt=0;
		for (int i=0;i<q;i++){
			scanf("%d%d",&qx[i],&qy[i]);
			if (!map[qx[i]]){
				map[qx[i]]=++cnt;
				for (int j=1;j<=m;j++)
					mapedmatrix[cnt][j]=(qx[i]-1)*m+j;
			}
		}
		for (int i=1;i<=n;i++)
			lastcol[i]=i*m;
		for (int i=0;i<q;i++){
			int out=mapedmatrix[map[qx[i]]][qy[i]];
			printf("%d\n",out);
			for (int j=qy[i];j<m;j++)
				mapedmatrix[map[qx[i]]][j]=mapedmatrix[map[qx[i]]][j+1];
			for (int j=qx[i];j<n;j++)
				lastcol[j]=lastcol[j+1];
			lastcol[n]=out;
			for (int j=0;j<q;j++)
				mapedmatrix[map[qx[j]]][m]=lastcol[qx[j]];
			//mapedmatrix[map[qx[i]]][m]=lastcol[qx[i]];
		}
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			matrix[i][j]=(i-1)*m+j;
	for (int i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		int out=matrix[x][y];
		printf("%d\n",out);
		for (int j=y;j<m;j++)
			matrix[x][j]=matrix[x][j+1];
		for (int j=x;j<n;j++)
			matrix[j][m]=matrix[j+1][m];
		matrix[n][m]=out;
	}
	return 0;
}
