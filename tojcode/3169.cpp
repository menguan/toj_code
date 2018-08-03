#include<iostream>
#include<cstring>
using namespace std;
char map[6][6];
bool vis[6][6];
int ans;int r,c;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int k;
void dfs(int x,int y,int step)
{
     //cout<<x<<" "<<y<<" "<<step<<endl;
     if(step>k)
       return ;
     if(x==1&&y==c)
     {
        ans++;
        return ;
     }
     for(int i=0;i<4;i++)
     {
         int tx=x+dir[i][0];
         int ty=y+dir[i][1];
         if(tx<1||ty<1||tx>r||ty>c)
           continue;
         if(vis[tx][ty])
           continue;
         if(map[tx][ty]=='T')
           continue;
         vis[tx][ty]=1;
         dfs(tx,ty,step+1);
         vis[tx][ty]=0;
     }
}
                   
                  
int main()
{
    
    while(cin>>r>>c>>k)
    {
       for(int i=1;i<=r;i++)
       {
             for(int j=1;j<=c;j++)
               cin>>map[i][j];
       }
       memset(vis,0,sizeof(vis));
       ans=0;
       vis[r][1]=1;
       dfs(r,1,1);
       
       cout<<ans<<endl;
    }
}
                      
