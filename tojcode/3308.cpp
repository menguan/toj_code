#include<iostream>
using namespace std;
int main()
{
  double n;
  while(cin>>n)
  {
    long double sum=0;
    int count=1;
    while(sum<1)
    {
      sum+=((n/100)/count);
      count++;
    }
    cout<<count-1<<endl;
  }
}  