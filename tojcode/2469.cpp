#include<iostream>
using namespace std;
int a[110];
bool b[110];
int main()
{
  int n,m,k;
  cin>>k;
  while(k--)
  {
    cin>>n>>m; 
    for(int i=1;i<=n;i++)
    {
      a[i]=i;
      b[i]=1;
    }  
      
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
    int count=0;
    for(int i=1;i<=n;i++)
    {
      if(b[a[i]])
      {
        count++;
        b[a[i]]=0;
      }
    }
    cout<<count<<endl;      
      
      
  }
}   