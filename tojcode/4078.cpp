#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool map[110][3];
bool visit[110][3];
struct f
{
       int x;int y;
}now,next;

       
bool bfs()
{
     queue<f> q;
     visit[0][0]=1;
     now.x=0;
     now.y=0;
     q.push(now);
     while(!q.empty())
     {
        now=q.front();
        q.pop();
        //cout<<now.x<<" "<<now.y<<endl;
        if(now.x==100&&now.y==0)
        {
          return 1;
          }
          if(map[now.x+1][now.y]==1||map[now.x+2][now.y]==1||map[now.x+3][now.y]==1)
          if(map[now.x+1][now.y+1]==0 &&map[now.x+2][now.y+2]==0 &&map[now.x+3][now.y+1]==0 &&map[now.x+4][now.y]==0)      
        {
           next.x=now.x+4;
           next.y=now.y;
           if(visit[next.x][next.y]==1)
              continue;
            if(next.x>100)
              continue; 
              visit[next.x][next.y]=1;
            q.push(next);
            }
        if(map[now.x+1][now.y]==0)
        {next.x=now.x+1;
            next.y=now.y;
            if(visit[next.x][next.y]==1)
              continue;
            if(next.x>100)
              continue;  
            
            visit[next.x][next.y]=1;
            q.push(next);
            }
        
            }
            return 0;} 
                                                                                                                 
int main()
{
    int n;int x,y;
    while(cin>>n)
    {
       memset(map,0,sizeof(map)); 
       memset(visit,0,sizeof(visit));         
       for(int i=0;i<n;i++)
       {
          cin>> x>>y;
          map[x][y]=1;
          }
       
       
         cout<<bfs()<<endl;
       
}
}       
                      