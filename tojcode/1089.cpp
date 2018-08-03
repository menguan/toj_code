#include<iostream>
using namespace std;
long long f(long long a,long long b,int n){ 
    long long ret=1;
    while(b)
    {
        if (b&1)
            ret=(long long)((((long long)ret)*a)%n);
        a=(a*a)%29;
        b>>=1;
    }
    return ret;
}
int main()
{
  long long n;
  while(cin>>n,n)
  {
    long long a,b,c;
    a=(f(2,2*n+1,29)-1)%29;
    b=((f(3,n+1,29)-1)*15)%29;
    c=((f(167,n+1,29)-1)*18)%29;
    cout<<(a*b*c)%29<<endl;
  }
}    