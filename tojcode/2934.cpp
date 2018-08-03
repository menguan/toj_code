#include<iostream>
#include<algorithm>
using namespace std;
struct f
{
   int r1,r2,num;
}a[60000];       
bool f1(f a,f b)
{
     return (a.r1>b.r1);
}     
bool f2(f a,f b)
{
     return (a.r2>b.r2);
}
int main()
{
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
     cin>>a[i].r1>>a[i].r2;
     a[i].num=i;
  } 
  sort(a,a+n,f1);
  sort(a,a+k,f2);
  cout<<a[0].num+1<<endl;
  }  