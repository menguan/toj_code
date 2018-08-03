#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main()
{
  double n;
  cin>>n;
  cout<<setprecision(6)<<fixed<<pi*n*n<<endl;
  cout<<setprecision(6)<<fixed<<2*n*n<<endl;
  
} 