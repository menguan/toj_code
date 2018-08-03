#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool visit[10][10][10];
char map[10][10][10];
int dir[6][3]={1,0,0,0,1,0,0,0,1,-1,0,0,0,-1,0,0,0,-1};
int m,n,o;
int cir,area;
double sum; 
struct f
{
  int x,y,z;
}now,next;  
void bfs(int xx,int yy,int zz)
{
  cir=0;
  area=1;
  visit[xx][yy][zz]=1;
  queue<f>q;
  now.x=xx;
  now.y=yy;
  now.z=zz;
  q.push(now);
  while(!q.empty())
  {
    now=q.front();
    q.pop();
    for(int i=0;i<6;i++)
    {
      if(map[now.x+dir[i][0]][now.y+dir[i][1]][now.z+dir[i][2]]!='X')
        cir++;
    }
    for(int i=0;i<6;i++)
    {
      next.x=now.x+dir[i][0];
      next.y=now.y+dir[i][1];
      next.z=now.z+dir[i][2];
      if(next.z<1||next.z>o||next.x<1||next.x>m||next.y<1||next.y>n||visit[next.x][next.y][next.z])
        continue;
      if(map[next.x][next.y][next.z]!='X')
        continue;
      
      visit[next.x][next.y][next.z]=1;
      area++;
      q.push(next);
    }
  }
}              
int main()
{
  while(cin>>m>>n>>o&&(m+n+o))
  {
     memset(map,0,sizeof(map));
     memset(visit,0,sizeof(visit));
     for(int k=1;k<=o;k++)
     for(int i=1;i<=m;i++)
     {
       for(int j=1;j<=n;j++)
       {
         cin>>map[i][j][o];
       }
     }
     sum=0;
     for(int k=1;k<=o;k++)
     for(int i=1;i<=m;i++)
     {
       for(int j=1;j<=n;j++)
       {
         if(!visit[i][j][k]&&map[i][j][k]=='X')
         {
           bfs(i,j,k);
           sum=sum+cir*1.0/area;
         }  
       }
     }
     if(sum<=m*n*1.0/4)
       cout<<"YES"<<endl;
     else
       cout<<"NO"<<endl;
  }
}       
            