#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[1000][1000];
int dir[4][2]={1,0,0,1,0,-1,-1,0};
char s[300];
int w,h;int xx,yy;
int dep;
void dfs(int x,int y,int &flag)
{
    for(int i=0;i<4;i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        if(xx<0||xx>=3*h||yy<0||yy>=3*w)
        {
            flag=0;
            continue;
        }
        else
        {
          if(!map[xx][yy])
          {
              dep++;
              map[xx][yy]=1;
              dfs(xx,yy,flag);
          }
        }

    }
}
int main()
{
    int cas=1;
    while(cin>>w>>h&&(w+h))
    {
        memset(map,0,sizeof(map));
        for(int i=0;i<h;i++)
        {
            cin>>s;
            for(int j=0;j<w;j++)
            {
                if(s[j]=='\\')
                {
                    map[3*i][3*j]=map[3*i+1][3*j+1]=map[3*i+2][3*j+2]=1;
                }
                else
                {
                    map[3*i+2][3*j]=map[3*i+1][3*j+1]=map[3*i][3*j+2]=1;
                }
            }
        }
        int maxn=0;int flag;int ans=0;
        for(int i=0;i<3*h;i++)
        {
            for(int j=0;j<3*w;j++)
            {
                if(!map[i][j])
                {
                    dep=flag=1;
                    dfs(i,j,flag);
                    if(flag)
                    {
                        ans++;
                        maxn=max(maxn,dep);
                    }
                }
            }
        }
        cout<<"Maze #"<<cas++<<":"<<endl;
        if(ans)
            cout<<ans<<" Cycles; the longest has length "<<maxn/3<<"."<<endl;
        else
            cout<<"There are no cycles."<<endl;
        cout<<endl;
    }
}
