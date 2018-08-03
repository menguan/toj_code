#include<iostream>
#include<cstring>
using namespace std;
char map[60][60];
bool trap[60][60];
bool vis[60][60];
int r,c;
int ans;
int dir[4][2]={0,1,1,0,-1,0,0,-1};
void dfs(int x,int y)
{
     if(x==0||y==0||x>r||y>c)  return;
     vis[x][y]=1;
     int tx,ty;
     if(map[x][y]=='G') ans++;
     if(trap[x][y])  return ;
     for(int i=0;i<4;i++)
     {
         tx=x+dir[i][0];ty=y+dir[i][1];
         if(vis[tx][ty])  continue;
         if(map[tx][ty]=='#')  continue;
         dfs(tx,ty);
     }
}    
int main()
{
    while(cin>>c>>r)
    {
         memset(vis,0,sizeof(vis));
         memset(trap,0,sizeof(trap));
         int sx,sy;ans=0;
         for(int i=1;i<=r;i++)
         {
             for(int j=1;j<=c;j++)
             {
                 cin>>map[i][j];
                 if(map[i][j]=='P')
                   {sx=i;sy=j;}
                 else if(map[i][j]=='T')
                 {
                    trap[i+1][j]=trap[i][j+1]=trap[i-1][j]=trap[i][j-1]=1;
                 } 
             }
         }
         dfs(sx,sy);
         cout<<ans<<endl;
    }
}                      
    
