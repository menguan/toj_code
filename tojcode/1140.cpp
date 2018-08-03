#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dir[6][3]={1,0,0,0,1,0,0,0,1,-1,0,0,0,-1,0,0,0,-1};
char map[40][40][40];
bool flag[40][40][40];
struct f
{
  int x,y,z;
  int time;
} a,b;
int sx,sy,sz,ex,ey,ez;int l,r,c;
int bfs()
{
  queue<f> q;
  flag[sx][sy][sz]=1;
  a.x=sx;
  a.y=sy;
  a.z=sz;
  a.time=0;
  q.push(a);
  while(!q.empty())
  {
    a=q.front();
    q.pop();
    if(a.x==ex&&a.y==ey&&a.z==ez)
      return a.time;
    for(int i=0;i<6;i++)
    {
      b.x=a.x+dir[i][0];
      b.y=a.y+dir[i][1];
      b.z=a.z+dir[i][2];
      if(b.x>=l||b.x<0||b.y>=r||b.y<0||b.z>=c||b.z<0)
        continue;
      if(map[b.x][b.y][b.z]=='#')
        continue;
      if(flag[b.x][b.y][b.z])
        continue;
      flag[b.x][b.y][b.z]=1;
      b.time=a.time+1;
      q.push(b);
    }
  }
  return 0;
}          
      
int main()
{
  while(cin>>l>>r>>c)
  {
    if(l==0&&r==0&&c==0)
      return 0;
    memset(map,'.',sizeof(map));
    memset(flag,0,sizeof(flag));
    for(int i=0;i<l;i++)
    {
      for(int j=0;j<r;j++)
      {
        for(int k=0;k<c;k++)
        {
          cin>>map[i][j][k];
          if(map[i][j][k]=='S')
          {
            sx=i;
            sy=j;
            sz=k;
          }
          if(map[i][j][k]=='E')
          {
            ex=i;
            ey=j;
            ez=k;
          }
        }
      }        
    }
    int ans=bfs();
    if(ans)
    {
      cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
    }
    else
      cout<<"Trapped!"<<endl;
  }
}        

          
      

  
