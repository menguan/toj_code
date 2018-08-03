#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct f
{
       int x;int y;
       }a[100];
    bool vis[200][220];   
int main()
{
    int t;
    int n,h;
    cin>>t;
    while(t--)
    {
              cin>>n>>h;
              memset(vis,0,sizeof(vis));
        for(int i=0;i<h;i++)
        {
                cin>>a[i].x>>a[i].y;
                vis[a[i].x][a[i].y]=1;
        } 
        bool flag=0;bool is=0;
        for(int i=1;i<n&&!flag;i++)
        {
          for(int j=1;j<n&&!flag;j++)
          {
                  if(vis[i][j])
                    continue;
                  is=1;int le=min(min(i,j),min(n-i,n-j));  
                  for(int k=0;k<h;k++)
                  {
                    if(hypot(1.0*i-a[k].x,1.0*j-a[k].y)>le)
                      is=0;
                  }
                  if(is==1)
                  {
                   flag=1;
                   cout<<i<<" "<<j<<endl;
                   break;
                  }
          }
        }
        if(flag==0)
          cout<<"poodle"<<endl;
    }
}   
                                       
                                    
              

