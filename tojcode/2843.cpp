#include<iostream>
#include<algorithm>
int a[10010],b[10010],c[10010];
using namespace std;
int main()
{
  int t,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++)
    {
      a[i]=a[i]+max(b[i-1],c[i-1]);
      b[i]=b[i]+max(a[i-1],c[i-1]);
      c[i]=c[i]+max(a[i-1],b[i-1]);
    }
    int re=max(a[n-1],max(b[n-1],c[n-1]));
    cout<<re<<endl;
  }
}  