#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char a[40];
int x[40],y[40];
int n;
bool vis[40];
int v[5];
int flag;
void dfs(int dep)
{
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
      vis[i]=1;
      if(dep==0)
      {
        v[dep]=i;
        dfs(dep+1);
      }
      else if(dep==1)
      {
        if(y[i]==y[v[0]]&&x[i]>x[v[0]])
        {
          v[dep]=i;
          dfs(dep+1);
        }
      }
      else if(dep==2)
      {
        if(x[i]==x[v[1]]&&y[i]<y[v[1]])
        {
          v[dep]=i;
          dfs(dep+1);
        }
      }
      else if(dep==3)
      {
        if(y[i]==y[v[2]]&&x[i]<x[v[2]]&&x[i]==x[v[0]])
        {
          v[dep]=i;
          if(flag%10==0)
          {
            cout<<endl;
          }
          flag++;
          cout<<" ";
          for(int j=0;j<4;j++)  cout<<a[v[j]];
        }
      }
      vis[i]=0;
    }
  }
}
int main()
{
  int cas=1;
  while(cin>>n,n)
  {
    
    flag=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
       cin>>a[i]>>x[i]>>y[i];
    }cout<<"Point set "<<cas++<<":";//<<endl;
    dfs(0);
    if(flag==0)
      cout<<" No rectangles"<<endl;
    else 
      cout<<endl;  
  }
}