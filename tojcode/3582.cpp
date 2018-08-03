#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct no
{
  long long p,c;
  friend bool operator<(const no &aa,const no &bb)
  {
    return aa.p<bb.p;
  }
}a[100010];
int main()
{
  long long ans=0;
  long long n;long long mon;
  cin>>n>>mon;
  //scanf("
  for(int i=0;i<n;i++)
    cin>>a[i].p>>a[i].c;
  sort(a,a+n);
  for(int i=0;i<n;i++)
  {
    if(mon/a[i].p>=a[i].c)
    {
      mon-=a[i].p*a[i].c;
      ans+=a[i].c;
    }
    else
    {
      ans+=mon/a[i].p;
      break;
    }
  }
  cout<<ans<<endl;
  //while(1);
}
    