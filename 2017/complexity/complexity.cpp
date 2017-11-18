#include <stdio.h>
#include <string.h>
#include <iostream>
int T,line,stack[26],top=-1;
bool inuse[26];
char c;
int read(){
	int ret=0;
	for (c=getchar();!isdigit(c)&&(c<'a'||c>'z');c=getchar());
	if (!isdigit(c))
		return 101;
	for (;isdigit(c);c=getchar())
		ret=ret*10+int(c)-int('0');
	return ret;
}
int readline(){
	int a,b;
	for (c=getchar();c!='E'&&c!='F';c=getchar());
	if (c=='E') return -1;
	for (;c<'a'||c>'z';c=getchar());
	stack[++top]=int(c)-int('a');
	if (inuse[int(c)-int('a')]) return -2;
	inuse[int(c)-int('a')]=true;
	a=read();b=read();
	if (a<100&&b>100) return 1;
	if (a>b) return -4;
	return 0;
}
int main(){
	freopen("complexity.in","r",stdin);
	freopen("complexity.out","w",stdout);
	scanf("%d",&T);
	for (;T;T--){
		top=-1;
		//printf("%d %d\n",T,top);
		int max=0,ef=0,error=0,t,cur=0,exp,unexec=0;
		memset(inuse,0,sizeof(inuse));
		scanf("%d O(%c",&line,&c);
		if (c=='1') exp=0;
		else scanf("^%d",&exp);
		if (line%2){
			printf("ERR\n");
			for (int i=0;i<line;i++)
				readline();
			continue;
		}
		for (int i=0;i<line;i++){
			t=readline();
			//printf("%d\n",t);
			if (t==-2) error=1;
			if (t==-1){
				ef--;
				inuse[stack[top]]=false;
				top--;
			} 
			if (ef<0) error=1;
			if (ef==0){
				//printf("%d %d\n",max,exp);
				if (max<cur)
					max=cur;
				cur=0;
				unexec=0;
			}
			if (t==-4){
				unexec=1;
				ef++;
			}
			if (t>=0){
				if (!unexec)
					cur=cur+t;
				ef++;
			}
			//printf("cur=%d\n",cur);
		}
		if (ef>0) error=1;
		//printf("%d %d\n",max,exp);
		//printf("%d %d ",T,top);
		if (error) printf("ERR\n");
		else printf("%s\n",exp==max?"Yes":"No");
	}
	return 0;
}
