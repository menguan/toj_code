#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
char ans[100000];
int map[220][200];
bool vis[220][220];
int r,c;int sx,sy;
int cnt;bool flag;
void dfs(int x,int y,int dep)
{
     //cout<<"kk"<<x<<" "<<y<<" "<<map[x][y]<<endl;
     //system("pause");
     if(flag)
       return ;
     if(vis[x][y]) return ;
     vis[x][y]=1;
     
     if(map[x][y]==1)
     {
       
       return ;
     }
     if(x==1||y==1||x==r||y==c)
     {
         flag=1;//cout<<x<<" "<<y<<" "<<dep<<endl;
         if(x==1)
           ans[dep]='U';
         else if(y==1)
           ans[dep]='L';
         else if(x==r)
           ans[dep]='D';
         else if(y==c)
           ans[dep]='R';      
         cnt=dep;
         return ;
     }
     ans[dep]='U';
     dfs(x-1,y,dep+1);
     if(flag) return;
     ans[dep]='R';
     dfs(x,y+1,dep+1);
     if(flag) return;
     ans[dep]='D';
     dfs(x+1,y,dep+1);
     if(flag) return ;
     ans[dep]='L';
     dfs(x,y-1,dep+1);
     return ;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>r>>c;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>map[i][j];
            }
        }
        cin>>sx>>sy;
        flag=0;
        dfs(sx,sy,0);
        for(int i=0;i<=cnt;i++)
        {
          if(i) cout<<" ";
          cout<<ans[i];
        }
        cout<<endl;
    }
}                
    
    
