#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[1200][1200];
char map[1200][1200];
int dir[8][2]={1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
int sx,xx,zy,yy;int cnt;int r,c;
void dfs(int x,int y)
{
     //cout<<x<<" "<<y<<" "<<sx<<" "<<xx<<" "<<zy<<" "<<yy<<endl;
     vis[x][y]=1;
     cnt++;
     if(x>xx)
       xx=x;
     if(x<sx)
       sx=x;
     if(y>yy)
       yy=y;
     if(y<zy)
       zy=y;
     //cout<<x<<" "<<y<<" "<<sx<<" "<<xx<<" "<<zy<<" "<<yy<<endl;  
     for(int k=0;k<8;k++)
     {
         int tx=x+dir[k][0];
         int ty=y+dir[k][1];
         if(tx<1||ty<1||tx>r||ty>c) continue;
         if(map[tx][ty]=='.') continue;
         if(vis[tx][ty]==1)  continue;
           dfs(tx,ty);
     }            
}     
int main()
{
    
    bool flag;
    while(cin>>r>>c&&(r+c))
    {
        for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
          cin>>map[i][j];
        memset(vis,0,sizeof(vis));
        flag=1;int ans=0;
        for(int i=1;i<=r;i++)
        { 
           if(!flag)
             break;
           for(int j=1;j<=c;j++)
           {
              if(!flag)
                break;
              if(!vis[i][j]&&map[i][j]=='#')
              {
                 ans++;
                 cnt=0;
                 sx=1200;xx=-1;zy=1200;yy=-1;
                 //cout<<i<<" "<<j<<endl;
                 dfs(i,j);
                 //cout<<sx<<" "<<xx<<" "<<zy<<" "<<yy<<" "<<cnt<<endl;
                 if((xx-sx+1)*(yy-zy+1)!=cnt)
                   flag=0;
              }
           }
        }
        if(flag)
          cout<<"There are "<<ans<<" ships."<<endl;
        else 
          cout<<"Bad placement."<<endl;
    }
}
                        
                                         
                             
