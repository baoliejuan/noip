#include <cstdio>
#include <cstring>
#define N 14
int T,n,a,b,count[N]={0};
void check(int &x,int y){
	if (y<x) x=y;
}
int dfs(){
	int ans=42,bns=0,ctn[4][N]={0},cot[5]={0};
	for (int i=1;i<4;i++)
		for (int j=2;j<N;j++)
			ctn[i][j]=count[j]<i?0:ctn[i][j-1]+1;
	int c[4]={0,5,3,2};
	for (int l=1;l<=3;l++)
		for (int i=1+c[l];i<N;i++)
			if (ctn[l][i]>=c[l])
				for (int k=ctn[l][i];k>=c[l];k--){
					for (int j=i;j>i-k;j--)
						count[j]-=l;
					check(ans,1+dfs());
					for (int j=i;j>i-k;j--)
						count[j]+=l;
				}
	for (int i=0;i<N;i++)
		cot[count[i]]++;
	for (int l=1;l<=2;l++)
		for (int i=1;i<=2;i++)
			if (cot[i]/l>=cot[l+2])
				cot[i]-=cot[l+2]*l,bns+=cot[l+2],cot[l+2]=0;
			else
				bns+=cot[i]/l,cot[l+2]-=cot[i]/l,cot[i]-=cot[i]/l*l;
	bns+=cot[1]+cot[2]+cot[3]+cot[4];
	return ans<bns?ans:bns;
}
int main(){
	scanf("%d%d",&T,&n);
	while (T--){
		int ans=0;
		memset(count,0,sizeof(count));
		for (int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			count[a?(a+11)%13+1:0]++;
		}
		if (count[0]==2) {ans=1;count[0]=0;}
		printf("%d\n",ans+dfs());
	}
}
