#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 510
#define inf -2000000000
int main()
{
    int cas,ori,i,j,n,p[N],w[N],dp[10010],total;
    cin>>cas;
    while(cas--)
    {
      cin>>ori>>total;
      total-=ori;
      cin>>n;
      for(i=1;i<=n;i++)
        cin>>p[i]>>w[i];
      for(i=1;i<=total;i++)  dp[i]=inf;
      dp[0]=0;
      for(i=1;i<=n;i++)
      for(j=w[i];j<=total;j++)
      {
         if(dp[j]<0)  dp[j]=dp[j-w[i]]+p[i];
         else  if(dp[j-w[i]]+p[i]>0)
           dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
      }
      if(dp[total]>0)
        cout<<"The minimum amount of money in the piggy-bank is "<<dp[total]<<"."<<endl;
      else
        cout<<"This is impossible."<<endl;
    }
}       
                                
                  
