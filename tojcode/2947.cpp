#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
struct node
{
  int x;int y;
  int step;
  char map[60][60];
}now,next,st,en;
int f[3600][2];
bool vis[60][60];
int r,c;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int ok(node & kk)
{
  if(kk.x>=1&&kk.x<=r&&kk.y>=1&&kk.y<=c&&kk.map[kk.x][kk.y]!='X'&&kk.map[kk.x][kk.y]!='*')
    return 1;
  return 0;
}
void tian(node &kk)
{
  int cnt=0;
  for(int i=1;i<=r;i++)
  {
    for(int j=1;j<=c;j++)
    {
      if(kk.map[i][j]=='*')
      {
        f[cnt][0]=i;f[cnt][1]=j;
        cnt++;
      }
    }
  }
  int x,y;
  for(int i=0;i<cnt;i++)
  {
    for(int j=0;j<4;j++)
    {
      x=f[i][0]+dir[j][0];
      y=f[i][1]+dir[j][1];
      if(x>=1&&x<=r&&y>=1&&y<=c&&kk.map[x][y]!='X'&&kk.map[x][y]!='*'&&kk.map[x][y]!='D')
        kk.map[x][y]='*';
    }
  }
}
int bfs()
{
  queue<node> q;
  st.step=0;
  memset(vis,0,sizeof(vis));
  q.push(st);
  while(!q.empty())
  {
    now=q.front();
    q.pop();
    if(vis[now.x][now.y])  continue;
    vis[now.x][now.y]=1;
    //cout<<now.x<<" "<<now.y<<" "<<now.step<<endl;
    if(now.x==en.x&&now.y==en.y)
      return now.step;
    tian(now);
    memcpy(next.map,now.map,sizeof(next.map));
    next.step=now.step+1;
    for(int i=0;i<4;i++)
    {
      next.x=now.x+dir[i][0];
      next.y=now.y+dir[i][1];
      if(ok(next))
      {
        //cout<<next.x<<" "<<next.y<<" "<<next.map[next.x][next.y]<<endl;
        q.push(next);
      }
    }
  }
  return -1;
}  
int main()
{
   cin>>r>>c;
   for(int i=1;i<=r;i++)
   {
     for(int j=1;j<=c;j++)
     {
       cin>>now.map[i][j];
       if(now.map[i][j]=='S')
       {  st.x=i;st.y=j;}
       if(now.map[i][j]=='D')
       {  en.x=i;en.y=j;}
     }
   }
   memcpy(st.map,now.map,sizeof(now.map));
   int ans=bfs();
   if(ans==-1)
     cout<<"KAKTUS"<<endl;
   else
     cout<<ans<<endl;
   //while(1);
}  
        