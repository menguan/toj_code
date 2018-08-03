#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define le 502
int dp[le][le],west[le][le],north[le][le];
int r,c;
int main(void){
    while(scanf("%d%d",&r,&c)==2&&r+c){
        int i,j;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            west[i][j]=north[i][j]=0;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++){
            scanf("%d",&west[i][j]);
            west[i][j]+=west[i][j-1];
        }
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++){
            scanf("%d",&north[i][j]);
            north[i][j]+=north[i-1][j];
        }
    for(i=0;i<=r;i++)   dp[i][0]=0;
    for(j=0;j<=c;j++)   dp[0][j]=0;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            dp[i][j]=max(dp[i][j-1]+north[i][j],dp[i-1][j]+west[i][j]);
       cout<<dp[r][c]<<endl;
    }
    return 0;
}
