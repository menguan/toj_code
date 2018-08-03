#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int c,m,n;
double dp[1010][101];
int main()
{

     while(scanf("%d",&c)!=EOF)
     {
         if(!c) return 0;
         scanf("%d%d",&n,&m);
         double ans;
         if((n+m)%2||c<m)
         {
             puts("0.000");
             continue;
         }
         dp[0][0]=1;
         dp[1][1]=1;
         dp[0][1]=0;
         dp[1][0]=0;
         if(n>1000)  n=1000+n%2;
         for(int i=2;i<=n;i++)
         {
             for(int j=0;j<=c;j++)
             {
                 dp[i][j]=0;
                 if(j>0)
                    dp[i][j]+=dp[i-1][j-1]*(c-j+1)/c;
                 if(j<c)
                    dp[i][j]+=dp[i-1][j+1]*(j+1)/c;
             }
         }
         printf("%.3f\n",dp[n][m]);
     }
}
