#include <iostream>//水题
#include <stdio.h>
#include <string.h>
using namespace std;
char b[2001][2001];
bool vis[2001],flag;
int dis[2001],n;
void dfs(int dep)
{
    if(flag) return;
    vis[dep]=1;
    int i;
    for(i=1;i<=n;i++)
      if(b[dep][i]=='1')
      {
         if(vis[i]&&dis[dep]==dis[i]+2)
         {
           flag=1;
           break;
         }
          else if(!vis[i])
          {
            dis[i]=dis[dep]+1;
            dfs(i);
          }
      }
}
int main()
{
    int t,cnt=1;
    int i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
         {    
             scanf("%s",b[i]+1);
         }
          flag=0;dis[1]=0;
          dfs(1);
          printf("Case #%d: ",cnt++);
          if(flag) printf("Yes\n");
          else printf("No\n");
    }
}
