#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long long a,b;
  long long sum;
  while(n--)
  {
    cin>>a>>b;
    sum=0;
    sum+=(a-1);
    sum+=(a*(b-1));
    cout<<sum<<endl;
  }
}    