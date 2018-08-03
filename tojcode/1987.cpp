#include<iostream>
using namespace std;

int main()
{
  int a[10]={0,1,2,3,3,4,5,6,7,8};
  int n;
  while(cin>>n,n)
  {
    int re=0;
    int t=n;
    int i=1;
    while(n)
    {
      re+=a[n%10]*i;
      n/=10;
      i*=9;
    }  
    cout<<t<<": "<<re<<endl;
  }
}   