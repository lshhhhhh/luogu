#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
const int k=100003;
long long n,m,ans=1,sum;
long long fast(long long z,long long t){
    sum=z;
    ans=1;
    while(t>0)
    {
        if(t%2==1)
        {
            ans*=sum;
            ans%=k;
        }
        t/=2;
        sum*=sum;
        sum%=k;
    }
    return ans;
}
int main()
{
    cin>>m>>n;
    //cout<<fast(m,n)<<endl;
    printf("%d\n",((fast(m,n)-m*fast(m-1,n-1))%k+k)%k);
    return 0;
}
