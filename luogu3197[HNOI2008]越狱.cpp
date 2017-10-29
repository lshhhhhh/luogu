#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

long long m,n;

long long poww(long long x,long long y){
    long long ans=1;
    long long base=x;
    while(y>0){
        if(y%2==1){
            ans*=base;
            ans%=100003;
        }
        base*=base;
        base%=100003;
        y/=2;
    }
    return ans;
}

int main(){
    cin>>m>>n;
    long long a=poww(m,n)%100003,b=(poww(m-1,n-1)*m)%100003;
    long long ans=(a-b)%100003;
    cout<<(ans+100003)%100003;
    
    return 0;
}
