#include<iostream>
#include<math.h>
using namespace std;
int n;
long long f(long long a,long long b,long long M) 
{
    long long t=1;
    while(b) 
    {
        if(b&1) t=t*a%M;
        a=a*a%M;
        b>>=1;
    }
    return t;
}


int main()
{
    while(cin>>n,n)
    {
        long long ans=f(2,n-1,n);
        cout<<ans+1<<endl;                       
    }
    return 0;    
} 
