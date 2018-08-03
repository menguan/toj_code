#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{int x,y;}a[210];
double g[210][210];
bool cmp(node aa,node bb){return aa.x<bb.x;}
int main()
{
    int n;int inf=1010101010;double dp[210][210];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                g[i][j]=hypot(a[i].x-a[j].x,a[i].y-a[j].y);
                dp[i][j]=inf;
            }
        dp[0][0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]+g[i-1][i]);
                dp[i][i-1]=min(dp[i][i-1],dp[i-1][j]+g[i][j]);
            }
        }
        for(int i=0;i<n;i++)
            dp[n-1][n-1]=min(dp[n-1][n-1],dp[n-1][i]+g[i][n-1]);
        printf("%.2f\n",dp[n-1][n-1]);
    }
}
