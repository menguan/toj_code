#include<iostream>
using namespace std;
int n,m;
int gcd(int a,int b)
{
  int r=b%a;
  while(r)
  {
    b=a;
    a=r;
    r=b%a;
  }
  return a;
}    
void solve()
{
  int a=m+1;
  int b=n+2;
  int c=gcd(a,b);
  cout<<a/c<<" "<<b/c<<endl;
}  
  int main()
{
  while(cin>>n>>m&&(n+m))
  {
    solve();
  }
}         
  