#include<stdio.h>//和之前组队练习赛的一道题类似 懒得打了 
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXD = 105;

int inc[MAXD][MAXD], ex[MAXD][MAXD];
int f[MAXD][MAXD];
int n, m;
int ans; 
int main()
{
    while( scanf( "%d%d", &n, &m) != EOF)
    {
    if( n == m && m == 0) break;
    for( int i = 1; i <= n; i ++)
        for( int j = 1; j <= n; j ++)
            scanf( "%d", &ex[i][j]); 
    for( int i = 1; i <= m; i ++)
        for( int j = 1; j <= n; j ++)
            scanf( "%d", &inc[i][j]); 
    memset( f, 0, sizeof f);
    for( int j = 1; j <= n; j ++)
        f[1][j] = inc[1][j] - ex[1][j];
    for( int i = 2; i <= m; i ++)
        for( int j = 1; j <= n; j ++)
            for( int k = 1; k <= n; k ++)
                f[i][j] = max( f[i][j], f[i - 1][k] + inc[i][j] - ex[k][j]);
    ans = 0;
    for( int i = 1; i <= n; i ++)
        if( ans < f[m][i]) ans = f[m][i];
    printf( "%d\n", ans);
    }
}
