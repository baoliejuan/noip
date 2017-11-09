//POJ1191
#include <stdio.h>
int n,a[8][8],sum=0;
float avr,INF=1e8,dp[8][8][8][8][16]={0};
float dfs(int x0,int y0,int x1,int y1,int t){
	float max=0;
	if ((x1-x0)*(y1-y0)<t)
		return -INF;
	for (int i=x0;i
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
			scanf("%d",&a[i][j]),
				sum+=a[i][j];
	avr=float(sum)/64;
	printf("%.3f\n",dfs(0,0,7,7,n));
}
