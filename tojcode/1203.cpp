#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  long long n;
  int i;
  while(cin>>n,~n)
  {
    for(i=2;i<=(int)sqrt(n*1.0);i++)
      for(;!(n%i);n/=i)
      cout<<"    "<<i<<endl;
    if(n>1)
      cout<<"    "<<n<<endl<<endl;
  }
return 0;
}