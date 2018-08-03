#include<iostream>
#include<queue>
#include<cstring>
#include<stdio.h>
using namespace std;
int minn;
bool visit[1000000];int m,a,b;int st,en;
struct f
{
  int x;
  int step;
}now,next;  
int bfs()
{
       queue<f>q;
       visit[st]=1;
       now.x=st;
       now.step=0;
       q.push(now);
       while(!q.empty())
       {
           now=q.front();
           q.pop();
           if(now.x==en)
           {
                         
                         return now.step;
           }
           next.x=now.x+1;
           if(next.x>m)
             next.x=m;
           if(!visit[next.x])
           {
             visit[next.x]=1;
             next.step=now.step+1;
             q.push(next);
             }
           next.x=now.x-1;
           if(next.x>=0&&!visit[next.x])
           {
             visit[next.x]=1;
             next.step=now.step+1;
             q.push(next);
             }        
           next.x=now.x*2;
           if(next.x>m)
             next.x=m;
           if(!visit[next.x])
           
           {
             visit[next.x]=1;
             next.step=now.step+1;
             q.push(next);
             }
             
            
             }
      
}                                              
                                                              
int main()
{
     
     while(cin>>m>>a>>b)
     {
       memset(visit,0,sizeof(visit));
       st=a;
       en=b;
       
       
       
        int ans=bfs();
        cout<<ans<<endl;                                                                
       
       }
}        
