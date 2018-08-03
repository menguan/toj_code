#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,t;
int a[1000100];
int dp[1000010];
int main()
{
    cin>>t;
    while(t--)
    {
              cin>>n;
              for(int i=0;i<n;i++)
              {
                 cin>>a[i];
              }
              cin>>m;
              memset(dp,0,sizeof(dp));
              int sum=0;
              int st=0;
              int ans=0;
              for(int i=0;i<n;i++)
              {
                   sum+=a[i];
                   
                   if(sum>m)
                   {
                      while(sum>m)
                      {
                         sum-=a[st];
                         st++;
                      }
                   }if(sum==m) ans++;
              }
              cout<<ans<<endl;
    }
    }     