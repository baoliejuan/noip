#include <stdio.h>
#include <math.h>
#define HA 10000000000000007
long long a[101],n,m,ans[1000001]={0};
long long read(){
	char r;long long ret=0,pn=1;
	for (r=getchar();r<'0'||r>'9';r=getchar())
		if (r=='-') pn=-1;
	ret=int(r)-int('0');
	for (r=getchar();r>='0'&&r<='9';r=getchar())
		ret=(ret*10+(long long)(r)-(long long)('0'))%HA;
	return pn*ret;
}
inline long long mul(long long x,long long p){
	long long ret=0,pn=1;
	if (x<0) x=-x,pn=-pn;
	if (p<0) p=-p,pn=-pn;
	if ((float(x)*float(p))<float(HA))
		return pn*x*p;
	for (;p;p>>=1){
		if (p&1)
			ret=(ret+x)%HA;
		x=(x<<1)%HA;
	}
	return pn*ret;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=0;i<=n;i++)
		a[i]=read();
	for (int i=1;i<=m;i++){
		long long sum=a[n];
			for (int j=n-1;j>=0;j--){
				//sum=(sum+mul(p,a[j]))%HA;
				//p=mul(p,i);
				sum=mul(sum,i);
				sum=(sum+a[j])%HA;
			}
		if (sum%HA==0)
			ans[++ans[0]]=i;
	}
	for (int i=0;i<=ans[0];i++)
		printf("%lld\n",ans[i]);
}
