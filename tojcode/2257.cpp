#include<iostream>
using namespace std;
int main()
{
  int a[200];
  int t;
  int n,k;
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    if(n==1)
    {
      cout<<k<<endl;
      continue;
    }
    a[0]=k;bool flag=0;
    int carry=0;int i;
    for(i=1;;i++)
    {
      a[i]=(n*a[i-1]+carry)%10;
      carry=(n*a[i-1]+carry)/10;
      if(carry+n*a[i]==k)
      {
          flag=1;
          break;
      }    
    }
    if(flag&&n<=k)
    {
      for(int j=i;j>=0;j--)
        cout<<a[j];
      cout<<endl;
    }
    else
      cout<<0<<endl;
  }
}                