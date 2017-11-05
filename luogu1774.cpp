#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
int n;
ll a[500005],c[500005];
ll ans,i,j;
void work(ll l,ll r){
	if(l==r)return ;
	work(l,(l+r)/2);
	work((l+r)/2+1,r);
	i=j=0;
	while(i+l<=(l+r)/2 && (l+r)/2+1+j<=r){
		if(a[i+l]<=a[(l+r)/2+j+1]){
			c[l+i+j]=a[i+l],i++;
			ans+=j;
		}
		else
		{
			c[l+i+j]=a[(l+r)/2+j+1],j++;
		}
	}
	while(i+l<=(l+r)/2)c[l+i+j]=a[i+l],i++,ans+=j;
	while((l+r)/2+1+j<=r)c[l+i+j]=a[(l+r)/2+j+1],j++;;
	for(int k=l;k<=r;k++)a[k]=c[k];
}
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    work(1,n);
    printf("%lld\n",ans);
    return 0;
}

