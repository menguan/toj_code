#include<iostream>
#include<cstring>
using namespace std;
int map[60][60];
bool vis[60][60];
int r,c;
int ans=0;
int dir[8][2]={1,-1,-1,1,1,1,-1,-1,0,1,1,0,0,-1,-1,0};
void dfs(int x,int y,int now)
{
     if(now>1)
     {  
        if(map[x][y]>ans)
          ans=map[x][y];
     }           
     vis[x][y]=1;
     for(int i=0;i<8;i++)
     {
         int nx=x+dir[i][0];
         int ny=y+dir[i][1];
         if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&!vis[nx][ny]&&map[nx][ny]==map[x][y])
           dfs(nx,ny,now+1);
     }
     return ;
}    
int main()
{
    memset(vis,0,sizeof(vis));
    cin>>r>>c;
    ans=0;
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
      cin>>map[i][j];
    for(int i=1;i<=r;i++)
    {
     for(int j=1;j<=c;j++)
     {
         if(!vis[i][j])
         {
            dfs(i,j,1);
         }
     }
    }
    cout<<ans<<endl;                         
  //  while(1);
}        
              
