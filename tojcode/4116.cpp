#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,t;
int a[1000100];
int dp[1000010];
int f(int a,int b)
{
    if(b==0) return a;
    return f(b,a%b);
}
int main()
{
    cin>>t;
    while(t--)
    {
              cin>>n;
              for(int i=0;i<n;i++) cin>>a[i];
              int ans=a[0];
              for(int i=1;i<n;i++)
                ans=f(ans,a[i]);
              cout<<ans<<endl;
                      
              
    }
    }               
                   

 