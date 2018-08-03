#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool flag[110][110];
bool map[110][110];
int sx,sy,ex,ey;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
int c,l;
struct f
{
  int x;int y;
  int step;
}now,next;
int bfs()
{
   queue<f>q;
   now.x=sx;
   now.y=sy;
   now.step=1;
   flag[sx][sy]=1;
   q.push(now);
   while(!q.empty())
   {
     now=q.front();
     q.pop();
     if(now.x==ex&&now.y==ey)
       return now.step;
     for(int i=0;i<4;i++)
     {
       next.x=now.x+dir[i][0];
       next.y=now.y+dir[i][1];
       if(next.x>=c||next.x<0||next.y>=l||next.y<0)  continue;
       if(flag[next.x][next.y])  continue;
       if(map[next.x][next.y])  
       {
         flag[next.x][next.y]=1;
         continue;
       }  
       
       flag[next.x][next.y]=1;
       next.step=now.step+1;
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
    memset(map,0,sizeof(map));
    memset(flag,0,sizeof(flag));
    cin>>c>>l;
    for(int i=0;i<l;i++)
    {
      for(int j=0;j<c;j++)
      {
        cin>>map[j][i];
      }
    }
    cin>>sx>>sy>>ex>>ey;
    cout<<bfs()<<endl;
  }
}    
    
        
  