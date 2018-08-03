#include<iostream>
#include<queue>
#include<cstring>
using namespace std;int n;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool visit[300][300];
int a[300][300];
int b[300][300];
struct f
{
  int x;int y;
  int step;
  bool is;
}now,next;  
  
int bfs(int xx,int yy)
{
  queue<f> q;
  memset(visit,0,sizeof(visit));
  visit[xx][yy]=1;
  now.x=xx;
  now.y=yy;int record=0;int get;
  now.step=0;
  now.is=0;
  q.push(now);
  while(!q.empty())
  {
    now=q.front();
    q.pop();
    
    if(now.is==1)
    {
      
      
      if(record==0)
      {record=now.step;get=a[now.x][now.y];}
      else if(record<now.step)
      {
        	
        return get;
      }
      else if(record==now.step)
      {
      
        return 0;
      }  
      
      continue;
    }
    else
    for(int i=0;i<4;i++)
    {
      next.x=now.x+dir[i][0];
      next.y=now.y+dir[i][1];
      next.step=now.step+1;
      if(next.x>=n||next.x<0||next.y>=n||next.y<0)
        continue;
      if(visit[next.x][next.y])
        continue;
      visit[next.x][next.y]=1;
      if(a[next.x][next.y]!=0){//cout<<next.x<<" "<<next.y<<endl;
        next.is=1;
       }
       else
         next.is=0;
     q.push(next);
   }
 }
 if(record)
   return get;
 else
   return 0;
}              
        
        
        
      
      
  
int main()
{
  
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[i][j])
      {
        b[i][j]=a[i][j];
      }
      else
      {
        
        b[i][j]=bfs(i,j);
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(j!=0)
        cout<<" ";
      cout<<b[i][j];
    }
    cout<<endl;
  }
  //while(1);
}        
                
      