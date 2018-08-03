#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int f[ 31 ][ 31 ];
int main()
{
  memset(f,0,sizeof(f) );
  for(int i=1;i<=30;i++)f[i][0] = i;
  for(int i=1;i<=30;i++)
  {
    for(int j=1;j<i;j++)
    {
      f[i][j] = f[ i - 1  ][ j - 1 ] + 1 + f[ i - 1 ][j];
    }
    for(int j=i;j<=30;j++)
       f[i][j] = f[i][i-1];
  }
  int n,m,cas=1;
  while( scanf("%d%d",&n,&m) && (m+n) )
  {
      printf("Case %d: %d\n",cas++,f[n][m]);
  }
}
