#include <stdio.h>
#include <string.h>
#ifdef D
#define N 82
#define Q 80
#else
#define N 402
#define Q 1000000
#endif
int n,m,k,a[N][N],p[N]={0},b[N]={0},sum[N][N]={0},s;
int count[Q]={0},ans=0;
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			sum[i][j]=(sum[i][j-1]+a[i][j])%k;
	for (int i=1;i<=m;i++)
		for (int j=i;j<=m;j++){
			int s=0;
			for (int l=1;l<=n;l++)
				s=(s+sum[l][j]-sum[l][i-1])%k;
			for (int l=1;l<=n;l++)
				p[l]=(p[l-1]+sum[l][j]-sum[l][i-1])%k;
			for (int l=n;l>0;l--)
				b[l]=(b[l+1]+sum[l][j]-sum[l][i-1])%k;
			for (int l=n-1;l>=0;l--){
				count[b[l+2]]++;
				ans+=count[(s-p[l]+k)%k];
			}
			for (int l=2;l<=n+1;l++)
				count[b[l]]--;
		}
	printf("%d\n",ans);
}
