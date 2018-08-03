#include<iostream>
using namespace std;
int a[600];

int main()
{
  for(int i=0;i<=599;i++)
  {
    a[i]=-1;
  }
  int n,m;
  cin>>n>>m;
  int op,st,en;
  while(m--)
  {
    cin>>op>>st>>en;
    if(op)
    {
      int count=0;
      for(int i=st;i<=en;i++)
      {
        if(a[i]==1)
          count++;
      }
      cout<<count<<endl;
    }
    else
    {
      for(int i=st;i<=en;i++)
      {
        a[i]*=-1;
      }
    }
  }
}   