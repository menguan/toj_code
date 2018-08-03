#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int n;
  while(cin>>n,n)
  {
    if(n<=3)
      cout<<1<<endl;
    else if(n==4)
      cout<<2<<endl;
    else
      cout<<n<<endl;
  }
}    
  