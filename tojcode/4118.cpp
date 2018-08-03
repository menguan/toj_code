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
    //cin>>t;
    while(cin>>n)
    {
              //cin>>n;
              memset(dp,0,sizeof(dp));
              int ans=0;
              for(int i=1;i<=n;i++)
              {
                      if(!dp[i])
                      {
                                ans++;
                                dp[2*i+2]=1;
                      }
              }
              cout<<ans<<endl;
                      
              
    }
    }               
           