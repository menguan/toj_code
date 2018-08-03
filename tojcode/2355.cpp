#include <cmath>//这个水题实在是懒得打了
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
  int h;
  char sex;
  char mus[110];
  char spo[110];
}M[510],F[510];
int n,m,f,mmap[550][550],pre[550],vis[550];
int pd(int i,int j)
{
  if( abs(M[i].h - F[j].h) > 40 )
    return 0;
  if( strcmp(M[i].mus,F[j].mus) )
    return 0;
  if( strcmp(M[i].spo,F[j].spo) == 0 )
    return 0;
  return 1;
}
int dfs(int x)
{
  for(int i=m+1;i<=m+f;i++){
    if(!vis[i]&&mmap[x][i]){
      vis[i]=1;
      if(pre[i]==-1||dfs(pre[i])){
        pre[i]=x;
        return 1;
      }
    }
  }
  return 0;
}
int main()
{
  int i,j,t,h;
  char str[100];
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    m=f=1;
    memset(mmap,0,sizeof(mmap));
    memset(pre,-1,sizeof(pre));
    memset(M,0,sizeof(M));
    memset(F,0,sizeof(F));
    for(i=1;i<=n;i++){
      scanf("%d%s",&h,str);
      if(str[0]=='M'){
        scanf("%s%s",M[m].mus,M[m].spo);
        M[m].h=h;
        M[m++].sex='M';
      }
      else {
        scanf("%s%s",F[f].mus,F[f].spo);
        F[f].h=h;
        F[f++].sex='F';
      }
    }
    for(i=1;i<=m;i++){
      for(j=1;j<=f;j++){
        if(pd(i,j))
        mmap[i][m+j]=1;
      }
    }
    int ans=0;
    for(i=1;i<m;i++){
      memset(vis,0,sizeof(vis));
      ans+=dfs(i);
    }
    printf("%d\n",n-ans);
  }
}
