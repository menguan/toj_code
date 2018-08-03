#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int a;
  while(cin>>a,a)
  {
    double k=1.0*((int)(a-1940)/10);
    double sum=0;
    for(double i=1;;i+=1.0)
    {
      sum+=log(i);
      if(sum/log(2.0)>pow(2.0,k))
      {
        cout<<i-1<<endl;
        break;
      }
    }
  }
} 