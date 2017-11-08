//POJ1185
#include <stdio.h>
int n,m,max[102][1024][1024]={0},high[102]={0},ans=0;
bool check[1024];
char c;
int count1(int x,int ans=0){
	for (;x;x-=x&-x)
		ans++;
	return ans;
}
bool ck(int x){
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
	for (int i=0;i<1<<m;i++)
		check[i]=ck(i);
	for (int i=0;i<2;i++)
		for (int j=0;j<m;j++)
			high[i]|=1<<j;
	for (int i=2;i<n+2;i++)
		for (int j=0;j<m;j++){
			for (c=getchar();c!='H'&&c!='P';c=getchar());
			if (c=='H')
				high[i]|=(1<<j);
		}
	for (int i=2;i<n+2;i++)
		for (int j=0;j<1<<m;j++)
			if (check[j]&&!(j&high[i]))
				for (int k=0;k<1<<m;k++)
					if (check[k]&&!(k&(j|high[i-1])))
						for (int l=0;l<1<<m;l++)
							if (check[l]&&!(l&(j|k|high[i-2])))
								if (max[i][j][k]<max[i-1][k][l]+count1(j))
									max[i][j][k]=max[i-1][k][l]+count1(j);
	for (int i=0;i<1<<m;i++)
		for (int j=0;j<1<<m;j++)
			if (ans<max[n+1][i][j])
				ans=max[n+1][i][j];
	printf("%d\n",ans);
}
