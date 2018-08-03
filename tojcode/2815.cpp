#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int r,c;int sx,sy;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int tt[51][51];
struct node
{
    int x,y,cost;
    //bool vis[51][51];
    friend bool operator<(node aa,node bb)
    {
        return aa.cost>bb.cost;
    }
}now,next;
char map[51][51];
priority_queue<node> q;
int bfs()
{
    while(!q.empty())q.pop();
    //memset(now.vis,0,sizeof(now.vis));
    memset(tt,-1,sizeof(tt));
    tt[sx][sy]=0;
    now.x=sx;now.y=sy;now.cost=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(map[now.x][now.y]=='$')
            return now.cost;
        //for(int i=0;i<r;i++)for(int j=0;j<c;j++)next.vis[i][j]=now.vis[i][j];
        for(int i=0;i<4;i++)
        {
           next.x=now.x+dir[i][0];
           next.y=now.y+dir[i][1];
           if(next.x<0||next.y<0||next.x>=r||next.y>=c)continue;
           if(map[next.x][next.y]=='1')continue;
           //if(next.vis[next.x][next.y])continue;
           //next.vis[next.x][next.y]=1;
           if(map[next.x][next.y]=='D')
              next.cost=now.cost+1;
           else
              next.cost=now.cost;
           if(next.cost<tt[next.x][next.y]||tt[next.x][next.y]==-1)
           {
             tt[next.x][next.y]=next.cost;
             q.push(next);
           }
           //next.vis[next.x][next.y]=0;
        }
    }
}
int main()
{
    while(cin>>r>>c&&(r+c))
    {
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
       {
           cin>>map[i][j];
           if(map[i][j]=='S')
           {
               sx=i;sy=j;
           }
       }
       cout<<bfs()<<endl;
    }
}
