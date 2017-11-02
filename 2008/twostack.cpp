#include <stdio.h>
#include <algorithm>
#define N 1001
int n,a[N],b[N],c=0,s[2][N],t[2]={-1,-1},min=0,max;
char o[2*N];
int main(){
	scanf("%d",&n);
	max=n-1;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	std::sort(b,b+n);
	for (int i=0;i<n;i++){
		//if (a[i]==b[max]) max--;
		if ((t[0]<0||s[0][t[0]]>=a[i])&&(t[1]<0||s[1][t[1]]>=b[max]))
			s[0][++t[0]]=a[i],o[++h]='a';
		else
			if ((t[1]<0||s[1][t[1]]>=a[i])&&(t[0]<0||s[0][t[0]]>=b[max]))
				s[1][++t[1]]=a[i],o[++h]='c';
			else{
				o[++h]='0';
				//puts("0");
				//return 0;
			}
		for (;;)
			if (t[0]>=0&&c<=n&&b[c]==s[0][t[0]])
				c++,t[0]--,o[++h]='b';
			else
				if (t[1]>=0&&c<=n&&b[c]==s[1][t[1]])
					c++,t[1]--,o[++h]='d';
				else break;
	}
	for (int i=0;i<=h;i++)
		printf("%c ",o[i]);
	printf("\n");
}
