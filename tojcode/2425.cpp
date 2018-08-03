#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
//int ge[120][120];
char map[120][120];
int dp[210][210][210];
//bool vis[120][120];
//int prex[120][120];
//int prey[120][120];
int r,c;
/*
int dir[2][2]={1,0,0,1};
int bfs()
{
    memset(prex,-1,sizeof(prex));
    memset(prey,-1,sizeof(prey));
    memset(ge,0,sizeof(ge));
    memset(vis,0,sizeof(vis)); 
    int tx,ty;int ttx,tty;
    int get;int gett;
    queue<int> q;
    q.push(1);q.push(1);
    if(map[1][1]=='*')
    {
      ge[1][1]=1;
      q.push(1);
    }
    else
      q.push(0);  
    vis[1][1]=1;
    while(!q.empty())
    {
       tx=q.front();q.pop();
       ty=q.front();q.pop();
       get=q.front();q.pop();
       for(int k=0;k<2;k++)
       {
         ttx=tx+dir[k][0];
         tty=ty+dir[k][1];
         gett=get;
         if(ttx>r||tty>c)
           continue;
         if(map[ttx][tty]=='#')
           continue;  
         if(map[ttx][tty]=='*')
           gett++;
         if(vis[ttx][tty])
         {
             if(ge[ttx][tty]<gett)
             {
                 ge[ttx][tty]=gett;
                 prex[ttx][tty]=tx;
                 prey[ttx][tty]=ty;
                 q.push(ttx);q.push(tty);q.push(gett);
             }
         }
         else
         {
           vis[ttx][tty]=1;
           ge[ttx][tty]=gett;
           prex[ttx][tty]=tx;
           prey[ttx][tty]=ty;
           q.push(ttx);q.push(tty);q.push(gett);
         }
       }
    }                                   
    return ge[r][c];       
}
*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         cin>>c>>r;
         for(int i=0;i<r;i++)
         for(int j=0;j<c;j++)
           cin>>map[i][j];
         int len=r+c-2;
         for(int i=0;i<=len;i++)
         for(int j=0;j<=r;j++)
         for(int k=0;k<=r;k++)
           dp[i][j][k]=-10101010;
         dp[0][0][0]=(map[0][0]=='*');
         for(int i=0;i<=c;i++)map[r][i]='#';
         for(int i=0;i<=r;i++)map[i][c]='#';
         for(int k=0;k<len;k++)
         {
             for(int i=0;i<=k;i++)
             {
                 if(i>=r) break;
                 if(k-i>=c) continue;
                 for(int j=0;j<=k;j++)
                 {
                    if(j>=r) break;
                    if(k-j>=c)  continue;
                    if(dp[k][i][j]<0||map[i][k-i]=='#'||map[j][k-j]=='#')
                      continue;
                    if(map[i+1][k-i]!='#'&&map[j+1][k-j]!='#')
                    {
                       int key=dp[k][i][j]+(map[i+1][k-i]=='*')+(map[j+1][k-j]=='*');
                       if(i==j&&map[i+1][k-i]=='*') key--;
                       dp[k+1][i+1][j+1]=max(dp[k+1][i+1][j+1],key);
                    }
                    if(map[i+1][k-i]!='#'&&map[j][k+1-j]!='#')
                    {
                       int key=dp[k][i][j]+(map[i+1][k-i]=='*')+(map[j][k+1-j]=='*');
                       if(i+1==j&&map[i+1][k-i]=='*') key--;
                       dp[k+1][i+1][j]=max(dp[k+1][i+1][j],key);
                    }
                    if(map[i][k+1-i]!='#'&&map[j+1][k-j]!='#')
                    {
                       int key=dp[k][i][j]+(map[i][k+1-i]=='*')+(map[j+1][k-j]=='*');
                       if(i==j+1&&map[i][k+1-i]=='*') key--;
                       dp[k+1][i][j+1]=max(dp[k+1][i][j+1],key);
                    }
                    if(map[i][k+1-i]!='#'&&map[j][k+1-j]!='#')
                    {
                       int key=dp[k][i][j]+(map[i][k+1-i]=='*')+(map[j][k+1-j]=='*');
                       if(i==j&&map[i][k+1-i]=='*') key--;
                       dp[k+1][i][j]=max(dp[k+1][i][j],key);
                    }
                 }
             }
         }
         int ans=dp[len][r-1][r-1];
         if(ans<0) ans=0;
         cout<<ans<<endl;                                                                 
         /*  
         int ans=bfs();
         //cout<<ans<<endl;
         int xx,yy;
         if(map[r][c]=='*')
           map[r][c]='.';
         if(map[1][1]=='*')
           map[1][1]='.';  
         xx=prex[r][c];yy=prey[r][c]; 
         int tx,ty;
         while(xx!=1||yy!=1)
         {
             if(map[xx][yy]=='*')
               map[xx][yy]='.';
             //cout<<xx<<" "<<yy<<endl;  
             tx=prex[xx][yy];
             ty=prey[xx][yy];
             xx=tx;
             yy=ty;
         }
         //for(int i=1;i<=r;i++)
         //{
         //   for(int j=1;j<=c;j++)
         //     cout<<map[i][j];
         //   cout<<endl;
         //}       
         ans+=bfs();                 
         cout<<ans<<endl;
         */
    }
}
         
