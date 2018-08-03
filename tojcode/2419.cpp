#include<iostream>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main()
{
  int t;
  double d,D,s;
  cin>>t;
  while(t--)
  {
    cin>>D>>d>>s;
    cout<<(int)(pi/asin((d+s)/(D-d)))<<endl;
  }
}