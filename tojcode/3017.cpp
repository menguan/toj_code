#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
long long dp[110][110];
int a[110];
int main()
{
    int n,k;
    while(cin>>n>>k&&(n+k))
    {
        for(int i=1;i<=n;i++)
          cin>>a[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
          dp[i][1]=1;
        for(int i=2;i<=k;i++)
        for(int j=i;j<=n;j++)
        for(int l=0;l<j;l++)
          if(a[j]>a[l])
            dp[j][i]+=dp[l][i-1];  
          
        long long ans=0;
        for(int i=k;i<=n;i++)
          ans+=dp[i][k];
        cout<<ans<<endl;
    }
}
  
                                  
