#include<iostream>
using namespace std;
int a[1001],b[1001],c[1001];
int main()
{
  int n,t,y;
  cin>>n;
  while(n--)
  {
    for(int i=0;i<1001;i++)
      c[i]=0;
    cin>>t>>y;
    for(int i=0;i<t;i++)
    {
      cin>>a[i];
    }
    for(int i=0;i<y;i++)
    {
      cin>>b[i];
    }
    
    for(int i=0;i<t;i++)
    {
      for(int j=0;j<y;j++)
      {
        if(a[i]==b[j])
          c[a[i]]=1;
      }
    }
    int count=0;
    for(int i=0;i<1001;i++)
    {
      if(c[i]&&!count++)
      cout<<i;
      else if(c[i])
      cout<<" "<<i;
    }
    cout<<endl;
  }
} 