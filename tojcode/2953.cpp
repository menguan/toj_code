#include<iostream>
using namespace std;
int a[600],b[600];
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
    a[i]=b[i]=0;
  int r,c;
  for(int i=0;i<n;i++)
  {
    cin>>r>>c;
    a[r]++;b[c]++;
  }
  int count=0;
  for(int i=1;i<=n;i++)
  {
    while(a[i]==0)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(a[j]>1)
        {
          a[j]--;
          a[i]++;
          count+=(j-i);
          break;
        }
      }
    }
    while(a[i]>1)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(a[j]==0)
        {
          a[j]++;
          a[i]--;
          count+=(j-i);
          break;
        }
      }
    }    
    while(b[i]==0)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(b[j]>1)
        {
          b[j]--;
          b[i]++;
          count+=(j-i);
          break;
        }
      }
    }
    while(b[i]>1)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(b[j]==0)
        {
          b[j]++;
          b[i]--;
          count+=(j-i);
          break;
        }
      }
    }
  }
  cout<<count<<endl;
  //while(1);
} 