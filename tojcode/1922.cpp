#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool visit[30][30];
char map[30][30];
int dir[8][2]={1,0,0,1,-1,0,0,-1,1,-1,-1,1,1,1,-1,-1};
int cdir[4][2]={1,0,0,1,-1,0,0,-1};
int m,n;
int cir,area;
double sum; 
struct f
{
  int x,y;
}now,next;  
void bfs(int xx,int yy)
{
  cir=0;
  area=1;
  visit[xx][yy]=1;
  queue<f>q;
  now.x=xx;
  now.y=yy;
  q.push(now);
  while(!q.empty())
  {
    now=q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
      if(map[now.x+cdir[i][0]][now.y+cdir[i][1]]!='X')
        cir++;
    }
    for(int i=0;i<8;i++)
    {
      next.x=now.x+dir[i][0];
      next.y=now.y+dir[i][1];
      if(next.x<1||next.x>m||next.y<1||next.y>n||visit[next.x][next.y])
        continue;
      if(map[next.x][next.y]!='X')
        continue;
      
      visit[next.x][next.y]=1;
      
      q.push(next);
    }
  }
}      int sx,sy;        
int main()
{
  while(cin>>m>>n>>sx>>sy&&(m+n+sx+sy))
  {
     memset(map,0,sizeof(map));
     memset(visit,0,sizeof(visit));
     for(int i=1;i<=m;i++)
     {
       for(int j=1;j<=n;j++)
       {
         cin>>map[i][j];
       }
     }
     sum=0;
     bfs(sx,sy);
     cout<<cir<<endl;
  }
}       
            