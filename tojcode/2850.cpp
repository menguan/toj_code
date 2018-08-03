#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
const int mod=100000000;
const int N=1<<12+4;
int dp[15][N],Map[15][15];
int n,m;
vector<int> vec[15];
int Pow(int x)
{
    int s=1;
    for(int i=1;i<=x;i++)
      s<<=1;
    return s;
}  
int fun(int x)
{
    int s=0;
    for(int i=1;i<=m;i++)
      s+=(!Map[x][i])*Pow(m-i); //0可以种 
    return s;
}  
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
       memset(dp,0,sizeof(dp));
       memset(vec,0,sizeof(vec));
       for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
         cin>>Map[i][j];
       vec[0].push_back(0);
       int k=1<<m;
       for(i=0;i<k;i++)
         dp[0][i]=1;
       for(i=1;i<=n;i++)
       {
         int tmp=fun(i); 
         for(j=0;j<k;j++)
         {
            if(j&(j>>1))  continue;
            if(j&tmp)  continue;
            vec[i].push_back(j);
         }
         for(j=0;j<vec[i].size();j++)
         {
            int u=vec[i][j];
            for(int z=0;z<vec[i-1].size();z++)
            {
               int v=vec[i-1][z];
               if(u&v)  continue;
               dp[i][u]=(dp[i][u]+dp[i-1][v])%mod;
            }
         }
       }
       int ans=0;
       for(i=0;i<k;i++)
         ans=(ans+dp[n][i])%mod;
       cout<<ans<<endl;
    }
}                                                          
         
                        
