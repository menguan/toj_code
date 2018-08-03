#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool dp[1000010];
int p[100];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,0,sizeof(dp));            
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
          scanf("%d",&p[i]);
        }       
        for(int i=0;i<n;i++)
        {
          for(int j=p[i];j<=m;j++)
          {
              if(dp[j-p[i]])
                dp[j]=1;
          }
        }
        int count=1;
        if(!dp[m])
          puts("impossible");
        else
        {
        for(int i=1;i<m;i++)
        {
            if(dp[i]) 
              count++;
        }
        printf("%d\n",count);
        }
    }
}                          
             
