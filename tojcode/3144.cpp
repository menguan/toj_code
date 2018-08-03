#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mx[8]={1,1,1,0,0,-1,-1,-1};
const int my[8]={1,0,-1,1,-1,1,0,-1};
inline int read()
{
       int x=0,f=1;char ch=getchar();
       while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
       while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
       return x*f;
}
struct point{
       int x,y,t;
}dat[500000];
int n,m,ans;
int a[1100][1100];
bool mark[1100][1100];
inline void dfs(int x,int y)
{
    mark[x][y]=1;
    for(int k=0;k<8;k++)
    {
         int nx=x+mx[k];
         int ny=y+my[k];
         if(nx>0&&ny>0&&nx<=n&&ny<=m&&a[x][y]>=a[nx][ny]&&!mark[nx][ny])
           dfs(nx,ny);
    }
}
inline bool cmp(point a,point b)
{
       return a.t>b.t;
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
        int now=(i-1)*m+j;
        a[i][j]=read();
        dat[now].t=a[i][j];
        dat[now].x=i;
        dat[now].y=j;
      }
    sort(dat+1,dat+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
       int x=dat[i].x;
       int y=dat[i].y;
       if(!mark[x][y])
       {
         dfs(x,y);
         ans++;
       }
    }
    printf("%d\n",ans);
  //  while(1);
}                                
       
