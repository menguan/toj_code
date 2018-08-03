#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<algorithm>
#define le 1010
using namespace std;
struct f
{
       int v,id;
}ar[le];
int n;int dp[le];
int g[le][le];
bool cmp(f mm,f nn)
{
     return mm.v>nn.v;
}
int main()
{
    while(~scanf("%d",&n))
    {
       if(n==0)  break;
       for(int i=0;i<n;i++)
       {
        scanf("%d",&ar[i].v);
        ar[i].id=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
              scanf("%d",&g[i][j]);
        }
        sort(ar,ar+n,cmp);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
          for(int j=i+1;j<n;j++)
          {
             if(g[ar[i].id][ar[j].id]&&ar[i].v>ar[j].v)
                dp[ar[j].id]+=dp[ar[i].id];}
        }
        if(dp[ar[n-1].id])
           cout<<dp[ar[n-1].id]<<endl;
        else puts("impossible")
        ;
    }
}                                              
    
