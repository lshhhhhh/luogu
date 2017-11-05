#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=100005;
int n,m,head[maxn],t,time,dfn[maxn],low[maxn],fa[maxn],ans;
struct edge{
    int to,nex;
}p[2*maxn];
void add(int x,int y)
{
    t++,p[t].to=y,p[t].nex=head[x],head[x]=t;
}
bool flag[maxn];
void work(int i)
{
    int sum=0;
    dfn[i]=low[i]=++time;
    for(int j=head[i];j!=0;j=p[j].nex)
    {
        int to=p[j].to;
        if(!dfn[to])
        {
            fa[to]=fa[i];
            work(to);
            low[i]=min(low[i],low[to]);
            if(low[to]>=dfn[i] && fa[i]!=i)flag[i]=1;
            if(fa[i]==i)sum++;
        }
        low[i]=min(low[i],dfn[to]);
    }
    if(fa[i]==i && sum>=2)flag[i]=1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	add(x,y);
    	add(y,x);
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            work(i);
        }
        if(flag[i])ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {
        if(flag[i])printf("%d ",i);
    }
    printf("\n");
    return 0;
}

