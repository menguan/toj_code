#include<iostream>
#include<cstring>
using namespace std;
int map[110][110];
bool flag[110][110];
int n,m;
void setnumber()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(map[i][j]==-1)
        continue;
      else
        {
          map[i][j]=0;
          if(map[i+1][j]==-1&&i+1<=n)
          map[i][j]++;
          if(map[i-1][j]==-1&&i-1>=0)
          map[i][j]++;
          if(map[i][j+1]==-1&&j+1<=n)
          map[i][j]++;
          if(map[i][j-1]==-1&&j-1>=0)
          map[i][j]++;
          if(map[i+1][j+1]==-1&&j+1<=n&&i+1<=n)
          map[i][j]++;
          if(map[i+1][j-1]==-1&&j-1>=0&&i+1<=n)
          map[i][j]++;
          if(map[i-1][j+1]==-1&&j+1<=n&&i-1>=0)
          map[i][j]++;
          if(map[i-1][j-1]==-1&&j-1>=0&&i-1>=0)
          map[i][j]++;
        }
     }
   }
}          
  
void bfs(int s,int t)
{
  
  if(s==0||s==n+1||t==0||t==n+1||flag[s][t]==1)
  {
    return;
  }
  else if(map[s][t]>0)
  {
    flag[s][t]=1;
    return;
  }
  else if(map[s][t]==0)
  {
    flag[s][t]=1;
    bfs(s+1,t-1);
    bfs(s+1,t+1);
    bfs(s+1,t);
    bfs(s-1,t+1);
    bfs(s-1,t-1);
    bfs(s-1,t);
    bfs(s,t+1);
    bfs(s,t-1);
  }
}    
          
  

int main()
{
  while(cin>>n>>m){
  if(m==0&&n==0)
    return 0;
  int s,t;
  memset(flag,0,sizeof(flag));
  memset(map,0,sizeof(map));//在这个地方wa了一次，虽然不知道为什么，我后面函数明明赋值了啊 
  while(m--)
  {  
    cin>>s>>t;
    map[s][t]=-1;
  }
  setnumber();
  cin>>s>>t;
  if(map[s][t]>0)
  {
    flag[s][t]=1;
  }
  else if(map[s][t]==-1)
  {
    cout<<"oops!"<<endl<<endl;
    continue;
  }
  else
  {
    bfs(s,t);
  }
   
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(flag[i][j])
        cout<<map[i][j];
      else
        cout<<".";
    }
    cout<<endl;
  }
  cout<<endl;
  }
}          
   