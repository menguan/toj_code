#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
char map[35][35];
bool vis[35][35];
int ansx[1000],ansy[1000];
int n;int sum;
bool flag;
int se[8][2]={0,1,1,0,-1,0,0,-1,1,1,1,-1,-1,1,-1,-1};
int go[8][2]={0,2,2,0,-2,0,0,-2,2,2,2,-2,-2,2,-2,-2};
void dfs(int x,int y,int dep)
{
    //cout<<x<<" "<<y<<" "<<dep<<endl;
    if(flag) return ;
    ansx[dep]=x;ansy[dep]=y;
    if(dep==sum+1)
    {
        flag=1;
        return ;
    }
    int tx,ty;int ttx,tty;
    for(int i=0;i<8;i++)
    {
        if(flag) return ;
        tx=x+se[i][0];
        ty=y+se[i][1];
        if(tx<1||ty<1||tx>n||ty>n)
            continue;
        if(map[tx][ty]=='o')
        {
            if(vis[tx][ty]==1)  continue;
            ttx=tx+se[i][0];
            tty=ty+se[i][1];
            if(ttx<1||tty<1||ttx>n||tty>n)
                continue;
            if(map[ttx][tty]=='+')
            {
                vis[tx][ty]=1;
                swap(map[x][y],map[ttx][tty]);
                dfs(ttx,tty,dep+1);
                vis[tx][ty]=0;
                swap(map[x][y],map[ttx][tty]);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    flag=0;
    for(int i=1;i<=n;i++)
        scanf("%s",map[i]+1);
    sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //cout<<map[i][j];
            if(map[i][j]=='o')
                sum++;
        }
        //cout<<endl;
    }
    int tx,ty;
    for(int i=1;i<=n;i++)
    {
        if(flag) break;
        for(int j=1;j<=n;j++)
        {
            if(flag) break;
            if(map[i][j]=='o')
            {
                for(int k=0;k<8;k++)
                {
                   tx=i+se[k][0];
                   ty=j+se[k][1];
                   if(tx<1||ty<1||tx>n||ty>n)
                            continue;
                   if(map[tx][ty]=='K')
                   {
                       //cout<<"kk"<<endl;
                       dfs(tx,ty,1);
                   }
                }
            }
        }
    }
    if(!flag)
         puts("impossible");
    else{
        for(int i=1;i<=sum+1;i++)
            printf("%d %d\n",ansx[i],ansy[i]);
    }

}
