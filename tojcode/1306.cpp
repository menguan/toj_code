#include<iostream>
using namespace std;
char map[4][4];
int ans;int n;
bool judge(int x,int y)
{
  for(int i=x+1;i<n;i++)
  {
    if(map[i][y]=='O')
      return 0;
    if(map[i][y]=='X')
      break;
  }
  for(int i=x-1;i>=0;i--)
  {
    if(map[i][y]=='O')
      return 0;
    if(map[i][y]=='X')
      break;
  }
  for(int i=y+1;i<n;i++)
  {
    if(map[x][i]=='O')
      return 0;
    if(map[x][i]=='X')
      break;
  }
  for(int i=y-1;i>=0;i--)
  {
    if(map[x][i]=='O')
      return 0;
    if(map[x][i]=='X')
      break;
  }
  return 1;
}       
void solve(int dep,int now)
{
  if(dep==n*n)
  {
    if(now>ans)
      ans=now;
    return;
  }
  int x=dep/n;
  int y=dep%n;
  if(map[x][y]=='.'&&judge(x,y))
  {
    map[x][y]='O';
    solve(dep+1,now+1);
    map[x][y]='.';
  }
  solve(dep+1,now);
}    
          
int main()
{
  while(cin>>n,n)
  {
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin>>map[i][j];
    ans=0;
    solve(0,0);
    cout<<ans<<endl;
  }
}  
    
    
    
    
    
    