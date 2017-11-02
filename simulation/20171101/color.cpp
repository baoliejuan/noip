#include <stdio.h>
#define N 33
int n,m,s[N]={1},p[N],t[N],c[N],opt,l,r,q;
int find(int cl,int po){
	for (int i=s[cl-1];i<s[cl];i++)
		if (p[i]==po)
			return i;
	printf("no found!\n");
	return -1;
}
int findl(int cl,int po){
	printf("l:%d %d\n",cl,po);
	//for (int i=s[cl-1]-1;i<s[cl];i++)
		//if (i+1>=s[cl]||s[i+1]>po)
			//return i;
	//printf("no foundl!\n");
	//return -1;
	int l=s[cl-1],r=s[cl]-1;
	while (l<r){
		int mid=(l+r)/2;
		if (p[mid]<=po) l=mid;
		else r=mid;
		printf("%d %d %d\n",l,r,mid);
	}
	return l;
}
int findh(int cl,int po){
	printf("h:%d %d\n",cl,po);
	//for (int i=s[cl];i>=s[cl-1];i--)
		//if (i-1<s[cl]||s[i-1]<po)
			//return i;
	//printf("no foundh!\n");
	//return -1;
	int l=s[cl-1],r=s[cl]-1;
	while (l<r){
		//if (r-l==1){
			//if (
		//}
		int mid=(l+r)/2;
		if (p[mid]<po) l=mid+1;
		else r=mid;
		printf("%d %d %d\n",r,l,mid);
	}
	return l;
}
int main(){
#ifdef D
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		s[c[i]]++;
	}
	for (int i=1;i<=n;i++)
		s[i]+=s[i-1];
	for (int i=1;i<=n;i++)
		p[s[c[i]-1]+(t[c[i]]++)]=i;
	for (int i=1;i<=m;i++){
		scanf("%d",&opt);
		if (opt==2){
			scanf("%d",&q);
			if (c[q]==c[q+1]);
			else p[find(c[q],q)]++,
				p[find(c[q+1],q+1)]--;
			int tmp=c[q];
			c[q]=c[q+1];c[q+1]=tmp;
		}
		if (opt==1){
			scanf("%d%d%d",&l,&r,&q);
			//int ans=0;
			//for (int j=s[q-1];j<s[q];j++)
				//if (p[j]>=l&&p[j]<=r)
					//ans++;
			//printf("%d\n",ans);
			printf("%d\n",findl(q,r)-findh(q,l)+1);
		}
	}
}
