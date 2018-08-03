#include<iostream>
using namespace std;
int gcd(int m,int n)
{
  int r=m%n;
  while(r)
  {
    m=n;
    n=r;
    r=m%n;
  }
  return n;
}
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int num,m,n;
        cin>>num;
        cin>>m;
        for(int i=1;i<num;i++)
        {
          cin>>n;
          m=(m/gcd(m,n))*n;
        }
        cout<<m<<endl;
    }
    return 0;
}   