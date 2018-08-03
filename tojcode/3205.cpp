#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  int b[n];
  for(int j=0;j<n;j++)
  {
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    sort(a,a+n);
    b[j]=a[n/2];
  }
  sort(b,b+n);
  cout<<b[n/2]<<endl;
  
}    