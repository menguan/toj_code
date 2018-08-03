#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[40][40];
bool vis[40][40];
int dir[4][2]={1,1,1,-1,-1,1,-1,-1};
int m,n,mm[2],sx,sy,tx,ty;
int bfs()
{
    queue<int> q;
    q.push(sx);q.push(sy);q.push(0);
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;
    int x,xx,y,yy,step;
    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        step=q.front();q.pop();
        if(x==tx&&y==ty)
            return step;
        for(int j=0;j<2;j++)
        for(int i=0;i<4;i++)
        {
            xx=x+dir[i][0]*mm[j%2];
            yy=y+dir[i][1]*mm[(j+1)%2];
            if(xx>=m||yy>=n||xx<0||yy<0) continue;
            if(map[xx][yy]==0||map[xx][yy]==2)continue;
            if(vis[xx][yy])continue;
            vis[xx][yy]=1;
            q.push(xx);q.push(yy);q.push(step+1);
        }

    }
    return -1;
}
int main()
{
    while(
    cin>>m>>n>>mm[0]>>mm[1]
    ){
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
           cin>>map[i][j];
           if(map[i][j]==3){sx=i;sy=j;}
           if(map[i][j]==4){tx=i;ty=j;}
        }
    cout<<bfs()<<endl;
    }
}
