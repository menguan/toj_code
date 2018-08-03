#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dir[12][2]={1,0,2,0,3,0,-1,0,-2,0,-3,0,0,1,0,2,0,3,0,-1,0,-2,0,-3};
int visit[60][60];
char map[60][60];
struct f 
{
  int x,y;
  int step;
}now,next,s,e;  
int r,c;
int bfs()
{
  queue<f> q;
  now.x=s.x;now.y=s.y;now.step=0;
  visit[now.x][now.y]=1;
  q.push(now);
  while(!q.empty())
  {
    now=q.front();
    q.pop();
    
    if(now.x==e.x&&now.y==e.y)
      return now.step;
    for(int i=0;i<12;i++)
    {
      next.x=now.x+dir[i][0];
      next.y=now.y+dir[i][1];  //cout<<next.x<<" "<<next.y<<endl;;
      if(next.x<0||next.x>=r||next.y<0||next.y>=c)
      {
        continue;
      }
      if(visit[next.x][next.y]==1)
        continue;
      if(map[next.x][next.y]=='X')
        continue;  
      visit[next.x][next.y]=1;
        next.step=now.step+1;
      q.push(next);  
    }
  }
  return -1;
}      
              
    
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    memset(visit,0,sizeof(visit));
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        cin>>map[i][j];
        if(map[i][j]=='S')
          s.x=i,s.y=j;
        else if(map[i][j]=='R')
          e.x=i,e.y=j;
      }
    }
    cout<<bfs()<<endl;
  }
}          
            
     