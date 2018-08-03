#include<iostream>
#include<algorithm>
using namespace std;
int a[1000010],b[1000010];
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    for(int i=0;i<n;i++)
      cin>>b[i];
        
    a[1]=a[0]+a[1];
    b[1]=b[0]+b[1];
    for(int i=2;i<n;i++)
    {
      a[i]=a[i]+max(a[i-1],b[i-2]);
      b[i]=b[i]+max(b[i-1],a[i-2]);
    }
    int re=max(a[n-1],b[n-1]);
    cout<<re<<endl;
  }
}