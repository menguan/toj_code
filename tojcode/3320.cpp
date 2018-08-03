#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[110],c[110],dp[100010];
void CompletePack(int v,int w,int m) 
{
     for(int j=v;j<=m;j++)
      dp[j]=max(dp[j],dp[j-v]+w);
}
void ZeroOnePack(int v,int w,int m) 
{
      for(int j=m;j>=v;j--)
       dp[j]=max(dp[j],dp[j-v]+w);
}
void MultiPack(int v,int w,int m,int c) 
{
    if(v*c>=m) 
     CompletePack(v,w,m);
    else  
    {
        int k=1;
        while(k<c) 
        {
            ZeroOnePack(k*v,k*w,m);
             c-=k;
             k*=2;
        }
        ZeroOnePack(c*v,c*w,m);
    }
}
int main()
{
    int n,i,j,m,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(i=0;i<n;i++)
         scanf("%d",&a[i]);  
        for(i=0;i<n;i++)
         scanf("%d",&c[i]); 
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            MultiPack(a[i],a[i],m,c[i]);
        }
        int count=0; 
        for(i=1;i<=m;i++)
         if(dp[i]==i) 
          count++;
        printf("%d\n",count);
    }
    return 0;
}
