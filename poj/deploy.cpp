#include <stdio.h>
int n,m,max[102][1024]={0},high[102]={0},ans=0;
char c;
int count1(int x,int ans=0){
	for (;x;x-=x&-x)
		ans++;
	return ans;
}
bool check(int x){
	for (int last=-1;x;x-=x&-x)
		if (last<0||(x&-x)/last>4)
			last=x&-x;
		else return false;
	return true;
}
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<2;i++)
		for (int j=0;j<1<<m;j++)
			high[i]|=1<<j;
	for (int i=2;i<n+2;i++)
		for (int j=0;j<m;j++){
			for (c=getchar();c!='H'&&c!='P';c=getchar());
			if (c=='H')
				high[i]|=(1<<j);
		}
	for (int i=2;i<n+2;i++)
		for (int j=0;j<1<<m;j++)
			if (!(j&high[i-2]) && check(j))
				for (int k=0;k<1<<m;k++)
					if (!(k&(j|high[i-1])) && check(k))
						for (int l=0;l<1<<m;l++)
							if (!(l&(j|k|high[i])) && check(l))
								if (max[i][l]<max[i-2][j]+count1(l)+count1(k))
									max[i][l]=max[i-2][j]+count1(l)+count1(k);
	for (int i=0;i<n+2;i++)
		for (int j=0;j<1<<m;j++)
			if (ans<max[i][j])
				ans=max[i][j];
	printf("%d\n",ans);
}