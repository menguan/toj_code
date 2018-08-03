#include<iostream>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    long long t=n*n;
    cout<<n<<" "<<t/2<<" "<<t/2+1<<endl;
  }
} 