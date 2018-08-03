#include<iostream>
using namespace std;
int main()
{
  int n,t;
  while(cin>>n,n)
  {
    int re=0;
    int sum=0;
    while(n--)
    {
      cin>>t;
      if(sum+t<=0)
        sum=0;
      else
        sum+=t;
      if(sum>=re)
        re=sum;
    }
    if(!re)
      cout<<"Losing streak."<<endl;
    else
      cout<<"The maximum winning streak is "<<re<<"."<<endl;
  }
}     