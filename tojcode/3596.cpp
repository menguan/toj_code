#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <iostream>
using namespace std; 
 
const int MAX = 123456789; 
int val[110],tim[110],dp[110][1010]; 
int main() 
{ 
    int t; 
    scanf("%d",&t); 
    while(t--) 
    { 
        int n,m,l; 
        scanf("%d%d%d",&n,&m,&l); 
        int i,j,k; 
        for(i = 0; i<n; i++) 
            scanf("%d%d",&tim[i],&val[i]); 
        for(i = 0; i<=m; i++) 
        { 
            for(j = 0; j<=l; j++) 
            { 
                if(i==0) 
                    dp[i][j] = 0; 
                else 
                    dp[i][j] = -MAX; //.......
            } 
        } 
        for(i = 0; i<n; i++)  
        { 
            for(j = m; j>=1; j--) 
            { 
                for(k = l; k>=tim[i]; k--) 
                { 
                    dp[j][k] = max(dp[j][k],dp[j-1][k-tim[i]]+val[i]); 
                } 
            } 
        } 
        if(dp[m][l]<0) 
            dp[m][l] = 0; 
        printf("%d\n",dp[m][l]); 
    } 
 
    return 0; 
} 
