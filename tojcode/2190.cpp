#include<iostream>
using namespace std;
int a[100010];
int main()
{
  int n,m,k;
  while(cin>>n>>m>>k)
  {
    for(int i=1;i<=n;i++)
      a[i]=i;
    int x,y,q;      
    while(m--)
    {
        cin>>x>>y;
        if(x>y)
        {
          int temp=x;
          x=y;
          y=temp;
        }
        int t=a[x];    
        for(int i=1;i<=n;i++)
        {
          if(a[i]==t)
            a[i]=a[y];
        }            
    }
    while(k--)
    {
        cin>>q;
        if(a[q]==a[1])
          cout<<"Yes"<<endl;
        else
          cout<<"No"<<endl;
    }
  }
} 