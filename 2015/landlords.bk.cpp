#include <cstdio>
#include <cstring>
#define N 14
int T,n,a,b;
int count[N]={0};
void check(int &x,int y){
	if (y<x) x=y;
}
int dfs(){
	int sum=0;
	for (int i=0;i<14;i++)
		sum+=count[i];
	if (sum==0) return 0;
	int ret=sum,ctn[4][N]={0};
	for (int i=1;i<4;i++)
		for (int j=2;j<N;j++)
			ctn[i][j]=count[j]<i?0:ctn[i][j-1]+1;
	for (int i=6;i<N;i++)	
		if (ctn[1][i]>=5){
			for (int k=ctn[1][i];k>=5;k--){
				for (int j=i;j>i-k;j--)
					count[j]--;
				check(ret,1+dfs());
				for (int j=i;j>i-k;j--)
					count[j]++;
			}
		}
	for (int i=4;i<N;i++)
		if (ctn[2][i]>=3){
			for (int k=ctn[2][i];k>=3;k--){
				for (int j=i;j>i-k;j--)
					count[j]-=2;
				check(ret,1+dfs());
				for (int j=i;j>i-k;j--)
					count[j]+=2;
			}
		}
	for (int i=3;i<N;i++)
		if (ctn[3][i]>=2){
			for (int k=ctn[3][i];k>=2;k--){
				for (int j=i;j>i-k;j--)
					count[j]-=3;
				check(ret,1+dfs());
				for (int j=i;j>i-k;j--)
					count[j]+=3;
			}
		}
	for (int i=1;i<N;i++)
		if (count[i]>=3){
			count[i]-=3;
			check(ret,1+dfs());
			for (int j=0;j<N;j++)
				if (count[j]){
					count[j]--;
					check(ret,1+dfs());
					count[j]++;
				}
			for (int j=1;j<N;j++)
				if (count[j]>=2){
					count[j]-=2;
					check(ret,1+dfs());
					count[j]+=2;
				}
			count[i]+=3;
		}
	for (int i=0;i<n;i++)
		if (count[i]==4){
			count[i]-=4;
			check(ret,1+dfs());
			for (int j=0;j<N;j++){
				if (count[j]){
					count[j]--;
					for (int k=j;k<N;k++){
						if (count[k]){
							count[k]--;
							check(ret,1+dfs());
							count[k]++;
						}
					}
					count[j]++;
				}
				if (count[j]>=2){
					count[j]-=2;
					for (int k=j;k<N;k++){
						if (count[k]>=2){
							count[k]-=2;
							check(ret,1+dfs());
							count[k]+=2;
						}
					}
					count[j]+=2;
				}
			}
		}
	if (ret==sum){
		ret=0;
		for (int i=0;i<N;i++)
			ret+=count[i]/2+count[i]%2;
	}
	//printf("%d\n",ret);
	return ret;
}
void work(){
	int ans=0;
	memset(count,0,sizeof(count));
	for (int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		count[a?(a+11)%13+1:0]++;
	}
	if (count[0]==2) {ans=1;count[0]=0;}
	printf("%d\n",ans+dfs());
}
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&T,&n);
	while (T--)
		work();
}
