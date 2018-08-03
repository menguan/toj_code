#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char name[20][50];
double dp[20][20],vic[20][20];
int main()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<16;i++)
    {
        gets(name[i]);
        dp[i][0]=1.0;
    }
    for(int i=0;i<16;i++)
    for(int j=0;j<16;j++)
    { 
        scanf("%lf",&vic[i][j]); 
        vic[i][j]/=100.0;
    }
    for(int k=1;k<=4;k++)//轮数 
    {
        int len=1<<k;
        int mid=len>>1;
        for(int i=0;i<16;i+=len)
        for(int j=0;j<mid;j++)//前一部分人和后一部分人都有可能碰上 
        for(int t=mid;t<len;t++)
        {
          dp[i+j][k]+=dp[i+j][k-1]*dp[i+t][k-1]*vic[i+j][i+t];
          dp[i+t][k]+=dp[i+j][k-1]*dp[i+t][k-1]*vic[i+t][i+j];
        }
    }
    for(int i=0;i<16;i++)
    {
        printf("%-11sp=%.2lf%%\n",name[i],dp[i][4]*100);
    }
    //while(1);
}
