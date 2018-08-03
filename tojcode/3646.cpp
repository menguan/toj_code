#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int map[310][1010];
bool vis[1100];
int main()
{
  int r,c,m;
  int x,y,xx,yy;
  while(scanf("%d%d%d",&r,&c,&m)!=EOF)
  {
    memset(vis,0,sizeof(vis));
    memset(map,-1,sizeof(map));
    for(int i=0;i<m;i++)
    {
      scanf("%d%d%d%d",&x,&y,&xx,&yy);
      if(x>xx)
        swap(x,xx);
      if(y>yy)
        swap(y,yy);
      for(int j=x;j<=xx;j++)
        for(int k=y;k<=yy;k++)
          map[j][k]=i;
    }int cc=0;
    for(int i=1;i<=r;i++)
    {
      for(int j=1;j<=c;j++)
      {
        if(map[i][j]!=-1&&!vis[map[i][j]])
        {
          vis[map[i][j]]=1;
          cc++;
        }
      }
    }
    printf("%d\n",m-cc);
  }
}         
   