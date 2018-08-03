#include<iostream>
using namespace std;
char map[101][101];
int m,n;
void bfs(int x,int y)
{
  
  if(map[x][y]=='@')
  {
  
  map[x][y]='*';
  bfs(x+1,y);
  bfs(x+1,y-1);
  bfs(x+1,y+1);
  bfs(x-1,y);
  bfs(x-1,y+1);
  bfs(x-1,y-1);
  bfs(x,y+1);                
  bfs(x,y-1);
  } 
  if(x<0||x==m||y<0||y==n||map[x][y]=='*') 
  return ;     
}
int main()
{
  int m,n;
  while(cin>>m>>n)
  {
    if(m==0)
      return 0;
    
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>map[i][j];
      }
    }
    int count=0;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(map[i][j]=='@')
        {
          
          bfs(i,j);
          count++;
          
        }  
      }
    }
    cout<<count<<endl;
  }
}