#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char map[2000][2000];
bool flag[2000][2000];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int m,n;
struct f
{
  int x,y;
  int len;
}now,next,maxn;
int sx,sy;
void dfs()
{
  queue<f>q;
  maxn.len=-1;
  now.x=sx;
  now.y=sy;
  flag[sx][sy]=1;
  now.len=0;
  q.push(now);
  while(!q.empty())
  {
    now=q.front();
    q.pop();
    if(now.len>maxn.len)
    {
      maxn.len=now.len;
      maxn.x=now.x;
      maxn.y=now.y;
    }
    for(int i=0;i<4;i++)
    {
      next.x=now.x+dir[i][0];
      next.y=now.y+dir[i][1];
      if(next.x<0||next.x>=m||next.y<0||next.y>=n)  continue;
      if(map[next.x][next.y]=='#')  continue;
      if(flag[next.x][next.y])  continue;
      
      flag[next.x][next.y]=1;
      next.len=now.len+1;
      q.push(next);
    }
  }     
}  
  
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    memset(flag,0,sizeof(flag));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin>>map[i][j];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(map[i][j]=='.')
      {  sx=i,sy=j;}
    dfs();
    sx=maxn.x;
    sy=maxn.y;
    memset(flag,0,sizeof(flag));
    dfs();
    cout<<"Maximum rope length is "<<maxn.len<<"."<<endl;
  }
}    
   
     