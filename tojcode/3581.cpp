#include<iostream>
#include<algorithm>
using namespace std;
struct f
{
  int id;
  int j,p;
  double me;
}c[30000];
bool cmp(f a, f b)
{
  return a.me>b.me;
}  
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>c[i].j>>c[i].p;
      c[i].me=c[i].j*1.0/c[i].p;
      c[i].id=i+1;
    }
    sort(c,c+n,cmp);
    int sum=c[0].p+c[1].p+c[2].p;
    cout<<sum<<endl;
    for(int i=0;i<3;i++)
      cout<<c[i].id<<endl;
    //while(1);
}      
      
    