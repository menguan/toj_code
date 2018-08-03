#include<iostream>
using namespace std;
int a[2000];
int main()
{
  int n;
  a[0]=1;
  a[1]=1;
  for(int i=2;i<=1000;i++)
  {
    a[i]=0;
      for(int j=0;j<=i/2;j++)
      {
        a[i]+=a[j];
      }  
  }
  int t,count=1;
  cin>>t;
  while(t--)
  {
    cin>>n;
    cout<<count++<<" "<<a[n]<<endl;
  }
}    
      