#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
char map[4][4];bool vis[4][4];bool used[4][4];int ans;
struct ff 
{
    int x[4],y[4];
}a[4];
struct node
{
     int x[4],y[4];
}wei;  
void dfs(int pos,ff m,int sum)
{
    if(pos==4)
    {
        ans=min(ans,sum);
        return ;
    }
    
    for(int i=0;i<4;i++)
    {
         int tx=wei.x[i],ty=wei.y[i];
         if(!vis[tx][ty])
         {
             vis[tx][ty]=1;
             for(int j=0;j<4;j++)
             {
               int ttx=m.x[j],tty=m.y[j];
               if(!used[ttx][tty])
               {      
                  //cout<<i<<" "<<j<<endl;
                  //cout<<tx<<" "<<ty<<" "<<ttx<<" "<<tty<<endl;
                  //cout<<sum<<endl;
                  //system("pause");
                  
                  used[ttx][tty]=1;
                  dfs(pos+1,m,sum+abs(tx-ttx)+abs(ty-tty));
                  used[ttx][tty]=0;
               }
             }
             vis[tx][ty]=0;
         }
    }
}                                  
int jud(ff m)
{
    memset(vis,0,sizeof(vis));
    memset(used,0,sizeof(used));
    dfs(0,m,0);
}
int f()
{
    ans=101010100;
    for(int i=0;i<3;i++)
    {
         for(int j=0;j<3;j++)
         {
              wei.x[0]=i;
              wei.y[0]=j;
              wei.x[1]=i+1;
              wei.y[1]=j;
              wei.x[2]=i;
              wei.y[2]=j+1;
              wei.x[3]=i+1;
              wei.y[3]=j+1;
              for(int k=0;k<4;k++)
              {
                  jud(a[k]);
              }    
         }
    }
    return ans;
}      
int main()
{
    cin>>t;
    while(t--)
    {
         int anu=0,bnu=0,cnu=0,dnu=0;
         for(int i=0;i<4;i++)
         {
             for(int j=0;j<4;j++)
             {
                 cin>>map[i][j];
                 if(map[i][j]=='A')
                 {
                     a[0].x[anu]=i;
                     a[0].y[anu]=j;
                     anu++;
                 }
                 else if(map[i][j]=='B')
                 {
                     a[1].x[bnu]=i;
                     a[1].y[bnu]=j;
                     bnu++;
                 }
                 else if(map[i][j]=='C')
                 {
                     a[2].x[cnu]=i;
                     a[2].y[cnu]=j;
                     cnu++;
                 }
                 else if(map[i][j]=='D')
                 {
                     a[3].x[dnu]=i;
                     a[3].y[dnu]=j;
                     dnu++;
                 }                   
             }  
         }
         cout<<f()<<endl;
    }
}  
                              
    
   
