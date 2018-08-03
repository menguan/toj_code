#include<iostream>
using namespace std;
bool map[1000][1000];int c,r;
int a[8][2]={{1,0},{1,-1},{1,1},{-1,0},{-1,1},{-1,-1},{0,1},{0,-1}};
void bfs(int i,int j)
{
  if(i<0||j<0||i==r||j==c||map[i][j]==0)
    return ;
  else
  {
    map[i][j]=0;
    for(int k=0;k<8;k++)
    {
      bfs(i+a[k][0],j+a[k][1]);
    }
  }  
}        
int main()
{
  while(cin>>c>>r)
  {
    if(c==0&&r==0)
      return 0;
      
    int ans=0;
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
      cin>>map[i][j];
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    if(map[i][j])
    {
      ans++;
      bfs(i,j);
    }
    cout<<ans<<endl;
  }
}         