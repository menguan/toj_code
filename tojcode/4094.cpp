#include<iostream>
#include<cstring>
using namespace std;
int ans[210][210];
bool visit[210][210];
int main()
{int n,m;
  while(cin>>n>>m){
  
  memset(visit,0,sizeof(visit));
  
  int dir=3;//0 1 2 3 u d l r
  int x=0,y=0;
  ans[x][y]=1;
  visit[0][0]=1; 
  int now=2;
  while(now<=n*m)
  {
    
    
    if(dir==3)
    {
      if(y+1>=m||visit[x][y+1])
      {
        dir=1;
        x++;
      }
      else
        y++;
      ans[x][y]=now++;visit[x][y]=1;
    }      
    else if(dir==1)
    {
      if(x+1>=n||visit[x+1][y])
      {
        dir=2;
        y--;
      }
      else
        x++;
       ans[x][y]=now++;visit[x][y]=1;
    }
    else if(dir==2)
    {
      if(y-1<0||visit[x][y-1])
      {
        dir=0;
        x--;
      }
      else
        y--;
      ans[x][y]=now++;visit[x][y]=1;
    }
    else if(dir==0)
    {
      if(x-1<0||visit[x-1][y])
      {
        dir=3;
        y++;
      }
      else
        x--;
      ans[x][y]=now++;visit[x][y]=1;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(j!=0)
        cout<<" ";
      cout<<ans[i][j]; 
    }
    cout<<endl;
  }
  }
}       