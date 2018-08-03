#include<iostream>
#include<cstring>
using namespace std;
int dir[11][4]={1,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1};
int  dp[1000000];
int cost[1000000];
int aa[1000000];
int map[1000][1000];
bool vis[1000][1000];
char a[100];
int m,n;
void ff(int x,int y)
{
     
     if(vis[x][y]) return ;
     
     vis[x][y]=1;
     int tt=map[x][y];
     if(dir[tt][0]==1){if(x>=0&&y-1>=0&&x<m&&y-1<n)
                        if(dir[map[x][y-1]][2]==1)
                                   ff(x,y-1);}
      if(dir[tt][1]==1){if(x-1>=0&&y>=0&&x-1<m&&y<n)
                        if(dir[map[x-1][y]][3]==1)
                                   ff(x-1,y);}
      if(dir[tt][2]==1){if(x>=0&&y+1>=0&&x<m&&y+1<n)
                        if(dir[map[x][y+1]][0]==1)
                                   ff(x,y+1);}
      if(dir[tt][3]==1){if(x+1>=0&&y>=0&&x+1<m&&y<n)
                        if(dir[map[x+1][y]][1]==1)
                                   ff(x+1,y);}
     return ;}
     
int main()
{
  //int n,m,a,b;
  int t;
  
  while(cin>>m>>n)
  {
     if(n<0||m<0) return 0;
     memset(map,-1,sizeof(map));
     for(int i=0;i<m;i++)
     {
           cin>>a;
           for(int j=0;j<n;j++)
           {
                 map[i][j]=a[j]-'A';
           }
     }
     int ans=0;
     memset(vis,0,sizeof(vis));
     for(int i=0;i<m;i++)
     {
          for(int j=0;j<n;j++)
          {
             if(!vis[i][j])
             {
                         ans++;
                         ff(i,j);
             }
          }
     }
     cout<<ans<<endl;          
             
                       
  }  
  
      
}
