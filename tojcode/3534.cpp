#include<iostream>
using namespace std;
int main()
{
  long long a;
  while(cin>>a,a)
  {
    long long b=11111111111;
    while(a%b)
    {
      b/=10;
    }
    cout<<a/b<<endl;
  }
}       