#include <stdio.h>
#include <string.h>
#define N 1001
#define pow(x) ((x)*(x))
#define abs(x) (((x)>=0)?(x):(-(x)))
long long x[N],y[N],z[N],h,r,r2;
int T,n;
bool sed[N];
long long dis(int a,int b){
	return pow(x[a]-x[b])+pow(y[a]-y[b])+pow(z[a]-z[b]);
}
bool dfs(int a){
	if (abs(z[a]-h)<=r) return true;
	for (int i=0;i<n;i++)
		if (!sed[i]&&dis(a,i)<=r2){
			sed[i]=true;
			if (dfs(i)) return true;
		}
	return false;
}
int main(){
	freopen("cheese.in","r",stdin);
	freopen("cheese.out","w",stdout);
	scanf("%d",&T);
	for (;T;T--){
		bool reach=false;
		memset(sed,0,sizeof(sed));
		scanf("%d%lld%lld",&n,&h,&r);
		r2=4*r*r;
		for (int i=0;i<n;i++)
			scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		for (int i=0;i<n;i++)
			if (!sed[i]&&abs(z[i])<=r){
				sed[i]=true;
				if (dfs(i)){
					reach=true;
					break;
				}
			}
		printf("%s\n",reach?"Yes":"No");
	}
	return 0;
}
