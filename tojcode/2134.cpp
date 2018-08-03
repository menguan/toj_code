#include <iostream>//懒得写了 
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 110

int n,m;
double g[N][N];

void floyd()
{
for(int k=1;k<=n;k++)
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
if(g[i][j]<g[i][k]*g[k][j])
{
g[i][j]=g[i][k]*g[k][j];
}
}
}
int main()
{
while(scanf("%d",&n)!=EOF&&n)
{
scanf("%d",&m);
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
if(i==j) g[i][j]=1;
else
g[i][j]=0;
}
for(int i=0;i<m;i++)
{
int x,y,key;
scanf("%d%d%d",&x,&y,&key);
g[x][y]=g[y][x]=(double )key/100;
}
floyd();
printf("%.6lf percent\n",g[1][n]*100);
}
return 0;
}
