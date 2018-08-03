#include<iostream>
using namespace std;
bool f(long long a,long long b)
{
  if(b>a)
  {
    long long temp=a;
    a=b;
    b=temp;
  }
  if(a==b)
    return 1;
  if(a>=2*b)
    return 1;
  if(a<2*b)
    return !f(a-b,b);
}          
int main()
{
  long long a,b;
  while(cin>>a>>b)
  {
    if(a==0&&b==0)
      return 0;
    bool flag=f(a,b);
    if(flag)
      cout<<"Stan wins"<<endl;
    else
      cout<<"Ollie wins"<<endl;
  }
}     