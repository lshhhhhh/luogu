#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
int add(int ans1,int ans2,int ans3,int ans4){
	int t1=ans1*ans4,t2=ans3*ans2;
	return t1+t2;
}
int gcd(int a,int b){
	if(a==0)return b;
	return gcd(b%a,a);
}
int sum1,sum2,sum3,sum4,i;
int str;
bool flag1,flag2;
string t;
int main()
{
    cin>>t;
    str=t.length();
    if(t[0]=='-')flag1=1;
    else sum4=t[0]-48;
    for(i=1;i<str;i++)
    {
    	if(t[i]=='+' || t[i]=='-')break;
    	if(t[i]=='/')
    	{
    		sum3=sum4;
    		if(t[i+1]=='-')flag2=1,sum4=0;
    		else sum4=t[i+1]-48;
    		i++;
    		continue;
    	}
    	sum4=sum4*10+t[i]-48;
    }
    if(flag1)sum3*=(-1);
    if(flag2)sum3*=(-1);
    flag1=flag2=0;
    sum1=sum3,sum2=sum4;
    if(t[i]=='-')flag1=1;
    int t=gcd(min(sum1,sum2),max(sum1,sum2));
    sum1/=t,sum2/=t;
	sum3=0;
	i++;
    for(i=i;i<str;i++)
    {
    	if(t[i]=='+' )//|| t[i]=='-')
    	{
    		if(flag1)sum3*=(-1);
    		if(flag2)sum3*=(-1);
    		sum1=add(sum1,sum2,sum3,sum4);
    		sum2*=sum4;
    		t=gcd(min(sum1,sum2),max(sum1,sum2));
    		sum1/=t,sum2/=t;
    		flag1=flag2=0;
    		continue;
		}
		if(t[i]=='/')
		{
			sum3=sum4;
			if(t[i+1]=='-')flag2=1,sum4=0;
			else sum4=t[i+1]-48;
			i++;
			continue;
		}
		sum4=sum4*10+t[i]-48;
    }
    if(flag1)sum3*=(-1);
    if(flag2)sum3*=(-1);
    sum1=add(sum1,sum2,sum3,sum4);
    sum2*=sum4;
    t=gcd(min(sum1,sum2),max(sum1,sum2));
    sum1/=t,sum2/=t;
    printf("%d/%d\n",sum1,sum2);
    return 0;
}
/*
ans1*sum/ans2*sum+sum1*ans2/sum*ans2
*/
