#include<iostream>
#include<algorithm>
using namespace std;
int a[5000],b[200000];
int main()
{
  int m,n;
  while(cin>>m>>n)
  {
    for(int i=0;i<m;i++)
      cin>>a[i];
    for(int i=0;i<n;i++)
      cin>>b[i];
    sort(a,a+m);
    sort(b,b+n);
    int d1=0,d2=0;
    int count=0;
    while(d1<m&&d2<n)
    {
      if(a[d1]==b[d2])
      {
        count++;
        d1++;
        d2++;
      }
      else
      {
        if(a[d1]>b[d2])
        {
          d2++;
        }
        else
          d1++;
      }
    }
    cout<<count<<endl;
  }
}              
          
  