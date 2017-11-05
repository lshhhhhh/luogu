#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int n,m,head[152],dfn[152],low[152],t,time,ans,fa[152];
struct aa{
	int to,nex;
	bool flag;
	int fa,num;
}q[10005];
void add(int x,int y)
{
	t++,q[t].to=y,q[t].nex=head[x],head[x]=t;
}
struct at{
	int x,y;
}p[10005];
void work(int i)
{
	time++,dfn[i]=low[i]=time;
	for(int j=head[i];j!=0;j=q[j].nex)
	{
		int to=q[j].to;
		if(!dfn[to])
		{
			fa[to]=i;
			work(to);
			low[i]=min(low[i],low[to]);
		}
		else 
		{
			if(low[to]>dfn[i])ans++,p[ans].x=i,p[ans].y=q[j].to;
		}
	}
}
bool cmp(const at &a1,const at &a2){
	return a1.x<a2.x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	add(x,y),q[t].num=i,add(y,x),q[t].num=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])work(i);
	}
	
	sort(p+1,p+1+ans,cmp);
	for(int i=1;i<=ans;i++)
	{
		printf("%d %d\n",p[i].x,p[i].y);
	}
    return 0;
}

