#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000][1000];
int dp[1000][1000];
int main()
{
    int n,m;int cas=1;
    while(cin>>n>>m)
    {
       int ans=0;
         memset(dp,0,sizeof(dp));   
         for(int j=0;j<n;j++)         
         for(int i=0;i<m;i++)
         {
           cin>>a[j][i];
         }
                             
         for(int i=1;i<m-1;i++)
         {
           dp[0][i]=abs(a[0][i-1]-a[0][i+1]);
         }
         for(int i=1;i<n;i++)
         {
           for(int j=1;j<m-1;j++)
           {
              dp[i][j]=abs(a[i][j-1]-a[i][j+1])+max(max(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
           }
         }     
         for(int i=1;i<m-1;i++)
           ans=max(dp[n-1][i],ans);                
       
       cout<<"Case #"<<cas++<<": ";
       cout<<ans<<endl;
    }
}                
