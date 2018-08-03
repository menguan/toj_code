#include<iostream>
#include<algorithm>
using namespace std;
struct f
{
  int st;
  int end;
  bool flag;
  int num;
}a[10010];
bool cmp(f a,f b)
{
  return (a.end<b.end);
}  
int main()
{
  int n;
  while(cin>>n,n)
  {
    for(int i=0;i<n;i++)
    {
      cin>>a[i].st>>a[i].end;
      a[i].end+=a[i].st;
      a[i].flag=0;
    }
    sort(a,a+n,cmp);
    a[0].flag=1;
    int now=0;
    for(int i=1;i<n;i++)
    {
      if(a[i].st>=a[now].end)
      {
        a[i].flag=1;
        now=i;
      }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
      if(a[i].flag)
        count++;
    }
    cout<<count<<endl;
  }
}  