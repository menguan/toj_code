#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long map[30][30];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int w,h;int n;int x1,x2,y1,y2;
void dfs(int x,int y,int s)
{
    map[x][y]=-1;
    for(int i=0;i<4;i++)
    {
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0||xx>=h||yy<0||yy>=w)
            continue;
        if(map[xx][yy]==s)
            dfs(xx,yy,s);
    }
}
int main()
{
    while(cin>>w>>h&&(w+h))
    {
        memset(map,0,sizeof(map));
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            if(x1>x2)swap(x1,x2);
            if(y1>y2)swap(y1,y2);
            for(int ii=x1;ii<x2;ii++)
                for(int j=y1;j<y2;j++)
                   map[ii][j]+=(1<<i);
        }
        int ans=0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(map[i][j]>=0)
                {
                    dfs(i,j,map[i][j]);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
