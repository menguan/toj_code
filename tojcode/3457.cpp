#include<iostream>
using namespace std;
int a[26][26];
int main()
{
  int n;
  while(cin>>n)
  {
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      cin>>a[i][j];
    for(int i=2;i<=n;i++)
      a[i][1]+=a[i-1][1];
    for(int i=2;i<=n;i++)
      a[i][i]+=a[i-1][i-1];
    for(int i=3;i<=n;i++)
    for(int j=2;j<i;j++)
    {
      if(a[i-1][j-1]>a[i-1][j])
        a[i][j]+=a[i-1][j-1];
      else
        a[i][j]+=a[i-1][j];
    }
    int max=0;
    for(int i=1;i<=n;i++)
    {
      if(a[n][i]>max)
        max=a[n][i];
    }
    cout<<max<<endl;
  }
}              
           
  