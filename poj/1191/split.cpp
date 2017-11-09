//POJ1191
#include <stdio.h>
#include <math.h>
int n,a[8][8],sum_bk[8][8][8][8]={0};
float avr=0,INF=1e8,dp[8][8][8][8][16]={0};
int sum(int x0,int y0,int x1,int y1){
	if (sum_bk[x0][y0][x1][y1])
		return sum_bk[x0][y0][x1][y1];
	int ret=0;
	for (int i=x0;i<=x1;i++)
		for (int j=y0;j<=y1;j++)
			ret+=a[i][j];
	return ret;
}
float dev(int x){
	return (float(x)-avr)*(float(x)-avr);
}
float dfs(int x0,int y0,int x1,int y1,int t){
	float min=INF;
	if ((x1-x0+1)*(y1-y0+1)<t)
		return INF;
	if (dp[x0][y0][x1][x1][n])
		return dp[x0][y0][x1][x1][n];
	if (t==1)
		return dev(sum(x0,y0,x1,y1));
	for (int i=x0;i<x1;i++)
		if (min>dev(sum(x0,y0,i,y1))+dfs(i+1,y0,x1,y1,t-1))
			min=dev(sum(x0,y0,i,y1))+dfs(i+1,y0,x1,y1,t-1);
	for (int i=x1;i>x0;i--)
		if (min>dev(sum(i,y0,x1,y1))+dfs(x0,y0,i-1,y1,t-1))
			min=dev(sum(i,y0,x1,y1))+dfs(x0,y0,i-1,y1,t-1);
	for (int i=y0;i<y1;i++)
		if (min>dev(sum(x0,y0,x1,i))+dfs(x0,i+1,x1,y1,t-1))
			min=dev(sum(x0,y0,x1,i))+dfs(x0,i+1,x1,y1,t-1);
	for (int i=y1;i>y0;i--)
		if (min>dev(sum(x0,i,x1,y1))+dfs(x0,y0,x1,i-1,t-1))
			min=dev(sum(x0,i,x1,y1))+dfs(x0,y0,x1,i-1,t-1);
	return (dp[x0][y0][x1][y1][t]=min);
}
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
			scanf("%d",&a[i][j]),
				avr+=a[i][j];
	avr/=n;
	//printf("%d %f\n",sum,avr);
	printf("%.3f\n",sqrt(dfs(0,0,7,7,n)/n));
}
