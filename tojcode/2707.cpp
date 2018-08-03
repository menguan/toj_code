#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n,m;
int a[510],b[501];
int dp[510][510];
int pre[510][510];
int an[510];
int main()
{
   while(cin>>n){

   for(int i=1;i<=n;i++)
        cin>>a[i];
   cin>>m;
   for(int i=1;i<=m;i++)
        cin>>b[i];
   memset(dp,0,sizeof(dp));
   memset(pre,0,sizeof(pre));
   int ma;int ans=0,tx,ty;
   for(int i=1;i<=n;i++)
   {
       ma=0;
       for(int j=1;j<=m;j++)
       {
           if(a[i]==b[j])
           {
               dp[i][j]=dp[i-1][ma]+1;
               pre[i][j]=ma;
           }
           else
           {
               dp[i][j]=dp[i-1][j];
               pre[i][j]=-1;
           }
           if(a[i]>b[j]&&dp[i-1][j]>dp[i-1][ma])
              ma=j;
           if(ans<dp[i][j])
              {
                  ans=dp[i][j];
                  tx=i;
                  ty=j;
              }
       }
   }

       cout<<ans<<endl;
       stack<int> st;
       int tt=tx;
       int tmp=ans;
        while(tmp)
        {
            if(pre[tt][ty]>-1)
            {
                an[tmp--]=b[ty];
                ty=pre[tt][ty];
            }
            tt--;
        }
        for(int i=1;i<=ans;i++)
            printf("%d%c",an[i],i==ans?'\n':' ');
   }
}
