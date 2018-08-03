#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
  int a,b;
  while(cin>>a>>b&&(a+b))
  {
    
    double t=(a-b)*1.0/(a+b);
    cout<<setprecision(3)<<fixed<<t<<endl;
    
  }
}    
     